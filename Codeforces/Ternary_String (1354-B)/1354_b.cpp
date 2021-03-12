#include <iostream>
#include <bits/stdc++.h>
#define  cero '0'

using namespace std;

int solve(string &s) {
	if(s.size() < 3) return 0;

	int bucket[4] = {0};
	int r = 2, n = s.size(), l = 0;
	int count  = 2e6;

	bucket[s[0] - cero]++;
	bucket[s[1] - cero]++;
	bucket[s[2] - cero]++;

	while(r < n && (l < n - 2) ){
		if(bucket[1] > 0 && bucket[2] > 0 && bucket[3] > 0) {
			count = (r - l + 1) < count ? (r - l + 1) : count;
			bucket[s[l] - cero]--;
			l++;
		} else {
			r++;
			if(r < n) bucket[s[r] - cero]++;
		}
	}

	return (count == 2e6) ? 0 : count;
}


int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
    	string s; cin >> s;
    	cout << solve(s) << '\n';

    }
	return 0;
}