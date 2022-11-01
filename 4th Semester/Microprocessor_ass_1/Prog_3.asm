	   LXI H,2500
	   MOV A,M
	   ANI 0F
	   MOV B,A
	   MOV A,M
	   RRC
	   RRC
	   RRC
	   RRC
	   ANI 0F
	   ADD B
	   STA 2550
	   HLT
