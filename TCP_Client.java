import java.net.*;
import java.io.*;
import java.util.*;
public class TCP_Client{
	public static void main(String[] args) throws Exception
	{
        
		Scanner scan=new Scanner(System.in);
        //Connection enstablishment.
		Socket s=new Socket("localhost",1800);
		DataOutputStream dout=new DataOutputStream(s.getOutputStream());
		DataInputStream dis=new DataInputStream(s.getInputStream());

        //Reading the messages.
		while(true)
		{
			System.out.println("Write Your message");
			String str=scan.nextLine();
			dout.writeUTF(str);
			dout.flush();
			if(str.equals("bye"))
			{
				dout.close();
				s.close();
				break;
			}
			
		}
	}
}
