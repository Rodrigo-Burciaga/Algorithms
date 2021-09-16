#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void towersOfHanoi(int n, char fromRod, char toRod, char auxRod){

	if ( n == 1) {
		cout << "Move disk 1 from rod " << fromRod << " to rod " << toRod << endl;
		return;
	}
	towersOfHanoi(n-1, fromRod, auxRod, toRod);
	cout << "Move disk " << n << " from rod " << fromRod << " to rod " << toRod << endl;
	towersOfHanoi(n-1, auxRod, toRod, fromRod);
}

int main(int argc, char const *argv[]) {

	int n = 3;

	towersOfHanoi(n, 'A', 'C', 'B');
	return 0;
}