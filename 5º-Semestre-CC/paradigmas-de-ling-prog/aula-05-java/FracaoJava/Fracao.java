/*
typedef struct{
    int num, den;
}TFracao;

TFracao * soma( TFracao *f1, TFracao *f2 ){

*/
public class Fracao{
  private int num, den;
  public Fracao( int num, int den ){
    this.num = num;
    this.den = den;
  }  
  public String toString(){
    return this.num+"/"+this.den;
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

}