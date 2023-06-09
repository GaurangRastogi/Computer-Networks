import java.net.*;
import java.io.*;
import java.util.*;
public class TCP_Server {
    public static void main(String[] args) throws Exception
	{
        //Socket creation.
		ServerSocket ss=new ServerSocket(1800);
		Socket s=ss.accept();
		DataInputStream dis=new DataInputStream(s.getInputStream());
        //Waiting for connection enstablishment.
		while(true)
		{
			String str=dis.readUTF();
			System.out.println("Client--->"+str);
			if(str.equals("exit()"))
			{
				System.out.println("Connection Termination.");
				dis.close();
				s.close();
				ss.close();
				break;
			}
		}
		
	}
}
