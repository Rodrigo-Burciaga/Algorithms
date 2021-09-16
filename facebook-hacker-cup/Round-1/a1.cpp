#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define len(v) (int) v.size()
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define fore(x,v) for(auto x: v)
#define gauss(n) ((n) * ((n) + 1)) / 2
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forr(i,a,b) for(int i = a; i <= b; ++i)

#ifdef LOCAL
#include "debugger.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

using namespace std;


int solve() {
	int N; cin >> N;
	string W; cin >> W;

	int left = 0;
	char actual_let = 'X';
	fore(letter, W){
		if (letter != 'F' && letter != actual_let){
			left++;
			actual_let = actual_let == 'X' ? 'O' : 'X';
		}
	}

	int right = 0;
	actual_let = 'O';
	fore(letter, W){
		if (letter != 'F' && letter != actual_let){
			right++;
			actual_let = actual_let == 'X' ? 'O' : 'X';
		}
	}

	return min(right, left);

}

int main(int argc, char const *argv[])
{

	int T; cin >> T;
	int caso = 1;
	while(T--){
		cout << "Case #" << caso++ << ": " << solve() << endl;
	}
	return 0;
}