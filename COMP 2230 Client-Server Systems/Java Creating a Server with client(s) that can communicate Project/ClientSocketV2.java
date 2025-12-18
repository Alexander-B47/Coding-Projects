import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

// Name: Alexander Bordenet
// Date: 3/7/25
// Purpose: To expand on the original ClientSocket class that now allows for asynchronous-
// communication with the server and Client. Also, allowing for the user to have a username
// To be used in the ServerSocketV3 to use a hashmap to keep track of who is who.

public class ClientSocketV2 extends Thread{

    static Scanner userInput;
    static ClientConn serverInteraction;

    public ClientSocketV2(){
        serverInteraction = new ClientConn(this);
        serverInteraction.start();
    }

    public void writeToConsole(String message){
        System.out.println(message);
    }

    public void run(){
        userInput = new Scanner(System.in);
        while(true) {
        String b = userInput.nextLine();
        System.out.println(b);
        serverInteraction.sendToServer(b);
        }

    }

    public static void main(String[] args) {
        try {
            ClientSocketV2 client = new ClientSocketV2();
            client.start();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

}
