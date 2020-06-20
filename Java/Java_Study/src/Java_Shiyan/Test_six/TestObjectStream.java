package Java_Shiyan.Test_six;

import java.io.*;

public class TestObjectStream {
    public static void main(String[] args) {
        ObjectOutputStream oos = null;
        ObjectInputStream ois = null;
        try{
            File f = new File("Person.object");
            oos = new ObjectOutputStream(new FileOutputStream(f));
            oos.writeObject(new Person("Andy"));
            oos.close();

            ois = new ObjectInputStream(new FileInputStream(f));
            Person d = (Person) ois.readObject();
            System.out.println(d.getName());
            ois.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

class Person implements Serializable {

    String name = null;

    public Person(String s) {
        this.name = s;
    }

    public String getName() {
        return name;
    }
}
