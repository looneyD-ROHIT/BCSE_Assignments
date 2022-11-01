	   LXI H,2050	// Load into HL pair
	   MOV B,M	// Copy to B
	   LXI H,2051	// Load into HL pair
	   MOV D,M	// Copy to D
	   MVI A,00	// Make Acc zero
	   MVI C,00	// Make C zero

LOOP:	   ADD D	// Multiply using repetiitve addition
	   JNC SKIP	// If no carry is generated skip
	   INR C	// Increment c

SKIP:	   DCR B	//Decrement B
	   JNZ LOOP	//If Z != 0 jump to loop
	   STA 2052	//Store result
	   MOV A,C	//Copy c to acc
	   STA 2053	//Store result
	   HLT
