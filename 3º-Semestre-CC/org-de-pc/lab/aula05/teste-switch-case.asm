#Nome: Matheus Soares Santos 	TIA: 31895263

# Definindo a Jump Table
.data
jTable: .word L0,L1,L2,L3
.text
# Definindo as vari�veis
li $s1, 10 # g = $s1 = 15
li $s2, 20 # h = $s2 = 20
li $s3, -10 # i = $s3 = 10
li $s4, 5 # j = $s4 = 5
li $s5, 3 # k = $s5 = 0
la $t4, jTable # $t4 = base address of the jump table
# Verificando os limites de K
slt $t3, $s5, $zero #se zero for maior doq oq estiver em S5, ent t3 recebe 1, se nao recebe zero(BOLEAN)
bne $t3, $zero, EXIT# be not equal (se t3 nao for igual a zero, ele sai do programa "EXIT")
slti $t3, $s5, 4 
beq $t3, $zero, EXIT #if se t3 for igual a zero ele sai do programa
# Calculando o endere�o correto do Label
sll $t1, $s5, 2#deslocamneto de bits para esquerda (ta multiplicando por dois)
add $t1, $t1, $t4
lw $t0, 0($t1)
# Sele��o do Label
jr $t0
# Casos
#Caso 1: IF
L0: beq $s1, $s2, F0
    j EXIT
    F0: add $s1, $s1, $s2
        J EXIT
#CASO 2: IF/ELSE
L1: bne $s1, $s3, F1
    sub $s3, $s1, $s4
    J EXIT
    F1: sub $s3, $s2, $s3
	j EXIT
#CASO 3: WHILE
L2: j WHILE1
    WHILE1: slt $t5, $s2, $zero
    	   bne $t5, $zero, EXIT
    	   subi $s2, $s2, 1
    	   addi $s3, $s1 4
    	   j WHILE1
#CASO 4: DO/WHILE
L3: j DO
    DO: addi $s3, $s3, 5
        j WHILE2
        WHILE2: slti $t5, $s3, 0
                bne $t5, $zero, EXIT
                subi $s3, $s3, 2
                add $t6, $s1, $s2
                j WHILE2
EXIT:
#FIM

 
