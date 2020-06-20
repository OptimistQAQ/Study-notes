package fourth;

public class Example4_1 {
    public static void main(String[] args) {
        XiyoujiRenwu zhubajie;   //声明对象
        zhubajie = new XiyoujiRenwu();  //为对象分配变量
        zhubajie.speak("大师兄，师傅被妖怪抓走了");
    }
}

class XiyoujiRenwu{
    float height, weight;
    String head, ear;
    void speak(String s){
        head = "歪着头";
        System.out.println(s);
    }
}
