import math

def fatorial(n, cont1):
    if n < 2 :
        return 1

    else:
        return n * fatorial(n-1) cont1+1

def funcao(x,n):

    f = 0
    cont =0
    for i in range (0, n+1):
        cont +=1

        f+= math.pow(x,i) / fatorial(i,cont1)
    print(cont)
    return f

x = 10
n = 10

coisa = funcao(x,n)


