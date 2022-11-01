.model small
.stack 100h
.data
msg2 db 'Loop proceeding...$'
msg3 db 'Loop terminated!!!$'
.code
main proc
mov ax, @data
mov ds, ax

mov cx, 10



L1:
mov dx, offset msg2
mov ah, 9
int 21h

LOOP L1

mov dx, offset msg3
mov ah, 9
int 21h

mov ah, 4ch
int 21h
main endp
end main
