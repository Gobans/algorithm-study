#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int arr[4][1024];
int field[101][101];
int	d_x[4] = {1, 0, -1, 0};
int d_y[4] = {0, -1, 0, 1};

void	fill_arr(void)
{
	arr[0][0] = 0;
	for (int i = 0; i < 10; i++)
	{
		int	k = pow(2, i);
		for (int j = k; j < pow(2, i + 1); j++)
			arr[0][j] = (arr[0][k - 1 - (j - k)] + 1) % 4;
	}
	for (int i = 0; i < 1024; i++)
	{
		arr[1][i] = (arr[0][i] + 1) % 4;
		arr[2][i] = (arr[0][i] + 2) % 4;
		arr[3][i] = (arr[0][i] + 3) % 4;
	}
}

int main()
{
	int n;
	int x, y, d, g;
	int ans = 0;

	fill_arr();
	cin >> n;
	while (n--)
	{
		cin >> x >> y >> d >> g;
		field[y][x] = 1;
		for (int i = 0; i < pow(2, g); i++)
		{
			x = x + d_x[arr[d][i]];
			y = y + d_y[arr[d][i]];
			field[y][x] = 1;
		}
	}

	for(int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (field[i][j] && field[i + 1][j] && field[i][j + 1] && field[i + 1][j + 1])
				ans++;
	cout << ans;
}