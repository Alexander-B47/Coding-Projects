import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Random;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.atomic.AtomicInteger;

// Name: Alexander Bordenet
// Date: 2/26/25-3/5/25
// Purpose: To expand on my first version of my Server class, now with the ability to handle multiple clients.

public class ServerSocketV3 extends Thread{

    ArrayList<Integer> allRandomNumbers = new ArrayList<>();
    static java.net.ServerSocket serverSocket;
    static ConcurrentHashMap<String, ServerConn> users = new ConcurrentHashMap<>();

    public static void closeServer() throws IOException {
        serverSocket.close();
    }

    public static void closeAllUsers() throws IOException {
        users.forEach((key, value) -> {
            PrintWriter x = value.getToClient();
            x.println("EXIT");
        });
        closeServer();
    }

    public void registerUser(String name, ServerConn instance){
        users.put(name, instance);
    }

    public void getAllUsers(){
        AtomicInteger i = new AtomicInteger();
        users.forEach((key, value) -> {
            i.getAndIncrement();
            PrintWriter x = value.getToClient();
            x.println("User " + i + ": " + key);
        });
        int f = 0;
        for (String x : users.keySet()){
            ServerConn z = users.get(x);
            PrintWriter y = z.getToClient();
            y.println("User " + f + ": " + x);
        }
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
                // Passes in 'this' which is the instance of the ServerSocketV3 class
                // This is so each ServerConn can access the methods of the ServerSocketV3 class
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
            new ServerSocketV3().start();
        } catch (IOException e) {
            System.out.println("Server failed to create!");
        }
    }

}
