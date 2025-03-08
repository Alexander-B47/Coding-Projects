import java.net.*;
import java.io.*;
import java.util.ArrayList;
import java.util.Collections;

// Name: Alexander Bordenet
// Date: 2/5/2025
// Description: This program will crawl fairmontstate's website and look for emails
// Then it will add those to an ArrayList then write its contents to a file

class SockIt {

    //NOTES: if you want to build a big string of the data, use stringbuilder class
    // You are not supposed to re-use the same httpurlconnection
    // Create a new one for each time that you want to connect to a website

    ArrayList<String> emails;
    ArrayList<String> links;
    ArrayList<String> linksChecked;
    static int LINK_COUNT = 0;

    SockIt(ArrayList<String> emails2, ArrayList<String> links2, ArrayList<String> linksChecked2) {
        BufferedReader in;
        String textIn;
        emails = emails2;
        links = links2;
        linksChecked = linksChecked2;

        String host;
        if(LINK_COUNT == 0) {
            host = "https://www.fairmontstate.edu";
        }
        else {
            if(!linksChecked.contains(links.getFirst())) {
                host = "https://www.fairmontstate.edu" + links.getFirst() + ".aspx";
                linksChecked.add(links.getFirst());
                links.removeFirst();
            }
            else { //Should never happen
                String temp = links.removeFirst(); //This link has already been checked
                host = "";
                System.out.println("Already done: " + temp);
            }
        }
        LINK_COUNT++;

        int responseCode;

        // The part of the code that actually crawls the websites
        try {
            URL myurl = new URL(host);

            // Type cast the myurl.openConnection to a HttpURLConnection
            HttpURLConnection httpCon = (HttpURLConnection) myurl.openConnection();

            //GET is what will retrieve stuff
            //There are others that will push stuff to the server
            httpCon.setRequestMethod("GET");
            responseCode = httpCon.getResponseCode();

            if (responseCode == HttpURLConnection.HTTP_OK) {
                //new buffered reader using the httpconnection
                in = new BufferedReader(new InputStreamReader(httpCon.getInputStream()));

                //once the readline stops finding things from the website it will be null
                while ((textIn = in.readLine()) != null) {
                    if(textIn.contains("mailto")) {
                        breakdownEmail(textIn);
                    }
                    else if (textIn.contains("href=\"/") && textIn.contains(".aspx")) {
                        breakdownLinks(textIn);
                    }
                }

                //close the reader once we have everything
                in.close();
            }
            else {
                System.out.println("Bad request");
            }


        }
        //If my url is bad then it will cause a UnkownHostException error
        catch (UnknownHostException f) {
            System.out.println("Target host not found");
        }
        catch (IOException e) {
            System.out.println("Generic I/O Error");
            //prints off what the error was, but doesn't crash the program because it was caught
            e.printStackTrace();
        }
    }

    //********************************************************************
    // WriteEmailsToFile
    // Input: ArrayList of the emails to be written
    // Output: A text file containing all of the emails from the ArrayList
    // Description: This function will take in an ArrayList of emails and
    // will write them to a file called "emails.txt"
    //*********************************************************************
    public static void writeEmailsToFile (ArrayList<String> emails) {
        try{
            FileWriter emailWriter = new FileWriter("emails.txt");
            int i = 0;
            for (String email : emails) {
                emailWriter.write("Email: " + i + ": " + email + "\n");
                i++;
            }
            emailWriter.close();
        }
        catch (IOException e) {
            System.out.println("Error, did not write to file!!!!!!");
            e.printStackTrace();
        }

    }
    //**************************************************************************
    // BreakdownEmail
    // Input: The string line scrapped from the website
    // Output: N/A
    // Description: Breaks down the line containing an email into just the email
    //**************************************************************************
    public void breakdownEmail(String textIn) {
        String mailtoString = textIn.substring(textIn.indexOf("mailto"));
        String justEmail = mailtoString.substring(mailtoString.indexOf("mailto")+7 , mailtoString.indexOf("\""));
        emails.add(justEmail);
    }

    //*************************************************************************
    // BreakdownLinks
    // Input: The string line scrapped from the website
    // Output: N/A
    // Description: Breaks down the line containing a link into just the link
    // and verifies that it hasn't already been done and then adds it to links
    //*************************************************************************
    public void breakdownLinks(String textIn) {
        String hrefString = textIn.substring(textIn.indexOf("href"));
        String justLink = hrefString.substring(hrefString.indexOf("href")+6, hrefString.indexOf(".aspx"));
        if(!links.contains(justLink) && !linksChecked.contains(justLink))
            links.add(justLink);
    }

    //***************************************************************
    // PrintArrayList
    // Input: An ArrayList to be displayed for debugging purposes
    // Output: The contents of the ArrayList displayed to the console
    // Description: Will display the contents of the Arraylist.
    //***************************************************************
    public static void printArrayList(ArrayList<String> items) {
        System.out.println("Test test test");
        for(int i = 0; i < items.size(); i++) {
            System.out.println("Item " + i+1 + ": " + items.get(i));
        }
    }


    public static void main(String[] args) {
        ArrayList<String> emails = new ArrayList<String>();
        ArrayList<String> links = new ArrayList<String>();
        ArrayList<String> linksChecked = new ArrayList<String>();
        String startingURL = "https://www.fairmontstate.edu";

        links.add(startingURL);

        while(!links.isEmpty()) {
            SockIt mySocket = new SockIt(emails, links, linksChecked);
        }

        writeEmailsToFile(emails);
        printArrayList(linksChecked);
    }
}
