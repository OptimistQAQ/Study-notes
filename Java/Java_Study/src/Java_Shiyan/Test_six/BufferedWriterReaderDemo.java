package Java_Shiyan.Test_six;

import java.io.*;

public class BufferedWriterReaderDemo {
    public static void main(String[] args) {

        File fWrite = new File("a.txt");
        File fRead = new File("b.txt");

        try {

            Writer out = new FileWriter(fWrite);
            BufferedWriter bw = new BufferedWriter(out);
            Reader in;
            BufferedReader br;

            for (int i=0; i<8; i++) {
                bw.write("abc");
                bw.newLine();
                bw.flush();
            }
            bw.close();
            out.close();

            out = new FileWriter(fRead);
            bw = new BufferedWriter(out);
            in = new FileReader(fWrite);
            br = new BufferedReader(in);
            String line = null;
            while ((line = br.readLine()) != null) {
                System.out.println(line);
                bw.write(line);
                bw.newLine();
                bw.flush();
            }
            br.close();
            in.close();
            bw.close();
            out.close();
        }
        catch (IOException e) {
            e.getMessage();
            System.out.println(e.toString());
        }
    }
}
