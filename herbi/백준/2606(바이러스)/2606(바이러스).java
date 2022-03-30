import java.util.ArrayList;
import java.util.Scanner;

public class Main{

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        final int V,M;
        ArrayList<ArrayList<Integer>> list;
        ArrayList<Integer> check;
        int answer;

        answer = 0;
        V = input.nextInt();
        M = input.nextInt();
        check = new ArrayList<Integer>();
        list = new ArrayList<ArrayList<Integer>>();
        for (int i=0; i<V + 1; i++)
        {
            check.add(0);
            list.add(new ArrayList<Integer>());
        }
        for(int i=0; i<M; i++)
        {
            int s = input.nextInt();
            int e = input.nextInt();

            list.get(s).add(e);
            list.get(e).add(s);
        }
        dfs(1, list, check);
        for(int c : check)
            answer += c;
        System.out.println(answer - 1);
        input.close();
    }

    private static void dfs(final int at, ArrayList<ArrayList<Integer>> list, ArrayList<Integer> check)
    {
        if (check.get(at) == 1)
            return;
        check.set(at, 1);
        for (int next : list.get(at))
        {
            dfs(next,list,check);
        }
    }
}
