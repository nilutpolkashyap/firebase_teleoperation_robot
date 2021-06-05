#!/usr/bin/env python
import rospy
from std_msgs.msg import String

def callback(data):
	#rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)
	rospy.loginfo("Student 2 learnt : %s", data.data)

def subscriber():
	rospy.init_node("student2", anonymous=True)
	rospy.Subscriber("/online_lesson", String, callback)

	rospy.spin()

if __name__ == '__main__':
	subscriber()