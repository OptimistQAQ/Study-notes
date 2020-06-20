package Java_Shiyan.Test_one;

public class Teacher {
    private String name;
    private int age;

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public int getAge() {
        if (age >= 30 && age <= 70) {
            return age;
        }
        return -1;
    }

    public void teach(){
        System.out.println(name + " " + age + " teach");
    }
}
