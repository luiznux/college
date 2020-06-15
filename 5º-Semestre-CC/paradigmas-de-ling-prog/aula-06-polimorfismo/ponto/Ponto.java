import java.lang.Math;

public class Ponto{

    private int x, y;
    public Ponto( int x, int y){
        this.x = x;
        this.y = y;
    }

    public String toString() {
        return "Ponto{" + "x=" + x + ", y=" + y + '}';
    }

    public boolean Equal(Ponto p){
      return ((this.x == p.x) && (this.y == p.y));
    }

    public double Distance(Ponto p){
      return (Math.sqrt(Math.pow(this.x-p.x,2) + Math.pow(this.y-p.y,2)));
    }

}
