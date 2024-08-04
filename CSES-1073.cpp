// USER: "Ab.Mahin"
// Problem: Towers
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1073
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define ll long long int
//#define  m 1000000007

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
const ll N = 2e5 + 5;


int32_t main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/
	
	ll n;
	cin >> n;
	
	multiset<ll> s;
	ll x;
	for(ll i = 0; i < n; i++){
		cin >> x;
		auto it = s.upper_bound(x);
		if(it != s.end()){
			s.erase(it);
			s.insert(x);
		}
		else s.insert(x);
	}
	
	cout << s.size() << '\n';
	
	return 0;
}