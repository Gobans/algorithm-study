#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(string a, string b)
{
	if (a.length() == b.length())
		return a < b;
	else
		return a.length() < b.length();
}

string word[20000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> word[i];
	sort(word, word + n, cmp);
	cout << word[0] << '\n';
	for (int i = 1; i < n; i++)
	{
		if (word[i] == word[i - 1])
			continue;
		cout << word[i] << '\n';
	}
}