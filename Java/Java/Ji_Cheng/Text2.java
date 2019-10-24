package Ji_Cheng;

class Text2 extends Test {
    /*public Ji_Cheng.Text2(){
        super();
        super.doSomething();
    }*/
    public void doSomethingnew(){
        System.out.println("大笨蛋");
    }
    public void doSomething(){
        System.out.println("这句话是真的？");
    }
    protected Text2 dolt(){
        return new Text2();
    }
    public static void main(String[] args){
        Text2 a = new Text2();
        Text2 aa = new Text2();
        a.doSomething();
//        a.doSomethingnew();
//        aa.doSomethingnew();
//        Text2 b = new Text2();
//        b.doSomething();
    }
}
