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
Sheet 2 5
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
L LM317_SOT223 U2
U 1 1 57160D0E
P 4050 2600
F 0 "U2" H 4050 2900 50  0000 C CNN
F 1 "LM317" H 4100 2350 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-220_Neutral123_Vertical" H 4050 2600 50  0001 C CNN
F 3 "" H 4050 2600 50  0000 C CNN
	1    4050 2600
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 57161132
P 4650 2750
F 0 "R6" V 4730 2750 50  0000 C CNN
F 1 "330" V 4650 2750 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Vertical_RM5mm" V 4580 2750 50  0001 C CNN
F 3 "" H 4650 2750 50  0000 C CNN
	1    4650 2750
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 5716119D
P 4050 3300
F 0 "R5" V 4130 3300 50  0000 C CNN
F 1 "1K" V 4050 3300 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Vertical_RM5mm" V 3980 3300 50  0001 C CNN
F 3 "" H 4050 3300 50  0000 C CNN
	1    4050 3300
	1    0    0    -1  
$EndComp
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
$Comp
L GND #PWR08
U 1 1 571613A6
P 4050 3550
F 0 "#PWR08" H 4050 3300 50  0001 C CNN
F 1 "GND" H 4050 3400 50  0000 C CNN
F 2 "" H 4050 3550 50  0000 C CNN
F 3 "" H 4050 3550 50  0000 C CNN
	1    4050 3550
	1    0    0    -1  
$EndComp
$Comp
L LM317_SOT223 U3
U 1 1 571810AE
P 7750 2600
F 0 "U3" H 7750 2900 50  0000 C CNN
F 1 "LM317" H 7800 2350 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-220_Neutral123_Vertical" H 7750 2600 50  0001 C CNN
F 3 "" H 7750 2600 50  0000 C CNN
	1    7750 2600
	1    0    0    -1  
$EndComp
$Comp
L R R22
U 1 1 571810BA
P 8350 2800
F 0 "R22" V 8430 2800 50  0000 C CNN
F 1 "330" V 8350 2800 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Vertical_RM5mm" V 8280 2800 50  0001 C CNN
F 3 "" H 8350 2800 50  0000 C CNN
	1    8350 2800
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 571810C0
P 7750 3300
F 0 "R7" V 7830 3300 50  0000 C CNN
F 1 "470" V 7750 3300 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Vertical_RM5mm" V 7680 3300 50  0001 C CNN
F 3 "" H 7750 3300 50  0000 C CNN
	1    7750 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	8150 2450 9250 2450
Wire Wire Line
	6500 2000 6500 2800
Wire Wire Line
	6500 2450 7350 2450
Connection ~ 6500 2450
Text HLabel 6500 2800 3    60   Output ~ 0
9V
Text HLabel 9250 2450 2    60   Output ~ 0
3V
$Comp
L GND #PWR09
U 1 1 571810D3
P 7750 3550
F 0 "#PWR09" H 7750 3300 50  0001 C CNN
F 1 "GND" H 7750 3400 50  0000 C CNN
F 2 "" H 7750 3550 50  0000 C CNN
F 3 "" H 7750 3550 50  0000 C CNN
	1    7750 3550
	1    0    0    -1  
$EndComp
Text Label 5200 2450 0    60   ~ 0
5.04V
Text Label 8950 2450 0    60   ~ 0
3V03
Wire Wire Line
	8350 2450 8350 2650
Connection ~ 8350 2450
Wire Wire Line
	8350 2950 8350 3050
Wire Wire Line
	8350 3050 7750 3050
Wire Wire Line
	7750 2950 7750 3150
Connection ~ 7750 3050
Wire Wire Line
	7750 3450 7750 3550
Wire Wire Line
	4650 2450 4650 2600
Connection ~ 4650 2450
Wire Wire Line
	4650 2900 4650 3050
Wire Wire Line
	4650 3050 4050 3050
Wire Wire Line
	4050 2950 4050 3150
Connection ~ 4050 3050
Wire Wire Line
	4050 3450 4050 3550
$Comp
L CP1 C4
U 1 1 571BB487
P 5100 2750
F 0 "C4" H 5125 2850 50  0000 L CNN
F 1 "1uF" H 5125 2650 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D5_L6_P2.5" H 5100 2750 50  0001 C CNN
F 3 "" H 5100 2750 50  0000 C CNN
	1    5100 2750
	1    0    0    -1  
$EndComp
$Comp
L CP1 C6
U 1 1 571BB503
P 8850 2800
F 0 "C6" H 8875 2900 50  0000 L CNN
F 1 "1uF" H 8875 2700 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D5_L6_P2.5" H 8850 2800 50  0001 C CNN
F 3 "" H 8850 2800 50  0000 C CNN
	1    8850 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	8850 2650 8850 2450
Connection ~ 8850 2450
Wire Wire Line
	5100 2600 5100 2450
Connection ~ 5100 2450
Wire Wire Line
	5100 2900 5100 3050
Wire Wire Line
	8850 2950 8850 3050
$Comp
L C C3
U 1 1 571BBB0A
P 3350 2750
F 0 "C3" H 3375 2850 50  0000 L CNN
F 1 "0.1uF" H 3375 2650 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D3_P2.5" H 3388 2600 50  0001 C CNN
F 3 "" H 3350 2750 50  0000 C CNN
	1    3350 2750
	1    0    0    -1  
$EndComp
$Comp
L C C5
U 1 1 571BBC58
P 7050 2800
F 0 "C5" H 7075 2900 50  0000 L CNN
F 1 "0.1uF" H 7075 2700 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D3_P2.5" H 7088 2650 50  0001 C CNN
F 3 "" H 7050 2800 50  0000 C CNN
	1    7050 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 2450 7050 2650
Connection ~ 7050 2450
Wire Wire Line
	7050 2950 7050 3050
Wire Wire Line
	3350 2600 3350 2450
Connection ~ 3350 2450
Wire Wire Line
	3350 2900 3350 3050
$Comp
L GND #PWR010
U 1 1 571BC1AC
P 3350 3050
F 0 "#PWR010" H 3350 2800 50  0001 C CNN
F 1 "GND" H 3350 2900 50  0000 C CNN
F 2 "" H 3350 3050 50  0000 C CNN
F 3 "" H 3350 3050 50  0000 C CNN
	1    3350 3050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 571BC2DA
P 5100 3050
F 0 "#PWR011" H 5100 2800 50  0001 C CNN
F 1 "GND" H 5100 2900 50  0000 C CNN
F 2 "" H 5100 3050 50  0000 C CNN
F 3 "" H 5100 3050 50  0000 C CNN
	1    5100 3050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR012
U 1 1 571BC41B
P 7050 3050
F 0 "#PWR012" H 7050 2800 50  0001 C CNN
F 1 "GND" H 7050 2900 50  0000 C CNN
F 2 "" H 7050 3050 50  0000 C CNN
F 3 "" H 7050 3050 50  0000 C CNN
	1    7050 3050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR013
U 1 1 571BC444
P 8850 3050
F 0 "#PWR013" H 8850 2800 50  0001 C CNN
F 1 "GND" H 8850 2900 50  0000 C CNN
F 2 "" H 8850 3050 50  0000 C CNN
F 3 "" H 8850 3050 50  0000 C CNN
	1    8850 3050
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X02 P7
U 1 1 5735CB2D
P 4750 1200
F 0 "P7" H 4750 1350 50  0000 C CNN
F 1 "CONN_01X02" V 4850 1200 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 4750 1200 50  0001 C CNN
F 3 "" H 4750 1200 50  0000 C CNN
	1    4750 1200
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2800 2000 6500 2000
Wire Wire Line
	4700 1400 4700 2000
Wire Wire Line
	4800 1400 4800 1550
Wire Wire Line
	4800 1550 4900 1550
$Comp
L GND #PWR014
U 1 1 5735CD07
P 4900 1550
F 0 "#PWR014" H 4900 1300 50  0001 C CNN
F 1 "GND" H 4900 1400 50  0000 C CNN
F 2 "" H 4900 1550 50  0000 C CNN
F 3 "" H 4900 1550 50  0000 C CNN
	1    4900 1550
	0    -1   -1   0   
$EndComp
$EndSCHEMATC
