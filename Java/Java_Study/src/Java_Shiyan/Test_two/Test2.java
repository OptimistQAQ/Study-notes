package Java_Shiyan.Test_two;

public class Test2 {
    public static void main(String[] args) {
        Triangle t1 = new Triangle(1.0);
        double area = t1.area();
        System.out.println("t1的面积为：" + area);

        Triangle t2 = new Triangle(1.0f);
        area = t2.area();
        System.out.println("t2的面积为：" + area);

        Triangle t3 = new Triangle(1.0, 1.0);
        area = t3.area();
        System.out.println("t3的面积：" + area);
    }
}

class Triangle{
    private double bottom;
    private double high;

    Triangle(double h){
        this.high = h;
    }

    Triangle(float b){
        this.bottom = b;
    }

    Triangle(double h, double b){
        this.high = h;
        this.bottom = b;
    }

    public double area() {
        return 0.5*bottom*high;
    }
}
