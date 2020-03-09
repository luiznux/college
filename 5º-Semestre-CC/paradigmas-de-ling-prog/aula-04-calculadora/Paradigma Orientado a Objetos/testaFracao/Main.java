class Main{
  // cliente que usa os metodos da classe Fracao
  // cliente de uma classe é qualquer outra classe ou método que declara ou instancia um objeto da classe.
  public static void main(String[] args) {
    // processo de instanciacao
    Fracao f1,f2;
    
    f1= new Fracao(1,2);
    f2 = new Fracao(1,2);

    if( f1.igual(f2))
       System.out.println("iguais");
    else
       System.out.println("diferentes");
    //f3 = soma( f1, f2);
    //f1 eh passado para o metodo de forma implicita
    //Fracao f3 = f1.soma(f2);
    System.out.println(f1);
    System.out.println(f2);
  }
  
}