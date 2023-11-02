#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/JointState.h"

void jointStateCallback(const sensor_msgs::JointState::ConstPtr& msg) {
    ROS_INFO("Dati sugli stati dei giunti ricevuti:");
    ROS_INFO("Timestamp: %f", msg->header.stamp.toSec());
    ROS_INFO("Frame di riferimento: %s", msg->header.frame_id.c_str());
    ROS_INFO("Nomi dei giunti:");
    for (size_t i = 0; i < msg->name.size(); i++) {
        ROS_INFO("%s", msg->name[i].c_str());
    }
    ROS_INFO("Posizioni dei giunti:");
    for (size_t i = 0; i < msg->position.size(); i++) {
        ROS_INFO("%f", msg->position[i]);
    }
    ROS_INFO("Velocità dei giunti:");
    for (size_t i = 0; i < msg->velocity.size(); i++) {
        ROS_INFO("%f", msg->velocity[i]);
    }
    ROS_INFO("Sforzi dei giunti:");
    for (size_t i = 0; i < msg->effort.size(); i++) {
        ROS_INFO("%f", msg->effort[i]);
    }
}

int main(int argc, char **argv){
    
  ros::init(argc, argv, "arm_controller_node");
  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("arm/joint_states", 1000, jointStateCallback);
  ros::spin();

  return 0;
}

