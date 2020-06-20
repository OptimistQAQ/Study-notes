package seven;

public class ReCowForm {
    static String formName;
    RewCow cow;  // 内部类对象声明
    ReCowForm(String s) {
        cow = new RewCow(150, 112, 5000);
        formName = s;
    }

    public void showCowMess() {
        cow.speak();
    }

    class RewCow{
        String cowName = "Red Cow";
        int height, weight, price;
        RewCow(int h, int w, int p) {
            height = h;
            weight = w;
            price = p;
        }
        void speak(){
            System.out.println("I am " + cowName + ", height: " + height + ", weight: " + weight + ", price: " + price);
        }
    }
}

class Example7_1{
    public static void main(String[] args) {
        ReCowForm form = new ReCowForm("Red Form");
        form.showCowMess();
        form.cow.speak();
    }
}
