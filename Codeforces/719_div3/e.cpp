#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;


void solve(){
	int n; cin >> n;
	string s; cin >> s;
	vector<int> indices;
	for(int i = 0; i < n; ++i){
		if(s[i] == '*'){
			indices.push_back(i);
		}
	}



	int middle = indices.size()/2;
	long long movements = 0;

	if (middle == 0){
		cout << movements << endl;
		return;
	}


	int left = middle -1, right = middle + 1;

	int rec = 0;
	while(left >= 0){
		++rec;
		movements += indices[middle] - rec - indices[left];
		--left;
	}	

	rec = 0;

	while(right < indices.size()) {
		++rec;
		movements += indices[right] - indices[middle] - rec;
		right++;
	}

	cout << movements << endl;
}

int main(int argc, char const *argv[]){

	int t; cin >> t;
	while(t--){
		solve();		
	}
	return 0;
}