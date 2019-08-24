.data
a: .word 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16

b:  .word 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26

c:.word 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31

.text
la $s0,a
la $s1,b
la $s2,c
#i
lw $t1,96($s1) #atenção, como word, a posição 25 do vetor é (4*25)-4
add $s0,$t1,$s2

#iii
la $s0,a
la $s1,b
la $s2,c
lw $t0, 56($s0)  #atenção, como word, a posição 15 do vetor é  (4*15)-4
lw $t2,116($s2)  #atenção, como word, a posição 30 do vetor é (4*30)-4
sub $s1,$t0,$t2

#iii
#iii
#Deixo pra vocês :)

