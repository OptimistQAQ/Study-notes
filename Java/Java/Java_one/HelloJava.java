package Java_one;

public class HelloJava{
    static String s1="秦嘉豪，你好";
    public static void main(String [] args){

        System.out.println(s1);
        //第一行代码
        /*String word = "Hello Java!";
        System.out.println(word);

        String s5 = new String("秦嘉豪");     //定义String类型的字符
        String s4 = new String("is so stupid!");
        String s = s5 + " " + s4;
        System.out.println(s);

        //    //////////   字符串的替换   replace的应用
        String str = "address";
        String newstr = str.replace("a","A");   //
        System.out.println(newstr);

        /////////////    判断字符串的开始与结尾    startsWith的应用
        /*String num1 = "22045612";
        String num2 = "21304578";
        boolean b = num1.startsWith("22");
        boolean b2 = num1.endsWith("78");
        boolean b3 = num2.startsWith("22");
        boolean b4 = num2.endsWith("78");
        System.out.println("字符串num1是以‘22’开始的吗？" + b);
        System.out.println("字符串num1是以‘78’结束的吗？" + b2);
        System.out.println("字符串num2是以‘22’开始的吗？" + b3);
        System.out.println("字符串num2是以‘78’结束的吗？" + b4);*/

        ////////////////////判断字符串是否相等  equals的应用
        /*String s1 = new String ("abc");
        String s2 = new String("ABC");
        String s3 = new String("abc");
        boolean b = s1.equals(s2);
        boolean b2 = s1.equalsIgnoreCase(s2);
        System.out.println(s1 + " equals " + s2 + ":" + b);
        System.out.println(s1 + " equalsIsIgnoreCase " + s2 + ":" + b2);*/

        //定义要匹配E-mail地址的正则表达式
        String regex = "\\w+@\\w+(\\.\\w{2,3})*\\.w{2,3}";
        String str1 = "aaa@";
        String str2 = "aaaaa";
        String str3 = "1111@111ffyu.dfg.com";
        if(str1.matches(regex))
            System.out.println(str1 + "是一个合法的地址格式");
        if(str2.matches(regex))
            System.out.println(str2 + "是一个合法的地址格式");
        if(str3.matches(regex))
            System.out.println(str3 + "是一个合法的地址格式");


        /*int x=20;
        {
            int y=40;
            System.out.println(y);
            int z
            =245;
            boolean b;
            {
                b=y>z;
                System.out.println(b);
            }
            String word="Hello Java";
            System.out.println(word);
        }*/
    }
}
