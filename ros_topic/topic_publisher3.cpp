#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include <iostream>

int main(int argc, char **argv)
{
	ros::init(argc,argv, "topic_publsiher3");
	ros::NodeHandle nh;
	ros::Publisher publisher = nh.advertise<std_msgs::Float32>("/float_data",1000);
	ros::Rate loop_rate(10);

	float var = 0.0;

	while(ros::ok())
	{
		std_msgs::Float32 message;
		message.data = var;
		ROS_INFO("I am publishing [%f]",message.data);
		publisher.publish(message);
		ros::spinOnce();
		loop_rate.sleep();
		var = var + 0.5;
	}
	return 0;
}