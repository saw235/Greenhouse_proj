#By Saw Xue Zheng
#This python script calls a C program

from subprocess import call


#first argument is program name, followed by there rest of the arguments
call(["./blah","1","2","4"])

print("call completed")
