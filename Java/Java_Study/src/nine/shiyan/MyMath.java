package nine.shiyan;

import java.math.BigDecimal;

public class MyMath {
    /**
     * 为一个double类型创建BigDecimal对象
     */
    private static BigDecimal getBigDecimal(double number){
        return new BigDecimal(number);
    }
    public static double add(double num1, double num2) {
        BigDecimal first = getBigDecimal(num1);
        BigDecimal second = getBigDecimal(num2);
        return first.add(second).doubleValue();
    }
    public static double subtract(double num1, double num2) {
        BigDecimal first = getBigDecimal(num1);
        BigDecimal second = getBigDecimal(num2);
        return first.subtract(second).doubleValue();
    }
    public static double multiply(double num1, double num2) {
        BigDecimal first = getBigDecimal(num1);
        BigDecimal second = getBigDecimal(num2);
        return first.multiply(second).doubleValue();
    }
    public static double divide(double num1, double num2) {
        BigDecimal first = getBigDecimal(num1);
        BigDecimal second = getBigDecimal(num2);
        return first.divide(second,3,BigDecimal.ROUND_HALF_UP).doubleValue();
    }
}
