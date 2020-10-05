#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>

void stringcallback(const std_msgs::String::ConstPtr& message)
{
	ROS_INFO("Publisher received [%s]",message->data.c_str());
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "topic_subscriber");
	ros::NodeHandle nh;
	ros::Subscriber subscriber = nh.subscribe("/string_data",1000,stringcallback);
	ros::spin();
	return 0;
}