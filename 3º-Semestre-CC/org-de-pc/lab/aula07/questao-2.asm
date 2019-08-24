#NOMES: BRUNO SEVERO 41781619, LUIZ FERNANDO 31861806

.data
a: .float 1.0, 2.0, 3.0, 4.0, 5.0

.text
li $a0, 0
li $a1, 16
jal sum
add.s $f7, $f7, $f8
j EXIT	
sum: addi $sp, $sp, -12
       swc1 $f0, 8($sp)
       swc1 $f1, 4($sp)
       swc1 $f2, 0($sp)
       for	beq $a0, $a1, DIVI
		l.s $f0, a($sp)
		add.s $f1, $f1, $f0
 		addi $t2, $t2, 1
		addi $a0, $a0, 4
       j for
       DIVI:
		div.v $f12, $f1, $f2
		l.s $f0, 8($sp)
		l.s $f1, 4($sp)
		l.s $f2, 0($sp)
		addi $sp, $sp, 12
jr $ra
EXIT:	       			  		
