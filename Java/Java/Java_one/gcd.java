package Java_one;

import java.util.Scanner;

public class gcd {

    //求两个数的最小公倍数和最大公约数
    public static void main(String[] args) {
        Scanner scanner1 = new Scanner(System.in);
        Scanner scanner2 = new Scanner(System.in);
        int a = scanner1.nextInt();
        int b = scanner2.nextInt();
        System.out.println("最大公约数：" + gads(a,b) + "\n" + "最小公倍数："
         + a/ gads(a,b)*b);
    }

    private static int gads(int a, int b){
        return b == 0 ? a: gads(b,a%b);
    }
}
