/*

Implemente também o método igual(Ponto p) na classe Ponto que verifica se
dois pontos são iguais, o método recebe um parâmetro de forma explícita
(Ponto p) e outro de forma implícita, ou seja, o objeto em que você invoca o
método também é considerado um parâmetro da chamada do método.
Implemente também o método distancia() que calcula e retorna a distância
entre dois objetos. Por fim implemente um cliente para testar a classe Ponto.
*/

public class Main {

    /**
     * cliente para testar a classe Ponto
     */
    public static void main(String[] args) {
        Ponto p1 = new Ponto(1, 1);
        Ponto p2 = new Ponto(3,1);
        System.out.println("ponto 1="+p1);
        System.out.println("ponto 2="+p2);

        System.out.print("Os pontos são iguais ? "+p1.Equal(p2));
        System.out.print("\n");

        System.out.print("Distancia entre os dois pontos="+p1.Distance(p2));
    }
}
