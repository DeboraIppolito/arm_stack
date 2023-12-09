# arm_stack
Repository contenente il codice relativo all'homework 1 del corso di Robotics Lab

Punto 1:
Per spawnare il robot in rviz --> roslaunch arm_description display.launch

Punto 2-3:
Per aprire gazebo --> roslaunch arm_gazebo arm_gazebo.launch;

Per vedere l'immagine della camera --> rqt_image_view

Punto 4: 
Aprire gazebo;

Lanciare i nodi --> rosrun arm_controller arm_controller_node

Per vedere cosa sto pubblicando --> rostopic echo /arm/PositionJointInterface_J0_controller/command
