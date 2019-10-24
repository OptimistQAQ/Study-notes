package Java_one;

import java.math.BigDecimal;
public class BigDecimalDemo {
    static final int location = 10;
    //定义加法
    public BigDecimal add(double value1 , double value2){
        BigDecimal b1 = new BigDecimal(Double.toString(value1));
        BigDecimal b2 = new BigDecimal(Double.toString(value2));
        return b1.add(b2);
    }
    //定义减法
    public BigDecimal sub(double value1 , double value2){
        BigDecimal b1 = new BigDecimal(Double.toString(value1));
        BigDecimal b2 = new BigDecimal(Double.toString(value2));
        return b1.subtract(b2);
    }
    //定义乘法
    public BigDecimal mul(double value1 , double value2){
        BigDecimal b1 = new BigDecimal(Double.toString(value1));
        BigDecimal b2 = new BigDecimal(Double.toString(value2));
        return b1.multiply(b2);
    }
    public static void main(String[] args) {
        BigDecimalDemo b = new BigDecimalDemo();
        System.out.println("两个数字相加的结果：" + b.add(-7.5, 8.9));
        System.out.println("两个数字相减的结果：" + b.sub(-7.5, 8.9));
        System.out.println("两个数字相乘的结果：" + b.mul(-7.5, 8.9));
    }
}
