package Java_Shiyan.Test_four;

public class Triangle extends Shape {

    private double a, b;

    Triangle(double a, double b) {
        this.a = a;
        this.b = b;
    }

    @Override
    public double Area() {
        return (a*b/2);
    }
}
