package Java_one;

public class KMP {

    /*
     ********求出字符数组的next数组
     */
    private static int[] getNextArray(char[] t){
        int[] next = new int[t.length];
        next[0] = -1;
        next[1] = 0;
        int k;
        for(int j=2;j<t.length;j++){
            k = next[j-1];
            while (k != -1){
                if(t[j-1] == t[k]){
                    next[j] = k+1;
                    break;
                }
                else{
                    k = next[k];
                }
                next[j] = 0;
            }
        }
        return next;
    }

    /*
     ******对主串s和模式串t进行kmp模式匹配
     */
    public static int kmpMatch(String s,String t){
        char[] s_arr = s.toCharArray();
        char[] t_arr = t.toCharArray();
        int[] next = getNextArray(t_arr);
        int i=0,j=0;
        while (i < s_arr.length && j < t_arr.length){
            if(j == -1 || s_arr[i] == t_arr[j]){
                    i++;j++;
            }
            else
                j = next[j];
        }
        if(j == t_arr.length)
            return i - j;
        else
            return -1;
    }

    public static void main(String[] args) {
        String a = new String("abcabaabaabcacb");
        String b = new String("abaabcac");
        System.out.println(kmpMatch(a,b));
    }
}
