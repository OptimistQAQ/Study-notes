package Java_Shiyan.Test_four;

public class Square extends Shape {

    private double a = 0.0;

    Square(double a) {
        this.a = a;
    }

    @Override
    public double Area() {
        return (a*a);
    }
}
