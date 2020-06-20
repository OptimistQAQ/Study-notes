package fourth;

public class Example4_19 {
    public static void main(String[] args) {
        Student zhang = new Student();
        Student geng = new Student();
        zhang.setAge(23);
        System.out.println("zhang的年龄："+zhang.getAge());
        geng.setAge(25);
        System.out.println("geng的年龄："+geng.getAge());
    }
}

class Student {
    private int age;

    public void setAge(int age) {
        if(age >= 7 && age <= 28){
            this.age = age;
        }
    }

    public int getAge() {
        return age;
    }
}
