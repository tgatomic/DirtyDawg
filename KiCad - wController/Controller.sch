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
Sheet 2 2
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
L Linkura U5
U 1 1 5717C731
P 4000 6600
F 0 "U5" H 4300 6750 60  0000 C CNN
F 1 "Linkura" H 3800 6650 60  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 4000 6600 60  0001 C CNN
F 3 "" H 4000 6600 60  0000 C CNN
	1    4000 6600
	-1   0    0    1   
$EndComp
$Comp
L I2C_LCD16X2 DS1
U 1 1 5717CD37
P 5000 2650
F 0 "DS1" H 4200 3050 50  0000 C CNN
F 1 "I2C_LCD16X2" H 5700 3050 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04" H 5000 2600 50  0001 C CIN
F 3 "" H 5000 2650 50  0000 C CNN
	1    5000 2650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 5717D255
P 4350 3150
F 0 "#PWR01" H 4350 2900 50  0001 C CNN
F 1 "GND" H 4350 3000 50  0000 C CNN
F 2 "" H 4350 3150 50  0000 C CNN
F 3 "" H 4350 3150 50  0000 C CNN
	1    4350 3150
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW1
U 1 1 5717DAA2
P 5750 4000
F 0 "SW1" H 5900 4110 50  0000 C CNN
F 1 "Reverse" H 5750 3900 50  0000 C CNN
F 2 "Holes:SolderWirePad1mmmodified" H 5750 4000 50  0001 C CNN
F 3 "" H 5750 4000 50  0000 C CNN
	1    5750 4000
	0    1    1    0   
$EndComp
$Comp
L SW_PUSH SW2
U 1 1 5717DAF5
P 6350 4300
F 0 "SW2" H 6500 4410 50  0000 C CNN
F 1 "Pairing" H 6350 4220 50  0000 C CNN
F 2 "Holes:SolderWirePad1mmmodified" H 6350 4300 50  0001 C CNN
F 3 "" H 6350 4300 50  0000 C CNN
	1    6350 4300
	0    1    1    0   
$EndComp
$Comp
L SW_PUSH SW3
U 1 1 5717DB44
P 6950 4600
F 0 "SW3" H 7100 4710 50  0000 C CNN
F 1 "Lights" H 6950 4520 50  0000 C CNN
F 2 "Holes:SolderWirePad1mmmodified" H 6950 4600 50  0001 C CNN
F 3 "" H 6950 4600 50  0000 C CNN
	1    6950 4600
	0    1    1    0   
$EndComp
$Comp
L R R34
U 1 1 5717E19D
P 5600 4450
F 0 "R34" V 5680 4450 50  0000 C CNN
F 1 "1k" V 5600 4450 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Vertical_RM5mm" V 5530 4450 50  0001 C CNN
F 3 "" H 5600 4450 50  0000 C CNN
	1    5600 4450
	0    1    1    0   
$EndComp
$Comp
L R R35
U 1 1 5717E455
P 6200 4750
F 0 "R35" V 6280 4750 50  0000 C CNN
F 1 "1k" V 6200 4750 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Vertical_RM5mm" V 6130 4750 50  0001 C CNN
F 3 "" H 6200 4750 50  0000 C CNN
	1    6200 4750
	0    1    1    0   
$EndComp
$Comp
L R R36
U 1 1 5717E48F
P 6800 5050
F 0 "R36" V 6880 5050 50  0000 C CNN
F 1 "1k" V 6800 5050 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Vertical_RM5mm" V 6730 5050 50  0001 C CNN
F 3 "" H 6800 5050 50  0000 C CNN
	1    6800 5050
	0    1    1    0   
$EndComp
$Comp
L GND #PWR02
U 1 1 5717E7A9
P 5450 4450
F 0 "#PWR02" H 5450 4200 50  0001 C CNN
F 1 "GND" H 5450 4300 50  0000 C CNN
F 2 "" H 5450 4450 50  0000 C CNN
F 3 "" H 5450 4450 50  0000 C CNN
	1    5450 4450
	0    1    1    0   
$EndComp
NoConn ~ 5650 3150
NoConn ~ 5750 3150
$Comp
L BlueSmirf U2
U 1 1 573D88C1
P 4900 6450
F 0 "U2" H 4600 6250 60  0000 C CNN
F 1 "BlueSmirf" H 4850 6850 60  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x06" H 4900 6450 60  0001 C CNN
F 3 "" H 4900 6450 60  0000 C CNN
	1    4900 6450
	0    -1   -1   0   
$EndComp
$Comp
L LM317_SOT223 U1
U 1 1 573DC02D
P 1850 1600
F 0 "U1" H 1850 1900 50  0000 C CNN
F 1 "LM317_SOT223" H 1900 1350 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-220_Neutral123_Vertical" H 1850 1600 50  0001 C CNN
F 3 "" H 1850 1600 50  0000 C CNN
	1    1850 1600
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 573DC2FF
P 2200 2050
F 0 "R2" V 2280 2050 50  0000 C CNN
F 1 "330" V 2200 2050 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Vertical_RM5mm" V 2130 2050 50  0001 C CNN
F 3 "" H 2200 2050 50  0000 C CNN
	1    2200 2050
	0    1    1    0   
$EndComp
$Comp
L R R1
U 1 1 573DC39C
P 1850 2300
F 0 "R1" V 1930 2300 50  0000 C CNN
F 1 "1k" V 1850 2300 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Vertical_RM5mm" V 1780 2300 50  0001 C CNN
F 3 "" H 1850 2300 50  0000 C CNN
	1    1850 2300
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 573DC3D7
P 1250 1750
F 0 "C1" H 1275 1850 50  0000 L CNN
F 1 "0.1uF" H 1275 1650 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D6_P5" H 1288 1600 50  0001 C CNN
F 3 "" H 1250 1750 50  0000 C CNN
	1    1250 1750
	1    0    0    -1  
$EndComp
$Comp
L CP1 C2
U 1 1 573DC418
P 2650 1750
F 0 "C2" H 2675 1850 50  0000 L CNN
F 1 "1uF" H 2675 1650 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D5_L11_P2" H 2650 1750 50  0001 C CNN
F 3 "" H 2650 1750 50  0000 C CNN
	1    2650 1750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 573DC5E1
P 1250 1900
F 0 "#PWR03" H 1250 1650 50  0001 C CNN
F 1 "GND" H 1250 1750 50  0000 C CNN
F 2 "" H 1250 1900 50  0000 C CNN
F 3 "" H 1250 1900 50  0000 C CNN
	1    1250 1900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 573DC620
P 1850 2450
F 0 "#PWR04" H 1850 2200 50  0001 C CNN
F 1 "GND" H 1850 2300 50  0000 C CNN
F 2 "" H 1850 2450 50  0000 C CNN
F 3 "" H 1850 2450 50  0000 C CNN
	1    1850 2450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 573DC676
P 2650 1950
F 0 "#PWR05" H 2650 1700 50  0001 C CNN
F 1 "GND" H 2650 1800 50  0000 C CNN
F 2 "" H 2650 1950 50  0000 C CNN
F 3 "" H 2650 1950 50  0000 C CNN
	1    2650 1950
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X02 P1
U 1 1 573DC88C
P 900 1000
F 0 "P1" H 900 1150 50  0000 C CNN
F 1 "9V" V 1000 1000 50  0000 C CNN
F 2 "Holes:SolderWirePad1mmmodified" H 900 1000 50  0001 C CNN
F 3 "" H 900 1000 50  0000 C CNN
	1    900  1000
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR06
U 1 1 573DC8E9
P 850 1250
F 0 "#PWR06" H 850 1000 50  0001 C CNN
F 1 "GND" H 850 1100 50  0000 C CNN
F 2 "" H 850 1250 50  0000 C CNN
F 3 "" H 850 1250 50  0000 C CNN
	1    850  1250
	1    0    0    -1  
$EndComp
Text Label 2800 1450 0    60   ~ 0
5V04
Wire Wire Line
	3950 3100 3950 3400
Wire Wire Line
	3950 3400 6950 3400
Wire Wire Line
	6350 3400 6350 4000
Wire Wire Line
	6950 3400 6950 4300
Connection ~ 6350 3400
Wire Wire Line
	5750 3700 5750 3400
Connection ~ 5750 3400
Wire Wire Line
	4900 4300 5750 4300
Wire Wire Line
	5750 4300 5750 4450
Wire Wire Line
	6350 4600 6350 4750
Wire Wire Line
	6950 4900 6950 5050
Wire Wire Line
	950  1450 1450 1450
Wire Wire Line
	1250 1450 1250 1600
Wire Wire Line
	2050 2050 1850 2050
Wire Wire Line
	1850 1950 1850 2150
Connection ~ 1850 2050
Wire Wire Line
	2250 1450 3100 1450
Wire Wire Line
	2450 1450 2450 2050
Wire Wire Line
	2450 2050 2350 2050
Connection ~ 2450 1450
Wire Wire Line
	2650 1600 2650 1450
Connection ~ 2650 1450
Wire Wire Line
	950  1200 950  1450
Connection ~ 1250 1450
Wire Wire Line
	6950 4200 7350 4200
Wire Wire Line
	7350 4200 7350 5600
Wire Wire Line
	7350 5600 4750 5600
Wire Wire Line
	4750 5600 4750 5900
Connection ~ 6950 4200
NoConn ~ 4650 5900
NoConn ~ 5150 5900
$Comp
L GND #PWR07
U 1 1 573DFA92
P 4850 5900
F 0 "#PWR07" H 4850 5650 50  0001 C CNN
F 1 "GND" H 4850 5750 50  0000 C CNN
F 2 "" H 4850 5900 50  0000 C CNN
F 3 "" H 4850 5900 50  0000 C CNN
	1    4850 5900
	-1   0    0    1   
$EndComp
$Comp
L CONN_02X03 P2
U 1 1 573E0FB7
P 3800 3950
F 0 "P2" H 3800 4150 50  0000 C CNN
F 1 "SPI" H 3800 3750 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x03" H 3800 2750 50  0001 C CNN
F 3 "" H 3800 2750 50  0000 C CNN
	1    3800 3950
	1    0    0    -1  
$EndComp
NoConn ~ 4050 3850
$Comp
L GND #PWR08
U 1 1 573E10A3
P 4050 3950
F 0 "#PWR08" H 4050 3700 50  0001 C CNN
F 1 "GND" H 4050 3800 50  0000 C CNN
F 2 "" H 4050 3950 50  0000 C CNN
F 3 "" H 4050 3950 50  0000 C CNN
	1    4050 3950
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR09
U 1 1 573E1332
P 6050 4750
F 0 "#PWR09" H 6050 4500 50  0001 C CNN
F 1 "GND" H 6050 4600 50  0000 C CNN
F 2 "" H 6050 4750 50  0000 C CNN
F 3 "" H 6050 4750 50  0000 C CNN
	1    6050 4750
	0    1    1    0   
$EndComp
$Comp
L GND #PWR010
U 1 1 573E1370
P 6650 5050
F 0 "#PWR010" H 6650 4800 50  0001 C CNN
F 1 "GND" H 6650 4900 50  0000 C CNN
F 2 "" H 6650 5050 50  0000 C CNN
F 3 "" H 6650 5050 50  0000 C CNN
	1    6650 5050
	0    1    1    0   
$EndComp
$Comp
L ATMEGA168-P IC1
U 1 1 573E38C5
P 2650 4700
F 0 "IC1" H 1800 6000 50  0000 L BNN
F 1 "ATMEGA168-P" H 3000 3350 50  0000 L BNN
F 2 "Housings_DIP:DIP-28_W7.62mm" H 2650 4700 50  0001 C CIN
F 3 "" H 2650 4700 50  0000 C CNN
	1    2650 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 1450 3100 3100
Wire Wire Line
	1450 3100 3950 3100
Wire Wire Line
	1450 3100 1450 3550
Wire Wire Line
	1450 3550 1650 3550
Connection ~ 3100 3100
$Comp
L GND #PWR011
U 1 1 573E49A9
P 1600 5750
F 0 "#PWR011" H 1600 5500 50  0001 C CNN
F 1 "GND" H 1600 5600 50  0000 C CNN
F 2 "" H 1600 5750 50  0000 C CNN
F 3 "" H 1600 5750 50  0000 C CNN
	1    1600 5750
	0    1    1    0   
$EndComp
$Comp
L GND #PWR012
U 1 1 573E4B78
P 1650 5850
F 0 "#PWR012" H 1650 5600 50  0001 C CNN
F 1 "GND" H 1650 5700 50  0000 C CNN
F 2 "" H 1650 5850 50  0000 C CNN
F 3 "" H 1650 5850 50  0000 C CNN
	1    1650 5850
	0    1    1    0   
$EndComp
Wire Wire Line
	3550 5150 4950 5150
Wire Wire Line
	4950 5150 4950 5900
Wire Wire Line
	3550 5250 5050 5250
Wire Wire Line
	5050 5250 5050 5900
Wire Wire Line
	3550 5450 4200 5450
Wire Wire Line
	4200 5450 4200 6200
Wire Wire Line
	3550 5550 4300 5550
Wire Wire Line
	4300 5550 4300 6200
Wire Wire Line
	4550 3150 4550 4900
Wire Wire Line
	4550 4900 3550 4900
Wire Wire Line
	4450 3150 4450 4800
Wire Wire Line
	4450 4800 3550 4800
Wire Wire Line
	4900 4300 4900 4400
Wire Wire Line
	4900 4400 3550 4400
Wire Wire Line
	4800 4600 3550 4600
Wire Wire Line
	6950 4900 4800 4900
Wire Wire Line
	4800 4900 4800 4600
Wire Wire Line
	5150 4600 6350 4600
Wire Wire Line
	5150 4600 5150 5350
Wire Wire Line
	5150 5350 3550 5350
Wire Wire Line
	3550 5000 4200 5000
Wire Wire Line
	4050 4050 4200 4050
Wire Wire Line
	4200 4050 4200 5000
NoConn ~ 1650 3850
NoConn ~ 1650 4150
NoConn ~ 3550 3550
NoConn ~ 3550 3650
NoConn ~ 3550 3750
NoConn ~ 3550 4150
NoConn ~ 3550 4250
NoConn ~ 3550 4500
NoConn ~ 3550 4700
NoConn ~ 3550 5650
NoConn ~ 3550 5750
NoConn ~ 3550 5850
Wire Wire Line
	4250 3150 4250 3400
Connection ~ 4250 3400
Wire Wire Line
	1600 5750 1650 5750
Wire Wire Line
	2650 1950 2650 1900
Wire Wire Line
	850  1250 850  1200
$EndSCHEMATC
