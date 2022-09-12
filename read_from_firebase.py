import pyrebase
import time

firebaseConfig= {
    "apiKey": "AIzaSyCmA22CoB3AsZrzDMRl4cWU62xvzDDfYnI",
    "authDomain": "teleop-robot-e5493.firebaseapp.com",
    "databaseURL": "https://teleop-robot-e5493-default-rtdb.asia-southeast1.firebasedatabase.app",
    "projectId": "teleop-robot-e5493",
    "storageBucket": "teleop-robot-e5493.appspot.com",
    "messagingSenderId": "292207401343",
    "appId": "1:292207401343:web:6146be259152cd5834e24a"
}

firebase = pyrebase.initialize_app(firebaseConfig)

db = firebase.database()

arm_val = 0
gripper_val = 0
direction_val = "ST"

while True:
    arm_control = db.child("teleoprobot").child("arm").get().val()
    if arm_val != arm_control:
        arm_val = arm_control
        print("Arm value : ", arm_control)

    gripper_control = db.child("teleoprobot").child("gripper").get().val()
    if gripper_val != gripper_control:
        gripper_val = gripper_control
        print("Gripper Value : ",  gripper_control)

    direction = db.child("teleoprobot").child("direction").get().val()
    if direction_val != direction:
        direction_val = direction
        print("Direction : ", direction_val)
