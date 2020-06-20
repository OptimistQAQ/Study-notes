package nine;

import javax.swing.*;
import java.awt.*;

public class WindowOperation extends JFrame {

    JTextField inputNumberOne, inputNumberTwo;
    JComboBox choiceFuhao;
    JTextArea textShow;
    JButton button;
    OperatorListener operator;
    ComputerListener computer;

    public WindowOperation(){
        init();
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    private void init(){
        setLayout(new FlowLayout());
        inputNumberOne = new JTextField(5);
        inputNumberTwo = new JTextField(5);
        choiceFuhao = new JComboBox();
        button = new JButton("计算");
        choiceFuhao.addItem("选择运算符号：");
        String [] a = {"+","-","*","/"};
        for(int i=0;i<a.length;i++){
            choiceFuhao.addItem(a[i]);
        }
        textShow = new JTextArea(9, 30);
        operator = new OperatorListener();
        computer = new ComputerListener();
        operator.setChoice(choiceFuhao);
        operator.setWorkTogether(computer);
        computer.setInputNumberOne(inputNumberOne);
        computer.setInputNumberTwo(inputNumberTwo);
        computer.setTextShow(textShow);
        choiceFuhao.addItemListener(operator);
        button.addActionListener(computer);
        add(inputNumberOne);
        add(choiceFuhao);
        add(inputNumberTwo);
        add(button);
        add(new JScrollPane(textShow));

    }

}
