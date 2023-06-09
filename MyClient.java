import java.io.*;
import java.net.*;
import java.util.*;
public class MyClient{
    public static void main(String[] args) throws Exception{
        Socket s=new Socket("localhost",6666);//ip for network layer and port for transport layer
        DataOutputStream  dos=new DataOutputStream(s.getOutputStream());
        String str;
        Scanner sc=new Scanner(System.in);
        str=sc.next();
        while(!str.equals("Bye")){
            dos.writeUTF(str);
            dos.flush();
            str=sc.next();
        }
        s.close();
    }
}