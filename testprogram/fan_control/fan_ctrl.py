## This scripts calls the raspberry pi to reads the current temperature
## and tries to speeds up or slows down the fan in order to achieve the
## desired temperature

## Note:  All temp values are in Celcius.


#this is for call()
from subprocess import check_output
import math


desired_Temp = 20; ##Set to 20 at the moment but values can come from another source.

tolerance = 2; 


# checks for current temperature
#calls c-program to check on current temperature and gets a reading from stdout
reading = check_output(["./temp_sensor2"])



# while current temperature is not within the allowed tolerance 
# speed up or slow down the fan
difference = float(reading) - desired_Temp;

while (math.fabs(difference) > tolerance):
	#speed up the fan if difference is > 0
	#that means temp reading is higher than desired
	if (difference > 0):
		print("Needs to speed fan up!")
		#speed up fan by running program
		######CODES TO BE IMPLEMENTED ########
	else:
		print("Needs to slown fan down!")
		#slow down fan/enable heater etc
		######CODES TO BE IMPLTEMENTED #######

#once achieved desired temp shutdown fan 
 
########CODES TO BE IMPLEMENTED##############
