package com;

public class Activity {
    public Activity(){
        this("this调用有参构造方法");
        System.out.println("无构造方法");
    }
    public Activity(String name){
        System.out.println("有参构造方法");
        System.out.println(name);
    }
    public static void main(String[] args){
        new Activity();
    }
}
