// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "ShooterSystemRight.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PID
ShooterSystemRight::ShooterSystemRight() : PIDSubsystem("ShooterSystemRight", 1.0, 0.0, 0.0) {
    SetAbsoluteTolerance(0.2);
    GetPIDController()->SetContinuous(false);
    LiveWindow::GetInstance()->AddActuator("ShooterSystemRight", "PIDSubsystem Controller", GetPIDController());
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PID

    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    shooterTalonRight = RobotMap::shooterSystemRightShooterTalonRight;
    quadEncShooterRight = RobotMap::shooterSystemRightQuadEncShooterRight;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

    // Use these to get going:
    // SetSetpoint() -  Sets where the PID controller should move the system
    //                  to
    // Enable() - Enables the PID controller.
}

double ShooterSystemRight::ReturnPIDInput() {
    // Return your input value for the PID loop
    // e.g. a sensor, like a potentiometer:
    // yourPot->SetAverageVoltage() / kYourMaxVoltage;
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=SOURCE
        return quadEncShooterRight->PIDGet();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=SOURCE
}

void ShooterSystemRight::UsePIDOutput(double output) {
    // Use output to drive your system, like a motor
    // e.g. yourMotor->Set(output);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=OUTPUT
    shooterTalonRight->PIDWrite(output);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=OUTPUT
}

void ShooterSystemRight::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void ShooterSystemRight::RawShootRight(double y){
	shooterTalonRight->Set(y);
}
