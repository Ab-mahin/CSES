// Problem: L - Breakfast 04
// Contest: Virtual Judge - Weekly Contest 04
// URL: https://vjudge.net/contest/560154#problem/L
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include<bits/stdc++.h>
#define ll long long int
#define  mod 1000000007
 
using namespace std;
 
//Findout buggs:
 
#define BUG
 
#ifdef BUG
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define bug(...)
#endif
 
//...................
const ll N = 1e5 + 5;
ll a[N], dp[N][105], m, n;
 
ll solve(ll i, ll p){
	if(i == n){
		return 1;
	}
	
	if(dp[i][p] != -1) return dp[i][p];
	ll res = 0;
	if(a[i + 1] == 0){
		if(p != 1) res = (res + solve(i + 1, p - 1)) % mod;
		if(p != m) res = (res + solve(i + 1, p + 1)) % mod;
		res = (res + solve(i + 1, p)) % mod;
	}
	else{
		if(abs(a[i + 1] - p) <= 1){
			res = (res + solve(i + 1, a[i + 1])) % mod;
		}
	}
 
	return dp[i][p] = res;
}
 
int32_t main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/
	
	cin >> n >> m;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	memset(dp, -1, sizeof(dp));
	
	ll ans = 0;
		
	if(a[1] == 0){
		for(ll i = 1; i <= m; i++){
			ans = (ans + solve(1, i)) % mod;
		}
	}
	else ans = solve(1, a[1]);
	
		
	cout << ans << '\n';
	
	return 0;
}