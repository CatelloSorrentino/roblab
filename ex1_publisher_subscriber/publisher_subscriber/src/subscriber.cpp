#include "ros/ros.h"
#include "std_msgs/String.h"
#include "trajectory_msgs/JointTrajectory.h"
#include <string>


void chatterCallback( trajectory_msgs::JointTrajectory joint)
{
  for(int i = 0; i < 6; i++){
    
    ROS_INFO_STREAM(joint.joint_names[i]);
    ROS_INFO_STREAM("Posizione del giunto:\nX: " << joint.points[i].positions[0] << "\nY: " << joint.points[i].positions[1]
                      << "\nZ: " << joint.points[i].positions[2]);

  }
}     


  int main(int argc, char **argv){
      ros::init(argc, argv, "listener");
      ros::NodeHandle nodeHandle;
      ros::Subscriber subscriber =
      nodeHandle.subscribe("sensor_data",10,chatterCallback);
      ros::spin();
      return 0;
  }