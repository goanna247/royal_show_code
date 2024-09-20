#include "Robot.h"
#include <iostream>
#include <frc/smartdashboard/smartdashboard.h>


void Robot::RobotInit() {
  _tankDrive = new TankDrivebase(&_map.tankConfig, &_map.controllers.primary);
  _elevator = new ElevatorLift(&_map.controllers.primary);
}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {
  _tankDrive->UpdateSpeeds();
  _elevator->OnUpdate();

  frc::SmartDashboard::PutNumber("Max elevator speed", maxElSpeed);

  double elSpeed = 0;
  if (_map.controllers.primary.GetRightTriggerAxis() > 0.05) {
    // motor->Set(0.4);
    elSpeed = _map.controllers.primary.GetRightTriggerAxis();
  } else if (_map.controllers.primary.GetLeftTriggerAxis() > 0.05) {
    // motor->Set(-0.4);
    elSpeed = _map.controllers.primary.GetLeftTriggerAxis();
  } else {
    elSpeed = 0;
    // motor->Set(0);
  }

  if (_map.controllers.primary.GetXButtonPressed()) {
    maxElSpeed -= 0.1;
  } else if (_map.controllers.primary.GetBButtonPressed()) {
    maxElSpeed += 0.1;
  }

  if (_map.controllers.primary.GetRightTriggerAxis() > 0.05) {
    elSpeed *= maxElSpeed;
  } else if (_map.controllers.primary.GetLeftTriggerAxis() > 0.05) {
    elSpeed *= maxElSpeed;
    elSpeed *= -1;
  }


  motor->Set(elSpeed);
}

void Robot::DisabledInit() {
  _tankDrive->Halt();
}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
