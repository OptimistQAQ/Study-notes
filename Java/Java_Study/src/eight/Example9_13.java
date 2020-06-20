package eight;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Example9_13 {
    public static void main(String[] args) {
        String cost = "市话 76.8元，长途：137.38元，短信12.68元";
        double priceSum = GetPrice.givePriceSum(cost);
        System.out.printf("%s\n总价： %.2f元\n", cost, priceSum);
    }
}

class GetPrice{
    public static double givePriceSum(String cost) {
        Scanner scanner = new Scanner(cost);
        scanner.useDelimiter("[^0123456789.]+");
        double sum = 0;
        while (scanner.hasNext()) {
            try {
                double price = scanner.nextDouble();
                sum += price;
            } catch (InputMismatchException exp) {
                String t = scanner.next();
            }
        }
        return sum;
    }
}
