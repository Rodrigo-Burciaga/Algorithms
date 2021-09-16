#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
	int N; cin >> N;
	string s; cin >> s;
	map<char, vector<int>> m;
	for (int i = 0; i < N; ++i)
		m[s[i]].push_back(i);

	for(auto &[k, v]: m){
		for (int i = 1; i < v.size(); ++i){
			if (v[i] - 1 != v[i - 1]){
				cout << "NO" << endl;
				return;
			}
		}
	}

	cout << "YES" << endl;

}

int main(int argc, char const *argv[])
{
	int t; cin >> t;
	cout << 2/10;
	return 0;
}