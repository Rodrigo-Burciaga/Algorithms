#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;
	if (n == 2){
		cout << -1 << endl;
		return;
	}
	int arr[n][n];
	int actualNumber = 1;

	for (int i = 0; i < n; ++i){
		for (int j = i % 2; j < n; j += 2){
			arr[i][j] = actualNumber++;
		}
	}


	for(int i = 0; i < n; ++i) {
		int j =  (i % 2) == 0 ? 1: 0;
		for (; j < n; j += 2){
			arr[i][j] = actualNumber++;
		}
	}

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

}

int main(int argc, char const *argv[]){
	int t; cin >> t;
	while(t--){
		solve();
	}
	return 0;
}