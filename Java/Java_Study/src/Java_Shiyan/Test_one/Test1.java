package Java_Shiyan.Test_one;

public class Test1 {
    public static void main(String[] args) {
        Student s = new Student();
        s.setName("张三");
        s.setAge(21);
        s.study();

        Teacher t = new Teacher();
        t.setName("张三丰");
        t.setAge(44);
        t.teach();
    }
}


