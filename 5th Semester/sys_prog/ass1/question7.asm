.model small
.stack 100h
.data
msg1 db 'Second number is greater than first number$'
msg2 db 'Second number is less than or equal first number$'
.code
main proc
mov ax, @data
mov ds, ax

; mov ah 1h
; INT 21h

; mov dl, al
mov dl, 5

mov ah, 1h
int 21h
cmp al, dl

jle Label
mov dx, offset msg1
mov ah, 9
int 21h

mov ah, 4ch
int 21h

Label:
mov dx, offset msg2
mov ah, 09h
int 21h

mov ah, 4ch
int 21h
main endp
end main
