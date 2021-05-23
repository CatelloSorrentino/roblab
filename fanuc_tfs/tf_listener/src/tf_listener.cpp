#include <ros/ros.h>
#include <tf2_ros/transform_listener.h>
#include <geometry_msgs/TransformStamped.h>


int main(int argc, char** argv) {
    ros::init(argc, argv, "tf2_listener");
    ros::NodeHandle nodeHandle;
    tf2_ros::Buffer tfBuffer;
    tf2_ros::TransformListener tfListener(tfBuffer);
    ros::Rate rate(10.0);

    while (nodeHandle.ok()) {
        geometry_msgs::TransformStamped transformStamped;
    try {
        transformStamped = tfBuffer.lookupTransform("base_link",
        "flange", ros::Time(0));
        ROS_INFO_STREAM("Base_link --> Flange "<< transformStamped.transform.translation);
        geometry_msgs::Quaternion a = transformStamped.transform.rotation;
        tf::Quaternion q;
        q.setW(a.w);
        q.setX(a.x);
        q.setY(a.y);
        q.setZ(a.z);

        tfScalar yaw, pitch, roll;
        tf::Matrix3x3 mat(q);
        mat.getEulerYPR(yaw, pitch, roll);
        

        transformStamped = tfBuffer.lookupTransform("link1",
        "flange", ros::Time(0));
        ROS_INFO_STREAM("Link1 --> Flange "<<   transformStamped.transform.translation);

        transformStamped = tfBuffer.lookupTransform("link2",
        "flange", ros::Time(0));
        ROS_INFO_STREAM("Link2 --> Flange "<<  transformStamped.transform.translation);

        transformStamped = tfBuffer.lookupTransform("link3",
        "flange", ros::Time(0));
        ROS_INFO_STREAM("Link3 --> Flange "<< transformStamped.transform.translation);

        transformStamped = tfBuffer.lookupTransform("link4",
        "flange", ros::Time(0));
        ROS_INFO_STREAM("Link4 --> Flange "<<  transformStamped.transform.translation);

        transformStamped = tfBuffer.lookupTransform("link5",
        "flange", ros::Time(0));
        ROS_INFO_STREAM("Link5 --> Flange "<<   transformStamped.transform.translation);

        transformStamped = tfBuffer.lookupTransform("link6",
        "flange", ros::Time(0));
        ROS_INFO_STREAM("Link6 --> Flange "<<   transformStamped.transform.translation);


    } catch (tf2::TransformException &exception) {
        ROS_WARN("%s", exception.what());
        ros::Duration(1.0).sleep();
        continue;
    }
    rate.sleep();
    }
    return 0;
};