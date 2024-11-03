#include <bits/stdc++.h>
using namespace std;
 
void solve(){
	int N;
	cin >> N;
	auto ask = [&](int x, int y){
		if(x == y) return 0;
		cout << "? " << x << ' ' << y << '\n';
		cout << flush;
		int res;
		cin >> res;
		return res;
	};
	vector<int> par(N);
	int x = 2;
	while(x < N && ask(1, x) == 1) x++;
	for(int v = 1; v < x; v++) par[v] = 0;
	vector<int> rep(N);
	for(int v = 1; v < x; v++) rep[v] = v;
	par[x] = 1;
	int cur = 2;
	for(int v = x+1; v < N; v++){
		while(true){
			if(cur == v-1 || !ask(cur, v)){
				par[v] = cur;
				cur++;
				break;
			}
			cur++;
		}
	}
	cout << "!";
	for(int v = 1; v < N; v++){
		cout << " " << par[v];
	}
	cout << '\n';
	cout << flush;
}
 
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}