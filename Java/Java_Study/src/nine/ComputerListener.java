package nine;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ComputerListener implements ActionListener {

    JTextField inputNumberOne, inputNumberTwo;
    JTextArea textShow;
    String fuhao;

    public void setInputNumberOne(JTextField inputNumberOne) {
        this.inputNumberOne = inputNumberOne;
    }

    public void setInputNumberTwo(JTextField inputNumberTwo) {
        this.inputNumberTwo = inputNumberTwo;
    }

    public void setTextShow(JTextArea textShow) {
        this.textShow = textShow;
    }

    public void setFuhao(String fuhao) {
        this.fuhao = fuhao;
    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {
        try{
            double number1 = Double.parseDouble(inputNumberOne.getText());
            double number2 = Double.parseDouble(inputNumberTwo.getText());
            double result = 0;
            if(fuhao.equals("+"))
                result = number1 + number2;
            else if(fuhao.equals("-"))
                result = number1 - number2;
            else if(fuhao.equals("*"))
                result = number1 * number2;
            else if(fuhao.equals("/"))
                result = number1 / number2;
            textShow.append(number1 + " " + fuhao + " " + number2 + " = " + result + "\n");
        }
        catch (Exception exp){
            textShow.append("\n请输入数字字符\n");
        }
    }
}
