package Java_Shiyan.Test_four;

public class Test_4 {
    public static void main(String[] args) {

       Shape []shapes = new Shape[5];
       shapes[0] = new Circle(5.0);
       System.out.println("圆形的面积为：" + shapes[0].Area());
       shapes[1] = new Square(0.5);
        System.out.println("正方形的面积为：" + shapes[1].Area());
        shapes[2] = new Triangle(1.2, 2.0);
        System.out.println("三角形的面积为：" + shapes[2].Area());
    }
}
