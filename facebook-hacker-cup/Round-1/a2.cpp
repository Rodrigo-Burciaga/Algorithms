#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define len(v) (int) v.size()
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define fore(x,v) for(auto x: v)
#define gauss(n) ((n) * ((n) + 1)) / 2
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define forr(i,a,b) for(int i = a; i <= b; ++i)
#define ll long long
const ll MOD = 1e9 + 7;



using namespace std;

struct mint {
	ll v; explicit operator ll() const { return v; }
	mint() { v = 0; }
	mint(ll _v) { 
		v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0) v += MOD;
	}
	friend bool operator==(const mint& a, const mint& b) { 
		return a.v == b.v; }
	friend bool operator!=(const mint& a, const mint& b) { 
		return !(a == b); }
	friend bool operator<(const mint& a, const mint& b) { 
		return a.v < b.v; }
   
	mint& operator+=(const mint& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	mint& operator-=(const mint& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	mint& operator*=(const mint& m) { 
		v = v*m.v%MOD; return *this; }
	mint& operator/=(const mint& m) { return (*this) *= inv(m); }
	friend mint pow(mint a, ll p) {
		mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mint inv(const mint& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	mint operator-() const { return mint(-v); }
	mint& operator++() { return *this += 1; }
	mint& operator--() { return *this -= 1; }
    mint operator++(int) { mint temp; temp.v = v++; return temp; }
    mint operator--(int) { mint temp; temp.v = v--; return temp; }
	friend mint operator+(mint a, const mint& b) { return a += b; }
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	friend mint operator/(mint a, const mint& b) { return a /= b; }
    friend ostream& operator<<(ostream& os, const mint& m) {
        os << m.v; return os;
    }

    friend istream& operator>>(istream& is, mint& m) {
        ll x; is >> x;
        m.v = x;
        return is;
    }
};


int solve() {
	int N; cin >> N;
	string W; cin >> W;

	int left = 0;
	char actual_let = 'X';
	fore(letter, W){
		if (letter != 'F' && letter != actual_let){
			left++;
			actual_let = actual_let == 'X' ? 'O' : 'X';
		}
	}

	int right = 0;
	actual_let = 'O';
	fore(letter, W){
		if (letter != 'F' && letter != actual_let){
			right++;
			actual_let = actual_let == 'X' ? 'O' : 'X';
		}
	}

	return min(right, left);

}

int main(int argc, char const *argv[])
{

	mint b = 16;

	cout << b << endl;

}