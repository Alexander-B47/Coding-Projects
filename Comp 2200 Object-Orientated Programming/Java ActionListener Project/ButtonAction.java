import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ButtonAction  implements ActionListener {
    private TextField textBox;
    public ActionListenerTest x;
    ButtonAction(TextField text, ActionListenerTest xy)
    {
        textBox = text;
        x = xy;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        x.setTimesChecked(x.getTimesChecked()-1);
        textBox.setText("You clicked the Button! Now count is " + x.getTimesChecked() + " Times!\nBoo!");
    }
}
