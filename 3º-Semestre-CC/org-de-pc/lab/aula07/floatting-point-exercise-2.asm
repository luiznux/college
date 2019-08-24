		.data
#crita todas as variaveis que serao usadas
decimo: .float 0.1
centesimo: .float 0.01
epsilon: .float 1.0e-7
				
																														
		.text
la $a0, decimo
la $a1, centesimo
la $a2, epsilon
l.s $f0, ($a0)#load single precison no registrador $a0
l.s $f1, ($a1)
l.s $f2, ($a2)
mul.s $f0, $f0, $f0 #multiplicação
sub.s $f3, $f0, $f1 #subtração
abs.s $f3, $f3 # abs--> transforma para valor absoluto(modulo)
c.lt.s 6 $f3, $f2# retorna a flag 6 se o valor de f3 for menor doq de f2
bc1f 6 not_quite #se nao retornar a flag 6, va par not_quite
	
not_quite: