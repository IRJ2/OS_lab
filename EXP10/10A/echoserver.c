import java.util.*;
import java.net.*;
import java.io.*;
public class echoserver{
  public static void main(String args[])throws IOException{
    ServerSocket serversocket = null;
    Socket link = null;
    PrintWriter pw = null;
    String fromclient;
    try{
      serversocket=new ServerSocket(4000);
      link=serversocket.accept();
      System.out.println("Waiting for connection...\n");
      
      Scanner in=new Scanner(link.getInputStream());
      fromclient=in.nextLine();
      System.out.println("Message received from client :"+fromclient);

      pw=new PrintWriter(link.getOutputStream(),true);
      pw.println(fromclient);
    }catch(IOException e){
      System.err.println(e);
    }
    finally{
      serversocket.close();
      link.close();
    }
  }
}
