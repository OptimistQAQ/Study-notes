package Java_Shiyan.Test_four;

public class Rectangle extends Shape {

    private double width = 0.0;
    private double length = 0.0;

    public Rectangle(double width, double length) {
        this.width=width;
        this.length=length;
    }

    @Override
    public double Area() {
        return width*length;
    }
}
