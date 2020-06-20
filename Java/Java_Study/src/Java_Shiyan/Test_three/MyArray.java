package Java_Shiyan.Test_three;

class MyArray {

    public static int getMax(int[] a){
        int max = -1;
        for (int value : a) {
            if (max < value)
                max = value;
        }
        return max;
    }

    public static void selectSort(int[] a){
        for(int i=0; i<a.length-1; i++){
            int t = i;
            for(int j=i+1; j<a.length; j++)
                if (a[t] > a[j])
                    t = j;
            int temp = a[t];
            a[t] = a[i];
            a[i] = temp;
        }
    }
}
