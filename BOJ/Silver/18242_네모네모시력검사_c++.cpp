#include <iostream>

using namespace std;

char arr[100][100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	int flag = 0;
	int i, j;
	int start_x, start_y, end_x, end_y;

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> arr[i][j];

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			if (arr[i][j] == '#')
			{
				start_x = j;
				start_y = i;
				flag = 1;
				break;
			}
		if (flag)
			break;
	}

	flag = 0;
	for (i = n - 1; i >= 0; i--) {
		for (j = m - 1; j >= 0; j--)
			if (arr[i][j] == '#')
			{
				end_x = j;
				end_y = i;
				flag = 1;
				break;
			}
		if (flag)
			break;
	}

	for (i = start_x; i < end_x; i++)
		if (arr[start_y][i] == '.') {
			cout << "UP";
			return 0;
		}

	for (i = start_x; i < end_x; i++)
		if (arr[end_y][i] == '.') {
			cout << "DOWN";
			return 0;
		}

	for (i = start_y; i < end_y; i++)
		if (arr[i][start_x] == '.') {
			cout << "LEFT";
			return 0;
		}

	for (i = start_y; i < end_y; i++)
		if (arr[i][end_x] == '.') {
			cout << "RIGHT";
			return 0;
		}
}