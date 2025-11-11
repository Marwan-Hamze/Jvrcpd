#include "Jvrcpd_Initial.h"
#include <iostream>
#include "../Jvrcpd.h"

void Jvrcpd_Initial::configure(const mc_rtc::Configuration & config)
{
}

void Jvrcpd_Initial::start(mc_control::fsm::Controller & ctl)
{
  active_motors_ =  {"L_HIP_P", "L_HIP_R", "L_HIP_Y", "L_KNEE", "L_ANKLE_R", "L_ANKLE_P",
                      "R_HIP_P", "R_HIP_R", "R_HIP_Y", "R_KNEE", "R_ANKLE_R", "R_ANKLE_P"};
  // active_motors_ = { "L_CROTCH_Y", "L_CROTCH_R", "L_CROTCH_P", "L_KNEE_P", "L_ANKLE_R", "L_ANKLE_P",
  //                    "R_CROTCH_Y", "R_CROTCH_R", "R_CROTCH_P", "R_KNEE_P", "R_ANKLE_R", "R_ANKLE_P"};
  std::cout << "SIZE: " << active_motors_.size() << std::endl;
  for (int i = 0; i < active_motors_.size(); i++) {

    double kp_temp, kd_temp;
  
  // read default pd gains
    std::cout << "CURRENT ACTIVE MOTOR READING: " << active_motors_[i] << std::endl;
    get_servo_success = ctl.datastore().call<bool, const std::string &, double &, double &>(
      ctl.robot().name() + "::GetPDGainsByName", active_motors_[i], kp_temp, kd_temp);

    std::cout << "P GAIN: " << kp_temp << std::endl; 
    std::cout << "D GAIN: " << kd_temp << std::endl; 

  }
}

bool Jvrcpd_Initial::run(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<Jvrcpd &>(ctl_);
  output("OK");
  return true;
}

void Jvrcpd_Initial::teardown(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<Jvrcpd &>(ctl_);
}

EXPORT_SINGLE_STATE("Jvrcpd_Initial", Jvrcpd_Initial)
