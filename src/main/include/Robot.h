// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/Joystick.h>

#include <units/length.h>
#include <units/time.h>

#include "Util.h"

#include "RobotMap.h"
#include "TankDrive.h"
#include "ElevatorLift.h"



class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;

  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;

  void DisabledInit() override;
  void DisabledPeriodic() override;

  void TestInit() override;
  void TestPeriodic() override;

 private:
  RobotMap _map;

  TankDrivebase *_tankDrive;
  ElevatorLift *_elevator;
  ElevatorLift *_elevatorLift;

  ctre::phoenix::motorcontrol::can::WPI_TalonSRX *motor = new ctre::phoenix::motorcontrol::can::WPI_TalonSRX(7);

  double maxElSpeed = 0.5;
};
