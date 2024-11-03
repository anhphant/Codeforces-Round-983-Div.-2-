#include <bits/stdc++.h>
using namespace std;
 
void solve(){
	int N;
	cin >> N;
	vector<int> A(N);
	for(int& x : A) cin >> x;
	sort(A.begin(), A.end());
	int j = 0;
	int best = 0;
	for(int i = 0; i+1 < N; i++){
		while(j < i) j++;
		while(j+1 < N && A[j+1] < A[i] + A[i+1]) j++;
		best = max(best, j-i+1);
	}
	cout << (N - best) << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}