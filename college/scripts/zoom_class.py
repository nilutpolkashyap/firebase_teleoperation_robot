#!/usr/bin/env python
import rospy
from std_msgs.msg import String

rospy.init_node("zoom_class", anonymous=True)

pub = rospy.Publisher("/online_lesson", String, queue_size = 10)
rate = rospy.Rate(1)

def callback(data):
	rospy.loginfo("Zoom class ongoing : %s", data.data)

def subscriber():
	
	rospy.Subscriber("/lesson", String, callback)

	while not rospy.is_shutdown():
		#rospy.spin()
		pub.publish("Do your homework")
		rate.sleep()

if __name__ == '__main__':
	subscriber()
