#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, num;

	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> num;
		if (binary_search(arr.begin(), arr.end(), num))
			cout << "1\n";
		else
			cout << "0\n";
	}
	return 0;
}