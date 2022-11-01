; Write and test a program to add and subtract two 16 bit numbers

dosseg
.model small
.stack 100h
.data
.code
mainp proc
mov dx, 256
add dx, 347

mov ax, 9
int 21h

mov ax, 4ch
int 21h

main endp
end main