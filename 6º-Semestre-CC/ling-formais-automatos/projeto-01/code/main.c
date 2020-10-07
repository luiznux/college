#include <stdio.h>
#include <string.h>

/**
* +-------------------------------------+-------------------+
* | NOME                                | TIA               |
* +-------------------------------------+-------------------+
* | Edison Aguiar de Souza Neto         | 31812295          |
* +-------------------------------------+-------------------+
* | Raphael Prandini Thome de Abrantes  | 31828728          |
* +-------------------------------------+-------------------+
* | Lucas Morita da Nova                | 31826199          |
* +-------------------------------------+-------------------+
* | Luiz Tagliaferro Brito              | 31861806          |
* +-------------------------------------+-------------------+
*/

/**
 * Enum usado para reprensatar o tipos de retorno da função scanner.
 */
enum tipos_resultado_automato {
  ERRO, INTEIRO, PFLUTUANTE
};

/**
 * Verifica se a letra do alfabeto está entre 1 e 9.
 */
int esta_entre_um_e_nove(char letra) {
  return letra >= '1' && letra <= '9';
}

/**
 * Implementação do automato, possíveis retornos:
 * 0. ERRO quando a palavra for inválida.
 * 1. INTEIRO Quando a palavra for do tipo inteiro.
 * 2. PFLUTUANTE Quando a palavra for do tipo ponto flutuante.
 */
int scanner(char palavra[])
{
  int i = -1;
q0: i++;
  if (palavra[i] == '.') goto q3;
  else if (palavra[i] == '-' || palavra[i] == '+') goto q2;
  else if (palavra[i] == '0') goto q4;
  else if (esta_entre_um_e_nove(palavra[i])) goto q5;
  else if (palavra[i] == '\0') return INTEIRO;
  return ERRO;

q1: i++;
  if (palavra[i] == '.') goto q2;
  else if (palavra[i] == '-' || palavra[i] == '+') goto q2;
  else if (palavra[i] == '0') goto q1;
  else if (esta_entre_um_e_nove(palavra[i])) goto q1;
  else if (palavra[i] == '\0') return PFLUTUANTE;
  return ERRO;

/**
 * Aqui poderíamos validar da forma que fizemos nos outros estados:
  if (palavra[i] == '.') goto q2;
  else if (palavra[i] == '-' || palavra[i] == '+') goto q2;
  else if (palavra[i] == '0') goto q2;
  else if (esta_entre_um_e_nove(palavra[i])) goto q2;
  else if (palavra[i] == '\0') return ERRO;
  return ERRO;
  Entretanto, o Q2 funciona como um poço, então independente da letra
  ele sempre retornará erro quando cair nele mesmo, por tanto, decidimo
  retornar logo erro, diminuindo assim, o tempo de processamento e complexidade
  do código.
 */
q2: i++;
  return ERRO;

q3: i++;
  if (palavra[i] == '.') goto q2;
  else if (palavra[i] == '-' || palavra[i] == '+') goto q2;
  else if (palavra[i] == '0') goto q1;
  else if (esta_entre_um_e_nove(palavra[i])) goto q1;
  else if (palavra[i] == '\0') return ERRO;
  return ERRO;

q4: i++;
  if (palavra[i] == '.') goto q3;
  else if (palavra[i] == '-' || palavra[i] == '+') goto q2;
  else if (palavra[i] == '0') goto q2;
  else if (esta_entre_um_e_nove(palavra[i])) goto q2;
  else if (palavra[i] == '\0') return INTEIRO;
  return ERRO;

q5: i++;
  if (palavra[i] == '.') goto q3;
  else if (palavra[i] == '-' || palavra[i] == '+') goto q2;
  else if (palavra[i] == '0') goto q5;
  else if (esta_entre_um_e_nove(palavra[i])) goto q5;
  else if (palavra[i] == '\0') return INTEIRO;
  return ERRO;
}

/**
 * Salva o resultado do automato no arquivo resultado.txt
 */
void escreve_resultado_no_arquivo(int tipo)
{
  char *resultado;
  if (tipo == ERRO) {
    resultado = "<ERRO>";
  } else if (tipo == INTEIRO) {
    resultado = "<INTEIRO>";
  } else if (tipo == PFLUTUANTE) {
    resultado = "<P.FLUTUANTE>";
  }

  FILE *file = fopen("resultado.txt", "a");
  fprintf(file, "%s\n", resultado);
  fclose(file);
}

int main(void)
{
  char palavras[] = "21      +45.67     0.123 .456 -42 xx 00.123";

	char separador[] = " ";

	char *palavra = strtok(palavras, separador);

	while(palavra != NULL)
	{
    int resultado = scanner(palavra);
    escreve_resultado_no_arquivo(resultado);
		palavra = strtok(NULL, separador);
	}
  return 0;
}