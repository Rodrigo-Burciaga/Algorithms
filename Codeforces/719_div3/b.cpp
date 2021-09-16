#include <iostream>
#include <bits/stdc++.h>

typedef long long int ll;

using namespace std;

vector<vector<ll>> posibleNumbers(10);

void solve(){
	int count = 0;
	int n; cin >> n;
	for (int i = 1; i < posibleNumbers.size(); ++i){
		 for(auto num: posibleNumbers[i]){
		 	if(num <= n)
		 		count++;	
		 	else
		 		break;
		 }
	}
	cout << count << endl;
}


void fillPosible(){
	for (ll i = 1; i <= 10e8; i = i * 10 + 1) {
		for (int j = 1; j <= 9; ++j){
			posibleNumbers[j].push_back(j*i);
		}
	}
}

int main(int argc, char const *argv[])
{
	fillPosible();
	int t; cin >> t;
	while(t--){
		solve();
	}	
	return 0;
}