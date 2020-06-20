package fourth;

public class Example4_8 {
    public static void main(String[] args) {
        Circle circle = new Circle();
        circle.setRadius(10);
        Circular circular = new Circular();

        System.out.println("circle的引用："+circle);
        System.out.println("圆锥的bottom引用："+circular.bottom);

        circular.setHeight(5);
        circular.setBottom(circle);

        System.out.println("circle的引用："+circle);
        System.out.println("圆锥体积："+circular.getVolme());
    }
}

class Circle{
    double radius, area;
    void setRadius(double r){
        radius = r;
    }

    double getRadius(){
        return radius;
    }

    public double getArea() {
        area = 3.14*radius*radius;
        return area;
    }
}

class Circular{
    Circle bottom;
    double height;

    public void setBottom(Circle bottom) {
        this.bottom = bottom;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    double getVolme(){
        if(bottom == null)
            return -1;
        else
            return bottom.getArea()*height/3.0;
    }

    double getBottomRadius(){
        return bottom.getRadius();
    }

    public void setBottomRadius(double r){
        bottom.setRadius(r);
    }
}
