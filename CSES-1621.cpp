#include<bits/stdc++.h>
#define ll long long int
 
using namespace std;
 
 
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	ll n;
	cin >> n;
	vector<ll> v(n);
	for(ll i = 0; i < n; i++){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	ll ans = 1;
	for(ll i = 1; i < n; i++){
		if(v[i] != v[i - 1]) ans++;
	}
 
	cout << ans << '\n';
	
     return 0;
}