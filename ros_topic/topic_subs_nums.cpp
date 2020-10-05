#include "std_msgs/Int32.h"
#include "ros/ros.h"
#include <iostream>

void number_callback(const std_msgs::Int32::ConstPtr& msg)
{
	ROS_INFO("Received [%d]", msg->data);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "topic_subs_nums");
	ros::NodeHandle nh;
	ros::Subscriber num_subscriber = nh.subscribe("/numbers",10, number_callback);
	ros::spin();

	return 0;
}