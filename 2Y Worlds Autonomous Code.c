
//while(SensorValue[x] > y);
void StarL()
{
	armHold = 1;
	desArmPos = armPos;
	ClawState = 1;
	desArmPos = 2450;             //arm up a lil
	driveADP(475,-127,);
	desArmPos = 2950;
	wait1Msec(3000);
	desArmPos = 1000;       //arm down
	driveADP(200,127);
	gyroTurn(9,200);
	driveADP(100,127);
	ClawState = 0;       //close
	wait1Msec(100);
	ClawState = 1;
	wait1Msec(400);
	ClawState = 0;
	desArmPos = 1750;
	driveADP(330,-127);
	desArmPos = 2950;
	wait1Msec(888);
	ClawState = 1;      //shoot
	desArmPos = 1000;
	driveADP(100,127);
	ClawState = 0;       //close
	wait1Msec(100);
	ClawState = 1;
	wait1Msec(400);
	ClawState = 0;
	desArmPos = 1750;
	driveADP(330,-127);
	desArmPos = 2950;
	wait1Msec(888);
	ClawState = 1;      //shoot
}

void StarR ()
{
	armHold = 1;
	desArmPos = armPos;
	ClawState = 1;
	desArmPos = 2450;             //arm up a lil
	driveADP(660,-127,2000);
	desArmPos = 2950;
	wait1Msec(3000);
	desArmPos = 1000;       //arm down
	driveADP(200,127);
	gyroTurn(8,280,87,22,1500);			//turn
	driveADP(300,127);
	ClawState = 0;       //close
	wait1Msec(100);
	ClawState = 1;
	wait1Msec(400);
	ClawState = 0;
	desArmPos = 1750;
	driveADP(230,-127);
	desArmPos = 2950;
	wait1Msec(888);
	ClawState = 1;      //shoot
	wait1Msec(500);
	desArmPos = 1000;
	wait1Msec(500);
	driveADP(100,127);
	ClawState = 0;       //close
	wait1Msec(100);
	ClawState = 1;
	wait1Msec(400);
	ClawState = 0;
	desArmPos = 1750;
	driveADP(200,-127);
	desArmPos = 2950;
	wait1Msec(888);
	ClawState = 1;      //shoot
}

void CubeL ()
{
	armHold = 1;
	desArmPos = armPos;
	ClawState = 1;
	driveADP(500,127,1500);
	ClawState = 0;          //claw close
	desArmPos = 1500;
	gyroTurn(8,950,87,22,1500);
	driveADP(280,-127);     //drive
	desArmPos = 2950;
	wait1Msec(890);
	ClawState = 1;				//shoot
	wait1Msec(200);
	desArmPos = 1000;
	wait1Msec(1300);
	driveADP(740,127,1500);
	ClawState = 0;       //close
	wait1Msec(100);
	ClawState = 1;
	wait1Msec(400);
	ClawState = 0;
	wait1Msec(200);
	gyroTurn(8,130,87,22,900);
	desArmPos = 1750;
	driveADP(420,-127);   //drive
	desArmPos = 2900;
	wait1Msec(875);
	ClawState = 1;      //shoot
}

void CubeR ()
{
	armHold = 1;
	desArmPos = armPos;
	ClawState = 1;
	driveADP(500,127,1500);
	ClawState = 0;          //claw close
	desArmPos = 1500;
	gyroTurn(9,970,87,22,1500);
	driveADP(280,-127);     //drive
	desArmPos = 2950;
	wait1Msec(880);
	ClawState = 1;				//shoot
	wait1Msec(200);
	desArmPos = 1000;
	wait1Msec(1300);
	driveADP(740,127,1500);
	ClawState = 0;       //close
	wait1Msec(100);
	ClawState = 1;
	wait1Msec(400);
	ClawState = 0;
	wait1Msec(200);
	gyroTurn(9,130,87,22,900);
	desArmPos = 1750;
	driveADP(420,-127);   //drive
	desArmPos = 2900;
	wait1Msec(860);
	ClawState = 1;      //shoot
}

void Skills ()
{
	//armHold = 1;
	//desArmPos = armPos;
	//ClawState = 1;
	//driveADP(500,127,1500);
	//ClawState = 0;          //claw close
	//driveADP(220,127,1500);
	//desArmPos = 1500;
	//gyroTurn(9,950,87,22,1500);
	//desArmPos = 2950;
	//wait1Msec(895);
	//ClawState = 1;				//shoot
	//wait1Msec(200);
	//driveADP(100,-127,1000);
	//desArmPos = 1000;
	//driveADP(300,127);
	//ClawState = 0;       //close
	//wait1Msec(100);
	//ClawState = 1;
	//wait1Msec(400);
	//ClawState = 0;
	//wait1Msec(200);
	armHold = 1;
	desArmPos = armPos;
	ClawState = 1;
	driveADP(500,127,1500);
	ClawState = 0;          //claw close
	desArmPos = 1500;
	gyroTurn(9,970,87,22,1500);
	driveADP(280,-127);     //drive
	desArmPos = 2950;
	wait1Msec(895);
	ClawState = 1;				//shoot
	wait1Msec(200);
	desArmPos = 1000;
	wait1Msec(1300);
	driveADP(740,127,1500);
	ClawState = 0;       //close
	wait1Msec(100);
	ClawState = 1;
	wait1Msec(400);
	ClawState = 0;
	wait1Msec(200);
	gyroTurn(9,130,87,22,900);
	desArmPos = 1750;
	driveADP(100,-127);   //drive
	desArmPos = 2900;
	wait1Msec(880);
	ClawState = 1;      //shoot
	desArmPos = 1000;
	gyroTurn(9,300,87,22,1000);
	driveADP(400,127,1500);
	ClawState = 0;       //close
	wait1Msec(100);
	ClawState = 1;
	wait1Msec(400);
	ClawState = 0;
	wait1Msec(200);
	desArmPos = 2950;
	driveADP(200,-127);
	wait1Msec(880);
	ClawState = 1;
	gyroTurn(9,200,87,22,1000);      //shoot 1
	driveADP(300,127,1500);
	ClawState = 0;       //close
	wait1Msec(100);
	ClawState = 1;
	wait1Msec(400);
	ClawState = 0;
	wait1Msec(200);
	desArmPos = 2950;
	driveADP(200,-127);
	wait1Msec(880);
	ClawState = 1;
	gyroTurn(9,200,87,22,1000); 		//shoot 2
	driveADP(300,127,1500);
	ClawState = 0;       //close
	wait1Msec(100);
	ClawState = 1;
	wait1Msec(400);
	ClawState = 0;
	wait1Msec(200);
	desArmPos = 2950;
	driveADP(200,-127);
	wait1Msec(880);
	ClawState = 1;
		gyroTurn(9,200,87,22,1000);      //shoot 3
	driveADP(300,127,1500);
	ClawState = 0;       //close
	wait1Msec(100);
	ClawState = 1;
	wait1Msec(400);
	ClawState = 0;
	wait1Msec(200);
	desArmPos = 2950;
	driveADP(200,-127);
	wait1Msec(880);
	ClawState = 1;














}

void NA ()
{
	armHold = 1;
	ClawState = 1;
}
