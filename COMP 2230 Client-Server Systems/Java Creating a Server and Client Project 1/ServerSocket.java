import java.io.*;
import java.net.Socket;
import java.util.Random;

// Name: Alexander Bordenet
// Date: 2/21/25
// Purpose: To create a server socket and generate a random number based on what the client's socket sends for the bounds.


public class ServerSocket {

    public static int generateNumber(int lowBound, int upBound) {
        Random randy = new Random();
        return lowBound + randy.nextInt(upBound - lowBound + 1);
    }

    public static void writeToSocket(Socket clientSocket, int randomNumber) throws IOException {
        PrintWriter toClient = new PrintWriter(clientSocket.getOutputStream(), true);

        toClient.println(randomNumber);
        System.out.println("Number to be send: " + randomNumber);
    }


    // This function will first read from the socket and then parse the input to integers to generate a random integer
    // Then write to the socket with the result.
    public static void readFromSocket(BufferedReader fromClient, Socket clientSocket) throws IOException {
        int lowBound;
        int upBound;
        String input;
        try {
            System.out.println("Trying to read...");
            input = fromClient.readLine();

            System.out.println("lower bound: " + input);
            lowBound = Integer.parseInt(input);
            input = fromClient.readLine();
            System.out.println("Upper bound: " + input);
            upBound = Integer.parseInt(input);

            int randomNumber = generateNumber(lowBound, upBound);
            writeToSocket(clientSocket, randomNumber);

        }
        // Throws exception to main because it is in a loop in main
        catch (IOException e) {
            throw new IOException(e);
        }
    }

    public static void main(String[] args){

        try {
            java.net.ServerSocket serverSocket = new java.net.ServerSocket(5000);
            Socket clientSocket = serverSocket.accept();
            BufferedReader clientInput = new BufferedReader(
                                         new InputStreamReader(clientSocket.getInputStream()));

            // Checks that the connection has been made and that the socket was not closed.S
            while (clientSocket.isConnected() && !clientSocket.isClosed()) {
                System.out.println("\nStill connected!");
                readFromSocket(clientInput, clientSocket);
            }

        }
        // Main handles the error and closes the program without crashing, whenever the socket gets closed
        catch(IOException e){
            System.out.println("Error occurred!");
        }
    }
}