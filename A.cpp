#include <bits/stdc++.h>
using namespace std;
 
void solve(){
	int N;
	cin >> N;
	int ans = 0;
	for(int i = 0; i < 2*N; i++){
		int a;
		cin >> a;
		if(a) ans++;
	}
	cout << (ans % 2);
	cout << ' ';
	cout << min(ans, 2*N - ans) << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}