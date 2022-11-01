;<write a assembly code in 8085 to add two nos.>

LXI H, 2500H
LDA #1
STA M
LDA #2
STA M+1
LDA M
ADC M+1
STA M
LDA M
STA M+1
LDA M
STA M+1
LDA M
STA M+1
LDA M
STA M+1
LDA M
