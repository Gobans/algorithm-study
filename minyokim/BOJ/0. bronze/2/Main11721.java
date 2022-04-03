import java.util.Scanner;

public class Main11721 {
	
	public static void main(String [] args)
	{
		Scanner in = new Scanner(System.in);
		
		String str = in.next();
		
		for (int i = 0; i < str.length(); i++)
		{
			System.out.print(str.charAt(i));
			if (i % 10 == 9)
				System.out.print("\n");
		}
		
		in.close(); 
	}
}
