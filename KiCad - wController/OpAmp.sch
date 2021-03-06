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
Sheet 4 7
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
L CA3240E U4
U 1 1 5718642F
P 4150 1900
F 0 "U4" H 3850 2250 50  0000 L CNN
F 1 "CA3240E" H 3850 1550 50  0000 L CNN
F 2 "" H 4150 1900 50  0001 C CNN
F 3 "" H 4150 1900 50  0000 C CNN
	1    4150 1900
	1    0    0    -1  
$EndComp
Text HLabel 3400 2300 3    60   Input ~ 0
SignalIn(A)
Text HLabel 3500 1450 1    60   Output ~ 0
SignaOut(A)
Text HLabel 4550 1700 2    60   Input ~ 0
9V
Text HLabel 4850 1450 1    60   Output ~ 0
SignaOut(B)
Text HLabel 4700 2300 3    60   Input ~ 0
SignalIn(B)
$Comp
L R R25
U 1 1 571877CF
P 3250 1700
F 0 "R25" V 3330 1700 50  0000 C CNN
F 1 "150" V 3250 1700 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Vertical_RM5mm" V 3180 1700 50  0001 C CNN
F 3 "" H 3250 1700 50  0000 C CNN
	1    3250 1700
	0    1    1    0   
$EndComp
$Comp
L R R24
U 1 1 57187832
P 3000 2400
F 0 "R24" V 3080 2400 50  0000 C CNN
F 1 "100" V 3000 2400 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Vertical_RM5mm" V 2930 2400 50  0001 C CNN
F 3 "" H 3000 2400 50  0000 C CNN
	1    3000 2400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR020
U 1 1 571879D5
P 3000 2550
F 0 "#PWR020" H 3000 2300 50  0001 C CNN
F 1 "GND" H 3000 2400 50  0000 C CNN
F 2 "" H 3000 2550 50  0000 C CNN
F 3 "" H 3000 2550 50  0000 C CNN
	1    3000 2550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR021
U 1 1 571879F0
P 3700 2200
F 0 "#PWR021" H 3700 1950 50  0001 C CNN
F 1 "GND" H 3700 2050 50  0000 C CNN
F 2 "" H 3700 2200 50  0000 C CNN
F 3 "" H 3700 2200 50  0000 C CNN
	1    3700 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 1450 3500 1700
Connection ~ 3500 1700
Wire Wire Line
	3000 1700 3100 1700
Wire Wire Line
	3400 1700 3750 1700
Wire Wire Line
	4550 1850 4950 1850
$Comp
L R R26
U 1 1 57187D93
P 5100 1850
F 0 "R26" V 5180 1850 50  0000 C CNN
F 1 "150" V 5100 1850 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Vertical_RM5mm" V 5030 1850 50  0001 C CNN
F 3 "" H 5100 1850 50  0000 C CNN
	1    5100 1850
	0    1    1    0   
$EndComp
Wire Wire Line
	4550 2100 4700 2100
Wire Wire Line
	4700 2100 4700 2300
Wire Wire Line
	4850 1950 4550 1950
Wire Wire Line
	4850 1450 4850 1850
Connection ~ 4850 1850
$Comp
L GND #PWR022
U 1 1 57187F37
P 5400 2550
F 0 "#PWR022" H 5400 2300 50  0001 C CNN
F 1 "GND" H 5400 2400 50  0000 C CNN
F 2 "" H 5400 2550 50  0000 C CNN
F 3 "" H 5400 2550 50  0000 C CNN
	1    5400 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 1950 4850 2200
$Comp
L R R28
U 1 1 571881CA
P 5400 2400
F 0 "R28" V 5480 2400 50  0000 C CNN
F 1 "100" V 5400 2400 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Vertical_RM5mm" V 5330 2400 50  0001 C CNN
F 3 "" H 5400 2400 50  0000 C CNN
	1    5400 2400
	-1   0    0    1   
$EndComp
$Comp
L R R27
U 1 1 57188573
P 5400 2000
F 0 "R27" V 5480 2000 50  0000 C CNN
F 1 "150" V 5400 2000 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Vertical_RM5mm" V 5330 2000 50  0001 C CNN
F 3 "" H 5400 2000 50  0000 C CNN
	1    5400 2000
	-1   0    0    1   
$EndComp
Wire Wire Line
	5250 1850 5400 1850
Wire Wire Line
	4850 2200 5400 2200
Wire Wire Line
	5400 2150 5400 2250
Connection ~ 5400 2200
$Comp
L R R23
U 1 1 57188968
P 3000 1850
F 0 "R23" V 3080 1850 50  0000 C CNN
F 1 "150" V 3000 1850 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Vertical_RM5mm" V 2930 1850 50  0001 C CNN
F 3 "" H 3000 1850 50  0000 C CNN
	1    3000 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 2000 3000 2250
Wire Wire Line
	3000 2100 3250 2100
Connection ~ 3000 2100
Wire Wire Line
	3750 1950 3400 1950
Wire Wire Line
	3400 1950 3400 2300
Wire Wire Line
	3750 2100 3700 2100
Wire Wire Line
	3700 2100 3700 2200
Wire Wire Line
	3750 1850 3250 1850
Wire Wire Line
	3250 1850 3250 2100
$EndSCHEMATC
