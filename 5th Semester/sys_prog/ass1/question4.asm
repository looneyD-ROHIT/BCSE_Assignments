TITLE	PROG4 {EXE}	Find second max and second min from an array of numbers
;------------------------------------
	.MODEL	SMALL
	.STACK
;------------------------------------
	.DATA
INPTMSG	DB	"Enter Array of elements: ", "$"
OUTMX	DB	"Second Max number is -> ", "$"
OUTMN	DB	09H, "Second Min number is -> ", "$"

MAX	DW	0FFFFH
SMAX	DW	0FFFFH
MIN	DW	7FFFH
SMIN	DW	7FFFH
;------------------------------------
	.CODE
MAIN	PROC	FAR
	MOV	AX,@data		; Initialize segment registers
	MOV	DS,AX

	MOV	AH,09H
	LEA 	DX,INPTMSG		; Display input prompt
	INT 	21H
INPTLOOP:
	CALL	INPT			; Request input
	
	CMP 	DX,MAX			; Check if number > max
	JLE	CONT1
	MOV	BX,MAX
	MOV	SMAX,BX			; Update second max
	MOV	MAX,DX			; Update max
	JMP	CONT2
CONT1:	
	CMP	DX,SMAX
	JLE	CONT2
	MOV	SMAX,DX

CONT2:	
	CMP	DX,MIN			; Check if number < min
	JGE	CONT3
	MOV	BX,MIN
	MOV	SMIN,BX			; Update second min
	MOV	MIN,DX			; Update min
	JMP	CONT4

CONT3:	CMP	DX,SMIN
	JGE	CONT4
	MOV	SMIN,DX

CONT4:
	CMP	AL,0DH			; Check if Enter
	JE	DISP
	CMP	AL,0AH			; Check if Linefeed
	JNE	INPTLOOP

DISP:
	LEA	DX,OUTMX
	MOV	AH,09H			; Display output message
	INT 	21H
	MOV	BX,SMAX	
	CALL	OUTPT			; Display second max number
	LEA	DX,OUTMN
	MOV	AH,09H			; Display output message
	INT 	21H
	MOV	BX,SMIN
	CALL	OUTPT			; Display second min number
		
TATA:
	MOV	AH,4CH			; Terminate
	INT 	21H

MAIN	ENDP

;	Accept input of number
;	----------------------
INPT	PROC	NEAR
	MOV 	DX,0000H
	MOV	CL,4
GETCH:
	MOV 	AH,01H			; Request character input
    	INT 	21H
	CMP 	AL,' '			; Check if Space
	JE 	DONE
	CMP	AL,0DH			; Check if Linefeed
	JE	DONE
	CMP	AL,0AH			; Check if Enter
	JE	DONE

	SHL 	DX,CL 			; Left shift 4 bits
	SUB 	AL,48 			; Find the numerical value from character
	CMP 	AL,9
	JLE 	ISNUM   		; Check if 0-9 or A-F
	SUB 	AL,7  			; for A-F