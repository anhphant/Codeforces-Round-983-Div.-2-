#include <bits/stdc++.h>
using namespace std;
 
void solve(){
	int N, K;
	cin >> N >> K;
	if(K == (N+1) / 2){
		cout << 1 << '\n';
		cout << 1 << '\n';
		return;
	}
	if(K == 1 || K == N){
		cout << -1 << '\n';
		return;
	}
	if(K % 2 == 0){
		cout << 3 << '\n';
		cout << 1 << ' ' << K << ' ' << K+1 << '\n';
	} else {
		cout << 3 << '\n';
		cout << 1 << ' ' << K-1 << ' ' << K+2 << '\n';
	}
}
 
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}
