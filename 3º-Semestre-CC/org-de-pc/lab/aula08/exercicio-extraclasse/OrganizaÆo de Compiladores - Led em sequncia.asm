;************************************************************ 
; Processor: PIC16F628 at 4 MHz using internal RC oscillator 
; Function:  Flash a LED connected to RA2 
; Hardware:  Testboard K4 
; Filename:  628LED.asm 
; Author:    Lars Petersen, oz1bxm@pobox.com 
; Website:   www.qsl.net/oz1bxm/PIC/pic.htm 
; Credit:    Tony Nixon's LED flasher 
;************************************************************ 

;Nome: Matheus Soares Santos     TIA: 31895263
;Professor, fiz o código pelo compilador online, então tive que alterar algumas coisas, como as definições do PIC


Loop1 EQU 0x020
Loop2 EQU 0x020

; 
; ----------- 
; INITIALIZE 
; ----------- 
; 
        ORG    0x000           ; Program starts at 0x000 
 
        CLRF   PORTA           ; Initialize port A 
        CLRF   PORTB           ; Initialize port B 
 
        BSF    STATUS,RP0      ; RAM bank 1 
 
        CLRF   TRISA           ; All pins port A output 
        CLRF   TRISB           ; All pins port B output 

        BCF    STATUS,RP0      ; RAM bank 0 
; 
; ------------------------ 
; FUNCTION OF PORT A PINS 
; ------------------------ 
; 
        MOVLW    7 
        MOVWF    CMCON         ; Comparators off, all pins digital I/O 
; 
; ---------- 
; MAIN LOOP 
; ---------- 
; 
Main     
        BSF     PORTA, 0      ; Liga o LED da porta 0 A
        CALL    delay 
        BCF     PORTA, 0      ; Desliga o LED da porta 0 A
        BSF     PORTA, 1      ; Liga o LED da porta 1 A
        CALL    delay
        BCF     PORTA, 1      ; Desliga o LED da porta 1 A
        BSF     PORTA, 2      ; Liga o LED da porta 2 A
        CALL    delay
        BCF     PORTA, 2      ; Desliga o LED da porta 2 A
        BSF     PORTA, 3      ; Liga o LED da porta 3 A
        CALL    delay 
        BCF     PORTA, 3      ; Desliga o LED da porta 3 A
        BSF     PORTA, 4      ; Liga o LED da porta 4 A
        CALL    delay
        BCF     PORTA, 4      ; Desliga o LED da porta 4 A
        BSF     PORTA, 5      ; Liga o LED da porta 5 A
        CALL    delay
        BCF     PORTA, 5      ; Desliga o LED da porta 5 A
        BSF     PORTA, 6      ; Liga o LED da porta 6 A
        CALL    delay
        BCF     PORTA, 6      ; Desliga o LED da porta 6 A
        BSF     PORTA, 7      ; Liga o LED da porta 7 A
        CALL    delay
	BST     PORTB, 0      ; Liga o LED da porta 0 B
        BCF     PORTA, 7      ; Desliga o LED da porta 7 A
        CALL    delay
	BCL     PORTB, 0      ; Desliga o LED da porta 0 B 
        BST     PORTB, 1      ; Liga o LED da porta 1 B
	CALL    delay 
	BCL     PORTB, 1      ; Desliga o LED da porta 1 B 
        BST     PORTB, 2      ; Liga o LED da porta 2 B
	CALL    delay 
	BCL     PORTB, 2      ; Desliga o LED da porta 2 B 
        BST     PORTB, 3      ; Liga o LED da porta 3 B
	CALL    delay 
	BCL     PORTB, 3      ; Desliga o LED da porta 3 B 
        BST     PORTB, 4      ; Liga o LED da porta 4 B
	CALL    delay 
	BCL     PORTB, 4      ; Desliga o LED da porta 4 B 
        BST     PORTB, 5      ; Liga o LED da porta 5 B
	CALL    delay 
	BCL     PORTB, 5      ; Desliga o LED da porta 5 B 
        BST     PORTB, 6      ; Liga o LED da porta 6 B
	CALL    delay 
	BCL     PORTB, 6      ; Desliga o LED da porta 6 B 
        BST     PORTB, 7      ; Liga o LED da porta 7 B
	CALL    delay 
	BCL     PORTB, 7      ; Desliga o LED da porta 7 B 
  	CALL    delay 
        GOTO    Main 
; 
; --------------- 
; DELAY 250 MSEC 
; --------------- 
; 
delay   
        MOVLW   D'250' 
        MOVWF   Loop1 
Outer   
        MOVLW   D'200' 
        MOVWF   Loop2 
Inner   
        NOP 
        NOP 
        DECFSZ  Loop2,F 
        GOTO    Inner          ; Inner loop = 5 usec. 
        DECFSZ  Loop1,F 
        GOTO    Outer 
        RETURN 
