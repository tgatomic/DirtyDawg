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
Sheet 3 7
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
L ATTINY85-P IC?
U 1 1 57175B9E
P 7100 1650
F 0 "IC?" H 5950 2050 50  0000 C CNN
F 1 "ATTINY85-P" H 8100 1250 50  0000 C CNN
F 2 "DIP8" H 8100 1650 50  0000 C CIN
F 3 "" H 7100 1650 50  0000 C CNN
	1    7100 1650
	1    0    0    -1  
$EndComp
Text HLabel 5750 1600 0    60   BiDi ~ 0
SCL
$Comp
L GND #PWR?
U 1 1 57175BA8
P 8550 2050
F 0 "#PWR?" H 8550 1800 50  0001 C CNN
F 1 "GND" H 8550 1900 50  0000 C CNN
F 2 "" H 8550 2050 50  0000 C CNN
F 3 "" H 8550 2050 50  0000 C CNN
	1    8550 2050
	1    0    0    -1  
$EndComp
$Comp
L IR_Recieve D?
U 1 1 57175BAE
P 3200 3150
F 0 "D?" H 3200 3250 50  0000 C CNN
F 1 "IR_Recieve" H 3216 2983 50  0000 C CNN
F 2 "" H 3200 3150 50  0000 C CNN
F 3 "" H 3200 3150 50  0000 C CNN
	1    3200 3150
	0    -1   -1   0   
$EndComp
$Comp
L LED D?
U 1 1 57175BB4
P 2800 3150
F 0 "D?" H 2800 3250 50  0000 C CNN
F 1 "LED" V 2800 3050 50  0000 C CNN
F 2 "" H 2800 3150 50  0000 C CNN
F 3 "" H 2800 3150 50  0000 C CNN
	1    2800 3150
	0    -1   -1   0   
$EndComp
$Comp
L LED D?
U 1 1 57175BBA
P 3600 3150
F 0 "D?" H 3600 3250 50  0000 C CNN
F 1 "LED" V 3600 3050 50  0000 C CNN
F 2 "" H 3600 3150 50  0000 C CNN
F 3 "" H 3600 3150 50  0000 C CNN
	1    3600 3150
	0    -1   -1   0   
$EndComp
$Comp
L R R?
U 1 1 57175BC0
P 3200 2600
F 0 "R?" V 3280 2600 50  0000 C CNN
F 1 "100" V 3200 2600 50  0000 C CNN
F 2 "" V 3130 2600 50  0000 C CNN
F 3 "" H 3200 2600 50  0000 C CNN
	1    3200 2600
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 57175BE1
P 3600 2600
F 0 "R?" V 3680 2600 50  0000 C CNN
F 1 "22" V 3600 2600 50  0000 C CNN
F 2 "" V 3530 2600 50  0000 C CNN
F 3 "" H 3600 2600 50  0000 C CNN
	1    3600 2600
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 57175BE7
P 2800 2600
F 0 "R?" V 2880 2600 50  0000 C CNN
F 1 "22" V 2800 2600 50  0000 C CNN
F 2 "" V 2730 2600 50  0000 C CNN
F 3 "" H 2800 2600 50  0000 C CNN
	1    2800 2600
	1    0    0    -1  
$EndComp
Text Label 3400 2050 0    60   ~ 0
Signal
$Comp
L IR_Recieve D?
U 1 1 57175BF9
P 1700 3150
F 0 "D?" H 1700 3250 50  0000 C CNN
F 1 "IR_Recieve" H 1716 2983 50  0000 C CNN
F 2 "" H 1700 3150 50  0000 C CNN
F 3 "" H 1700 3150 50  0000 C CNN
	1    1700 3150
	0    -1   -1   0   
$EndComp
$Comp
L LED D?
U 1 1 57175BFF
P 1300 3150
F 0 "D?" H 1300 3250 50  0000 C CNN
F 1 "LED" V 1300 3050 50  0000 C CNN
F 2 "" H 1300 3150 50  0000 C CNN
F 3 "" H 1300 3150 50  0000 C CNN
	1    1300 3150
	0    -1   -1   0   
$EndComp
$Comp
L LED D?
U 1 1 57175C05
P 2100 3150
F 0 "D?" H 2100 3250 50  0000 C CNN
F 1 "LED" V 2100 3050 50  0000 C CNN
F 2 "" H 2100 3150 50  0000 C CNN
F 3 "" H 2100 3150 50  0000 C CNN
	1    2100 3150
	0    -1   -1   0   
$EndComp
$Comp
L R R?
U 1 1 57175C0B
P 1700 2600
F 0 "R?" V 1780 2600 50  0000 C CNN
F 1 "100" V 1700 2600 50  0000 C CNN
F 2 "" V 1630 2600 50  0000 C CNN
F 3 "" H 1700 2600 50  0000 C CNN
	1    1700 2600
	1    0    0    -1  
$EndComp
$Comp
L Q_NPN_BCE Q?
U 1 1 57175C18
P 3550 3850
F 0 "Q?" H 3850 3900 50  0000 R CNN
F 1 "Q_NPN_BCE" H 4150 3800 50  0001 R CNN
F 2 "" H 3750 3950 50  0000 C CNN
F 3 "" H 3550 3850 50  0000 C CNN
	1    3550 3850
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR?
U 1 1 57175C1F
P 3900 3750
F 0 "#PWR?" H 3900 3500 50  0001 C CNN
F 1 "GND" H 3900 3600 50  0000 C CNN
F 2 "" H 3900 3750 50  0000 C CNN
F 3 "" H 3900 3750 50  0000 C CNN
	1    3900 3750
	-1   0    0    1   
$EndComp
$Comp
L R R?
U 1 1 57175C25
P 3800 4050
F 0 "R?" V 3880 4050 50  0000 C CNN
F 1 "1K" V 3800 4050 50  0000 C CNN
F 2 "" V 3730 4050 50  0000 C CNN
F 3 "" H 3800 4050 50  0000 C CNN
	1    3800 4050
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 57175C2C
P 2100 2600
F 0 "R?" V 2180 2600 50  0000 C CNN
F 1 "22" V 2100 2600 50  0000 C CNN
F 2 "" V 2030 2600 50  0000 C CNN
F 3 "" H 2100 2600 50  0000 C CNN
	1    2100 2600
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 57175C32
P 1300 2600
F 0 "R?" V 1380 2600 50  0000 C CNN
F 1 "22" V 1300 2600 50  0000 C CNN
F 2 "" V 1230 2600 50  0000 C CNN
F 3 "" H 1300 2600 50  0000 C CNN
	1    1300 2600
	1    0    0    -1  
$EndComp
Text Label 1900 2050 0    60   ~ 0
Signal
Text HLabel 5750 1400 0    60   BiDi ~ 0
SDA
Text HLabel 8950 1400 2    60   Input ~ 0
5V
Text HLabel 1300 2450 1    60   Input ~ 0
3V
Text HLabel 2100 2450 1    60   Input ~ 0
3V
Text HLabel 2800 2450 1    60   Input ~ 0
3V
Text HLabel 3600 2450 1    60   Input ~ 0
3V
$Comp
L ATTINY85-P IC?
U 1 1 5718B309
P 7100 4700
F 0 "IC?" H 5950 5100 50  0000 C CNN
F 1 "ATTINY85-P" H 8100 4300 50  0000 C CNN
F 2 "DIP8" H 8100 4700 50  0000 C CIN
F 3 "" H 7100 4700 50  0000 C CNN
	1    7100 4700
	1    0    0    -1  
$EndComp
Text HLabel 5750 4650 0    60   BiDi ~ 0
SCL
$Comp
L GND #PWR?
U 1 1 5718B310
P 8550 5100
F 0 "#PWR?" H 8550 4850 50  0001 C CNN
F 1 "GND" H 8550 4950 50  0000 C CNN
F 2 "" H 8550 5100 50  0000 C CNN
F 3 "" H 8550 5100 50  0000 C CNN
	1    8550 5100
	1    0    0    -1  
$EndComp
$Comp
L IR_Recieve D?
U 1 1 5718B316
P 3200 6200
F 0 "D?" H 3200 6300 50  0000 C CNN
F 1 "IR_Recieve" H 3216 6033 50  0000 C CNN
F 2 "" H 3200 6200 50  0000 C CNN
F 3 "" H 3200 6200 50  0000 C CNN
	1    3200 6200
	0    -1   -1   0   
$EndComp
$Comp
L LED D?
U 1 1 5718B31C
P 2800 6200
F 0 "D?" H 2800 6300 50  0000 C CNN
F 1 "LED" V 2800 6100 50  0000 C CNN
F 2 "" H 2800 6200 50  0000 C CNN
F 3 "" H 2800 6200 50  0000 C CNN
	1    2800 6200
	0    -1   -1   0   
$EndComp
$Comp
L LED D?
U 1 1 5718B322
P 3600 6200
F 0 "D?" H 3600 6300 50  0000 C CNN
F 1 "LED" V 3600 6100 50  0000 C CNN
F 2 "" H 3600 6200 50  0000 C CNN
F 3 "" H 3600 6200 50  0000 C CNN
	1    3600 6200
	0    -1   -1   0   
$EndComp
$Comp
L R R?
U 1 1 5718B328
P 3200 5650
F 0 "R?" V 3280 5650 50  0000 C CNN
F 1 "100" V 3200 5650 50  0000 C CNN
F 2 "" V 3130 5650 50  0000 C CNN
F 3 "" H 3200 5650 50  0000 C CNN
	1    3200 5650
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5718B32E
P 3600 5650
F 0 "R?" V 3680 5650 50  0000 C CNN
F 1 "22" V 3600 5650 50  0000 C CNN
F 2 "" V 3530 5650 50  0000 C CNN
F 3 "" H 3600 5650 50  0000 C CNN
	1    3600 5650
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5718B334
P 2800 5650
F 0 "R?" V 2880 5650 50  0000 C CNN
F 1 "22" V 2800 5650 50  0000 C CNN
F 2 "" V 2730 5650 50  0000 C CNN
F 3 "" H 2800 5650 50  0000 C CNN
	1    2800 5650
	1    0    0    -1  
$EndComp
Text Label 3400 5100 0    60   ~ 0
Signal
$Comp
L IR_Recieve D?
U 1 1 5718B33B
P 1700 6200
F 0 "D?" H 1700 6300 50  0000 C CNN
F 1 "IR_Recieve" H 1716 6033 50  0000 C CNN
F 2 "" H 1700 6200 50  0000 C CNN
F 3 "" H 1700 6200 50  0000 C CNN
	1    1700 6200
	0    -1   -1   0   
$EndComp
$Comp
L LED D?
U 1 1 5718B341
P 1300 6200
F 0 "D?" H 1300 6300 50  0000 C CNN
F 1 "LED" V 1300 6100 50  0000 C CNN
F 2 "" H 1300 6200 50  0000 C CNN
F 3 "" H 1300 6200 50  0000 C CNN
	1    1300 6200
	0    -1   -1   0   
$EndComp
$Comp
L LED D?
U 1 1 5718B347
P 2100 6200
F 0 "D?" H 2100 6300 50  0000 C CNN
F 1 "LED" V 2100 6100 50  0000 C CNN
F 2 "" H 2100 6200 50  0000 C CNN
F 3 "" H 2100 6200 50  0000 C CNN
	1    2100 6200
	0    -1   -1   0   
$EndComp
$Comp
L R R?
U 1 1 5718B34D
P 1700 5650
F 0 "R?" V 1780 5650 50  0000 C CNN
F 1 "100" V 1700 5650 50  0000 C CNN
F 2 "" V 1630 5650 50  0000 C CNN
F 3 "" H 1700 5650 50  0000 C CNN
	1    1700 5650
	1    0    0    -1  
$EndComp
$Comp
L Q_NPN_BCE Q?
U 1 1 5718B353
P 3550 6900
F 0 "Q?" H 3850 6950 50  0000 R CNN
F 1 "Q_NPN_BCE" H 4150 6850 50  0001 R CNN
F 2 "" H 3750 7000 50  0000 C CNN
F 3 "" H 3550 6900 50  0000 C CNN
	1    3550 6900
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR?
U 1 1 5718B359
P 3900 6800
F 0 "#PWR?" H 3900 6550 50  0001 C CNN
F 1 "GND" H 3900 6650 50  0000 C CNN
F 2 "" H 3900 6800 50  0000 C CNN
F 3 "" H 3900 6800 50  0000 C CNN
	1    3900 6800
	-1   0    0    1   
$EndComp
$Comp
L R R?
U 1 1 5718B35F
P 3800 7100
F 0 "R?" V 3880 7100 50  0000 C CNN
F 1 "1K" V 3800 7100 50  0000 C CNN
F 2 "" V 3730 7100 50  0000 C CNN
F 3 "" H 3800 7100 50  0000 C CNN
	1    3800 7100
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 5718B365
P 2100 5650
F 0 "R?" V 2180 5650 50  0000 C CNN
F 1 "22" V 2100 5650 50  0000 C CNN
F 2 "" V 2030 5650 50  0000 C CNN
F 3 "" H 2100 5650 50  0000 C CNN
	1    2100 5650
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5718B36B
P 1300 5650
F 0 "R?" V 1380 5650 50  0000 C CNN
F 1 "22" V 1300 5650 50  0000 C CNN
F 2 "" V 1230 5650 50  0000 C CNN
F 3 "" H 1300 5650 50  0000 C CNN
	1    1300 5650
	1    0    0    -1  
$EndComp
Text Label 1900 5100 0    60   ~ 0
Signal
Text HLabel 5750 4450 0    60   BiDi ~ 0
SDA
Text HLabel 8950 4450 2    60   Input ~ 0
5V
Text HLabel 1300 5500 1    60   Input ~ 0
3V
Text HLabel 2100 5500 1    60   Input ~ 0
3V
Text HLabel 2800 5500 1    60   Input ~ 0
3V
Text HLabel 3600 5500 1    60   Input ~ 0
3V
$Sheet
S 9550 4950 950  950 
U 5718B39F
F0 "OpAmp" 60
F1 "OpAmp.sch" 60
F2 "SignalIn(A)" I L 9550 5100 60 
F3 "SignaOut(A)" O R 10500 5250 60 
F4 "9V" I R 10500 5800 60 
F5 "SignaOut(B)" O R 10500 5400 60 
F6 "SignalIn(B)" I L 9550 5550 60 
$EndSheet
Wire Wire Line
	8950 1400 8450 1400
Wire Wire Line
	8450 1900 8550 1900
Wire Wire Line
	8550 1900 8550 2050
Wire Wire Line
	3200 2250 3200 2450
Wire Wire Line
	3200 2750 3200 2950
Connection ~ 3200 2850
Wire Wire Line
	2800 3350 2800 3500
Wire Wire Line
	2800 3500 3600 3500
Connection ~ 3200 3500
Wire Wire Line
	3600 3500 3600 3350
Wire Wire Line
	2800 2750 2800 2950
Wire Wire Line
	3600 2750 3600 2950
Wire Wire Line
	3200 2850 3400 2850
Wire Wire Line
	3400 2850 3400 2050
Wire Wire Line
	1700 2250 1700 2450
Wire Wire Line
	1700 2750 1700 2950
Connection ~ 1700 2850
Wire Wire Line
	1300 3350 1300 3500
Wire Wire Line
	1300 3500 2100 3500
Connection ~ 1700 3500
Wire Wire Line
	2100 3500 2100 3350
Wire Wire Line
	1300 2750 1300 2950
Wire Wire Line
	2100 2750 2100 2950
Wire Wire Line
	1700 2850 1900 2850
Wire Wire Line
	1900 2850 1900 2050
Wire Wire Line
	1900 2050 2900 2050
Wire Wire Line
	3750 3750 3900 3750
Wire Wire Line
	3550 4050 3650 4050
Wire Wire Line
	2900 2050 2900 1700
Wire Wire Line
	5450 1900 5750 1900
Wire Wire Line
	1700 3350 1700 3750
Wire Wire Line
	1700 3750 3350 3750
Wire Wire Line
	3200 3350 3200 3750
Connection ~ 3200 3750
Wire Wire Line
	3950 4050 5450 4050
Wire Wire Line
	5450 4050 5450 1900
Wire Wire Line
	3400 2050 4800 2050
Wire Wire Line
	2900 1700 5750 1700
Wire Wire Line
	4800 1800 5750 1800
Wire Wire Line
	8950 4450 8450 4450
Wire Wire Line
	8450 4950 8550 4950
Wire Wire Line
	8550 4950 8550 5100
Wire Wire Line
	3200 5300 3200 5500
Wire Wire Line
	3200 5800 3200 6000
Connection ~ 3200 5900
Wire Wire Line
	2800 6400 2800 6550
Wire Wire Line
	2800 6550 3600 6550
Connection ~ 3200 6550
Wire Wire Line
	3600 6550 3600 6400
Wire Wire Line
	2800 5800 2800 6000
Wire Wire Line
	3600 5800 3600 6000
Wire Wire Line
	3200 5900 3400 5900
Wire Wire Line
	3400 5900 3400 5100
Wire Wire Line
	1700 5300 1700 5500
Wire Wire Line
	1700 5800 1700 6000
Connection ~ 1700 5900
Wire Wire Line
	1300 6400 1300 6550
Wire Wire Line
	1300 6550 2100 6550
Connection ~ 1700 6550
Wire Wire Line
	2100 6550 2100 6400
Wire Wire Line
	1300 5800 1300 6000
Wire Wire Line
	2100 5800 2100 6000
Wire Wire Line
	1700 5900 1900 5900
Wire Wire Line
	1900 5900 1900 5100
Wire Wire Line
	1900 5100 2900 5100
Wire Wire Line
	3750 6800 3900 6800
Wire Wire Line
	3550 7100 3650 7100
Wire Wire Line
	2900 5100 2900 4750
Wire Wire Line
	5450 4950 5750 4950
Wire Wire Line
	1700 6400 1700 6800
Wire Wire Line
	1700 6800 3350 6800
Wire Wire Line
	3200 6400 3200 6800
Connection ~ 3200 6800
Wire Wire Line
	3950 7100 5450 7100
Wire Wire Line
	5450 7100 5450 4950
Wire Wire Line
	3400 5100 3800 5100
Wire Wire Line
	2900 4750 5750 4750
Wire Wire Line
	3800 4850 5750 4850
Wire Wire Line
	3800 5100 3800 4850
Wire Wire Line
	4800 2050 4800 1800
Text HLabel 3200 2250 1    60   Input ~ 0
5V
Text HLabel 1700 2250 1    60   Input ~ 0
5V
Text HLabel 1700 5300 1    60   Input ~ 0
5V
Text HLabel 3200 5300 1    60   Input ~ 0
5V
$EndSCHEMATC
