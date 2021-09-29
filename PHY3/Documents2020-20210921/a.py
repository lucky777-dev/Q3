import time
import serial

# configure the serial connections (the parameters differs on the device you are connecting to)
ser = serial.Serial(
    port='/dev/ttyS0',
    baudrate=9600
)

ser.isOpen()

try:

	while 1 :	

        	ser.write('A')        
        	# let's wait one second before reading output (let's give device time to answer)
        	time.sleep(1)

except KeyboardInterrupt:
	pass

ser.close()
