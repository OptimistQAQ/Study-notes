package Java_Shiyan.Test_four;

public class Circle extends Shape {

    private double r = 0.0;

    Circle(double r){
        this.r = r;
    }

    @Override
    public double Area() {
        return (3.14*r*r);
    }
}
