package nine.shiyan;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Arrays;

public class CalFrame extends JFrame {
    /**
     * 计算器的外观设计
     */
    private static final long serialVersionUID = 1L;
    private final static int PRE_WIDTH = 500;
    private final static int PRE_HEIGHT = 400;

    private JTextField text = null;
    private JButton button = null; //存储标记

    private String[] nOp = {"7","8","9","/","sqrt","4","5","6","*","%","1","2","3","-","1/x","0","+/-",".","+","="};
    private String[] mOp = {"MC","MR","MS","M+"};
    private String[] rOp = {"Back","CE","C"};
    private CalService service = new CalService();

    public CalFrame(){
        this.setTitle("计算器");
        this.setSize(PRE_WIDTH, PRE_HEIGHT);
        this.setLocationRelativeTo(null);
        this.setResizable(false);

        //添加底层
        JPanel panel = new JPanel();
        panel.setLayout(new BorderLayout(10,1));
        panel.add(getTextField(), BorderLayout.NORTH);
        panel.setPreferredSize(new Dimension(PRE_WIDTH, PRE_HEIGHT));

        //WEST
        JButton[] mButton = getMButton();
        JPanel panel1 = new JPanel();
        panel1.setLayout(new GridLayout(5,1,0,5));
        for(JButton b : mButton ){
            panel1.add(b);
        }
        panel.add(panel1,BorderLayout.WEST);
        //
        JButton[] rButton = getRButton();
        JPanel panel2 = new JPanel();
        panel2.setLayout(new BorderLayout(1,5));
        JPanel panel21 = new JPanel();
        panel21.setLayout(new GridLayout(1,3,3,3));
        for(JButton b : rButton){
            panel21.add(b);
        }
        panel2.add(panel21,BorderLayout.NORTH);

        JButton[] nButton = getNButton();
        JPanel panel22 = new JPanel();
        panel22.setLayout(new GridLayout(4,5,3,5));
        for(JButton b : nButton){
            panel22.add(b);
        }
        panel2.add(panel22,BorderLayout.CENTER);
        panel.add(panel2,BorderLayout.CENTER);

        this.add(panel);
        this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        this.setVisible(true);


    }
    //返回显示框
    private JTextField getTextField(){
        text = new JTextField("0",10);
        //text.setSize(480, 50);
        return text;
    }
    //返回数字键
    private JButton[] getNButton(){
        String[] redButton = {"/","*","-","+","="};
        JButton[] nbutton = new JButton[nOp.length];
        for(int i = 0; i < this.nOp.length; i++){
            JButton b = new JButton(this.nOp[i]);
            b.addActionListener(getActionListener());

            Arrays.sort(redButton);
            if(Arrays.binarySearch(redButton, nOp[i]) >= 0){
                b.setForeground(Color.red);
            }else{
                b.setForeground(Color.blue);
            }
            nbutton[i] = b;
        }
        return nbutton;
    }
    //返回操作健
    private JButton[] getMButton(){
        JButton[] mbutton = new JButton[mOp.length + 1];
        mbutton[0] = getButton();
        for(int i = 0; i < this.mOp.length; i++){
            JButton b = new JButton(this.mOp[i]);
            b.addActionListener(getActionListener());
            b.setForeground(Color.red);
            mbutton[i+1] = b;
        }
        return mbutton;
    }
    private JButton[] getRButton(){
        JButton[] rbutton = new JButton[rOp.length];
        for(int i = 0; i < this.rOp.length; i++){
            JButton b = new JButton(this.rOp[i]);
            b.addActionListener(getActionListener());
            b.setForeground(Color.red);
            rbutton[i] = b;
        }
        return rbutton;
    }
    private JButton getButton(){
        button = new JButton();
        return button;
    }
    private ActionListener getActionListener(){
        ActionListener actionListener = new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                String cmd = e.getActionCommand();
                String result = null;
                try {
                    result = service.callMethod(cmd, text.getText());
                } catch (Exception e2) {
                    System.out.println(e2.getMessage());
                }
                if(cmd.indexOf("MC") == 0){
                    button.setText("");
                }else if(cmd.indexOf("M") == 0){
                    button.setText("M");
                }
                //显示计算结果
                if(result != null){
                    text.setText(result);
                }

            }
        };
        return actionListener;
    }
    public static void main(String[] args) {
        new CalFrame();
    }
}
