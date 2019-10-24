package Lian_biao;

class Node{
    private String data;
    private Node next;
    public Node(String data){
        this.data = data;  //必须要有数据才有data
    }
    public void setData(String data) {
        this.data = data;
    }
    public String getData() {
        return data;
    }
    public void setNext(Node next) {
        this.next = next;
    }
    public Node getNext() {
        return next;
    }
}

class Node2{
    private String data;
    private Node2 next;
    public Node2(String data){
        this.data = data;
    }
    public String getData() {
        return data;
    }
    public void setData(String data) {
        this.data = data;
    }
    public Node2 getNext() {
        return next;
    }
    public void setNext(Node2 next) {
        this.next = next;
    }
    /*
    ***实现节点的增加
    ***第一次调用(Link) this = Link.root
    ***第二次调用(Link) this = Link.root.next
    ***以此类推
     */

    public void addNode(Node2 newNode){
        if(this.next == null){   //当前节点的下一个节点为空
            this.next = newNode;   //保存这个新节点
        }else{    //当前节点的下一个节点还存在节点
            this.next.addNode(newNode);   //继续往下保存
        }
    }

    public void print(){    //输出
        System.err.print(this.data + "\n");
        if(this.next != null){
            this.next.print();
        }
    }
}

class Link{    //增加节点
    private Node2 root;   //根节点
    /*
    *向链表中增加新的数据
     */
    public void add(String data){
        Node2 newNode2 = new Node2(data);  //将data包装在一个Node对象中
        if(this.root == null) {   //一个链表只有一个根节点
            this.root = newNode2;
        }else{
            this.root.addNode(newNode2);   //由Node类来进行节点保存
        }
    }

    public void print(){   //数据输出
        if(this.root != null){  //存在根节点
            this.root.print();  //交由Node类进行输出
        }
    }
}

public class TestDemo {
    public static void main(String[] args) {
        Node root = new Node("开车了开车了");      //定义一个对象
        Node n1 = new Node("快上车快上车");  //定义一个对象
        Node n2 = new Node("走了走了!!");  //定义一个对象

        root.setNext(n1);
        n1.setNext(n2);

        print(root);
        System.out.println("*******************");
        Link link = new Link();
        link.add("中北大学");
        link.add("大数据学院");
        link.add("18070041班");
        link.add("1807004120秦嘉豪");
        link.print();
    }

    private static void print(Node p){
        if(p == null)  //如果p为空，则返回
            return;
        System.out.println(p.getData());
        print(p.getNext());    //递归
    }
}
