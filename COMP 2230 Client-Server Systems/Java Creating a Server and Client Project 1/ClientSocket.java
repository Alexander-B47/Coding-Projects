import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

// Name: Alexander Bordenet
// Date: 2/21/25
// Purpose: To create a client socket that will connect with the server socket in order to send numbers to be used for generating random numbers
// Then receive the result back.



public class ClientSocket {

    public static void main(String[] args) {

        //initialize the Socket and BufferedReader to null, so if they fail to create the code won't completely break
        boolean continueGen = true;
        Socket client = null;
        BufferedReader serverOutput = null;
        Scanner in = new Scanner(System.in);


        // Attempt to create the socket and bufferedReader for the input from the server
        try {
            client = new Socket("localhost", 5000);
            serverOutput =  new BufferedReader(
                            new InputStreamReader(client.getInputStream()));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }



        //While loop to continue generating numbers
        while (continueGen) {
            try {
                PrintWriter output = new PrintWriter(client.getOutputStream(), true);



                //Ask user for the bounds
                System.out.print("\nPlease enter a lower bound (integer): ");
                int lowBound = in.nextInt();
                System.out.print("\nPlease enter an upper bound (integer): ");
                int upperBound = in.nextInt();

                // Send the bounds to the server for generation
                output.println(lowBound);
                output.println(upperBound);

                // Read from the socket and display the result
                System.out.println("Number generated: " + serverOutput.readLine());

                System.out.print("\nGenerate another number (y/n): ");
                String userChoice = in.next();

                if(userChoice.toLowerCase().contains("y")) {
                    continueGen = true;
                }
                else if (userChoice.toLowerCase().contains("n")) {
                    continueGen = false;
                }
                else {
                    System.out.println("Invalid Option!");
                    continueGen = false;
                }

            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
}