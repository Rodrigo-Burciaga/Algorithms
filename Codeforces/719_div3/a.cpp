#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;


bool checkBefore(stack<char> pila, char toBrowse) {
	while(!pila.empty()){
		char top = pila.top();
		pila.pop();
		if(toBrowse == top) return true;
	}
	return false;
}

int main () {

	
	int t = 0, n ;

	cin >> t;
	while(t--){
		n = 0;
		cin >> n;
		string str;
		stack<char> pila;
		cin.ignore();
		getline(cin, str);
		bool isyes = true;
		for (int i = 0; i < n; ++i){	
			if(pila.empty()) {
				pila.push(str[i]);
			} else {
				char before = pila.top();
				if(before != str[i]) {
					if(checkBefore(pila, str[i])){
						cout << "NO" << endl;
						isyes = false;
						break;
					} 
					pila.push(str[i]);
				}
			}
		}
		if(isyes) cout << "YES" << endl;
	}

	
  
    
	
	return 0;
}
