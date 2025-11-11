#pragma once

#include <mc_control/fsm/State.h>
#include <string>
#include <vector>

struct Jvrcpd_Initial : mc_control::fsm::State
{
  void configure(const mc_rtc::Configuration & config) override;

  void start(mc_control::fsm::Controller & ctl) override;

  bool run(mc_control::fsm::Controller & ctl) override;

  void teardown(mc_control::fsm::Controller & ctl) override;

  bool get_servo_success;

  std::vector<std::string> active_motors_;
};
