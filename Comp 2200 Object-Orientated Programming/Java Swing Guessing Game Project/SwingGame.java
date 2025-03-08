import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;

// Name: N/A
// Date: 11/12/24
// Purpose: To create a number guessing game to show my understanding of swing

public class SwingGame extends JFrame{

    private final Random randy = new Random(); //Used to generate random number
    private int guess;
    private int numGuesses;
    private int toGuess;
    private JTextField userInputArea = new JTextField(10);
    private JLabel correctOrNot = new JLabel("");
    private JLabel congrats = new JLabel("");

    SwingGame(){
        toGuess = genNumToGuess();

        //Label to act as header
        JLabel firstLine = new JLabel("Welcome to number guessing game!");
        add(firstLine);

        //Label to prompt user to guess
        JLabel guessHeader = new JLabel("Please enter a guess (1-100):");
        add(guessHeader);

        //TextField to read in user's guess
        add(userInputArea);

        //JButton to have user confirm their selection
        JButton confirmGuess = new JButton("Confirm");
        add(confirmGuess);
        correctOrNot.setText("");
        confirmGuess.addActionListener(this::submit);
        add(correctOrNot);
        add(congrats);


        //Formatting and stuff
        setTitle("Number Guessing Game");
        setSize(500, 500);
        setLayout(new FlowLayout());
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    //generates random number
    public int genNumToGuess() {
        return randy.nextInt(1, 100);
    }

    public void submit(ActionEvent e) {
        guess = Integer.parseInt(userInputArea.getText());
        numGuesses++;
        boolean correct = verifyGuess(guess);
        if(correct) {
            correctOrNot.setText("You Got it!");
            displayCongrats();
        }
        else {
            String hotOrCold = hotCold(guess);
            correctOrNot.setText("Incorrect, try again.\n You are " + hotOrCold);
        }
    }


    // if they get it correct this should display this message
    public void displayCongrats() {
        //("Congrats! It took you " + numGuesses + " to get the right answer, which was " + toGuess);
        congrats.setText("Congrats! It took you " + numGuesses + " to get the right answer, which was " + toGuess);
    }

    //Verifies the guess
    public boolean verifyGuess(int guess) {
        return (guess == toGuess);
    }

    public String hotCold(int guess) {
        int guess2 = Math.abs(guess - toGuess);
        String temp;
        if(guess2 < 3) {
            temp = "super hot";
        }
        else if(guess2 <= 5) {
            temp = "hot";
        }
        else if (guess2 >= 6 && guess2 <= 10) {
            temp = "warm";
        }
        else if (guess2 >10 && guess2 <= 20) {
            temp = "cold";
        }
        else{
            temp = "ice cold";
        }
        return temp;
    }

    public static void main(String [] args) {
        new SwingGame();
    }

}
