# Description

This is a simple mc_rtc controller for the **JVRC1** robot that prints the PD gains of the joints inside the `active_motors_` vector, using a datastore call. 

The controller works as intended with mc_mujoco, however, with mc_openrtm and choreonoid, the same call doesn't work (the PDcontroller is deactivated).

## Install and Usage

To Install:

```
$ cd jvrcpd
$ mkdir build && cd build
$ cmake ..
$ make install
```

To run, simply add the controller in the mc_rtc configuration file (`Enabled: Jvrcpd`), then run either:

1. `mc_mujoco`: The controller works properly.
2. `cd $PREFIX/share/JVRC1`, then `./clear-omninames.sh`, and then `choreonoid sim_mc.cnoid --start-simulation`: The controller will run but will be deactivated without printing the gains, hence the bug.
