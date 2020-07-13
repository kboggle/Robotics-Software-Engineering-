# Udacity-Robotics-software-engg

### The following repo has various folders for different projects. 

### 1. Build my World

**Summary of Tasks**
       
 1. Build a single floor wall structure using the Building Editor tool in Gazebo. Apply at least one feature, one color, and optionally one texture to your structure. Make sure there's enough space between the walls for a robot to navigate.
 2. Model any object of your choice using the Model Editor tool in Gazebo. Your model links should be connected with joints.
 3. Import your structure and two instances of your model inside an empty Gazebo World.
 4. Import at least one model from the Gazebo online library and implement it in your existing Gazebo world.
 5. Write a C++ World Plugin to interact with your world. Your code should display “Welcome to ’s World!” message as soon as you launch the Gazebo world file.
        
        
### 2. Go Chase It!      
      
**Summary of Tasks**

The goal is to create two packages `ball_chaser` and `drive_bot`
        
 1.  `drive_bot`
  - Create a my_robot ROS package to hold your robot, the white ball, and the world.
  - Design a differential drive robot with the Unified Robot Description Format. Add two sensors to your robot: **a lidar and a camera**. Add Gazebo plugins for your robot’s differential drive, lidar, and camera. The robot you design should be significantly different from the one presented in the project lesson. Implement significant changes such as adjusting the color, wheel radius, and chassis dimensions. Or completely redesign the robot model! After all you want to impress your future employers :-D
  - House your robot inside the world you built in the Build My World project.
  - Add a white-colored ball to your Gazebo world and save a new copy of this world.
  - The `world.launch` file should launch your world with the white-colored ball and your robot.
 
 2. `ball_chaser`
 
  - Create a ball_chaser ROS package to hold your C++ nodes.
  - Write a drive_bot C++ node that will provide a ball_chaser/command_robot service to drive the robot by controlling its linear x and angular z velocities. The service should publish to the wheel joints and return back the requested velocities.
  - Write a process_image C++ node that reads your robot’s camera image, analyzes it to determine the presence and position of a white ball. If a white ball exists in the image, your node should request a service via a client to drive the robot towards it.
  - The ball_chaser.launch should run both the drive_bot and the process_image nodes.
  
 ### 3. Where am I?
 
 **Summary of Tasks**
 
  - Build and implemented the AMCL localization package on your robot!
  
 ### 4. Map my World
 
 **Summary of Tasks**
 
  - Develop a package to interface with the rtabmap_ros package.
  - Build upon the localization project to make the necessary changes to interface the robot with RTAB-Map.
  - The `teleop` command moves around the room to generate a proper map of the environment.
