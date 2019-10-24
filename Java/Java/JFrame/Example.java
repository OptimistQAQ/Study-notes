package JFrame;

import java.awt.*;
import javax.swing.*;
public class Example extends JFrame{
    private void CreatJFrame(String title){
        JFrame jf = new JFrame(title);
        Container container = jf.getContentPane();
        JLabel jl = new JLabel("你猜我想干嘛？");
        jl.setHorizontalAlignment(SwingConstants.CENTER);
        container.add(jl);
        container.setBackground(Color.blue);
        jf.setVisible(true);
        jf.setSize(200,150);
        jf.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
    }
    public static void main(String[] args){
        new Example().CreatJFrame("今天是中秋节！");
    }
}
