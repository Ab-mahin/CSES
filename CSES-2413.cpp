// USER: "Ab.Mahin"
// Problem: Counting Towers
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2413/
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define m 1000000007 // 998244353
//0x3f
 
#define MAX LLONG_MAX
 
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
//find_by_order() and order_of_key()
//k-th largest element and strictly smaller
 
 
/* To finding all possible submask for a mask(set bits);
 
for(ll mask = 0; mask < (1 << n); mask++){
    for(ll submask = mask ; submask > 0; submask = (submask - 1) & mask){
    	cout << mask << ' ' << submask << '\n';	
    }
}
*/
 
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
cout.write(names, comma - names) << " : " << arg1<< " | ";__f(comma+1, args...);
}
#else
#define bug(...)
#endif
 
//...................
const ll N = 1e6 + 5;
ll dp[N][10];
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/
 
    ll t, tt;
    t = tt = 1;
    
    cin >> t;
    for(ll i = 1; i <= 8; i++) dp[1][i] = 1;
    
    for(ll i = 2; i < N; i++){
    	for(ll j = 1; j <= 8; j++){
    		if(j == 1 || j == 3 || j == 4 || j == 5 || j == 6){
				dp[i][j] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][5] + dp[i - 1][6]) % m;
			}
			else {
				dp[i][j] = (dp[i - 1][3] + dp[i - 1][7] + dp[i - 1][8]) % m;
			}
    	}
    }
	
	while(t--){
        ll n;
        cin >> n;
        cout << (dp[n][3] + dp[n][7]) % m << '\n';
    }
    
    
    return 0;
}