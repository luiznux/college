// Luiz Henrique Monteiro de Carvalho - 41719468
// Patrick Gandolf Gioz - 41700627

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>

int main (){
  char carac[] ="a7-b5-acj2";//Entrada
  int a = 0;//será usado para adcionar na variavel array depois da separação pelo hifem
    char *x = strtok (carac, "-");//strtok para separar
    char *array[3];

    while (x != NULL)//loop while para separar a entrada pelo hifem com a função strtok
    {
        array[a++] = x;//adcionando em uma lista a separação de letra+numero
        x = strtok (NULL, "-");//separação
    }
  char *sil;//criação da variavel para separar a silaba de letra com numero para contar e printar
  int w = 0;//sera usada em um loop for
  
  int x = 0;//zera a variavel
  int parar = 0;//cria essa variavel que sera uma medida de parada para os loops de for
  char resposta[5];
  char qtd[100];
  
  for (int i = 0; i < sizeof(sil)-5; i++){//o primeiro for que passa pela variavel inteira para contar tudo
    parar = 0;  //determina a parada como 0
    sil = array[i];//adciona a parte de letra+numero na variavel sil
    if(isdigit(sil[i])){//se foi um digito entra nessa condicao
      parar = sil[i]-48;//parar agora é uma contagem para printar os digitos em relacao a tabela ASCII
      if(isdigit(sil[i+1])){//verifica se o segundo digito é numero
        parar = sil[i] + sil[i+1];//por ter entrado nas duas condicoes faz a soma dos dois
      }
    }

   

    if(!(isdigit(sil[1])) && !(isdigit(sil[2]))){//se o segundo e terceiro caractere forem diferentes de digitos
      
      if (parar == 0){//e se a variavel de contagem ainda estiver como 0
        parar = sil[3] -48;//consideramos o quarto caractere como numero a ser contado
      }
      for (w; w <parar; w++){//esse loop vai ser para printar a silaba e suas posicoes 1,2,3
        printf("%c",sil[0]);
        printf("%c",sil[1]);
        printf("%c",sil[2]);
       
      }
      parar = 0;//zera o parar para poder ser usado em outro for e condicoes
    }else if(!(isdigit(sil[1]))){//se o segundo caractere for diferente de digito
      
      if (parar == 0){//e se o parar for zerado
        parar = sil[2]-48;//agora temos certeza que o terceiro caracter
      }
      for (w; w<parar; w++){//esse loop vai ser para printar a silaba e suas posicoes 1,2
        printf("%c",sil[0]);
        printf("%c",sil[1]);
       
      }
    parar = 0;//zera o parar para poder ser usado em outro for e condicoes
    }else if(isdigit(sil[1])){//se o segundo caractere for igual a um digito
      
      if (parar == 0){
        parar = sil[1] - 48;//agora temos certeza que o segundo é caractere
      }
      for (w; w <parar; w++){
        printf("%c",sil[0]);//printa o primeiro caractere
       
      }
    parar = 0;//zera o parar para poder recomecar o loop no primeiro grande for
    }

    w = 0;//zera o w pois usamos ele para contagem diversas vezes e precisaremos usar mais
 
  }
}

