package Collatz;

import org.knowm.xchart.QuickChart;
import org.knowm.xchart.SwingWrapper;
import org.knowm.xchart.XYChart;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

//Date: 11/16/24
//Name: Alexander Bordenet
//Purpose: To prompt the user to give a number and use it to perform Collatz and display
//The results in a chart and steps

public class Collatz extends JFrame {
    private static final int INVALID_INPUT = 0;
    private double closedInitialPrompt = 0.0;
    private int collatzCount = 0;
    private final ArrayList<Double> yData = new ArrayList<>();
    private final ArrayList<Integer> xData = new ArrayList<>();
    private boolean continueCollatz = true;
    private final JPanel stepsPanel = new JPanel(new FlowLayout(FlowLayout.CENTER, 10 , 10));

    public Collatz(){
        setTitle("Collatz.Collatz Visualization");
        setSize(1000, 1000);
        //setLocation(800 , 522);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        redoLayouts();
        doCollatz(); //The Collatz-ing
    }

    // The point of this function is to call other functions and validation for whether it should be performed or not
    private void doCollatz() {
        double userVal = getStartingVal();
        if (closedInitialPrompt == -0.1) {
            dispose();
        }
        else {
            setVisible(true);
            performStepsForCollatz(userVal);
        }
    }

    private int getStartingVal() {
        String rawVal = JOptionPane.showInputDialog(null, "Enter a positive integer: "
                                                    , "Collatz Starting value" , JOptionPane.QUESTION_MESSAGE);
        //They cancelled or closed the dialog
        if(rawVal == null || rawVal.isEmpty()) {
            closedInitialPrompt = -0.1;
            JOptionPane.showMessageDialog(null ,"Okay, fine, don't enter a positive integer!");
        }
        else if(userValIsDigit(rawVal)){
            return Integer.parseInt(rawVal);
        }
        return -1;
    }

    private void performStepsForCollatz(double userVal) {

        if(userVal < INVALID_INPUT) {
            JLabel failed = new JLabel("Wrong thing, bro! Not a positive integer");
            JFrame error = new JFrame();
            error.add(failed);
            error.setSize(300 , 300);
            error.setVisible(true);
        }
        else {
            displaySteps(userVal);
            double startingValue = userVal;
            while (userVal > 1) {
                userVal = performCollatz(userVal);
                yData.add(userVal);
                xData.add(collatzCount);
                displaySteps(userVal);
            }

            // This should hopefully catch if the user decides to enter a 1 as the starting value
            if(collatzCount == 1 || userVal == 1)  {
                yData.add(1.0);
                xData.add(collatzCount);
            }
            JOptionPane.showMessageDialog(null, (int)(startingValue) + " took " +
                                          collatzCount + " steps to finish!");
            createXYChart();
        }
    }

    private  void displaySteps(double userVal) {
        JLabel start = new JLabel("Step " + (collatzCount + 1) + ": " + (int) (userVal));
        stepsPanel.add(start);
        collatzCount++;
    }

    private void createXYChart() {
        // Data must be converted to a double array to be used
        double[] yData2 = yData.stream().mapToDouble(Double::doubleValue).toArray();
        double[] xData2 = xData.stream().mapToDouble(Integer::intValue).toArray();
        XYChart chart = QuickChart.getChart("Collatz", "Collatz Step",
                                      "Collatz Value", "Collatz Sequence", xData2, yData2);
        SwingWrapper<XYChart> newChart = new SwingWrapper<>(chart);
        new Thread(newChart::displayChart).start();
    }

    // Validation to ensure the user followed directions
    private boolean userValIsDigit(String x) {
        for(char c : x.toCharArray()) {
            if(!Character.isDigit(c))
                return false;
        }
        return true;
    }

    // Not recursive because it is necessary for my chart to get each value
    // before putting it back into the function
    private double performCollatz(double seedVal) {
        if(seedVal % 2 == 1) {
            seedVal = seedVal*3 +1;
        }
        else {
            seedVal = (seedVal/2);
        }
        return seedVal;
    }

    // Returns a JButton that will be responsible for restarting the process of making a Collatz
    private JButton goNextButton() {

        JButton button = new JButton("Make new Collatz?");
        button.setSize(100,100);

        // Anonymous inner class for the action listener
        button.addActionListener(new ActionListener() {
            @Override
            // If button is pressed: see if user wants to make another Collatz, if so re-setup the JFrame and doCollatz
            public void actionPerformed(ActionEvent e) {
                continueCollatz = userContinuePrompt();
                if(continueCollatz) {
                    cleanup();
                    goNextButton();
                    doCollatz();
                }
            }
        });
        return button;
    }

    // This handles checking whether the user wants to make another collatz
    private boolean userContinuePrompt() {
        boolean temp = false;
        int choice = JOptionPane.showConfirmDialog(null, "Do you wish to perform another Collatz?"
                                                   ,"Continue?", JOptionPane.YES_NO_CANCEL_OPTION);

        if (choice == JOptionPane.NO_OPTION || choice == JOptionPane.CLOSED_OPTION) {
            JOptionPane.showMessageDialog(null, "Okay, Bye!");
            cleanup();
        }
        else if (choice == JOptionPane.CANCEL_OPTION) {
            JOptionPane.showMessageDialog(null, "Okay, bye!");
        }
        else if (choice == JOptionPane.YES_OPTION) {
            temp = true;
            cleanup();
        }
        return temp;
    }

    // Handles; cleaning up the pane, reformatting it, and resetting what is needed to generate another graph
    private void cleanup() {
        getContentPane().removeAll();
        repaint();
        stepsPanel.removeAll();
        repaint();
        collatzCount = 0;
        yData.clear();
        xData.clear();
        redoLayouts();
        dispose();
    }

    private void redoLayouts() {
        JPanel buttonPanel = new JPanel();
        buttonPanel.add(goNextButton());
        JSplitPane halfIt = new JSplitPane(JSplitPane.VERTICAL_SPLIT, buttonPanel , stepsPanel);
        add(halfIt);
    }

    public static void main(String[] args) {
        new Collatz();
    }
}
