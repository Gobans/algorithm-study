import java.util.Scanner;

public class Main2588 {
	
	public static void main(String [] args) {
		
		Scanner input = new Scanner(System.in);
		
		int n1 = input.nextInt();
		int n2 = input.nextInt();
		int [] arr = new int[3];
		int total = 0;
	
		for (int i = 0; i < 3; i++)
		{
			arr[i] = (n2 % 10) * n1;
			n2 /= 10;
		}
		
		for (int i = 0; i < 3; i++)
		{
			System.out.println(arr[i]);
			total = (total + arr[2 - i]) * 10;
		}
		System.out.println(total/10);
		
		input.close();
		
	}
}
