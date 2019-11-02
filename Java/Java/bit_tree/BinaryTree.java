package bit_tree;

import java.util.Stack;

public class BinaryTree {

    public static class Node{
        int data;
        Node left_child;
        Node right_child;

        Node(int data){
            this.data = data;
            left_child = null;
            right_child = null;
        }

        void display(){
            System.out.println(data + "\t");
        }
    }

    public static void main(String[] args) {
        int[] data = {2,4,1,9,10,40,100,6,70,30};
        BinaryTree binaryTree = new BinaryTree();
        Node root = null;
        for(int i=0;i < data.length;i++){
           root = binaryTree.insertNode(root,data[i]);
        }

        System.out.println("前序遍历：");
        binaryTree.preOrderTree(root);
//        binaryTree.preOrderTreeStack(root);
    }

    //前序遍历递归
    private void preOrderTree(Node root){
        if(root == null)
            return;
        root.display();
        preOrderTree(root.left_child);
        preOrderTree(root.right_child);
    }

    //前序遍历，压栈（非递归）
    private void preOrderTreeStack(Node root){
        Stack<Node> nodes = new Stack<Node>();
        Node current = root;
        while(current != null || !nodes.isEmpty()){
            while (current != null){
                current.display();
                nodes.push(current);
                current = current.left_child;
            }
            if(!nodes.isEmpty()){
                current = nodes.pop();
                current = current.right_child;
            }
        }
    }

    private Node insertNode(Node root, int data){
        Node current = new Node(data);
        if(root == null){
            root = current;
            return root;
        }
        if(root.data < data){
            if(root.right_child == null){
                root.right_child = current;
            }else{
                root.right_child = insertNode(root.right_child,data);
            }
        }else{
            if(root.left_child == null){
                root.left_child = current;
            }else{
                root.left_child = insertNode(root.left_child,data);
            }
        }
        return root;
    }

}
