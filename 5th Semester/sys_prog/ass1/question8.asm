.model small
.stack 100h
.data
msg1 db ' IS GREATEST IS $'
msg2 db ' IS SMALLEST IS $'
array db 4,2,3,1
.code
main proc
mov ax, @data
mov ds, ax
mov si, offset array
mov cx, 4
mov bl, 0
L1:
mov dx, [si]
cmp bl, dx
jg L2
mov bl, dx
L2:
inc si
LOOP L1
mov dx, bl
add dx, 48
mov ah, 2
int 21h
mov dx, offset msg1
mov ah, 9
int 21h
mov si, offset array
mov cx, 4

L3:
mov dx, [si]
cmp bl, dx
jle L4
mov bl, dx
L4:
inc si
LOOP L3
mov dx, bl
add dx, 48
mov ah, 2
int 21h
mov dx, offset msg2
mov ah, 9
int 21h
mov ah, 4ch
int 21h
main endp
end main
