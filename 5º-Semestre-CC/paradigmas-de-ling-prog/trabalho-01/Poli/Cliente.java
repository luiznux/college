/*
Entrega de trabalho - Nome do trabalho

Nós,

Bruno Severo Camilo      Tia:41781619
Luiz Fernando            Tia:31861806
Kayque Lima              Tia:31783511

Declaramos que:

Todas as respostas são fruto de nosso próprio trabalho, não copiamos respostas de colegas externos à equipe,
não disponibilizamos nossas respostas para colegas externos à equipe e não realizamos quaisquer outras atividades
desonestas para nos beneficiar ou prejudicar outros.
*/

import java.util.Scanner;


class Cliente{
  public static void main(String[] args) {
    Scanner ler = new Scanner(System.in);
      System.out.printf("Calculadora de polinomios!!!! ");
      System.out.printf("\n");
    int Opicao;
    Polinomio Poli = null;
    Polinomio Poli2 = null;
    while (true){
      System.out.printf("Selecione uma opção: ");
      System.out.printf("\n");
      System.out.printf("1 - Criar/Alterar primeiro polinomio");
      System.out.printf("\n");
      System.out.printf("2 - Criar/Alterar segundo polinomio");
      System.out.printf("\n");
      System.out.printf("3 - Mostrar primeiro polinomio");
      System.out.printf("\n");
      System.out.printf("4 - Mostrar segundo polinomio");
      System.out.printf("\n");
      System.out.printf("5 - Calcular primeiro polinomio");
      System.out.printf("\n");
      System.out.printf("6 - Calcular segundo polinomio");
      System.out.printf("\n");
      System.out.printf("7 - Somar polinomios");
      System.out.printf("\n");
      System.out.printf("8 - Multiplicar polinomios");
      System.out.printf("\n");
      System.out.printf("9 - Sair");
      System.out.printf("\n");

      Opicao = ler.nextInt();

      if (Opicao == 1){
          int grau;
          double valor;
          System.out.printf("Digite o Grau do Polinomio.");
          System.out.printf("\n");
          ler = new Scanner(System.in);
          grau = ler.nextInt();

          Poli = new Polinomio(grau);

          System.out.printf("Agora preencha o Polinomio");

          for ( int i = 0; i<=grau;i++){
            ler = new Scanner(System.in);
            System.out.printf("\n");
            System.out.printf("Digite o valor a ser inserido no expoente ^ %d", i);
            System.out.printf("\n");
            valor = ler.nextDouble();
            Poli.Set_Poli(i,valor);
          }

          Poli.print_Poli();

      }
      if(Opicao == 2){
          int grau2;
          double valor2;
          System.out.printf("Digite o Grau do Polinomio.");
          System.out.printf("\n");
          ler = new Scanner(System.in);
          grau2 = ler.nextInt();

          Poli2 = new Polinomio(grau2);

          System.out.printf("Agora preencha o Polinomio");

          for ( int i = 0; i<=grau2;i++){
            ler = new Scanner(System.in);
            System.out.printf("\n");
            System.out.printf("Digite o valor a ser inserido no expoente ^ %d", i);
            System.out.printf("\n");
            valor2 = ler.nextDouble();
            Poli2.Set_Poli(i,valor2);
          }

          Poli2.print_Poli();

      }
      if(Opicao == 3 ){
        if (Poli != null){
          Poli.print_Poli();
        }
        else{
          System.out.printf("\n");
          System.out.printf("Você ainda nao preencheu o polinomio xD");
          System.out.printf("\n");
        }

      };
      if(Opicao == 4){
        if (Poli2 != null){
          Poli2.print_Poli();
        }
        else{
          System.out.printf("\n");
          System.out.printf("Você ainda nao preencheu o polinomio xD");
          System.out.printf("\n");
        }
      }
      if(Opicao == 5 ){
        ler = new Scanner(System.in);
        System.out.printf("\n");
        System.out.printf("Digite o Valor do X: ");
        System.out.printf("\n");
        double valorx = ler.nextDouble();

        Poli.calcula_Poli(valorx);
      }
      if(Opicao == 6 ){
        ler = new Scanner(System.in);
        System.out.printf("\n");
        System.out.printf("Digite o Valor do X: ");
        System.out.printf("\n");
        double valorx = ler.nextDouble();

        Poli2.calcula_Poli(valorx);
      }
      if(Opicao == 7 ){
        Polinomio Polinomiosoma = null;
        System.out.printf("\n");
        System.out.printf("Somando o primeiro polinomio com o segundo: ");
        System.out.printf("\n");

        Polinomiosoma = Poli.somar_Poli(Poli2);

        Polinomiosoma.print_Poli();
      }
      if(Opicao == 8 ){
        if (Poli == null || Poli2 == null){
          System.out.printf("\n");
          System.out.printf("Você ainda nao preencheu os dois Polinomios");
          System.out.printf("\n");
        }
        else {
        Polinomio Polinomiomult = null;

        System.out.printf("\n");
        System.out.printf("Multiplicando os polinomios");
        System.out.printf("\n");

        Polinomiomult = Poli.mult_Poli(Poli2);

        Polinomiomult.print_Poli();
        }

      }
      if(Opicao == 9 ){
        System.out.printf("\n");
        System.out.printf("Até a Próxima!!");
        System.out.printf("\n");
        break;
      }
    }
  }
}
