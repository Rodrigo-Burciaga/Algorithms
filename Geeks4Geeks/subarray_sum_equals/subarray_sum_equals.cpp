#include <iostream>
#include <bits/stdc++.h>


using namespace std;

int main(int argc, char const *argv[]) {
	
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for(auto &num: arr) cin >> num;

	int sum = 0, count = 0;
	unordered_map<int,int> prevSum;

	for (int i = 0; i < n; ++i) {
		sum += arr[i];

		if (sum == k) {
		 	count++;
		 }

		 if (prevSum.find(sum - k) != prevSum.end()) {
		 	count += (prevSum[sum - k]);
		 }

		 prevSum[sum]++;
	}


	cout << count << '\n';



	return 0;
}