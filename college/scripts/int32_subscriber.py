#!/usr/bin/env python
import rospy
from std_msgs.msg import Int32

def callback(data):
	rospy.loginfo("Subscriber heard : %d", data.data)

def subscriber():
	rospy.init_node("int32_subscriber", anonymous =True)
	rospy.Subscriber("integer", Int32, callback)
	rospy.spin()

if __name__ == '__main__':
	subscriber()