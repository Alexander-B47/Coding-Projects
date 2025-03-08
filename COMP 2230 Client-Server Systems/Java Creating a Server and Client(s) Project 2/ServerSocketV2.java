import java.io.IOException;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Random;

// Name: Alexander Bordenet
// Date: 2/26/25-3/5/25
// Purpose: To expand on my first version of my Server class, now with the ability to handle multiple clients.

public class ServerSocketV2 extends Thread{

    ArrayList<Integer> allRandomNumbers = new ArrayList<>();
    static java.net.ServerSocket serverSocket;


    public static void closeServer() throws IOException {
        serverSocket.close();
    }

    public int generateNumber(int lowBound, int upBound) {
        Random randy = new Random();
        int randomNumber = (lowBound + randy.nextInt(upBound - lowBound + 1));
        allRandomNumbers.add(randomNumber);
        return randomNumber;
    }

    public ArrayList getRandomNumbers(){
        return allRandomNumbers;
    }

    public void run() {
        try {
            while(!serverSocket.isClosed()) {
                Socket clientSocket = serverSocket.accept();

                // Passes in your socket that is now connected with your specific client
                // Passes in 'this' which is the instance of the ServerSocketV2 class
                // This is so each ServerConn can access the methods of the ServerSocketV2 class
                new ServerConn(clientSocket, this).start();
            }

        }
        // Run handles the error and closes the program without crashing, whenever the socket gets closed
        catch (Exception e) {
            System.out.println("Server closed!\nPossibly error caused.");
        }
    }
    public static void main(String[] args){
        try {
            serverSocket = new java.net.ServerSocket(5000);
            new ServerSocketV2().start();
        } catch (IOException e) {
            System.out.println("Server failed to create!");
        }
    }

}
