#pragma once

#include "PID.h"


#include <units/length.h>
#include <units/time.h>
#include <units/voltage.h>

#include <frc/Joystick.h>
#include <frc/XboxController.h>

#include "ppm/PPMMotor.h"
#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>


struct ElevatorConfig {
  //ctre::phoenix::motorcontrol::can::WPI_VictorSPX *motor;
  // int speed;
  // units::meter_t minHeight;
  // units::meter_t maxHeight;
  // wom::PIDConfig<units::meter, units::volts> pidConfig;
};


class ElevatorLift {
 public:
  ElevatorLift( frc::XboxController *joystick);

  void SetSetpoint(units::meter_t setpoint);
  void OnUpdate();
  double CalculateDisplacement(double velocity, double dt);

 private:
  ElevatorConfig *_config;
  frc::XboxController *_joystick;
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX *motor = new ctre::phoenix::motorcontrol::can::WPI_VictorSPX(7);


  units::meter_t _setpoint;
  
  units::meter_t _currentHeight;

  // wom::PIDController<units::meter, units::volts> _pid;

};