def termopro(i, value, x): 
	pro = 1; 
	for j in range(i): 
		pro = pro * (value - x[j]); 
	return pro; 

def diftabela(x, y, n): 

	for i in range(1, n): 
		for j in range(n - i): 
			y[j][i] = ((y[j][i - 1] - y[j + 1][i - 1]) /
									(x[j] - x[i + j])); 
	return y; 


def aplicandoform(value, x, y, n): 

	sum = y[0][0]; 

	for i in range(1, n): 
		sum = sum + (termopro(i, value, x) * y[0][i]); 
	
	return sum; 

#diferença tabela

def printtabela(y, n): 

	for i in range(n): 
		for j in range(n - i): 
			print(round(y[i][j], 4), "\t", 
							end = " "); 

		print(""); 

# numero de entradas 
n = 4; 
y = [[0 for i in range(10)] 
		for j in range(10)]; 
x = [ 5, 6, 9, 11 ]; 

y[0][0] = 12; 
y[1][0] = 13; 
y[2][0] = 14; 
y[3][0] = 16; 

# diferença da divisão
y=diftabela(x, y, n); 
 
printtabela(y, n); 

# interpolação
value = 7; 

# Valor 
print("\nValue at", value, "is", 
		round(aplicandoform(value, x, y, n), 2)) 

