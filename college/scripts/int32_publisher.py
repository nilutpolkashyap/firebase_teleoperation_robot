#!/usr/bin/env python
import rospy
from std_msgs.msg import Int32
import random

def publisher():
	pub = rospy.Publisher('integer',Int32, queue_size  =100)
	rospy.init_node("int32_publisher", anonymous=True)
	rate = rospy.Rate(10)

	while not rospy.is_shutdown():
		var = random.randint(0,100)
		rospy.loginfo("Publisher sent : %d", var)
		pub.publish(var)
		rate.sleep()

if __name__ == '__main__':
	try:
		publisher()
	except rospy.ROSInterruptException():
		pass