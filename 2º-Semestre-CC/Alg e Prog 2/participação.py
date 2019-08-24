def troca(lista,i,ganhador):
    if i+1 < len(lista):
        
        if lista[i] > lista[i+1]:
            lista[i], lista[i+1]= lista[i+1], lista[i]
            print(lista)
            return troca(lista,0,ganhador+1)
        else:
            return troca(lista,i+1,ganhador)
    return ganhador
from random import randint
lista=[0]*8
for i in range (0,8):
    lista[i]= randint(0,9)
print(lista)
ganhador = troca(lista,0,0)
if ganhador%2==0:
    print('Carlos')
else:
    print('Marcelo')
