/*
typedef struct{
    int num, den;
}TFracao;

TFracao * soma( TFracao *f1, TFracao *f2 ){

*/
public class Fracao{
  // atributos da classe (variaveis de instancia)
  private int num, den;
  // construtor da classe
  public Fracao( int num, int den ){
    this.num = num;
    this.den = den;
  }
  public Fracao(){
    this.num = 0;
    this.den = 0; 
  }
  // metodo
 
  public String toString(){
    return this.num+"/"+this.den;
  }

  public void setDen(int den){
     // this.den acesso o atributo da classe
     this.den = den;
  }
  /*
  TFracao * soma( TFracao *f1, TFracao *f2 ){

    TFracao * f = (TFracao*) calloc(1, sizeof(TFracao));
    //(a/b)+(c/d)=( (a.d+c.b) / b.d )
    f->num = f1->num*f2->den + f2->num*f1->den;
    f->den = f1->den*f2->den;

    f1->num = 10;
    return f;
   }
  Fazer a soma em Java
  */
  // TFracao * soma( TFracao *f1, TFracao *f2 ){
  public Fracao soma( Fracao f ){
     // TFracao * f = (TFracao*) calloc(1, sizeof(TFracao));
     Fracao fResp = new Fracao();
     //(a/b)+(c/d)=( (a.d+c.b) / b.d )
     //f->num = f1->num*f2->den + f2->num*f1->den;
     fResp.num = this.num*f.den + f.num*this.den;
     //f->den = f1->den*f2->den;
     fResp.den = this.den*f.den;
     
     return fResp;
     
  }
  public boolean igual( Fracao f){
     //Igualdade: (a/b)== (c/d) se a*d == b*c
     return this.num*f.den == this.den*f.num;
  }

}