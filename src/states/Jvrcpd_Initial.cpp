#include "Jvrcpd_Initial.h"

#include "../Jvrcpd.h"

void Jvrcpd_Initial::configure(const mc_rtc::Configuration & config)
{
}

void Jvrcpd_Initial::start(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<Jvrcpd &>(ctl_);
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
