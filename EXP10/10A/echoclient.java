import java.util.*;
import java.net.*;
import java.io.*;
public class echoclient{
  public static void main(String args[])throws IOException{
    Socket link = null;
    PrintWriter pw = null;
    String fromuser,fromserver;
    try{
      link=new Socket(InetAddress.getLocalHost(),4000);
      
      System.out.println("Enter message :");
      Scanner in=new Scanner(System.in);
      fromuser=in.nextLine();
      
      pw=new PrintWriter(link.getOutputStream(),true);
      pw.println(fromuser);
      System.out.println("Message sent to server from client :"+fromuser);

      Scanner input=new Scanner(link.getInputStream());
      fromserver=input.nextLine();
      System.out.println("Reply from server :"+fromserver);
      
    }catch(IOException e){
      System.err.println(e);
    }
    finally{
      link.close();
    }
  }
}
