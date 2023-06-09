import java.io.*;
import java.net.*;
public class MyServer{
    public static void main(String[] args) throws Exception{
        ServerSocket ss=new ServerSocket(6666);
        Socket s=ss.accept();
        DataInputStream dis=new DataInputStream(s.getInputStream());
        String str=(String)dis.readUTF();
        while(!str.equals("Bye")){
            System.out.println(str);
            try{
            str=(String)dis.readUTF();
            }
            catch(Exception e){
                System.out.println("connection teminated");
                break;
            }
        }   
        ss.close();
    }
}