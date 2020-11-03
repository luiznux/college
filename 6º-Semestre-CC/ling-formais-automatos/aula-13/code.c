/*
 * COLOQUE AQUI OS AUTORES DO PROJETO - 1 por linha
 *
 */

#include<stdio.h>
#include<stdlib.h>

/*
 * S -> aBc$
 * B -> bB
 * B -> e         e: palavra vazia
 */

char lookahead;   /* Excepcionalmente variavel global */

int  match(char t, char palavra[], int *pos){
	if (lookahead == t){
		lookahead= palavra[++(*pos)];
		return(1);
	}
	return(0);
}

/* S -> aBc$  */
int S(char palavra[], int *pos){
    if (match('a', palavra, pos)  &&
        B(palavra, pos)           &&
        match('c', palavra, pos)  &&
   	    match('$', palavra, pos)  )
      return(1);
	else return(0);
}

/* B -> bB  ,   B -> e  */
int B(char palavra[], int *pos){
	if (lookahead == 'b'){    /* lookahead e� o FIRST!!! */
		if (match('b', palavra, pos) &&
		    B(palavra, pos)          )
	   	  return(1);
	   	else return(0);
	} else return(1);         /* caso com palavra vazia */
}

void trataErro(){
	printf("\n\nERRO DE SINTAXE\n\n");
	/* Faca um tratamento melhor */
}

int main(){
	char palavra[]= "abbbc$";
	int  pos=0;

	lookahead= palavra[pos];
	if (S(palavra, &pos))
	    printf("\nPalavra %s reconhecida\n", palavra);
	else
	    trataErro();
	system("PAUSE");
	return(0);
}
