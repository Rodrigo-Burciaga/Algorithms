#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;
	int arr[n];

	map<int, long long> m;
	long long count = 0;
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
		int k = arr[i] - i;
		m[k] += 1;
	}


	for(auto &[k, v]: m){
		if (v > 1){
			count += (v*(v-1))/2;
		}
	}

	cout << count << endl;
}

int main(int argc, char const *argv[]){
	int t; cin >> t;
	while(t--){
		solve();
	}
	return 0;
}