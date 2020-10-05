#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>

int main(int argc, char **argv)
{
	ros::init(argc,argv, "topic_publisher2");
	ros::NodeHandle nh;
	ros::Publisher publisher = nh.advertise<std_msgs::Int32>("/int_data",1000);
	ros::Rate loop_rate(10);

	int count= 0;

	while(ros::ok())
	{
		std_msgs::Int32 message;
		message.data = count;
		ROS_INFO("I am publishing %d",message.data);
		publisher.publish(message);
		ros::spinOnce();
		loop_rate.sleep();
		++count;
	}
	return 0;
}