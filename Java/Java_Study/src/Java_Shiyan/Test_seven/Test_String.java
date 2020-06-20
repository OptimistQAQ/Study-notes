package Java_Shiyan.Test_seven;

public class Test_String {
    public static void main(String[] args) {
        String str = "abcabccabbafkdfjabc";
        String key = "abc";

        int count = getKeyStringCount(str, key);
        System.out.println(str + "\n" + key);
        if (count == 0) {
            System.out.println("count = -1");
        }
        else {
            System.out.println("count = " + count);
        }
    }
    private static int getKeyStringCount(String str, String key) {
        int count = 0;
        int index = 0;
        while ((index = str.indexOf(key, index)) != -1) {
            index = index + key.length();
            count++;
        }
        return count;
    }
}
