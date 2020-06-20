package Java_Shiyan.Test_seven;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Test_Date {
    public static void main(String[] args) throws ParseException {

        String s1 = "2020-1-21";
        String s2 = "2020-4-30";

        DateFormat dateFormat = DateFormat.getDateInstance();

        SimpleDateFormat format = new SimpleDateFormat("yyyy-MM-dd");

        Date date1 = format.parse(s1);
        Date date2 = format.parse(s2);

        long t1 = date1.getTime();
        long t2 = date2.getTime();

        long t = Math.abs(t1 - t2);

        System.out.println(t/1000/60/60/24);

    }
}
