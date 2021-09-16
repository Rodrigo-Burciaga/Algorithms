#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define len(v) v.size()
#define all(v) v.begin(), v.end()
#define forr(i,a,b) for(int i = a;i <= b;++i)
#define forn(i,n) for(int i = 0;i < int(n);++i)

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int main () {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	long long ans = 0;
	vector<int> numbers;
	for (int i = 1; i <= n; ++i)
	{
		int number;
		cin >> number;
		numbers.push_back(number);
		if (i % 2 == 0)
		{
		 ans += numbers[i-1] - numbers[i-2];
		}
	}

	cout << ans << endl;

	
	return 0;
}

