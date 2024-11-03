#include <bits/stdc++.h>
using namespace std;
 
using ll = int64_t;
 
void solve(){
	ll N;
	cin >> N;
	vector<ll> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	if(N == 1){
		cout << 0 << '\n';
		return;
	}
	while(accumulate(A.begin(), A.end(), ll(0)) % 4 != 0) {
		for(ll& x : A) x += 1;
	}
	vector<ll> psums(N+1);
	for(int i = 0; i < N; i++) psums[i+1] = psums[i] + A[i];
	ll v0 = 0;
	ll v1 = 0;
	for(int i = 0; i < N; i++){
		ll m = i;
		if(m > N/2) m = N-m;
		m = (N - 2 * m) * (m & 1 ? -1 : 1);
		v0 += A[i] * m;
		v1 += A[(i+1) % N] * m;
	}
	vector<ll> v(N);
	v[0] = -v0;
	v[1] = -v1;
	assert(v[0] % 4 == 0);
	assert(v[1] % 4 == 0);
	for(int i = 2; i < N; i++){
		v[i] = -4 * A[i-1] - 2 * v[i-1] - v[i-2];
	}
	ll x = *min_element(v.begin(), v.end());
	for(ll& y : v) y -= x;
	for(int i = 0; i < N; i++){
		cout << (v[i] / 4) << ' ';
	}
	cout << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}