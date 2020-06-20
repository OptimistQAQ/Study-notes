package Java_Shiyan.Test_five;

public class Triangle implements Shape {

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
