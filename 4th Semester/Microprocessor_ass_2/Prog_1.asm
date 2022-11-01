	   LXI H,2050
	   MOV B,M	// copy MN in b
	   LXI H,2051
	   MOV A,M	// store KL in accumulator
	   MOV C,A	// copy KL to c
	   ANI F0	// convert KL to K0
	   MOV D,A	// copy K0 to d
	   MOV A,B	// copy MN to acc
	   ANI 0F	// convert MN to 0N
	   ORA D	// Logical or contents of D and acc to get KN
	   RRC
	   RRC
	   RRC
	   RRC	// rotate by 4 bits to get NK
	   STA 2052	// stroe result in 2052
	   MOV A,C	// copy KL to acc
	   ANI 0F	// convert KL to 0L
	   MOV D,A	// copy 0L to D
	   MOV A,B	// copy MN to acc
	   ANI F0	// convert MN to M0
	   ORA D	// Logical or contents of d and acc to get ML
	   RRC
	   RRC
	   RRC
	   RRC	// rotate by 4 bits to get LM
	   STA 2053	// store result in 2053
	   HLT
