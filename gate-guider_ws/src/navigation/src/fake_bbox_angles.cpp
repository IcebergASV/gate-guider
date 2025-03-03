#include <ros/ros.h>
#include <navigation/PropInProgress.h>


void fake_bbox_angles() {
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<navigation::PropInProgress>("prop_angle_range", 1);
    ros::Rate rate(10);
    navigation::PropInProgress msg;
    msg.prop_type = "red_marker";
    msg.theta_1 = 1.6057;
    msg.theta_2 = 2.7925;

    while (ros::ok()) {
        ROS_INFO_STREAM(msg);
        pub.publish(msg);
        rate.sleep();
    }
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "fake_bbox_angles_node");
    try {
        fake_bbox_angles();
    }
    catch (ros::Exception& e) {
        ROS_ERROR_STREAM("An exception occurred in the fake_bbox_angles_node: " << e.what());
    }
    return 0;
}