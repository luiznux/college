;************************************************************ 
; Processor: PIC16F628 at 4 MHz using internal RC oscillator 
; Function:  Flash a LED connected to RA2 
; Hardware:  Testboard K4 
; Filename:  628LED.asm 
; Author:    Lars Petersen, oz1bxm@pobox.com 
; Website:   www.qsl.net/oz1bxm/PIC/pic.htm 
; Credit:    Tony Nixon's LED flasher 
;************************************************************ 

        LIST P=16F628A, R=DEC    ; Use the PIC16F628 and decimal system 

        #include <P16F628A.INC>  ; Include header file 

        __config  _INTRC_OSC_NOCLKOUT & _LVP_OFF & _WDT_OFF & _PWRTE_ON & _BODEN_ON 

        CBLOCK 0x20             ; Declare variable addresses starting at 0x20
          Loop1,Loop2 
        ENDC 
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
Main    BSF     PORTA, 0      ; Turn on LED connected to RA0 
        CALL    delay
        BCF     PORTA, 0        ; Turn off LED connected to RA0  
	BSF     PORTA, 1      ; Turn on LED connected to RA1 
        CALL    delay 
        BCF     PORTA, 1        ; Turn off LED connected to RA1
	BSF     PORTA, 2      ; Turn on LED connected to RA2 
        CALL    delay 
        BCF     PORTA, 2        ; Turn off LED connected to RA2
	BSF     PORTA, 3      ; Turn on LED connected to RA3
        CALL    delay 
        BCF     PORTA, 3        ; Turn off LED connected to RA3
	BSF     PORTA, 4      ; Turn on LED connected to RA4 
        CALL    delay 
        BCF     PORTA, 4        ; Turn off LED connected to RA4
	BSF     PORTA, 5      ; Turn on LED connected to RA5
        CALL    delay 
        BCF     PORTA, 5        ; Turn off LED connected to RA5
	BSF     PORTA, 6      ; Turn on LED connected to RA6
        CALL    delay 
        BCF     PORTA, 6        ; Turn off LED connected to RA6
	BSF     PORTA, 7      ; Turn on LED connected to RA7
        CALL    delay 
        BCF     PORTA, 7        ; Turn off LED connected to RA7
	BSF     PORTB, 0      ; Turn on LED connected to RA0
        CALL    delay
        BCF     PORTB, 0        ; Turn off LED connected to RA0
	BSF     PORTB, 1      ; Turn on LED connected to RA1
        CALL    delay 
        BCF     PORTB, 1        ; Turn off LED connected to RA1
	BSF     PORTB, 2      ; Turn on LED connected to RA2
        CALL    delay 
        BCF     PORTB, 2        ; Turn off LED connected to RA2
	BSF     PORTB, 3      ; Turn on LED connected to RA3 
        CALL    delay 
        BCF     PORTB, 3        ; Turn off LED connected to RA3
	BSF     PORTB, 4      ; Turn on LED connected to RA4 
        CALL    delay 
        BCF     PORTB, 4        ; Turn off LED connected to RA4
	BSF     PORTB, 5      ; Turn on LED connected to RA5 
        CALL    delay 
        BCF     PORTB, 5        ; Turn off LED connected to RA5
	BSF     PORTB, 6      ; Turn on LED connected to RA6 
        CALL    delay 
        BCF     PORTB, 6        ; Turn off LED connected to RA6
	BSF     PORTB, 7      ; Turn on LED connected to RA7 
        CALL    delay 
        BCF     PORTB, 7        ; Turn off LED connected to RA7 
        GOTO    Main 
; 
; --------------- 
; DELAY 250 MSEC 
; --------------- 
; 
delay   MOVLW   250 
        MOVWF   Loop1 
Outer   MOVLW   200 
        MOVWF   Loop2 
Inner   NOP 
        NOP 
        DECFSZ  Loop2,F 
        GOTO    Inner          ; Inner loop = 5 usec. 
        DECFSZ  Loop1,F 
        GOTO    Outer 
        RETURN 

        END
 
