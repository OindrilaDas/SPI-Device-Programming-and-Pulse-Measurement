# KDIR:=/opt/clanton-full/1.4.2/sysroots/i586-poky-linux/usr/src/kernel
# PWD:= $(shell pwd)
# PATH=${PATH}:/home/Gen2/IoT_downloads/iotdk-ide-linus//devkit-x86/sysroots/x86_64-pokysdk-linux/usr/bin/i586-poky-linux/

#/opt/iot-devkit/1.7.2/sysroots/x86_64-pokysdk-linux/usr/bin/i586-poky-linux

IOT_HOME = /opt/iot-devkit/1.7.2/sysroots/
CFLAGS = -Wall
PATH := $(PATH):$(IOT_HOME)/x86_64-pokysdk-linux/usr/bin/i586-poky-linux

CC = i586-poky-linux-gcc
ARCH = x86
CROSS_COMPILE = i586-poky-linux-
SROOT=$(IOT_HOME)/i586-poky-linux/

APP1 = User_App
#APP2 = example2

all:
	echo my new PATH is ${PATH}
	$(CC) $(CFLAGS) -o $(APP1) --sysroot=$(SROOT) User_App.c -pthread -lm
#	$(CC) -o $(APP2) example2.c

clean:
	rm -f *.o
	rm -f $(APP1) 
