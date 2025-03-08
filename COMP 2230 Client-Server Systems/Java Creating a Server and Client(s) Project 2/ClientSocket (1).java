import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

// Name: Alexander Bordenet
// Date: 2/28/25
// Purpose: To create a client socket that will connect with the server socket in order to send numbers to be used for generating random numbers
// Then receive the result back.

// Protocol:
// A : from the server means that it expects a response
// A x from the client means that the server should close
// A g from the client means that the server should generate a number
// A a from the client means that the server should send all the numbers
// A m from the client means that the server should send their numbers





public class ClientSocket {

    public static void main(String[] args) {

        //initialize the Socket and BufferedReader to null, so if they fail to create the code won't completely break
        Socket client = null;
        BufferedReader serverOutput = null;
        Scanner in = new Scanner(System.in);


        // Attempt to create the socket and bufferedReader for the input from the server
        try {
            client = new Socket("localhost", 5000);
            serverOutput = new BufferedReader(
                    new InputStreamReader(client.getInputStream()));
            PrintWriter output = new PrintWriter(client.getOutputStream(), true);


            //Sent to the server to see if it is connected or not
            output.println("Hello");

            // Expects a 'Connected!' in return
            // If not, throw error

            String serverMessage = serverOutput.readLine();

            if (serverMessage.equals("Connected!")) {

                //While loop to continue generating numbers
                while ((serverMessage = serverOutput.readLine()) != null) {



                    System.out.println(serverMessage);

                    if(serverMessage.contains(":")){
                        String userChoice = in.nextLine();
                        while(userChoice.isEmpty()){
                            System.out.println("Invalid option, try again: ");
                            userChoice = in.nextLine();
                        }
                        output.println(userChoice);
                        if(userChoice.equals("x")){
                            System.out.println("Closing connection!");
                            break;
                        }
                    }
                }
            } else {
                throw new RuntimeException();
            }
        }
        catch(IOException e){
            //throw new RuntimeException(e);
            System.out.println("Connect lost!");
        }
    }
}