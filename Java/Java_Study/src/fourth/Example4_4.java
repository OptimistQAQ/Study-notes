package fourth;

public class Example4_4 {
    public static void main(String[] args) {
        Point p1, p2;
        p1 = new Point();
        p2 = new Point();
        System.out.println("p1的引用："+p1);
        System.out.println("p2的引用："+p2);
        p1.setXV(1111,2222);
        p2.setXV(-100,-200);
        System.out.println("p1的x，y坐标: "+p1.x + "," + p1.y);
        System.out.println("p2的x，y坐标: "+p2.x + "," + p2.y);
        p1 = p2;
        System.out.println("p1的x，y坐标: "+p1.x + "," + p1.y);
        System.out.println("p2的x，y坐标: "+p2.x + "," + p2.y);
    }
}
