package fourth;

import java.util.Arrays;
import java.util.Scanner;
import java.util.Date;

public class Example4_11 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] a = {12,34,9,23,45,6,45,90,123,19,34};
        Arrays.sort(a);
        System.out.println(Arrays.toString(a));
        System.out.println("输入整数，程序判断该整数是否在数组中：");
        int number = scanner.nextInt();
        int index = Arrays.binarySearch(a, number);
        if(index >= 0)
            System.out.println(number + "在数组中的索引为：" + index);
        else
            System.out.println("该数不在数组中。");
        Date date = new Date();
        System.out.println("本机时间为：");
        System.out.println(date.toString());
    }
}
