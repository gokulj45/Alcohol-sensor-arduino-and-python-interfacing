import time
import playsound
from threading import Thread
import serial

flag = 0
moto = '5'

alco = 0

def readalco():
	global alco
	while flag == 0:
		alco = int(ser.readline())
		if alco < 600:
			alco = 11
		else:
			alco = 12

ser = serial.Serial("/dev/ttyACM0",9600)

ser.flushInput()

ser.write(moto.encode())


def alarm():
	playsound.playsound("alarm.wav")

while True:
	if alco == 11:
		moto = '1'
		ser.write(moto.encode())
	if alco == 12:
		print("Alcohol detected")
		t = Thread(target=alarm)
		t.deamon = True
		t.start()
		ser.write('8'.encode())
		break
ser.flushInput()