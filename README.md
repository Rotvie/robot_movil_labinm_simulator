# robot_movil_labinm_simulator
A ROS/Gazebo LABINM Mobile Robot Model.

# Install
```
cd ~/catkin_ws/src
git clone https://github.com/Rotvie/robot_movil_labinm_simulator.git
git clone --recursive https://github.com/gepetto/ouster-gazebo-simulation.git
cd ..
catkin_make
```

# Run the simulation:
Source the environment and launch Gazebo in one terminal tab.
```
roslaunch gazebo_ros empty_world.launch
```

Spawn the robot in another terminal tab.
```
roslaunch rmls_gazebo gazebo.launch
```

# Note:
For teleoperating the robot run this:
```
rosrun teleop_twist_keyboard teleop_twist_keyboard.py 
```
