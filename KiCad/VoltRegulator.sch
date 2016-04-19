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
LIBS:Project-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 4
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
L LM317_SOT223 U?
U 1 1 57160D0E
P 4050 2600
F 0 "U?" H 4050 2900 50  0000 C CNN
F 1 "LM317" H 4100 2350 50  0000 L CNN
F 2 "" H 4050 2600 50  0000 C CNN
F 3 "" H 4050 2600 50  0000 C CNN
	1    4050 2600
	1    0    0    -1  
$EndComp
$Comp
L +9V #PWR?
U 1 1 571610CA
P 2800 2000
F 0 "#PWR?" H 2800 1850 50  0001 C CNN
F 1 "+9V" H 2800 2140 50  0000 C CNN
F 2 "" H 2800 2000 50  0000 C CNN
F 3 "" H 2800 2000 50  0000 C CNN
	1    2800 2000
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 57161132
P 4950 2750
F 0 "R?" V 5030 2750 50  0000 C CNN
F 1 "R" V 4950 2750 50  0000 C CNN
F 2 "" V 4880 2750 50  0000 C CNN
F 3 "" H 4950 2750 50  0000 C CNN
	1    4950 2750
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5716119D
P 4500 3150
F 0 "R?" V 4580 3150 50  0000 C CNN
F 1 "R" V 4500 3150 50  0000 C CNN
F 2 "" V 4430 3150 50  0000 C CNN
F 3 "" H 4500 3150 50  0000 C CNN
	1    4500 3150
	0    1    1    0   
$EndComp
Wire Wire Line
	4050 2950 4050 3550
Wire Wire Line
	4350 3150 4050 3150
Connection ~ 4050 3150
Wire Wire Line
	4650 3150 4950 3150
Wire Wire Line
	4950 3150 4950 2900
Wire Wire Line
	4950 2600 4950 2450
Wire Wire Line
	4450 2450 5550 2450
Wire Wire Line
	2800 2000 2800 2800
Wire Wire Line
	2800 2450 3650 2450
Connection ~ 2800 2450
Text HLabel 2800 2800 3    60   Output ~ 0
9V
Text HLabel 5550 2450 2    60   Output ~ 0
5V
Connection ~ 4950 2450
$Comp
L GND #PWR?
U 1 1 571613A6
P 4050 3550
F 0 "#PWR?" H 4050 3300 50  0001 C CNN
F 1 "GND" H 4050 3400 50  0000 C CNN
F 2 "" H 4050 3550 50  0000 C CNN
F 3 "" H 4050 3550 50  0000 C CNN
	1    4050 3550
	1    0    0    -1  
$EndComp
$EndSCHEMATC
