Para os dados de entrada: 770, 761, 333, 222, 110, 100 e hash_size = 13.

a) (1.0) Qual o número de colisões para a função: (n/100 + ((n%100)%10))%hash_size, onde n é o número inteiro a ser inserido.

b) (1.0) Apresente o vetor com os valores inseridos, através do Probing linear.

a)  obtemos somente uma colisao.
+---+-+
|770|8|
+---+-+
|761|9|
+---+-+
|333|6|
+---+-+
|222|4|
+---+-+
|110|1|
+---+-+
|100|1|
+---+-+

b) tabela com os dados

+-+---+---+-+---+-+---+-+---+---+--+--+--+
|0| 1 |2  |3|4  |5|6  |7| 8 |9  |10|11|12|
+-+---+---+-+---+-+---+-+---+---+--+--+--+
| |110|100| |222| |333| |770|761|  |  |  |
+-+---+---+-+---+-+---+-+---+---+--+--+--+
