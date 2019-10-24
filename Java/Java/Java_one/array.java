package Java_one;

import java.util.Scanner;
public class array {
    public static void main(String[] args){
        /*int arr[] = new int[] {31,28,31,30,31,30,31,31,31,30,31,30,31};
        for(int i=0;i<12;i++){
            System.out.println((i+1) + "月有" + arr[i] + "天");
        }*/

        //一维数组的创建排序，二分查找一个数在不在该数组中。
        int start = 0,end,mid;
        int arr[] = new int[] {12,456,879,-156};
        int N = arr.length;
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                if(arr[j]<arr[i]){
                    int t=arr[i];
                    arr[i]=arr[j];
                    arr[j]=t;
                }
            }
        }
        System.out.println("排序以后的数组是：");
        for(int i : arr){
            System.out.print(i + " ");
        }
        System.out.println();
        System.out.println("输入一个整数，程序判断该整数是否在数组中：");
        Scanner scanner = new Scanner(System.in);
        int number = scanner.nextInt();
        int cnt = 0;
        end = N;
        mid = (start + end)/2;
        while(number != arr[mid]){
            if(number > arr[mid])
                start = mid;
            else if(number < arr[mid])
                end = mid;
            mid = (start + end)/2;
            cnt++;
            if(cnt>(N/2))
                break;
        }
        if(cnt > N/2)
            System.out.println("该数不在数组中。");
        else
            System.out.printf("%d在数组中",number);

    }
}
