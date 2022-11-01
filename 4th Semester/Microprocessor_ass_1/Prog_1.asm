	   LXI H,2200
	   MOV B,M
	   INX H
	   MOV A,M
	   ADD B
	   STA 2202
	   MVI A,00
	   ADC A
	   STA 2203
	   HLT
