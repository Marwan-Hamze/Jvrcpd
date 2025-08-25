# Description

This is a simple mc_rtc controller for the **JVRC1** robot that prints the PD gains of the joints inside the `active_motors_` vector, using a datastore call. 

The controller works as intended with mc_mujoco, however, with mc_open_rtm and choreonoid, the same call doesn't work (the PDcontroller is deactivated).