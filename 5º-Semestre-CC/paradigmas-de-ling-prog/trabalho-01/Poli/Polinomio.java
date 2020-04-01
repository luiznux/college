public class Polinomio{

    private double termos[]; //vetor com os termos do polinomio
    private int grau; // grau do polinomio

    /*
      Construtor da classe, recebe como parametros o grau desejado e gera um vetor
      com o tamanho do grau
     */
    public Polinomio(int grau)
    {
        this.termos = new double[grau+1];
        this.grau = grau;
    }


    /*
      Seta um valor em um polinomio.
      Recebe como parametro a posição(grau) e o valor que deseja colocar
     */
    public void Set_Poli(int index, double valor)
    {
        this.termos[index] = valor;
    }


    /*
      Metodo para imprimir um polinomio
     */
    public void print_Poli()
    {
        System.out.printf("\n");
        for (int i = this.grau; i>=0;i--){
            System.out.printf("%.2fX^%d ",this.termos[i],i);
        }
        System.out.printf("\n");
    }


    /*
      Metodo para somar um valor, dado como parametro, em um elemento especifico
      do polinomio que tambem deve ser fornecido
     */
    public void soma_valor_Poli(double valor, int indice)
    {
        this.termos[indice] += valor;
    }


    /*
      Metodo para calcular o polinomio de acordo com um valor dado
     */
    public void calcula_Poli(double valor)
    {
        double resultado = 0;
        for(int i = 0; i<=this.grau;i++){
            resultado = resultado + this.termos[i]*(Math.pow(valor,i));
        }
        System.out.printf("%.3f",resultado);
        System.out.printf("\n");
    }

    /*
      Metodo para somar dois polinomios, recebe um polinomio como parametro e retorna um polinomio resultante(result).
      Primeiramente verifico qual é o maior grau para instanciar um polinomio resultante com o tamanho
      do maior grau. Caso seus graus forem equivalentes, estancio com o tamanho de qualquer um dos dois.
     */
    public Polinomio somar_Poli(Polinomio p)
    {
        //Verifica qual o maior grau entre os polinomios dados
        if(this.grau < p.grau){

            Polinomio result = new Polinomio(p.grau);

            for (int i = 0; i<=this.grau;i++){
                result.Set_Poli(i,this.termos[i]+p.termos[i]);

            }for (int i = this.grau+1; i<=p.grau;i++){
                result.Set_Poli(i,p.termos[i]);
            }
            return result;

        }else if (p.grau < this.grau){

            Polinomio result = new Polinomio(this.grau);

            for (int i = 0; i<=p.grau;i++){
                result.Set_Poli(i,this.termos[i]+p.termos[i]);

            }for (int i = p.grau+1; i<=this.grau;i++){
                result.Set_Poli(i,this.termos[i]);
            }
            return result;

        }else{
            //graus equivalentes
            Polinomio result = new Polinomio(p.grau);
            for (int i = 0; i<=p.grau;i++){
                result.Set_Poli(i,this.termos[i]+p.termos[i]);
            }
            return result;
        }
    }


    /*
      Metodo para multiplicar dois polinomios.
      O processo consiste em iterar cada elemento do primeiro polinomio com cada elemento do
      segundo polinomio(p) e armazenar no polinomo resultante(multresult). O grau do produto
      é igual a soma dos graus
      Utilizo a função soma valor para setar os valores
     */
    public Polinomio mult_Poli(Polinomio p)
    {
        Polinomio multresult = new Polinomio(p.grau+this.grau);

        for (int i = 0 ; i<=this.grau; i++){
            for (int j = 0; j<=p.grau;j++){
                multresult.soma_valor_Poli(this.termos[i]*p.termos[j], i+j);
            }
        }
        return multresult;
    }
}
