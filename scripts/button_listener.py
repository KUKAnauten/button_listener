#!/usr/bin/env python
import roslib; roslib.load_manifest('robotiq_s_model_control')
import rospy
from robotiq_s_model_control.msg import _SModel_robot_input  as inputMsg
from robotiq_s_model_control.msg import _SModel_robot_output  as outputMsg

myvar = None

def Callback(data):
    global myvar
    myvar = data

rospy.init_node('rq3_proxy')

while not rospy.is_shutdown():
    rospy.Subscriber("SModelRobotInput", inputMsg.SModel_robot_input, Callback)
    rospy.sleep(1)

   print "myvar is: " + myvar

   if myvar == 1:
         #do something"
    elif myvar == 0:
         #do something else
    else :
         #error


