#include "MoveServos.h"


bool closed = false;
#define hi


MoveServos::MoveServos():Command()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);

}

// Called just before this Command runs the first time
void MoveServos::Initialize()
{
	joy = Robot::oi->getDriveJoy();
}

// Called repeatedly when this Command is scheduled to run
void MoveServos::Execute()
{
#ifdef hi
	if (joy->GetPOV()==270||joy->GetPOV()==90) { // goes middle
	Robot::intakeSubsystem->MoveServoLeft(90);
	Robot::intakeSubsystem->MoveServoRight(100);
	closed=false;
	Wait(1.0);
	//should open it
	}
	else if (joy->GetPOV()==180) // goes out
	{
		Robot::intakeSubsystem->MoveServoLeft(180);
		Robot::intakeSubsystem->MoveServoRight(0);
		closed=true;
		Wait(1.0);
		//should close it, first action
	}
	else if (joy->GetPOV()==0) //currently goes up
	{
		Robot::intakeSubsystem->MoveServoLeft(0);
		Robot::intakeSubsystem->MoveServoRight(180);
		//should go to middle
		Wait(1.0);
	}



#endif
	SmartDashboard::PutNumber("Thingy", joy->GetPOV());
//	Robot::intakeSubsystem->MoveServos(30);
	//225-315 left
	//315-45 top
	//right: 45  -135
	//bottom: 135-225
}

// Make this return true when this Command no longer needs to run execute()
bool MoveServos::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void MoveServos::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveServos::Interrupted()
{

}
