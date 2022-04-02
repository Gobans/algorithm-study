import java.util.Scanner;

public class Main2439 {
	
	public static void main(String [] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();

		for (int i = 0; i < N; i++)
		{
			for (int j = N-1-i; j >= 1; j--)
			{
				System.out.print(" ");
			}
			for (int j = 0; j <= i; j++)
			{
				System.out.print("*");
			}
			System.out.print("\n");
		}
		
		sc.close();
	}
}
