package Java_Shiyan.Test_seven;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Test_JFrame extends JFrame implements ActionListener {

    public JLabel j = null;
    public JLabel j2 = null;

    public JTextField jTextField = null;
    public JTextField jTextField2 = null;

    public JButton jButton = null;

    int num = 0;

    public Test_JFrame() {
        setLayout(new FlowLayout(FlowLayout.LEFT, 80, 60));
        setFont(new Font("Test_seven", Font.PLAIN, 14));
        j = new JLabel("双击次数");
        j2 = new JLabel("密码");
        jTextField = new JTextField(20);
        jTextField2 = new JTextField(10);
        jButton = new JButton("点击");

        getContentPane().add(j);
        getContentPane().add(jTextField);
        getContentPane().add(jButton);
        jButton.addActionListener(this);
    }

    public static void main(String[] args) {
        Test_JFrame window = new Test_JFrame();
        window.setTitle("演示鼠标和键盘监听");
        window.pack();
        window.setVisible(true);
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.setLocationRelativeTo(null);
    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {
        if (actionEvent.getSource() == jButton) {
            num++;
            if (num % 2 == 0) {
                jTextField.setText("mouse clicked count " + num/2 + "");
            }
        }
    }
}
