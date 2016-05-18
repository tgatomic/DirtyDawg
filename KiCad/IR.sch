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
Sheet 3 5
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
L ATTINY85-P IC2
U 1 1 57175B9E
P 7200 1300
F 0 "IC2" H 6050 1700 50  0000 C CNN
F 1 "ATTINY85-P" H 8200 900 50  0000 C CNN
F 2 "Housings_DIP:DIP-8_W7.62mm" H 8200 1300 50  0000 C CIN
F 3 "" H 7200 1300 50  0000 C CNN
	1    7200 1300
	1    0    0    -1  
$EndComp
Text HLabel 4950 1250 0    60   BiDi ~ 0
SCL
$Comp
L GND #PWR017
U 1 1 57175BA8
P 8650 1700
F 0 "#PWR017" H 8650 1450 50  0001 C CNN
F 1 "GND" H 8650 1550 50  0000 C CNN
F 2 "" H 8650 1700 50  0000 C CNN
F 3 "" H 8650 1700 50  0000 C CNN
	1    8650 1700
	1    0    0    -1  
$EndComp
$Comp
L IR_Recieve D9
U 1 1 57175BAE
P 3300 2800
F 0 "D9" H 3300 2900 50  0000 C CNN
F 1 "IR_Recieve" H 3316 2633 50  0000 C CNN
F 2 "Holes:SolderWirePad1mmmodified" H 3300 2800 50  0001 C CNN
F 3 "" H 3300 2800 50  0000 C CNN
	1    3300 2800
	0    -1   -1   0   
$EndComp
$Comp
L LED D7
U 1 1 57175BB4
P 2900 2800
F 0 "D7" H 2900 2900 50  0000 C CNN
F 1 "LED" V 2900 2700 50  0000 C CNN
F 2 "Holes:SolderWirePad1mmmodified" H 2900 2800 50  0001 C CNN
F 3 "" H 2900 2800 50  0000 C CNN
	1    2900 2800
	0    -1   -1   0   
$EndComp
$Comp
L LED D11
U 1 1 57175BBA
P 3700 2800
F 0 "D11" H 3700 2900 50  0000 C CNN
F 1 "LED" V 3700 2700 50  0000 C CNN
F 2 "Holes:SolderWirePad1mmmodified" H 3700 2800 50  0001 C CNN
F 3 "" H 3700 2800 50  0000 C CNN
	1    3700 2800
	0    -1   -1   0   
$EndComp
$Comp
L R R16
U 1 1 57175BC0
P 3300 2250
F 0 "R16" V 3380 2250 50  0000 C CNN
F 1 "100" V 3300 2250 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Vertical_RM5mm" V 3230 2250 50  0001 C CNN
F 3 "" H 3300 2250 50  0000 C CNN
	1    3300 2250
	1    0    0    -1  
$EndComp
$Comp
L R R18
U 1 1 57175BE1
P 3700 2250
F 0 "R18" V 3780 2250 50  0000 C CNN
F 1 "22" V 3700 2250 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Vertical_RM5mm" V 3630 2250 50  0001 C CNN
F 3 "" H 3700 2250 50  0000 C CNN
	1    3700 2250
	1    0    0    -1  
$EndComp
$Comp
L R R14
U 1 1 57175BE7
P 2900 2250
F 0 "R14" V 2980 2250 50  0000 C CNN
F 1 "22" V 2900 2250 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Vertical_RM5mm" V 2830 2250 50  0001 C CNN
F 3 "" H 2900 2250 50  0000 C CNN
	1    2900 2250
	1    0    0    -1  
$EndComp
Text Label 3500 1700 0    60   ~ 0
Signal
$Comp
L IR_Recieve D3
U 1 1 57175BF9
P 1800 2800
F 0 "D3" H 1800 2900 50  0000 C CNN
F 1 "IR_Recieve" H 1816 2633 50  0000 C CNN
F 2 "Holes:SolderWirePad1mmmodified" H 1800 2800 50  0001 C CNN
F 3 "" H 1800 2800 50  0000 C CNN
	1    1800 2800
	0    -1   -1   0   
$EndComp
$Comp
L LED D1
U 1 1 57175BFF
P 1400 2800
F 0 "D1" H 1400 2900 50  0000 C CNN
F 1 "LED" V 1400 2700 50  0000 C CNN
F 2 "Holes:SolderWirePad1mmmodified" H 1400 2800 50  0001 C CNN
F 3 "" H 1400 2800 50  0000 C CNN
	1    1400 2800
	0    -1   -1   0   
$EndComp
$Comp
L LED D5
U 1 1 57175C05
P 2200 2800
F 0 "D5" H 2200 2900 50  0000 C CNN
F 1 "LED" V 2200 2700 50  0000 C CNN
F 2 "Holes:SolderWirePad1mmmodified" H 2200 2800 50  0001 C CNN
F 3 "" H 2200 2800 50  0000 C CNN
	1    2200 2800
	0    -1   -1   0   
$EndComp
$Comp
L R R10
U 1 1 57175C0B
P 1800 2250
F 0 "R10" V 1880 2250 50  0000 C CNN
F 1 "100" V 1800 2250 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Vertical_RM5mm" V 1730 2250 50  0001 C CNN
F 3 "" H 1800 2250 50  0000 C CNN
	1    1800 2250
	1    0    0    -1  
$EndComp
$Comp
L Q_NPN_BCE Q2
U 1 1 57175C18
P 3650 3500
F 0 "Q2" H 3950 3550 50  0000 R CNN
F 1 "Q_NPN_BCE" H 4250 3450 50  0001 R CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Narrow_Oval" H 3850 3600 50  0001 C CNN
F 3 "" H 3650 3500 50  0000 C CNN
	1    3650 3500
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR018
U 1 1 57175C1F
P 4000 3400
F 0 "#PWR018" H 4000 3150 50  0001 C CNN
F 1 "GND" H 4000 3250 50  0000 C CNN
F 2 "" H 4000 3400 50  0000 C CNN
F 3 "" H 4000 3400 50  0000 C CNN
	1    4000 3400
	-1   0    0    1   
$EndComp
$Comp
L R R20
U 1 1 57175C25
P 3900 3700
F 0 "R20" V 3980 3700 50  0000 C CNN
F 1 "1K" V 3900 3700 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Vertical_RM5mm" V 3830 3700 50  0001 C CNN
F 3 "" H 3900 3700 50  0000 C CNN
	1    3900 3700
	0    1    1    0   
$EndComp
$Comp
L R R12
U 1 1 57175C2C
P 2200 2250
F 0 "R12" V 2280 2250 50  0000 C CNN
F 1 "22" V 2200 2250 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Vertical_RM5mm" V 2130 2250 50  0001 C CNN
F 3 "" H 2200 2250 50  0000 C CNN
	1    2200 2250
	1    0    0    -1  
$EndComp
$Comp
L R R8
U 1 1 57175C32
P 1400 2250
F 0 "R8" V 1480 2250 50  0000 C CNN
F 1 "22" V 1400 2250 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Vertical_RM5mm" V 1330 2250 50  0001 C CNN
F 3 "" H 1400 2250 50  0000 C CNN
	1    1400 2250
	1    0    0    -1  
$EndComp
Text Label 2000 1700 0    60   ~ 0
Signal
Text HLabel 5600 1050 0    60   BiDi ~ 0
SDA
Text HLabel 8550 1050 2    60   Input ~ 0
5V
Text HLabel 1400 2100 1    60   Input ~ 0
3V
Text HLabel 2200 2100 1    60   Input ~ 0
3V
Text HLabel 2900 2100 1    60   Input ~ 0
3V
Text HLabel 3700 2100 1    60   Input ~ 0
3V
Wire Wire Line
	3300 1900 3300 2100
Wire Wire Line
	3300 2400 3300 2600
Connection ~ 3300 2500
Wire Wire Line
	2900 3000 2900 3150
Wire Wire Line
	2900 3150 3700 3150
Connection ~ 3300 3150
Wire Wire Line
	3700 3150 3700 3000
Wire Wire Line
	2900 2400 2900 2600
Wire Wire Line
	3700 2400 3700 2600
Wire Wire Line
	3300 2500 3500 2500
Wire Wire Line
	3500 2500 3500 1700
Wire Wire Line
	1800 1900 1800 2100
Wire Wire Line
	1800 2400 1800 2600
Connection ~ 1800 2500
Wire Wire Line
	1400 3000 1400 3150
Wire Wire Line
	1400 3150 2200 3150
Connection ~ 1800 3150
Wire Wire Line
	2200 3150 2200 3000
Wire Wire Line
	1400 2400 1400 2600
Wire Wire Line
	2200 2400 2200 2600
Wire Wire Line
	1800 2500 2000 2500
Wire Wire Line
	2000 2500 2000 1700
Wire Wire Line
	2000 1700 3000 1700
Wire Wire Line
	3850 3400 4000 3400
Wire Wire Line
	3650 3700 3750 3700
Wire Wire Line
	3000 1700 3000 1350
Wire Wire Line
	5550 1550 5850 1550
Wire Wire Line
	1800 3000 1800 3400
Wire Wire Line
	1800 3400 3450 3400
Wire Wire Line
	3300 3000 3300 3400
Connection ~ 3300 3400
Wire Wire Line
	4050 3700 5550 3700
Wire Wire Line
	5550 3700 5550 1550
Wire Wire Line
	3500 1700 4900 1700
Wire Wire Line
	3000 1350 5850 1350
Wire Wire Line
	4900 1450 5850 1450
Wire Wire Line
	4900 1700 4900 1450
Text HLabel 3300 1900 1    60   Input ~ 0
5V
Text HLabel 1800 1900 1    60   Input ~ 0
5V
Wire Wire Line
	5200 1250 5850 1250
Wire Wire Line
	5600 1050 5850 1050
$Comp
L ATTINY85-P IC3
U 1 1 5735BACE
P 7250 4700
F 0 "IC3" H 6100 5100 50  0000 C CNN
F 1 "ATTINY85-P" H 8250 4300 50  0000 C CNN
F 2 "Housings_DIP:DIP-8_W7.62mm" H 8250 4700 50  0000 C CIN
F 3 "" H 7250 4700 50  0000 C CNN
	1    7250 4700
	1    0    0    -1  
$EndComp
Text HLabel 5100 4650 0    60   BiDi ~ 0
SCL
$Comp
L GND #PWR019
U 1 1 5735BAD5
P 8700 5100
F 0 "#PWR019" H 8700 4850 50  0001 C CNN
F 1 "GND" H 8700 4950 50  0000 C CNN
F 2 "" H 8700 5100 50  0000 C CNN
F 3 "" H 8700 5100 50  0000 C CNN
	1    8700 5100
	1    0    0    -1  
$EndComp
$Comp
L IR_Recieve D10
U 1 1 5735BADB
P 3350 6200
F 0 "D10" H 3350 6300 50  0000 C CNN
F 1 "IR_Recieve" H 3366 6033 50  0000 C CNN
F 2 "Holes:SolderWirePad1mmmodified" H 3350 6200 50  0001 C CNN
F 3 "" H 3350 6200 50  0000 C CNN
	1    3350 6200
	0    -1   -1   0   
$EndComp
$Comp
L LED D8
U 1 1 5735BAE1
P 2950 6200
F 0 "D8" H 2950 6300 50  0000 C CNN
F 1 "LED" V 2950 6100 50  0000 C CNN
F 2 "Holes:SolderWirePad1mmmodified" H 2950 6200 50  0001 C CNN
F 3 "" H 2950 6200 50  0000 C CNN
	1    2950 6200
	0    -1   -1   0   
$EndComp
$Comp
L LED D12
U 1 1 5735BAE7
P 3750 6200
F 0 "D12" H 3750 6300 50  0000 C CNN
F 1 "LED" V 3750 6100 50  0000 C CNN
F 2 "Holes:SolderWirePad1mmmodified" H 3750 6200 50  0001 C CNN
F 3 "" H 3750 6200 50  0000 C CNN
	1    3750 6200
	0    -1   -1   0   
$EndComp
$Comp
L R R15
U 1 1 5735BAED
P 3350 5650
F 0 "R15" V 3430 5650 50  0000 C CNN
F 1 "100" V 3350 5650 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Vertical_RM5mm" V 3280 5650 50  0001 C CNN
F 3 "" H 3350 5650 50  0000 C CNN
	1    3350 5650
	1    0    0    -1  
$EndComp
$Comp
L R R17
U 1 1 5735BAF3
P 3750 5650
F 0 "R17" V 3830 5650 50  0000 C CNN
F 1 "22" V 3750 5650 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Vertical_RM5mm" V 3680 5650 50  0001 C CNN
F 3 "" H 3750 5650 50  0000 C CNN
	1    3750 5650
	1    0    0    -1  
$EndComp
$Comp
L R R13
U 1 1 5735BAF9
P 2950 5650
F 0 "R13" V 3030 5650 50  0000 C CNN
F 1 "22" V 2950 5650 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Vertical_RM5mm" V 2880 5650 50  0001 C CNN
F 3 "" H 2950 5650 50  0000 C CNN
	1    2950 5650
	1    0    0    -1  
$EndComp
Text Label 3550 5100 0    60   ~ 0
Signal
$Comp
L IR_Recieve D4
U 1 1 5735BB00
P 1850 6200
F 0 "D4" H 1850 6300 50  0000 C CNN
F 1 "IR_Recieve" H 1866 6033 50  0000 C CNN
F 2 "Holes:SolderWirePad1mmmodified" H 1850 6200 50  0001 C CNN
F 3 "" H 1850 6200 50  0000 C CNN
	1    1850 6200
	0    -1   -1   0   
$EndComp
$Comp
L LED D2
U 1 1 5735BB06
P 1450 6200
F 0 "D2" H 1450 6300 50  0000 C CNN
F 1 "LED" V 1450 6100 50  0000 C CNN
F 2 "Holes:SolderWirePad1mmmodified" H 1450 6200 50  0001 C CNN
F 3 "" H 1450 6200 50  0000 C CNN
	1    1450 6200
	0    -1   -1   0   
$EndComp
$Comp
L LED D6
U 1 1 5735BB0C
P 2250 6200
F 0 "D6" H 2250 6300 50  0000 C CNN
F 1 "LED" V 2250 6100 50  0000 C CNN
F 2 "Holes:SolderWirePad1mmmodified" H 2250 6200 50  0001 C CNN
F 3 "" H 2250 6200 50  0000 C CNN
	1    2250 6200
	0    -1   -1   0   
$EndComp
$Comp
L R R9
U 1 1 5735BB12
P 1850 5650
F 0 "R9" V 1930 5650 50  0000 C CNN
F 1 "100" V 1850 5650 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Vertical_RM5mm" V 1780 5650 50  0001 C CNN
F 3 "" H 1850 5650 50  0000 C CNN
	1    1850 5650
	1    0    0    -1  
$EndComp
$Comp
L Q_NPN_BCE Q1
U 1 1 5735BB18
P 3700 6900
F 0 "Q1" H 4000 6950 50  0000 R CNN
F 1 "Q_NPN_BCE" H 4300 6850 50  0001 R CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Narrow_Oval" H 3900 7000 50  0001 C CNN
F 3 "" H 3700 6900 50  0000 C CNN
	1    3700 6900
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR020
U 1 1 5735BB1E
P 4050 6800
F 0 "#PWR020" H 4050 6550 50  0001 C CNN
F 1 "GND" H 4050 6650 50  0000 C CNN
F 2 "" H 4050 6800 50  0000 C CNN
F 3 "" H 4050 6800 50  0000 C CNN
	1    4050 6800
	-1   0    0    1   
$EndComp
$Comp
L R R19
U 1 1 5735BB24
P 3950 7100
F 0 "R19" V 4030 7100 50  0000 C CNN
F 1 "1K" V 3950 7100 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Vertical_RM5mm" V 3880 7100 50  0001 C CNN
F 3 "" H 3950 7100 50  0000 C CNN
	1    3950 7100
	0    1    1    0   
$EndComp
$Comp
L R R11
U 1 1 5735BB2A
P 2250 5650
F 0 "R11" V 2330 5650 50  0000 C CNN
F 1 "22" V 2250 5650 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Vertical_RM5mm" V 2180 5650 50  0001 C CNN
F 3 "" H 2250 5650 50  0000 C CNN
	1    2250 5650
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 5735BB30
P 1450 5650
F 0 "R4" V 1530 5650 50  0000 C CNN
F 1 "22" V 1450 5650 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Vertical_RM5mm" V 1380 5650 50  0001 C CNN
F 3 "" H 1450 5650 50  0000 C CNN
	1    1450 5650
	1    0    0    -1  
$EndComp
Text Label 2050 5100 0    60   ~ 0
Signal
Text HLabel 5600 4450 0    60   BiDi ~ 0
SDA
Text HLabel 8600 4450 2    60   Input ~ 0
5V
Text HLabel 1450 5500 1    60   Input ~ 0
3V
Text HLabel 2250 5500 1    60   Input ~ 0
3V
Text HLabel 2950 5500 1    60   Input ~ 0
3V
Text HLabel 3750 5500 1    60   Input ~ 0
3V
Wire Wire Line
	8600 4950 8700 4950
Wire Wire Line
	8700 4950 8700 5100
Wire Wire Line
	3350 5300 3350 5500
Wire Wire Line
	3350 5800 3350 6000
Connection ~ 3350 5900
Wire Wire Line
	2950 6400 2950 6550
Wire Wire Line
	2950 6550 3750 6550
Connection ~ 3350 6550
Wire Wire Line
	3750 6550 3750 6400
Wire Wire Line
	2950 5800 2950 6000
Wire Wire Line
	3750 5800 3750 6000
Wire Wire Line
	3350 5900 3550 5900
Wire Wire Line
	3550 5900 3550 5100
Wire Wire Line
	1850 5300 1850 5500
Wire Wire Line
	1850 5800 1850 6000
Connection ~ 1850 5900
Wire Wire Line
	1450 6400 1450 6550
Wire Wire Line
	1450 6550 2250 6550
Connection ~ 1850 6550
Wire Wire Line
	2250 6550 2250 6400
Wire Wire Line
	1450 5800 1450 6000
Wire Wire Line
	2250 5800 2250 6000
Wire Wire Line
	1850 5900 2050 5900
Wire Wire Line
	2050 5900 2050 5100
Wire Wire Line
	2050 5100 3050 5100
Wire Wire Line
	3900 6800 4050 6800
Wire Wire Line
	3700 7100 3800 7100
Wire Wire Line
	3050 5100 3050 4750
Wire Wire Line
	5600 4950 5900 4950
Wire Wire Line
	1850 6400 1850 6800
Wire Wire Line
	1850 6800 3500 6800
Wire Wire Line
	3350 6400 3350 6800
Connection ~ 3350 6800
Wire Wire Line
	4100 7100 5600 7100
Wire Wire Line
	5600 7100 5600 4950
Wire Wire Line
	3550 5100 4950 5100
Wire Wire Line
	3050 4750 5900 4750
Wire Wire Line
	4950 4850 5900 4850
Wire Wire Line
	4950 5100 4950 4850
Text HLabel 3350 5300 1    60   Input ~ 0
5V
Text HLabel 1850 5300 1    60   Input ~ 0
5V
Wire Wire Line
	5300 4650 5900 4650
Wire Wire Line
	5600 4450 5900 4450
$Comp
L CONN_02X03 P6
U 1 1 5735BDC8
P 9050 2950
F 0 "P6" H 9050 3150 50  0000 C CNN
F 1 "CONN_02X03" H 9050 2750 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x03" H 9050 1750 50  0001 C CNN
F 3 "" H 9050 1750 50  0000 C CNN
	1    9050 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	9300 3050 9300 5700
Wire Wire Line
	9300 5700 5850 5700
Wire Wire Line
	5850 5700 5850 4950
Connection ~ 5850 4950
Wire Wire Line
	9300 3850 5750 3850
Wire Wire Line
	5750 3850 5750 1550
Connection ~ 5750 1550
Connection ~ 9300 3850
$Comp
L GND #PWR021
U 1 1 5735C5A5
P 9300 2950
F 0 "#PWR021" H 9300 2700 50  0001 C CNN
F 1 "GND" H 9300 2800 50  0000 C CNN
F 2 "" H 9300 2950 50  0000 C CNN
F 3 "" H 9300 2950 50  0000 C CNN
	1    9300 2950
	0    -1   -1   0   
$EndComp
NoConn ~ 9300 2850
Wire Wire Line
	5500 1250 5500 3050
Wire Wire Line
	5500 3050 8800 3050
Wire Wire Line
	5650 4650 5650 3050
Connection ~ 5650 3050
Connection ~ 5650 4650
Connection ~ 5500 1250
$Comp
L CONN_01X02 P3
U 1 1 5735D811
P 5150 1050
F 0 "P3" H 5150 1200 50  0000 C CNN
F 1 "CONN_01X02" V 5250 1050 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x01" H 5150 1050 50  0001 C CNN
F 3 "" H 5150 1050 50  0000 C CNN
	1    5150 1050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5100 1250 4950 1250
$Comp
L CONN_01X02 P4
U 1 1 5735DC6A
P 5250 4450
F 0 "P4" H 5250 4600 50  0000 C CNN
F 1 "CONN_01X02" V 5350 4450 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x01" H 5250 4450 50  0001 C CNN
F 3 "" H 5250 4450 50  0000 C CNN
	1    5250 4450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5200 4650 5100 4650
$Comp
L CONN_02X04 P5
U 1 1 5735F18B
P 7450 2600
F 0 "P5" H 7450 2850 50  0000 C CNN
F 1 "CONN_02X04" H 7450 2350 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04" H 7450 1400 50  0001 C CNN
F 3 "" H 7450 1400 50  0000 C CNN
	1    7450 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	8800 2850 8800 2500
Wire Wire Line
	8800 2500 8000 2500
Wire Wire Line
	8000 2450 8000 2550
Wire Wire Line
	8000 2450 7700 2450
Wire Wire Line
	8000 2550 7700 2550
Connection ~ 8000 2500
Wire Wire Line
	8800 2950 8650 2950
Wire Wire Line
	8650 2950 8650 2700
Wire Wire Line
	8650 2700 8000 2700
Wire Wire Line
	8000 2650 8000 2750
Wire Wire Line
	8000 2650 7700 2650
Wire Wire Line
	8000 2750 7700 2750
Connection ~ 8000 2700
Wire Wire Line
	7200 2450 7200 2000
Wire Wire Line
	7200 2000 9600 2000
Wire Wire Line
	9600 2000 9600 700 
Wire Wire Line
	9600 700  5700 700 
Wire Wire Line
	5700 700  5700 1050
Connection ~ 5700 1050
Wire Wire Line
	7200 2550 5850 2550
Wire Wire Line
	5850 2550 5850 4450
Connection ~ 5850 4450
Wire Wire Line
	7200 2650 5650 2650
Wire Wire Line
	5650 2650 5650 1150
Wire Wire Line
	5650 1150 5850 1150
Wire Wire Line
	7200 2750 5700 2750
Wire Wire Line
	5700 2750 5700 4550
Wire Wire Line
	5700 4550 5900 4550
Wire Wire Line
	8650 1700 8650 1550
Wire Wire Line
	8650 1550 8550 1550
$EndSCHEMATC
