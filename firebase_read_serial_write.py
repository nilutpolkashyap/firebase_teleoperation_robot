import pyrebase
import time
import serial

ser = serial.Serial('/dev/ttyACM0', 9600)

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
        if arm_control == 0:
            ser.write(b'A0')
            print("Arm value : A0", arm_control)
        if arm_control == 1:
            ser.write(b'A1')
            print("Arm value : A1", arm_control)
        if arm_control == 2:
            ser.write(b'A2')
            print("Arm value : A2", arm_control)
        if arm_control == 3:
            ser.write(b'A3')
            print("Arm value : A3", arm_control)

    gripper_control = db.child("teleoprobot").child("gripper").get().val()
    if gripper_val != gripper_control:
        gripper_val = gripper_control
        #print("Gripper Value : ",  gripper_control)
        if gripper_control == 0:
            ser.write(b'G0')
            print("Gripper value : G0", gripper_control)
        if gripper_control == 1:
            ser.write(b'G1')
            print("Gripper value : G1", gripper_control)
        if gripper_control == 2:
            ser.write(b'G2')
            print("Gripper value : G2", gripper_control)
        if gripper_control == 3:
            ser.write(b'G3')
            print("Gripper value : G3", gripper_control)
        if gripper_control == 4:
            ser.write(b'G4')
            print("Gripper value : G4", gripper_control)
        if gripper_control == 5:
            ser.write(b'G5')
            print("Gripper value : G5", gripper_control)

    direction = db.child("teleoprobot").child("direction").get().val()
    if direction_val != direction:
        direction_val = direction
        #print("Direction : ", direction_val)
        if direction == "ST":
            print("Direction : M0 Stop")
            ser.write(b'M0')
            #temp1 = direction
        elif direction == "FR":
            print("Direction : M1 Front")
            ser.write(b'M1')
            #temp1 = direction
        elif direction == "BK":
            print("Direction : M2 Back")
            ser.write(b'M2')
            #temp1 = direction
        elif direction == "LT":
            print("Direction : M3 Left")
            ser.write(b'M3')
            #temp1 = direction
        elif direction == "RT":
            print("Direction : M4 Right")
            ser.write(b'M4')
            #temp1 = direction
