import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ActionListenerTest extends JFrame implements ActionListener {

    //The count TextField should hopefully display the timesChecked
    private int timesChecked = 0;
    static TextField count = new TextField(20);

    public void setTimesChecked(int timesChecked) {
        this.timesChecked = timesChecked;
    }

    public int getTimesChecked() {
        return timesChecked;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        timesChecked++;
        count.setText("You checked the box: " + timesChecked + " Times!\nYay!");
    }

    public static void main(String[] args) {
        ActionListenerTest x = new ActionListenerTest();
        ButtonAction y = new ButtonAction(count, x);
        GridLayout grid = new GridLayout(3, 3); // 3 rows & columns
        x.setSize(500, 500);
        x.setLayout(grid);

        //First, Checkbox
        JCheckBox checkBox = new JCheckBox("Check it out!");
        checkBox.addActionListener(x);
        x.add(checkBox);
        x.add(count);

        //Second, Button
        JButton button = new JButton("Don't click this button!");
        button.addActionListener(y);
        x.add(button);


        x.setVisible(true);
        x.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
}
