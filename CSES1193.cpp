// Problem: Labyrinth
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1193
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
const ll N = 1e3 + 5;
ll n, m, ok = 0;
string s[N];
ll dis[N][N], path[N][N];

bool ck(ll i, ll j){
	if(i < 0 || j < 0 || i >= n || j >= m){
		return false;
	}
	return (s[i][j] != '#') ;
}
const ll fx[]={+1,-1,+0,+0};
const ll fy[]={+0,+0,+1,-1};

vector<char> ans;

void bfs(ll i, ll j){
	queue<pair<ll, ll>> q;
	q.push({i, j});
	dis[i][j] = 1;
	while(!q.empty()){
		ll x = q.front().first;
		ll y = q.front().second;
		q.pop();
		for(ll k = 0; k < 4; k++){
			ll xx = x + fx[k], yy = y + fy[k];
			if(ck(xx, yy)){
				if(dis[xx][yy] > dis[x][y] + 1){
					dis[xx][yy] = dis[x][y] + 1;
					path[xx][yy] = k;
					q.push({xx, yy});
				}
			}
		}		
	}
}


int32_t main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/
	
	cin >> n >> m;
	ll x = 0, y = 0, p = 0, q = 0;
	for(ll i = 0; i < n; i++){
		cin >> s[i];
		for(ll j = 0; j < m; j++){
			if(s[i][j] == 'A'){
				x = i, y = j;
			}
			if(s[i][j] == 'B'){
				p = i, q = j;
			}
			dis[i][j] = m * n * max(n ,m);
			path[i][j] = 4;
		}
	}
	
	bfs(x, y);
	vector<char> ans;
	if(dis[p][q] == n * m * max(n, m)){
		cout << "NO" << '\n';
	}
	else{
		
		while(path[p][q] <= 3){
			if(path[p][q] == 0) ans.push_back('D'), p = p + fx[1], q = q + fy[1];
			else if(path[p][q] == 1) ans.push_back('U'), p = p + fx[0], q = q + fy[0];
			else if(path[p][q] == 2) ans.push_back('R'), p = p + fx[3], q = q + fy[3];
			else ans.push_back('L'), p = p + fx[2], q = q + fy[2];
		}
		reverse(ans.begin(), ans.end());
		cout << "YES" << '\n'; 
		cout << ans.size() << '\n';
		
		for(auto i : ans){
			cout << i;
		}
		
	}
		
	return 0;
}