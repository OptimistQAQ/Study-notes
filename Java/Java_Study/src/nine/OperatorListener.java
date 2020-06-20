package nine;

import javax.swing.*;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;

public class OperatorListener implements ItemListener {

    JComboBox choice;
    ComputerListener workTogether;

    public void setChoice(JComboBox choice) {
        this.choice = choice;
    }

    public void setWorkTogether(ComputerListener workTogether) {
        this.workTogether = workTogether;
    }

    @Override
    public void itemStateChanged(ItemEvent itemEvent) {
        String fuhao = choice.getSelectedItem().toString();
        workTogether.setFuhao(fuhao);
    }
}
