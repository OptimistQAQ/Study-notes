package fourth;

public class Example4_2 {
    public static void main(String[] args) {
        Point p1, p2;
        p1 = new Point(10, 10);
        p2 = new Point(23, 35);
        System.out.println("(" + p1.x + "," + p1.y + ")" + "\n"
                + "(" + p2.x + "," + p2.y + ")");
    }
}

class Point{
    int x, y;

    Point(){

    }
    Point(int a, int b){
        this.x = a;
        this.y = b;
    }

    void setXV(int m, int n){
        x = m;
        y = n;
    }
}
