from PyQt5 import QtWidgets, uic, QtGui
from PyQt5.QtWidgets import QMainWindow, QApplication, QLCDNumber, QProgressBar, QLabel, QComboBox, QPushButton, QSlider
from PyQt5.QtCore import QTime, QTimer
import sys
import pyrebase
import time
from PyQt5.QtWidgets import (QApplication, QWidget)
from PyQt5.Qt import Qt

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


class Ui(QtWidgets.QMainWindow):
    def __init__(self):
        super(Ui, self).__init__()
        uic.loadUi('remote_gui.ui', self)

        self.setWindowIcon(QtGui.QIcon('images/icon.png'))
        # set the title
        self.setWindowTitle("Icon")

        self.arm = self.findChild(QSlider, "arm_slider")
        self.arm.valueChanged.connect(self.change_arm_angle)

        self.gripper1 = self.findChild(QSlider, "gripper1_slider")
        self.gripper1.valueChanged.connect(self.change_gripper1_angle)

        # self.gripper2 = self.findChild(QSlider, "gripper2_slider")
        # self.gripper2.valueChanged.connect(self.change_gripper2_angle)

        self.front_button = self.findChild(QPushButton, "front_button")
        self.front_button.clicked.connect(self.front_button_clicked)

        self.back_button = self.findChild(QPushButton, "back_button")
        self.back_button.clicked.connect(self.back_button_clicked)

        self.stop_button = self.findChild(QPushButton, "stop_button")
        self.stop_button.clicked.connect(self.stop_button_clicked)

        self.left_button = self.findChild(QPushButton, "left_button")
        self.left_button.clicked.connect(self.left_button_clicked)

        self.right_button = self.findChild(QPushButton, "right_button")
        self.right_button.clicked.connect(self.right_button_clicked)

        # self.lturn_button = self.findChild(QPushButton, "left_turn_button")
        # self.lturn_button.clicked.connect(self.lturn_button_clicked)

        # self.rturn_button = self.findChild(QPushButton, "right_turn_button")
        # self.rturn_button.clicked.connect(self.rturn_button_clicked)


        self.show()

    def clickme(self):
        global light_status
        light_status = not light_status
        if(light_status == True):
            db.child("test").update({"light": 1})
            print("LIGHT ON")
        else:
            db.child("test").update({"light": 0})
            print("LIGHT OFF")

    def front_button_clicked(self):
        db.child("test").update({"command": "1"})
        print("GO FRONT")

    def back_button_clicked(self):
        db.child("test").update({"command": "2"})
        print("GO BACK")

    def stop_button_clicked(self):
        db.child("test").update({"command": "0"})
        print("STOP")

    def left_button_clicked(self):
        db.child("test").update({"command": "3"})
        print("LEFT ROTATE")

    def right_button_clicked(self):
        db.child("test").update({"command": "4"})
        print("RIGHT ROTATE")

    # def lturn_button_clicked(self):
    #     db.child("test").update({"command": "5"})
    #     print("LEFT TURN")

    # def rturn_button_clicked(self):
    #     db.child("test").update({"command": "6"})
    #     print("RIGHT TURN")

    def change_arm_angle(self, value):
        db.child("test").update({"arm": value})
        print(value)

    def change_gripper1_angle(self, value):
        db.child("test").update({"gripper": value})
        print(value)

    # def change_gripper2_angle(self, value):
    #     db.child("test").update({"gripper2": value})
    #     print(value)


app = QtWidgets.QApplication(sys.argv)
window = Ui()
app.exec_()
