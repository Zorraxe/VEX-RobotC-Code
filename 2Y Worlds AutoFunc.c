
void gyroInitialize ()
{
	SensorType[Gyro] = sensorNone;
	wait1Msec(1000);
	SensorType[Gyro] = sensorGyro;
	wait1Msec(2000);
	//SensorScale[Gyro] = 260;
	SensorValue[Gyro] = 0;
	SensorFullCount[Gyro] = 36000;
}

// ** GYRO TURN ***************************************************************************************************
// target (in degrees) is added/subtracted from current gyro reading to get a target gyro reading
// run PD loop to turn to target
// checks if target has been reached AND is at target for over 250ms before moving on
void gyroTurn (int turnDirection, int targetDegrees, int maxPower = 87, int minPower = 22, int timeOut = 3000)
{
	// initialize PD loop variables
	float kp = 0.33; // TO BE TUNED
	int error = targetDegrees;
	int drivePower = 0;

	clearTimer(T2);

	// finish check variables
	bool isAtTarget = false;

	// initialize gyro data variables
	int targetReading = SensorValue[Gyro];

	// get gyroscope target reading
	if (turnDirection == 8)
		targetReading += targetDegrees;
	else if (turnDirection == 9)
		targetReading -= targetDegrees;

	// change kp if target is under 20 degree threshold
	if (targetDegrees < 200)
		kp = 0.4;

	// run motors until target is within 1/10 degree certainty
	while (!isAtTarget && time1[T2] < timeOut)
	{
		error = targetReading - SensorValue[Gyro]; 	// calculate error
		drivePower = error * kp;	// calculate PD loop output

		// cap between min and max power
		drivePower = drivePower < minPower && drivePower > 0 ? minPower : drivePower > -minPower && drivePower < 0 ? -minPower : drivePower;
		drivePower = drivePower > maxPower ? maxPower : drivePower < -maxPower ? -maxPower : drivePower;

		// send power to motors
		LPower = drivePower;
		RPower = -drivePower;

		// check for finish
		if (abs(error) > 10) 	// if robot is within 1 degree of target and timer flag is off
			clearTimer(T1);			// start a timer
		if (time1(T1) > 200)	// if the timer is over 250ms and timer flag is true
			isAtTarget = true;	// set boolean to complete while loop
	}
	// stop motors
	LPower = 0;
	RPower = 0;

	// reset kp
	kp = 0.3;
}

void turnDP(int direction, int distance, int power, float Kd = 0.4, int timeOut = 5000)
{
	int error = 0;
	SensorValue[RightEncoder] = SensorValue[LeftEncoder] = 0;
	clearTimer(T1);
	if(direction == 8)
	{
		while(SensorValue[RightEncoder] < distance && time1[T1] < timeOut)
		{
			error = distance - SensorValue[RightEncoder];
			//int sync = abs(SensorValue[LeftEncoder]) - abs(SensorValue[RightEncoder]);
			if(minTurnPower + error*Kd > power)
			{
				LPower = -power;
				RPower = power;
			}
			else
			{
				LPower = -minTurnPower - error*Kd ;
				RPower = minTurnPower + error*Kd ;
			}
		}
		RPower = -5;
		LPower = 5;
	}
	else
	{
		while(SensorValue[LeftEncoder] < distance && time1[T1] < timeOut)
		{
			error = distance - SensorValue[LeftEncoder];

			if(minTurnPower + error*Kd > power)
			{
				LPower = power;
				RPower = -power;
			}
			else
			{
				LPower = minTurnPower + error*Kd;
				RPower = -minTurnPower - error*Kd;
			}
		}
		RPower = +5;
		LPower = -5;

	}
	wait1Msec(50);
	RPower = 0;
	LPower = 0;
}
//##########################################################################################################################
void driveADP(int distance, int power, int timeOut = 3000, int brakePower = 0, float aKp = 0.5, float dKp = 0.01) // flip brake power when driving backwards
{
	//the bigger the aKp is, the faster you accelerate
	//the bigger the dKP is, the later you decelerate
	clearTimer(T1);
	float Kp = 0.00005;

	//resets encoders
	SensorValue[LeftEncoder] = SensorValue[RightEncoder] = 0;

	//calculate if forward or backwards
	int direction = 1;
	if(power<0)
		direction = -1;



	while((abs(SensorValue[LeftEncoder] + SensorValue[RightEncoder]) / 2)< distance/2 && time1[T1] < timeOut)
	{
		int error = SensorValue[LeftEncoder] - SensorValue[RightEncoder];

		float acceleration = (SensorValue[LeftEncoder] + SensorValue[RightEncoder])* aKp;
		writeDebugStream("Accleration is %f \n",acceleration);
		//LPower = abs(direction*minMovePower +acceleration) > power ? direction*power - error*Kp : direction*minMovePower + acceleration - error*Kp;
		//RPower = abs(direction*minMovePower +acceleration) > power ? direction*power + error*Kp : direction*minMovePower + acceleration + error*Kp;

		// if the min power + acceleration > 127, it caps to max speed
		if(abs(minMovePower +acceleration) > power)
		{
			LPower = power - error*Kp;
			RPower = power + error*Kp;

			writeDebugStream("LPower is %d , RPower is %d \n",LPower,RPower);
		}
		else
		{
			LPower = direction*minMovePower + acceleration - error*Kp;
			RPower = direction*minMovePower + acceleration + error*Kp;

			writeDebugStream("LPower is %d , RPower is %d \n",LPower,RPower);

		}
	}

	power = LPower = RPower;
	while((abs(SensorValue[LeftEncoder] + SensorValue[RightEncoder]) / 2)< distance && time1[T1] < timeOut)
	{
		int error = SensorValue[LeftEncoder] - SensorValue[RightEncoder];

		float decceleration = (distance - ((SensorValue[LeftEncoder] + SensorValue[RightEncoder])/2))* dKp;
		writeDebugStream("Deccleration is %f \n",decceleration);

		//LPower = abs(direction*minMovePower +acceleration) > power ? direction*power - error*Kp : direction*minMovePower + acceleration - error*Kp;
		//RPower = abs(direction*minMovePower +acceleration) > power ? direction*power + error*Kp : direction*minMovePower + acceleration + error*Kp;

		// if the min power + acceleration > 127, it caps to max speed
		if(abs(direction*minMovePower + decceleration) > power)
		{
			LPower = power - error*Kp;
			RPower = power + error*Kp;
		}
		else if(decceleration > 0)
		{
			LPower = 15 + decceleration - error*Kp;
			RPower = 15 + decceleration + error*Kp;

		}
	}

	LPower = RPower = direction*brakePower;
}
