float target;
float sens_last;
float sens_current;
float vel_current;
float vel_err;
float errorT;
float motor_output;

float Kp = 0;
float Ki = 0;
float Kd = 0;

float proportion;
float integral;
float derivative;

float errorLast;
float integralActiveZone = 1;

task flywheel_control()
{

	while (1 == 1)
	{
		sens_current = SensorValue[dgtl11];

		vel_current = sens_current - sens_last;
		sens_last = sens_current;

		writeDebugStream("%f\n", vel_current);

		// Calculate error
		vel_err = target - vel_current;
		// Total error
		errorT += vel_err;

		// Compute P, I, and D terms
		proportion += (vel_err * Kp);
		integral += errorT * Ki;
		derivative = (errorT - errorLast) * Kd;


		writeDebugStream("Proportion: %f\n", proportion);

		// Integral cap - so it does not accumulate too much
		if (integral > 127) integral = 127;
		if (integral < 0) integral = 0;

		// Send power output to motors
		motor_output = proportion + integral + derivative;

		if (motor_output > 127)
		{
			motor_output = 127;
		}

		// Motor powers, this is different on every robot ...
		motor[port3] = motor_output;
		motor[port7] = motor_output;
		motor[port8] = motor_output;
		motor[port1] = motor_output;

		writeDebugStream("Motor Output: %f\n", motor_output);

		errorLast = errorT;

		wait1Msec(25); // Refresh rate
	}
}

