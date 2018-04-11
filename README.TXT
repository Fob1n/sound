# ---------------------------SOUND SENSOR PROJECT--------------------------------

This project is meant to collect sound level at a proximity of a Raspberry Pi device.
The RPi is equipped with a USB sound card (C-Media Electronics, Inc. Audio Adapter)
and a microphone. The sound is recorded at 16000Hz sample rate and every second will
produce 80 pieces of RMS value as a bar-diagram.

Table of Content
1. Configuration
2. Installation
3. Operation
4. Manifest (list of files and short description of their roles)
5. License
6. Contact Information

#----------------------------CONFIGURATION--------------------------------------

SOUND CARD:

1. Attach a USB sound card to your Raspberry Pi
2. Change the default audio device to be USB sound card
	a. Run command "lsusb" to see if the USB is mounted
	   (C-Media Electronics, Inc. Audio Adapter should appear)
	b. Run command "sudo nano /etc/asound.conf" and type following code:
		"pcm.!default {
			type plug
			slave {
				 pcm "hw:1,0"
			}
		}
			ctl.!default {
				type hw
				card 1
			} "
	c. Use command "nano .asoundrc" in home diractory and type the
	   same code as in previous step
3. Run command "alsamixer" to see if USB sound card is the default audio device
-------------------------------------------------------------------------------

ARECORD BUG:

The newest version of Raspbian (a.k.a. Jessie) comes with a new version of alsa-utils
(1.0.28), which has a bug while recording: it doesn’t stop even a ‘—duration' switch
is given, and generates lots of useless audio files. To fix this problem, we have to
downgrade alsa-util to an earlier version (1.0.25).

If your version is not (1.0.25), follow the following steps:

1. Run command "sudo nano /etc/apt/sources.list" and add the line:
	"deb http://mirrordirector.raspbian.org/raspbian/ wheezy main contrib non-free rpi"
2. Run command "sudo apt-get update"
3. Run command "sudo aptitude versions alsa-utils" and check if (1.0.25) is available
4. Run command "sudo apt-get install alsa-utils=1.0.25-4" to downgrade the version
5. (If necessary) Reboot your device
6. Run command "arecord -r44100 -c1 -f S16_LE -d5 test.wav" to test your microphone,
   you should see a "test.wav" file in your current folder
7. Run command "aplay test.wav" to check that your recording works properly
--------------------------------------------------------------------------------

INSTALL LIBCURL:

1. Run command "ls/usr/include/curl" to find out if the folder already exists
2. Run command "ls/usr/include/arm-linux-gnueabihf/curl"

(If neither of the folders exists, proceed with the following steps)
3. Run command "sudo apt-get update"
4. Run command "sudo apt-get install libcurl3" to install libcurl3
5. Run command "sudo apt-get install libcurl4-openssl-dev" to install the development API of libcurl4


#--------------------------------INSTALLATION-----------------------------------

To get the program needed for this, you need to clone it from github.
Run command "git init" in the folder you want the project to be, to initialize your current folder.
Run command "git clone https://github.com/Fob1n/sound.git".
Then check that the files does appear with command "ls", you should see a folder
named "sound".

To compile the program, type the command "make". The program will print the result in the "sound_log" file.

To clean the directory, run command "make clean", and all object files is erased


#--------------------------------OPERATION--------------------------------------

To run the program, run the command "./sound.a" and you will see bars on the terminal screen and an
information bar at the top of the screen, and it changes every second.


#--------------------------------MANIFEST---------------------------------------


- comm.c: This file sends information to a file named "sound_log.txt" via the file sound.php, when the program is executed.

- comm.h: Contains function definition for comm.c and other definitions.

- main.c: This file records the audio, and calculates fast dBs plus.

- makefile: This file contains the information about what should happen when you use the make/make clean commands.

- screen.c: This file prepares the terminal screen for displaying the bars, and displays the bars-

- screen.h: Contains function and constant definitions for "screen.h".

- sound.c: This file contains function displayBar(), which opens file "test.wav" and reads the information that should 
		   create the bars. The file also prints the information bar that shows up while running the program.
	 
- sound.h: Contains function and constant definition for "sound.c", plus the wav header.


#--------------------------------LICENSE----------------------------------------


Copyright Robin Snellman: All rights reserved.
This project is guided by Dr. Chao Gao.


#--------------------------------CONTACT INFORMATION----------------------------


Robin Snellman:
				Email: e1700709@edu.vamk.fi
				Phone: +358 4476234
