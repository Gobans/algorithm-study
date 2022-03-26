#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


vector<int> card(500000);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> card[i];

	sort(card.begin(), card.begin() + n);
	int m,tmp;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		if (binary_search(card.begin(), card.begin() + m, tmp))
			cout << upper_bound(card.begin(), card.begin() + n, tmp) - lower_bound(card.begin(), card.begin() + n, tmp)<<' ';
		else
			cout << 0 << ' ';
	}

}