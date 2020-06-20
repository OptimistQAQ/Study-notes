package eight;

public class Example8_1 {
    public static void main(String[] args) {
        String hello = "你好";
        String testOne = "你" + "好";
        System.out.println(hello == testOne);
        System.out.println("你好" == testOne);
        System.out.println("你好" == hello);
        String you = "你";
        String hi = "好";
        String testTwo = you + hi;
        System.out.println(hello == testTwo);
        String testThree = you + hi;
        System.out.println(testThree == testTwo);
    }
}
