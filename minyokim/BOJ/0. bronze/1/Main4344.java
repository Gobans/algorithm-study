import java.util.Scanner;

public class Main4344 {

	public static void main(String [] args) {
		Scanner input = new Scanner(System.in);
		
		int C = input.nextInt();
		int N;
		int [][] arr = new int[C][];
		int avg;
		float percent;
		
		for (int i = 0; i < C; i++)
		{
			avg = 0;
			percent = 0;
			N = input.nextInt();
			arr[i] = new int[N];
			
			for (int j = 0; j < N; j++)
			{
				arr[i][j] = input.nextInt();
				avg += arr[i][j];
			}
			avg /= N;
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j] > avg)
					percent += 1;
			}
			percent = (percent / N) * 100;
		
			System.out.print(String.format("%.3f", percent));
			System.out.println("%");
		}
		
		input.close();
	}
}
