import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.ArrayList;

// Name: Alexander Bordenet
// Date: 2/26/25-3/5/25
// Purpose: This will handle each of the clients interactions with the server


public class ServerConn extends Thread{

    Socket clientSocket;
    ServerSocketV2 serverInstance;
    ArrayList<Integer> myNumbers = new ArrayList<>();

    public ServerConn(Socket cs, ServerSocketV2 ss){
        clientSocket = cs;
        serverInstance = ss;
    }


    public void run(){
        try {
            // Initialize both the input from the client and output to the client
            BufferedReader clientInput = new BufferedReader( new InputStreamReader(clientSocket.getInputStream()));
            PrintWriter toClient = new PrintWriter(clientSocket.getOutputStream(), true);


            // If the client sent hello, to show connection
            if(clientInput.readLine().equals("Hello")) {

                // Send Connected! to client to show they are connected
                toClient.println("Connected!");
                System.out.println("Hello hello, the client sent hello!");

                // Initial display of the options for the loop
                toClient.println("""
                        
                        Type 'x' for exit, 'a' to get all numbers, or 'm' for your numbers
                        Type 'g,a,b' to generate a number where a is the lower bound and b is the upper bound!:\s""");


                String input;
                while ((input = clientInput.readLine()) != null) {

                    // Checks to see that the server still exists
                    // If not, break this connection
                    if(!serverInstance.isAlive()){
                        break;
                    }

                    //Use just the first character of the input to determine the operation
                    String operation = input.substring(0, 1);

                    switch (operation) {
                        case "x" -> { // exit/close server
                            ServerSocketV2.closeServer();
                            break;
                        }
                        case "a" -> {  // get all numbers
                            toClient.println(serverInstance.getRandomNumbers());
                            break;
                        }
                        case "m" -> { // get their numbers
                            toClient.println(myNumbers);
                            break;
                        }
                        case "g" -> { // generate a new number
                            int low, up, commaPos, rand;
                            commaPos = input.indexOf("," , input.indexOf(",") +1);

                            up = Integer.parseInt(input.substring(commaPos+1));
                            low = Integer.parseInt(input.substring(2, commaPos));

                            // A swap for the bounds, if the user enters a larger lower bound than upper bound.
                            if(low > up){
                                int temp = low;
                                low = up;
                                up = temp;
                            }

                            rand = serverInstance.generateNumber(low, up);
                            myNumbers.add(rand);
                            toClient.println("Here is your generated number from " + low + " to " + up + " is " + rand);
                            break;
                        }
                        default -> {
                            System.out.println("Invalid option");
                            toClient.println("Invalid option, try again.");
                            break;
                        }
                    }

                    // The user wants to exit, so break the loop
                    if(operation.equals("x"))
                        break;

                    // Send the client the options
                    toClient.println("""
                        
                        Type 'x' for exit, 'a' to get all numbers, or 'm' for your numbers
                        Type 'g,a,b' to generate a number where a is the lower bound and b is the upper bound!:\s""");

                }
            }
            else {
                System.out.println("Failed to connect!");
            }
        } catch (Exception e) {
            //e.printStackTrace();
            System.out.println("Client disconnected.");

        }
    }
}
