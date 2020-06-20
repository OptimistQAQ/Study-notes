package algorithm;

import javax.swing.*;
import java.awt.*;
import java.util.*;

import static java.lang.Math.toDegrees;

public class ConvexHull extends JFrame  {

    public static void main(String[] args){

        new ConvexHull(); //画图窗口

    }

    // 构造方法，定义画图窗口
    private ConvexHull(){
        Show show = new Show(); // 构造组件
        this.add(show); // 加入组件
        //设置窗体
        this.setSize(500,500);
        this.setTitle("分治法解决二维凸包问题");
        this.setVisible(true);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
}

// 绘图窗口组件
    static class Show extends JPanel{
        private static final long serialVersionUID = 1L;
        @Override
        public void paint(Graphics g) {
            super.paint(g);

            ArrayList<Point> points = get_points();
            System.out.println("所有的点：");
            ArrayListPrint(points);
            g.setColor(Color.BLUE);
            for(int i=0;i<=points.size()-1;i++){
                g.fillOval(points.get(i).x,points.get(i).y,6,6); //画随机点
            }

            ArrayList<Point> endpoint=get_endpoint(points);
            endpoint.sort(new Comparator<Point>() { //按照角度从小到大排序
                @Override
                public int compare(Point o1, Point o2) {
                    if (getAngle(o1, get_center(endpoint)) < getAngle(o2, get_center(endpoint)))
                        return -1;
                    if (getAngle(o1, get_center(endpoint)) > getAngle(o2, get_center(endpoint)))
                        return 1;
                    return 0;
                }
            });

            g.setColor(Color.RED);
            for(int i=0;i<=endpoint.size()-1;i++) {
                if (i == endpoint.size()-1){
                    g.drawLine(endpoint.get(i).x+3,endpoint.get(i).y+3,endpoint.get(0).x+3,endpoint.get(0).y+3);
                }else{
                    g.drawLine(endpoint.get(i).x+3,endpoint.get(i).y+3,endpoint.get(i+1).x+3,endpoint.get(i+1).y+3);
                }
            }
            System.out.println("凸包顶点：");
            ArrayListPrint(endpoint);
        }
    }

//得到凸包端点数组的中心点
    private static Point get_center(ArrayList<Point> endpoint){
        double X = 0, Y = 0;
        for (Point point : endpoint) {
            X += point.x;
            Y += point.y;
        }
        Point center = new Point((int)X / endpoint.size(),(int)Y / endpoint.size());
        return center;
    }

//得到随机点数组
    private static ArrayList<Point> get_points(){
        ArrayList<Point> points=new ArrayList<Point>(); //用来存储元素为Point的数组
        for(int i=0;i<100;i++)
            points.add( new Point(new Random().nextInt(400), new Random().nextInt(400)));
        points.sort(new Comparator<Point>() { //按照x从小到大排序
            @Override
            public int compare(Point o1, Point o2) {
                return Integer.compare(o1.x, o2.x);
            }
        });
        return  points;
    }

//得到凸包端点数组（已按与中心点角度大小逆时针排序）
    private static ArrayList<Point> get_endpoint(ArrayList<Point> points){
        ArrayList<Point> endpoint=new  ArrayList<Point>(); //用来存储凸包端点
        int left=0;
        int right=points.size()-1;
        endpoint.add(points.get(left));
        endpoint.add(points.get(right)); //将x轴方向上的左右端点加入数组
        findUpPoint(left,right,points,endpoint); //寻找上凸包端点
        findDownPoint(left,right,points,endpoint);  //寻找下凸包端点
        return endpoint;
    }

//寻找上凸包中的端点
    private static void findUpPoint(int left, int right, ArrayList<Point> points, ArrayList<Point> endpoint) {
         int distance =Integer.MIN_VALUE;
         int biggest=0;
        int direction=0;
         Point left_point=points.get(left);
         Point right_point=points.get(right);
        for(int i=left;i<=right;i++){ //对left和right之间的点进行遍历
            Point temp = points.get(i);
            int temp_distance = get_distance(left_point,right_point,temp); //计算当前到left，right所在直线的距离
            if(get_direction(left_point,right_point,temp)<0) { //筛选出上凸包中的点
               direction=get_direction(left_point,right_point,temp);
                if (temp_distance >= distance) { //距离直线最远的点
                    distance = temp_distance;
                    biggest = i;
                }
            }
        }
        if(distance > 0|| direction<0){
            endpoint.add(points.get(biggest));
            findUpPoint(biggest,right,points,endpoint);
            findUpPoint(left,biggest,points,endpoint);
        } //找不到点或者点在直线上，递归结束
    }

//寻找下凸包中的端点
    private static void findDownPoint(int left,int right,ArrayList<Point> points,ArrayList<Point> endpoint) {
        int distance=Integer.MAX_VALUE;
        int biggest=0;
        int direction=0;
        Point left_point=points.get(left);
        Point right_point=points.get(right);
        for(int i=left;i<=right;i++){ //对left和right之间的点进行遍历
            Point temp = points.get(i);
            int temp_distance = get_distance(left_point,right_point,temp); //计算当前到left，right所在直线的距离
            if(get_direction(left_point,right_point,temp)>0) { //筛选出下凸包中的点
                direction=get_direction(left_point,right_point,temp);
                if (temp_distance <= distance) { //距离直线最远的点
                    distance = temp_distance;
                    biggest = i;
                }
            }
        }
        if(distance < 0 || direction>0){
            endpoint.add(points.get(biggest));
            findDownPoint(left,biggest,points,endpoint);
            findDownPoint(biggest,right,points,endpoint);
        } //找不到点或者点在直线上，递归结束
    }

//计算凸包顶点与其中心点的夹角
     private static double getAngle(Point a, Point center) {
        double angle = Math.atan2(a.y-center.y, a.x-center.x);
        angle= toDegrees(angle);
        if (angle < 0)
            angle = angle + 360.0;
        return angle;
    }

//计算点到端点划分线的距离
    private static int get_distance(Point left_point, Point right_point, Point temp) {
        return (left_point.x * right_point.y + temp.x * left_point.y + right_point.x * temp.y - temp.x * right_point.y-right_point.x * left_point.y + left_point.x * temp.y);
    }

//判断点的方位（顺时针还是逆时针）,小于零则最大端点为上凸包中的点（逆时针），大于零为下凸包中的点（顺时针）
    private static int get_direction(Point left_point, Point right_point, Point temp){
        return ((temp.x-left_point.x)*(right_point.y-left_point.y))-((right_point.x-left_point.x)*(temp.y-left_point.y)) ;
    }

    private static void ArrayListPrint(ArrayList<Point> point) {
        for (Point value : point) {
            System.out.print("( " + value.x + "," + value.y + " ) ");
        }
        System.out.println();
    }
}
