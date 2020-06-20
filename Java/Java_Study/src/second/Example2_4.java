package second;

public class Example2_4 {
    public static void main(String[] args) {
        int a[] = {1,2,3,4};
        int b[] = {100,200,300};
        System.out.println("数组a的元素个数为：" + a.length);
        System.out.println("数组b的元素个数为：" + b.length);

        System.out.println("数组a的引用=" + a);
        System.out.println("数组b的引用=" + b);
        a = b;

        System.out.println("数组a的元素个数为：" + a.length);
        System.out.println("数组b的元素个数为：" + b.length);

    }
}
