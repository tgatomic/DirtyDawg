EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:ir_recieve
LIBS:I2C_LCD
LIBS:LinkuraModule
LIBS:i2cdisplay
LIBS:ca3240e
LIBS:SN754410NE
LIBS:motor
LIBS:Project-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 7 7
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L SN754410NE U?
U 1 1 571C28D3
P 4850 2900
F 0 "U?" H 5000 3500 50  0000 C CNN
F 1 "SN754410NE" H 4850 2300 50  0000 C CNN
F 2 "" H 4850 2900 50  0000 C CNN
F 3 "" H 4850 2900 50  0000 C CNN
	1    4850 2900
	1    0    0    -1  
$EndComp
$Comp
L Motor M?
U 1 1 571C29B6
P 2650 2950
F 0 "M?" H 2650 2850 60  0000 C CNN
F 1 "Motor" H 2650 3050 60  0000 C CNN
F 2 "" H 2650 2950 60  0000 C CNN
F 3 "" H 2650 2950 60  0000 C CNN
	1    2650 2950
	0    -1   -1   0   
$EndComp
Text HLabel 4150 2550 0    60   Input ~ 0
Forw.
Text HLabel 4150 3250 0    60   Input ~ 0
Backw.
Text HLabel 5650 2400 2    60   Input ~ 0
5V
Text HLabel 4150 3400 0    60   Input ~ 0
9V
Wire Wire Line
	2650 2400 3300 2400
Wire Wire Line
	3300 2400 3300 2700
Wire Wire Line
	3300 2700 4150 2700
Wire Wire Line
	2650 3500 3300 3500
Wire Wire Line
	3300 3500 3300 3100
Wire Wire Line
	3300 3100 4150 3100
Wire Wire Line
	5650 2400 5550 2400
Wire Wire Line
	4150 2100 4150 2400
Connection ~ 5600 2400
Wire Wire Line
	5600 2400 5600 2100
Wire Wire Line
	5600 2100 4150 2100
$Comp
L GND #PWR?
U 1 1 571C303C
P 4050 2900
F 0 "#PWR?" H 4050 2650 50  0001 C CNN
F 1 "GND" H 4050 2750 50  0000 C CNN
F 2 "" H 4050 2900 50  0000 C CNN
F 3 "" H 4050 2900 50  0000 C CNN
	1    4050 2900
	0    1    1    0   
$EndComp
$Comp
L GND #PWR?
U 1 1 571C3054
P 5650 2900
F 0 "#PWR?" H 5650 2650 50  0001 C CNN
F 1 "GND" H 5650 2750 50  0000 C CNN
F 2 "" H 5650 2900 50  0000 C CNN
F 3 "" H 5650 2900 50  0000 C CNN
	1    5650 2900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5650 2850 5650 2950
Wire Wire Line
	5650 2850 5550 2850
Wire Wire Line
	5650 2950 5550 2950
Connection ~ 5650 2900
Wire Wire Line
	4150 2850 4050 2850
Wire Wire Line
	4050 2850 4050 2950
Wire Wire Line
	4050 2950 4150 2950
Connection ~ 4050 2900
Text HLabel 5550 2550 2    60   Input ~ 0
Right
Text HLabel 5550 3250 2    60   Input ~ 0
Left
Text HLabel 5550 3400 2    60   Input ~ 0
5V
$Comp
L Motor M?
U 1 1 571C3169
P 7050 2950
F 0 "M?" H 7050 2850 60  0000 C CNN
F 1 "Motor" H 7050 3050 60  0000 C CNN
F 2 "" H 7050 2950 60  0000 C CNN
F 3 "" H 7050 2950 60  0000 C CNN
	1    7050 2950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6400 2400 7050 2400
Wire Wire Line
	6400 2400 6400 2700
Wire Wire Line
	7050 3500 6400 3500
Wire Wire Line
	6400 3500 6400 3100
$Comp
L R R?
U 1 1 571CA76A
P 6000 3100
F 0 "R?" V 6080 3100 50  0000 C CNN
F 1 "47" V 6000 3100 50  0000 C CNN
F 2 "" V 5930 3100 50  0000 C CNN
F 3 "" H 6000 3100 50  0000 C CNN
	1    6000 3100
	0    1    1    0   
$EndComp
Wire Wire Line
	5850 3100 5550 3100
Wire Wire Line
	6400 3100 6150 3100
$Comp
L R R?
U 1 1 571CA7D8
P 6000 2700
F 0 "R?" V 6080 2700 50  0000 C CNN
F 1 "47" V 6000 2700 50  0000 C CNN
F 2 "" V 5930 2700 50  0000 C CNN
F 3 "" H 6000 2700 50  0000 C CNN
	1    6000 2700
	0    1    1    0   
$EndComp
Wire Wire Line
	5850 2700 5550 2700
Wire Wire Line
	6400 2700 6150 2700
$EndSCHEMATC
