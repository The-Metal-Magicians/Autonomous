#pragma config(Hubs,  S2, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Hubs,  S3, HTServo,  none,     none,     none)
#pragma config(Sensor, S1,     irs,            sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S2_C1_1,     motorD,        tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S2_C1_2,     motorE,        tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S2_C2_1,     motorF,        tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S2_C2_2,     motorG,        tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S2_C3_1,     motorH,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C3_2,     motorI,        tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S2_C4_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S2_C4_2,    servo2,               tServoStandard)
#pragma config(Servo,  srvo_S2_C4_3,    servo3,               tServoStandard)
#pragma config(Servo,  srvo_S2_C4_4,    servo4,               tServoStandard)
#pragma config(Servo,  srvo_S2_C4_5,    servo5,               tServoStandard)
#pragma config(Servo,  srvo_S2_C4_6,    servo6,               tServoContinuousRotation)
#pragma config(Servo,  srvo_S3_C1_1,    servo7,               tServoStandard)
#pragma config(Servo,  srvo_S3_C1_2,    servo8,               tServoContinuousRotation)
#pragma config(Servo,  srvo_S3_C1_3,    servo9,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_4,    servo10,              tServoNone)
#pragma config(Servo,  srvo_S3_C1_5,    servo11,              tServoNone)
#pragma config(Servo,  srvo_S3_C1_6,    servo12,              tServoNone)

//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

int ch; // defines integer

void initializeRobot() // resets all servos to starting position
{
	servo[servo1] = 0;
	servo[servo2] = 256;
	servo[servo3] = 0;
	servo[servo4] = 0;
	servo[servo7] = 256;
	servo[servo5] = 0;
	servo[servo8] = 256;

	return;
}

void ereset() //reset the encoder
{
	nMotorEncoder[motorD] = 0;
	nMotorEncoder[motorE] = 0;
	nMotorEncoder[motorF] = 0;
	nMotorEncoder[motorG] = 0;

	return;
}

void moveforward() //move the robot forward
{
	motor[motorD] = 75;
	motor[motorE] = 75;
	motor[motorF] = 75;
	motor[motorG] = 75;

	return;
}

void turnleft() //make the robot turn left
{
	motor[motorD] = -10;
	motor[motorE] = 50;
	motor[motorF] = -10;
	motor[motorG] = 50;

	return;
}

void turnright() //make the robot turn right
{
	motor[motorD] = 50;
	motor[motorE] = -50;
	motor[motorF] = 50;
	motor[motorG] = -50;

	return;
}

void movebackward() //make the robot move backwards
{
	motor[motorD] = -75;
	motor[motorE] = -75;
	motor[motorF] = -75;
	motor[motorG] = -75;

	return;
}

void brake() //temporary stop
{
	motor[motorD] = 0;
	motor[motorE] = 0;
	motor[motorF] = 0;
	motor[motorG] = 0;

	return;
}

task main()
{
	initializeRobot();

	ereset();

	waitForStart();

	ch = 1;

	brake();
	wait1Msec(300);

	motor[motorH] = 50;
	motor[motorI] = 50;
	wait1Msec(300);
	motor[motorH] = 0;
	motor[motorI] = 0;

	movebackward();
	wait1Msec(1500);

	servo[servo3] = 242;

	brake(); //temporary stop
	wait1Msec(300);

	motor[motorD] = -10;
	motor[motorE] = 50;
	motor[motorF] = -10;
	motor[motorG] = 50;
	wait1Msec(1650);

	brake(); //temporary stop
	wait1Msec(100);

	motor[motorD] = 50;
	motor[motorE] = -10;
	motor[motorF] = 50;
	motor[motorG] = -10;
	wait1Msec(1650);

	brake();
	wait1Msec(100);

	movebackward();// move forward to the center goal structure
	wait1Msec(1825);

	brake();
	wait1Msec(1000);

	if (SensorRaw(irs) > 3 && SensorRaw(irs) < 7)//checks for the ir value to know if the center goal structure is at postion 1
	{ //center goal structure is in the 1

		moveforward(); // move forward to be adjacent to the kickstand
		wait1Msec(1600);

		brake(); //temporary stop
		wait1Msec(50);

		turnright(); //turn right to face the kickstand
		wait1Msec(1000);

		brake(); //temporary stop
		wait1Msec(100);

		moveforward(); //moveforward to knock down the kickstand and to be adjacent to the ir beacon and center goal
		wait1Msec(2000);

		turnright();
		wait1Msec(900);

		moveforward();
		wait1Msec(900);

		motor[motorH] = 60;
		motor[motorI] = 60;
		wait1Msec(200);
		motor[motorH] = 0;
		motor[motorI] = 0;

		motor[motorD] = 50;
		motor[motorE] = -50;
		motor[motorF] = 50;
		motor[motorG] = -50;
		wait1Msec(1100);

		brake();
		wait1Msec(300);

		movebackward();
		wait1Msec(600);

		brake();
		wait1Msec(100);

		servo[servo4] = 207;
		servo[servo7] = 47;
		wait1Msec(800);

		motor[motorH] = 30;
		motor[motorI] = 30;
		wait1Msec(6835);
		motor[motorH] = 0;
		motor[motorI] = 0;

		brake();
		wait1Msec(100);

		motor[motorD] = 25;
		motor[motorE] = 25;
		motor[motorF] = 25;
		motor[motorG] = 25;
		wait1Msec(700);

		motor[motorH] = 30;
		motor[motorI] = 30;
		wait1Msec(200);
		motor[motorH] = 0;
		motor[motorI] = 0;

		brake();
		wait1Msec(1100);

		motor[motorD] = -25;//resets the initialize
		motor[motorE] = -25;
		motor[motorF] = -25;
		motor[motorG] = -25;
		wait1Msec(150);
		
		servo[servo6] = 256;
		wait1Msec(300);
		servo[servo6] = 127;

		brake();
		wait1Msec(300);

		brake();
		wait10Msec(3000);
	}

	else if(SensorRaw(irs) <= 3 || SensorRaw(irs) >= 7)//if the ir sensor senses a value between 3 and 7
	{ //center goal is in position 2/3
		movebackward();//move the robot back to be adjacent to the ir beacon
		wait1Msec(600);

		turnleft();//turns left to check for position 2.
		wait1Msec(650);

		movebackward();//moves abckwards to be next to the ir beacon
		wait1Msec(975);

		ch = 0;//gives the integer chicks the value of of 0
	}

	if (SensorRaw(irs) >= 7 && SensorRaw(irs) <= 8)//if ir value is between 7 and 8
	{ //center goal structure is in the 3 position

		while(SensorRaw(irs) < 5)//if it senses a value less than 5 until it senses at 5
		{
			movebackward();
		}
		moveforward();//moves the robot forward to be adjacent to the
		wait1Msec(375);

		turnright();//turn right to face the kickstand
		wait1Msec(350);

		moveforward();//knocks down the kickstand
		wait1Msec(750);

		turnleft();
		wait1Msec(550);
	}

	else
	{ //center goal structure is in the 2 position
		moveforward();//move forward to be adjacent to the kickstand
		wait1Msec(1650);

		turnright();//turn right to face the kickstand
		wait1Msec(525);

		moveforward();
		wait1Msec(1850);

		turnright();
		wait1Msec(900);

		moveforward();
		wait1Msec(700);

		motor[motorH] = 60;
		motor[motorI] = 60;
		wait1Msec(200);
		motor[motorH] = 0;
		motor[motorI] = 0;

		motor[motorD] = 50;
		motor[motorE] = -50;
		motor[motorF] = 50;
		motor[motorG] = -50;
		wait1Msec(1175);

		brake();
		wait1Msec(300);

		movebackward();
		wait1Msec(600);

		brake();
		wait1Msec(100);

		servo[servo4] = 207;
		servo[servo7] = 47;
		wait1Msec(800);

		motor[motorH] = 30;
		motor[motorI] = 30;
		wait1Msec(6835);
		motor[motorH] = 0;
		motor[motorI] = 0;

		motor[motorH] = 60;//resets the initialize
		motor[motorI] = 60;
		wait1Msec(572);
		motor[motorH] = 0;//stops the 80/20 so that it does not move
		motor[motorI] = 0;

		brake();
		wait1Msec(100);

		motor[motorD] = 25;
		motor[motorE] = 25;
		motor[motorF] = 25;
		motor[motorG] = 25;
		wait1Msec(650);

		brake();
		wait1Msec(199);

		brake();
		wait1Msec(300);

		servo[servo6] = 256;
		wait1Msec(300);
		servo[servo6] = 127;


		brake();
		wait10Msec(3000);
	}
}
//The Metal Magicians
