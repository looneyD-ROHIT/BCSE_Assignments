	   LXI H,2500
	   MOV A,M
	   MVI C,08

LOOP:	   RLC
	   JC SKIP
	   INR B

SKIP:	   DCR C
	   JNZ LOOP
	   MOV A,B
	   STA 2511
	   MVI A,08
	   SUB B
	   STA 2610
	   HLT
