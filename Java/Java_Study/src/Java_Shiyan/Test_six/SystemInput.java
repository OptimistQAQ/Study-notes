package Java_Shiyan.Test_six;

import java.io.*;

public class SystemInput {
    public static void main(String[] args) {
        BufferedReader br = null;
        BufferedWriter bw = null;
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String line = null;

        try{
            while ((line = br.readLine()) != null) {
                String s = line.toUpperCase();
                bw.write(s);
                bw.newLine();
                bw.flush();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        finally
        {
            try{
                br.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
            try {
                bw.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
