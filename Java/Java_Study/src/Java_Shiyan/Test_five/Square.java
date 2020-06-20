package Java_Shiyan.Test_five;

public class Square implements Shape {
    private double a;
    Square(double a) {
        this.a = a;
    }
    @Override
    public double Area() {
        return (a * a);
    }
}
