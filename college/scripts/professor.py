#!/usr/bin/env python
import rospy 
from std_msgs.msg import String

def publisher():
	pub = rospy.Publisher("/lesson", String, queue_size = 10)
	rospy.init_node("professor", anonymous=False)
	rate = rospy.Rate(1)

	while not rospy.is_shutdown():
		str = "Lesson 1" 
		rospy.loginfo(str)
		pub.publish(str)
		rate.sleep()

if __name__ == '__main__':
	try:
		publisher()
	except rospy.ROSInterruptException:
		pass