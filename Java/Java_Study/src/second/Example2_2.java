package second;

public class Example2_2 {
    public static void main(String[] args) {
        byte b = 22;
        int n = 129;
        float f = 123456.67889f;
        double d = 123456.12345679;
        System.out.println("b= " + b);
        System.out.println("n= " + n);
        System.out.println("f= " + f);
        System.out.println("d= " + d);

        b = (byte) n;
        f = (float) d;
        System.out.println("\nb= " + b);
        System.out.println("f= " + f);
    }
}
