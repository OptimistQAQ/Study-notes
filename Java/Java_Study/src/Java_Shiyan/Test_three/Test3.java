package Java_Shiyan.Test_three;

public class Test3 {
    public static void main(String[] args) {
        int[] a = {1,20, 34, 50, 100, 8};
        System.out.println("max num in array a[] is " + MyArray.getMax(a));
        MyArray.selectSort(a);
        for (int value:a){
            System.out.print(value + " ");
        }
    }
}
