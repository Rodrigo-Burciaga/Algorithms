#include <iostream>

using namespace std;


void sort(int arr[], int n) {
	if (n < 2) {
		return;
	}
	int key;
	for(int i = 1; i < n; i++) {
		key = arr[i];
		int j = i - 1;
		while(j >= 0 &&  arr[j] > key) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

void print_arr(int n, int arr[]) {
	for(int i = 0; i < n; i++) {
		cout << arr[i];
	}
	cout << endl;
}

int main() {

	int n; cin >> n;
	int arr[n];
	int aux;
	for (int i=0; i<n ; i++) {
		cin >> aux;
		arr[i] = aux;
	}
	sort(arr, n);
	print_arr(n, arr);

	return 0;
}
