#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include <iostream>

void floatcallback(const std_msgs::Float32::ConstPtr& message)
{
	ROS_INFO("I received [%f]",message->data);
}

int main(int argc, char **argv)
{
	ros::init(argc,argv,"topic_subscriber3");
	ros::NodeHandle nh;
	ros::Subscriber subscriber = nh.subscribe("/float_data",1000,floatcallback);
	ros::spin();
	return 0;
}