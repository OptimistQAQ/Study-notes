package Java_Shiyan.Test_five;

public class Circle implements Shape {

    private double r;

    Circle(double r) {
        this.r = r;
    }

    @Override
    public double Area() {
        return (3.14*r*r);
    }
}
