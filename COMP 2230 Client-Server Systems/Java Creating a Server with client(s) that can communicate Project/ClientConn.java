import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class ClientConn extends Thread{

    ClientSocketV2 client;
    BufferedReader serverOutput;
    Socket clientSocket;
    PrintWriter clientOutput;

    public ClientConn(ClientSocketV2 cs){
        client = cs;
    }

    public void setClient (ClientSocketV2 c){
        client = c;
    }

    public void sendToServer(String x) {
        clientOutput.println(x);
    }

    public String receiveFromServer() throws IOException {
        return serverOutput.readLine();
    }

    public void run() {
        try {
            clientSocket = new Socket("localhost", 5000);
            serverOutput = new BufferedReader( new InputStreamReader(clientSocket.getInputStream()));
            clientOutput = new PrintWriter(clientSocket.getOutputStream(), true);
            String serverMessage ="This is a message from the server, yo";


            System.out.println("Hello world! This is from the ClientConn.run()");
            client.writeToConsole(serverMessage);

            while((serverMessage = serverOutput.readLine()) != null) {
                client.writeToConsole(serverMessage);
            }

            /*
            String serverMessage;

            while((serverMessage = serverOutput.readLine() ) != null){
                client.writeToConsole(serverMessage);
            }
            */



        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}