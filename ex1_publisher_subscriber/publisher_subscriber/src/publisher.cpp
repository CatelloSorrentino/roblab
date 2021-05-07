#include <ros/ros.h>
#include <std_msgs/String.h>
#include <trajectory_msgs/JointTrajectory.h>

int main(int argc, char **argv) {

    ros::init(argc, argv, "publisher");
    ros::NodeHandle nh;
    ros::Publisher chatterPublisher = nh.advertise<trajectory_msgs::JointTrajectory>("sensor_data", 1);
    

    trajectory_msgs::JointTrajectory joint;
    trajectory_msgs::JointTrajectoryPoint point1, point2, point3, point4, point5, point6;

    joint.joint_names.push_back("Giunto 1");
    joint.joint_names.push_back("Giunto 2");
    joint.joint_names.push_back("Giunto 3");
    joint.joint_names.push_back("Giunto 4");
    joint.joint_names.push_back("Giunto 5");
    joint.joint_names.push_back("Giunto 6");

    joint.points.push_back(point1);
    joint.points.push_back(point2);
    joint.points.push_back(point3);
    joint.points.push_back(point4);
    joint.points.push_back(point5);
    joint.points.push_back(point6);

     for(int i = 0; i<6; i++){
        joint.points[i].positions.push_back(rand() % 100);
        joint.points[i].positions.push_back(rand() % 100);
        joint.points[i].positions.push_back(rand() % 100);
     }

    ros::Rate loopRate(10);
    unsigned int count = 0;
    while (ros::ok()) {
    ROS_INFO_STREAM(joint);
    chatterPublisher.publish(joint);
    ros::spinOnce();

}
return 0;
}