#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "topic_publisher");
	ros::NodeHandle nh;
	ros::Publisher publisher = nh.advertise<std_msgs::String>("/string_data",1000);
	ros::Rate loop_rate(10);
	while(ros::ok())
	{
		std_msgs::String message;
		std::stringstream ss;
		ss << "I am the publisher node";
		message.data = ss.str();
		ROS_INFO("%s", message.data.c_str());
		publisher.publish(message);
		ros::spinOnce();
		loop_rate.sleep();
	}
	return 0;
	
}
