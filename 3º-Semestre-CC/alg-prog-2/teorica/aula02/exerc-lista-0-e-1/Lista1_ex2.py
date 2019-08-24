import math
'''
função  calcula a raiz quadrada de um número usando o algoritmo da lista 1 exercício 12
no final comparo o resultado da função com a resposta da função sqrt.
'''
def raiz( A ):
    Xn = 1
    i = 1
    while i <= 5:
        Xn = 0.5*(Xn+A/Xn)
        i+=1



    return Xn

# --- MAIN

respRaiz = raiz(9)
respSqrt = math.sqrt(9)

print(" raiz = ", respRaiz)
print(" sqrt = ", respSqrt)
