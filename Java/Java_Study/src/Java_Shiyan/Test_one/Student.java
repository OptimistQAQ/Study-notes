package Java_Shiyan.Test_one;

public class Student {
    private String name;
    private int age;

    public void setAge(int age) {
        this.age = age;
    }

    public int getAge() {
        if (age >= 20 && age <=30){
            return age;
        }
        else
            return -1;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void study(){
        System.out.println(name + " " + age + " study");
    }
}
