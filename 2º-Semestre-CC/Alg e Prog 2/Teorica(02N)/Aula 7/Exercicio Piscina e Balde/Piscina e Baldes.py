import random

def organizaLista(vet,i,cont):
	if i+1 < len(vet):
		print(vet)
		if vet[i] > vet[i+1]:
			aux = vet[i]
			vet[i] = vet[i+1]
			vet[i+1] = aux
			return organizaLista(vet,0,cont+1)
		else:
			return organizaLista(vet,i+1,cont)
	return cont

tam = int(input("digite o tamanho do vetor "))
vet = []
for i in range(0,tam):
	vet.append(random.randint(0,10))
cont = organizaLista(vet,0,0)
if cont%2 == 0:
	print ('Marcelo')
else:
	print ('Carlos')
