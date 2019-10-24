package Java_one;

import java.io.IOException;
import java.io.InputStreamReader;

public class Buffered {


    public static void main(String[] args) throws IOException {
        //读取用户输入
        java.io.BufferedReader br = new java.io.BufferedReader(new InputStreamReader(System.in));

        //把用户输入转成字符类型数组
        char[] strArr = br.readLine().toCharArray();

        int[] countArr = new int[128];
        for(int i = 0;i<strArr.length;i++){
            if(('A' <= strArr[i] && strArr[i] <= 'Z') || ('a' <= strArr[i] && strArr[i] <= 'z')){
                ++countArr[strArr[i]];
                if(countArr[strArr[i]] == 3){
                    System.out.println(strArr[i]);
                    break;
                }
            }
        }
    }
}
