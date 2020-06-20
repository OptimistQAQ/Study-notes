package fourth;

public class Example4_3 {
    public static void main(String[] args) {
        XiyoujiRenwu zhubajie, sunwukong;
        zhubajie = new XiyoujiRenwu();
        sunwukong = new XiyoujiRenwu();
        zhubajie.height = 1.80f;
        zhubajie.head = "大头";
        zhubajie.ear = "一双大耳朵";
        sunwukong.height = 1.62f;
        sunwukong.head = "秀发飘飘";
        System.out.println("猪八戒的身高：" + zhubajie.height);
        System.out.println("猪八戒的头：" + zhubajie.head);
        System.out.println("孙悟空的身高：" + sunwukong.height);
        System.out.println("孙悟空的头：" + sunwukong.head);
        zhubajie.speak("俺老猪想娶媳妇");
    }
}