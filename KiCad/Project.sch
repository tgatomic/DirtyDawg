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
Sheet 1 5
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
L ATMEGA328-P IC1
U 1 1 5714DE10
P 2500 2350
F 0 "IC1" H 1750 3600 50  0000 L BNN
F 1 "ATMEGA328-P" H 2900 950 50  0000 L BNN
F 2 "Housings_DIP:DIP-28_W7.62mm" H 2500 2350 50  0000 C CIN
F 3 "" H 2500 2350 50  0000 C CNN
	1    2500 2350
	1    0    0    -1  
$EndComp
$Comp
L BlueSmirf U1
U 1 1 5714FF78
P 8800 3550
F 0 "U1" H 8600 3400 60  0000 C CNN
F 1 "BlueSmirf" H 8750 3750 60  0000 C TNN
F 2 "Pin_Headers:Pin_Header_Straight_1x06_Pitch2.00mm" H 8800 3550 60  0001 C CNN
F 3 "" H 8800 3550 60  0000 C CNN
	1    8800 3550
	0    1    1    0   
$EndComp
$Comp
L GND #PWR1
U 1 1 5715DC43
P 1500 3800
F 0 "#PWR1" H 1500 3550 50  0001 C CNN
F 1 "GND" H 1500 3650 50  0000 C CNN
F 2 "" H 1500 3800 50  0000 C CNN
F 3 "" H 1500 3800 50  0000 C CNN
	1    1500 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 3450 1500 3450
Wire Wire Line
	1500 3450 1500 3800
Wire Wire Line
	1600 3550 1500 3550
Connection ~ 1500 3550
$Sheet
S 9500 4900 1100 700 
U 57160B94
F0 "VoltRegulator" 60
F1 "VoltRegulator.sch" 60
F2 "9V" O L 9500 5200 60 
F3 "5V" O L 9500 5400 60 
F4 "3V" O L 9500 5000 60 
$EndSheet
$Sheet
S 5750 4350 1700 850 
U 571635B2
F0 "IR" 60
F1 "IR.sch" 60
F2 "5V" I R 7450 5000 60 
F3 "SDA" B L 5750 4600 60 
F4 "SCL" B L 5750 4950 60 
F5 "9V" I L 5750 5100 60 
F6 "3V" I R 7450 4800 60 
$EndSheet
Wire Wire Line
	8200 5400 8200 5000
Wire Wire Line
	8200 5000 7450 5000
Wire Wire Line
	8000 5000 8000 5850
Wire Wire Line
	8000 5850 900  5850
Wire Wire Line
	900  5850 900  1000
Connection ~ 8000 5000
Wire Wire Line
	900  1250 1600 1250
Wire Wire Line
	8950 4100 8950 5400
Connection ~ 8950 5400
Wire Wire Line
	8750 4100 8750 4550
Wire Wire Line
	8750 4550 7800 4550
Wire Wire Line
	7800 4550 7800 2850
Wire Wire Line
	7800 2850 3500 2850
Wire Wire Line
	3500 2950 7650 2950
Wire Wire Line
	7650 2950 7650 4700
Wire Wire Line
	7650 4700 8650 4700
Wire Wire Line
	8650 4700 8650 4100
Wire Wire Line
	8850 4100 8850 4900
Wire Wire Line
	8850 4900 8800 4900
$Comp
L GND #PWR7
U 1 1 57165880
P 8800 4900
F 0 "#PWR7" H 8800 4650 50  0001 C CNN
F 1 "GND" H 8800 4750 50  0000 C CNN
F 2 "" H 8800 4900 50  0000 C CNN
F 3 "" H 8800 4900 50  0000 C CNN
	1    8800 4900
	0    1    1    0   
$EndComp
$Sheet
S 5750 950  1600 850 
U 57166F5B
F0 "lights" 60
F1 "Lights.sch" 60
F2 "5V" I L 5750 1150 60 
F3 "Brake" I L 5750 1400 60 
F4 "Headlight" I L 5750 1650 60 
$EndSheet
Connection ~ 900  1250
Wire Wire Line
	900  1000 5200 1000
Wire Wire Line
	5200 1000 5200 1150
Wire Wire Line
	5200 1150 5750 1150
$Comp
L Photores R3
U 1 1 5716DAD8
P 5000 2300
F 0 "R3" V 5080 2300 50  0000 C CNN
F 1 "Photores" V 5210 2300 50  0000 C TNN
F 2 "Wire_Connections_Bridges:WireConnection_1.50mmDrill" V 4930 2300 50  0001 C CNN
F 3 "" H 5000 2300 50  0000 C CNN
	1    5000 2300
	0    -1   -1   0   
$EndComp
$Comp
L R R2
U 1 1 5716E4CF
P 4450 2050
F 0 "R2" V 4530 2050 50  0000 C CNN
F 1 "10k" V 4450 2050 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Vertical_RM5mm" V 4380 2050 50  0001 C CNN
F 3 "" H 4450 2050 50  0000 C CNN
	1    4450 2050
	-1   0    0    1   
$EndComp
Wire Wire Line
	5500 1150 5500 2300
Wire Wire Line
	5500 2300 5250 2300
Connection ~ 5500 1150
Wire Wire Line
	4750 2300 4150 2300
Wire Wire Line
	4150 2300 4150 2100
Wire Wire Line
	4150 2100 3500 2100
$Comp
L GND #PWR4
U 1 1 5716EE89
P 4450 1800
F 0 "#PWR4" H 4450 1550 50  0001 C CNN
F 1 "GND" H 4450 1650 50  0000 C CNN
F 2 "" H 4450 1800 50  0000 C CNN
F 3 "" H 4450 1800 50  0000 C CNN
	1    4450 1800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3500 2500 4550 2500
Wire Wire Line
	4550 2500 4550 4600
Wire Wire Line
	4550 4600 5750 4600
Wire Wire Line
	5750 4950 4200 4950
Wire Wire Line
	4200 4950 4200 2600
Wire Wire Line
	4200 2600 3500 2600
Wire Wire Line
	8200 5400 9500 5400
Wire Wire Line
	9500 5000 8350 5000
Wire Wire Line
	8350 5000 8350 4800
Wire Wire Line
	8350 4800 7450 4800
Wire Wire Line
	9500 5200 7700 5200
Wire Wire Line
	7700 5200 7700 5500
Wire Wire Line
	7700 5500 5300 5500
Wire Wire Line
	5300 5500 5300 5100
Wire Wire Line
	5300 5100 5750 5100
Wire Wire Line
	4450 1800 4450 1900
Wire Wire Line
	4450 2200 4450 2300
Connection ~ 4450 2300
$Sheet
S 5750 3200 1650 850 
U 571BEA93
F0 "Motor" 60
F1 "Motor.sch" 60
F2 "Forw." I L 5750 3350 60 
F3 "Backw." I L 5750 3500 60 
F4 "5V" I R 7400 3850 60 
F5 "9V" I R 7400 3700 60 
F6 "Right" I L 5750 3900 60 
F7 "Left" I L 5750 3750 60 
$EndSheet
Wire Wire Line
	4950 3350 3500 3350
Wire Wire Line
	4800 3450 3500 3450
Wire Wire Line
	7600 5000 7600 3850
Wire Wire Line
	7600 3850 7400 3850
Connection ~ 7600 5000
Wire Wire Line
	8100 5200 8100 3700
Wire Wire Line
	8100 3700 7400 3700
Connection ~ 8100 5200
$Comp
L Crystal Y1
U 1 1 57338CDA
P 5950 2550
F 0 "Y1" H 5950 2700 50  0000 C CNN
F 1 "Crystal" H 5950 2400 50  0000 C CNN
F 2 "Crystals:Crystal_HC52-U_Vertical" H 5950 2550 50  0001 C CNN
F 3 "" H 5950 2550 50  0000 C CNN
	1    5950 2550
	0    1    1    0   
$EndComp
$Comp
L CONN_02X03 P1
U 1 1 5733918F
P 3950 1650
F 0 "P1" H 3950 1850 50  0000 C CNN
F 1 "CONN_02X03" H 3950 1450 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x03" H 3950 450 50  0001 C CNN
F 3 "" H 3950 450 50  0000 C CNN
	1    3950 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 1550 3500 1550
Wire Wire Line
	3700 1650 3500 1650
Wire Wire Line
	3700 1750 3500 1750
Wire Wire Line
	4200 1750 4300 1750
Wire Wire Line
	4300 1750 4300 2700
Wire Wire Line
	4300 2700 3500 2700
$Comp
L GND #PWR3
U 1 1 5733AA01
P 4250 1650
F 0 "#PWR3" H 4250 1400 50  0001 C CNN
F 1 "GND" H 4250 1500 50  0000 C CNN
F 2 "" H 4250 1650 50  0000 C CNN
F 3 "" H 4250 1650 50  0000 C CNN
	1    4250 1650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4200 1650 4250 1650
Wire Wire Line
	3500 1850 3700 1850
Wire Wire Line
	3700 1850 3700 2750
Wire Wire Line
	3700 2750 5650 2750
Wire Wire Line
	5650 2750 5650 2300
Wire Wire Line
	5650 2300 6350 2300
Wire Wire Line
	3500 1950 3600 1950
Wire Wire Line
	3600 1950 3600 2800
Wire Wire Line
	3600 2800 6350 2800
Wire Wire Line
	5950 2700 5950 2800
Connection ~ 5950 2800
Wire Wire Line
	5950 2400 5950 2300
Connection ~ 5950 2300
$Comp
L C C1
U 1 1 5733CE6C
P 6500 2300
F 0 "C1" H 6525 2400 50  0000 L CNN
F 1 "22pF" H 6525 2200 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D3_P2.5" H 6538 2150 50  0001 C CNN
F 3 "" H 6500 2300 50  0000 C CNN
	1    6500 2300
	0    1    1    0   
$EndComp
Wire Wire Line
	6350 2800 6350 2650
Wire Wire Line
	6350 2650 6550 2650
$Comp
L C C2
U 1 1 5733D154
P 6700 2650
F 0 "C2" H 6725 2750 50  0000 L CNN
F 1 "22pF" H 6725 2550 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D3_P2.5" H 6738 2500 50  0001 C CNN
F 3 "" H 6700 2650 50  0000 C CNN
	1    6700 2650
	0    1    1    0   
$EndComp
$Comp
L GND #PWR5
U 1 1 5733D1EA
P 6650 2300
F 0 "#PWR5" H 6650 2050 50  0001 C CNN
F 1 "GND" H 6650 2150 50  0000 C CNN
F 2 "" H 6650 2300 50  0000 C CNN
F 3 "" H 6650 2300 50  0000 C CNN
	1    6650 2300
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR6
U 1 1 5733D278
P 6850 2650
F 0 "#PWR6" H 6850 2400 50  0001 C CNN
F 1 "GND" H 6850 2500 50  0000 C CNN
F 2 "" H 6850 2650 50  0000 C CNN
F 3 "" H 6850 2650 50  0000 C CNN
	1    6850 2650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3500 3050 4000 3050
Wire Wire Line
	4000 3050 4000 3900
$Comp
L SW_PUSH SW4
U 1 1 5733F7BC
P 4000 4200
F 0 "SW4" H 4150 4310 50  0000 C CNN
F 1 "SW_PUSH" H 4000 4120 50  0000 C CNN
F 2 "Wire_Connections_Bridges:WireConnection_1.50mmDrill" H 4000 4200 50  0001 C CNN
F 3 "" H 4000 4200 50  0000 C CNN
	1    4000 4200
	0    1    1    0   
$EndComp
Wire Wire Line
	7600 4200 4750 4200
Wire Wire Line
	4750 4200 4750 5300
Wire Wire Line
	4750 5300 4000 5300
Wire Wire Line
	4000 5300 4000 4500
Connection ~ 7600 4200
$Comp
L R R1
U 1 1 573423F7
P 3650 4200
F 0 "R1" V 3730 4200 50  0000 C CNN
F 1 "1k" V 3650 4200 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Vertical_RM5mm" V 3580 4200 50  0001 C CNN
F 3 "" H 3650 4200 50  0000 C CNN
	1    3650 4200
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR2
U 1 1 5734269F
P 3650 4700
F 0 "#PWR2" H 3650 4450 50  0001 C CNN
F 1 "GND" H 3650 4550 50  0000 C CNN
F 2 "" H 3650 4700 50  0000 C CNN
F 3 "" H 3650 4700 50  0000 C CNN
	1    3650 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 3800 3650 3800
Wire Wire Line
	3650 3800 3650 4050
Connection ~ 4000 3800
Wire Wire Line
	3650 4350 3650 4700
Wire Wire Line
	5750 1400 4900 1400
Wire Wire Line
	4900 1400 4900 1250
Wire Wire Line
	4900 1250 3500 1250
Wire Wire Line
	3500 2400 4650 2400
Wire Wire Line
	4650 2400 4650 1900
Wire Wire Line
	4650 1900 5200 1900
Wire Wire Line
	5200 1900 5200 1650
Wire Wire Line
	5200 1650 5750 1650
Wire Wire Line
	4800 3450 4800 3900
Wire Wire Line
	4800 3900 5750 3900
Wire Wire Line
	4950 3350 4950 3750
Wire Wire Line
	4950 3750 5750 3750
Wire Wire Line
	3650 1550 3650 3000
Wire Wire Line
	3650 3000 5300 3000
Wire Wire Line
	5300 3000 5300 3350
Wire Wire Line
	5300 3350 5750 3350
Connection ~ 3650 1550
Wire Wire Line
	3500 3150 5200 3150
Wire Wire Line
	5200 3150 5200 3500
Wire Wire Line
	5200 3500 5750 3500
$Comp
L CONN_01X02 P2
U 1 1 5734FE54
P 8350 2400
F 0 "P2" H 8350 2550 50  0000 C CNN
F 1 "CONN_01X02" V 8450 2400 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 8350 2400 50  0001 C CNN
F 3 "" H 8350 2400 50  0000 C CNN
	1    8350 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	8150 2350 7450 2350
Wire Wire Line
	7450 2350 7450 2850
Connection ~ 7450 2850
Wire Wire Line
	7550 2450 7550 2950
Wire Wire Line
	7550 2450 8150 2450
Connection ~ 7550 2950
NoConn ~ 4200 1550
NoConn ~ 8550 4100
NoConn ~ 9050 4100
NoConn ~ 3500 1350
NoConn ~ 3500 1450
NoConn ~ 3500 2200
NoConn ~ 3500 2300
NoConn ~ 3500 3250
NoConn ~ 3500 3550
NoConn ~ 1600 1550
$EndSCHEMATC
