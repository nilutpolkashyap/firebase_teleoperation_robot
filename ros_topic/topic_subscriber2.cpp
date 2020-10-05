#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>

void intcallback(const std_msgs::Int32::ConstPtr& message)
{
	ROS_INFO("I received [%d]",message->data);
}

int main(int argc, char ** argv)
{
	ros::init(argc,argv, "topic_subscriber2");
	ros::NodeHandle nh;
	ros::Subscriber subscriber = nh.subscribe("/int_data",1000, intcallback);
	ros::spin();
	return 0;
}