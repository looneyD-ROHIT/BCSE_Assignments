.model small
.stack 100h
.data
.code
main proc
mov bl, 01h
mov cl, 02h
add bl, cl
add b1, 30h
mov dl, bl
mov ah, 2
int 21h
mov ah, 4ch
int 21h
main endp
end main
