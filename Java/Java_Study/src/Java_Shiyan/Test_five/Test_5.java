package Java_Shiyan.Test_five;

public class Test_5 {
    public static void main(String[] args) {
        Shape []shapes = new Shape[3];
        shapes[0] = new Circle(5.5);
        System.out.println("Size of Circle: " + shapes[0].Area());
        shapes[1] = new Square(0.5);
        System.out.println("Size of square: " + shapes[1].Area());
        shapes[2] = new Triangle(1.2, 2.0);
        System.out.println("Size of Triangle: " + shapes[2].Area());
    }
}
