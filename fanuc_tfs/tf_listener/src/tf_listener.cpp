#include <ros/ros.h>
#include <tf2_ros/transform_listener.h>
#include <geometry_msgs/TransformStamped.h>
#include <tf/tf.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "tf2_listener");
    ros::NodeHandle nodeHandle;
    tf2_ros::Buffer tfBuffer;
    tf2_ros::TransformListener tfListener(tfBuffer);
    ros::Rate rate(10.0);

    while (nodeHandle.ok()) {
        std::vector<geometry_msgs::TransformStamped> transformStamped(7);
    try {

        transformStamped[0] = tfBuffer.lookupTransform("base_link", "flange", ros::Time(0));
        transformStamped[1] = tfBuffer.lookupTransform("link1", "flange", ros::Time(0));
        transformStamped[2] = tfBuffer.lookupTransform("link2", "flange", ros::Time(0));
        transformStamped[3] = tfBuffer.lookupTransform("link3", "flange", ros::Time(0));
        transformStamped[4] = tfBuffer.lookupTransform("link4", "flange", ros::Time(0));
        transformStamped[5] = tfBuffer.lookupTransform("link5", "flange", ros::Time(0));
        transformStamped[6] = tfBuffer.lookupTransform("link6", "flange", ros::Time(0));

    } catch (tf2::TransformException &exception) {
        ROS_WARN("%s", exception.what());
        ros::Duration(1.0).sleep();
        continue;
    }

    for(int i=0; i<7; i++){
        ROS_INFO_STREAM(transformStamped[i].header.frame_id << "to " << transformStamped[i].child_frame_id);

        ROS_INFO_STREAM("\n-------Traslation:-------\n" << transformStamped[i].transform.translation);

        tf2::Quaternion quaternion;
        tf2::fromMsg(transformStamped[i].transform.rotation, quaternion);
        tf2::Vector3 rotation_axis = quaternion.getAxis();

        ROS_INFO_STREAM("\n-------Axis/Angle:-------");
        ROS_INFO_STREAM("Axis: " << rotation_axis.getX() <<", " << rotation_axis.getY() << ", " <<rotation_axis.getZ());
        ROS_INFO_STREAM("Angle: " << quaternion.getAngle());

        tf2::Matrix3x3 matrix(quaternion);

        ROS_INFO_STREAM("\n-------Rotation Matrix:-------");

        ROS_INFO_STREAM(matrix[0][0] << matrix[0][1] << matrix[0][2]);
        ROS_INFO_STREAM(matrix[1][0] << matrix[1][1] << matrix[1][2]);
        ROS_INFO_STREAM(matrix[2][0] << matrix[2][1] << matrix[2][2]);

        tf2Scalar roll, pitch, yaw;
        matrix.getRPY(roll, pitch, yaw);

        ROS_INFO_STREAM("\n-------Euler Angles:-------");
        ROS_INFO_STREAM("Roll: " << roll << "\nPitch: " << pitch << "\nYaw: " << yaw);

    }
    rate.sleep();
    }
    return 0;
};