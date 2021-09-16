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
	string s;
	cin >> s;
	int s_size = len(s);
	map<char, int> letters;
	int vowel = 0, consonant = 0;
	for(char c: s){
		letters[c]++;
		if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
			vowel++;
		} else {
			consonant++;
		}
	}

	int movements = 0;

	if (vowel == s_size || consonant == s_size){
		int more_repeated = 0;
		for(auto const& x: letters){
			if (x.second > more_repeated){
				more_repeated = x.second;
			}
		}

		if (more_repeated != s_size){
			int less_chain = s_size - more_repeated;
			if (more_repeated >= less_chain){
				movements = less_chain * 2;
			} else {
				movements = s_size;
			}

		}

		return movements;
	}


	int more_repeated_vowel = 0;
	int more_repeated_consonant = 0;
	for(auto const& x: letters){
		if (x.first == 'A' || x.first == 'E' || x.first == 'I' || x.first == 'O' || x.first == 'U') {
			if (x.second > more_repeated_vowel){
				more_repeated_vowel = x.second;
			} 		
		} else {
			more_repeated_consonant = x.second > more_repeated_consonant ? x.second : more_repeated_consonant;
		}

	}

	int less_consonant = (consonant - more_repeated_consonant) * 2 + vowel;
	int less_vowel = (vowel - more_repeated_vowel) * 2 +  consonant;
	movements = less_consonant < less_vowel ? less_consonant : less_vowel;



	return movements;
	
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	int a_case = 0;
	while(T--)
		cout << "Case #" << ++a_case << ": " << solve() << endl;

	return 0;
}