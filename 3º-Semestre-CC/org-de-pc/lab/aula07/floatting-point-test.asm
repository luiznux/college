	.data
pi: 	.double 3.1415926535 89793

	.text
	.globl main

main:	li $v0,7  #read_double
	syscall #chama o input do usuario
	la $a0,pi 
	l.d $f12, 0($a0) #a:= pi (carrega o  double para o f12 "registrador de  float")
	mul.d $f12, $f12, $f0 #a:=a*r
	mul.d $f12, $f12, $f0 #a:=a*r (elevando ao quadrado para fazer o padrao i3eee)
	li $v0, 3   #printa o double 
	syscall  #printa para o usuario
	jr $ra #pula para o endereço de $ra
	
		
