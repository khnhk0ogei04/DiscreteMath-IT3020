#include<bits/stdc++.h>
#define ll long long
const int MAXN = 1e5 + 3;
const int inf = 1e9 + 7;
using namespace std;
	vector<int>adj[MAXN]; vector<int>res;
	priority_queue<int, vector<int>, greater<int> >pq;
	ll n,deg[MAXN],parent[MAXN];
	bool visited[MAXN];
		void inp(){
			std::cin>>n;
			for ( int i = 1 ; i <= n ; i++ ){
				int u,v;
				std::cin>>u>>v;
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
			for ( int i = 0 ; i <= n ; i++ ){
				deg[i] = adj[i].size();
			}
		}
		void dfs (int u){
			visited[u] = true;
			for ( int v : adj[u] ){
				if (!visited[v]){
					parent[v] = u;
					dfs(v);
				}
			}
		}
		void solve() {
		
		for ( int i = 1 ; i <= n ; i++ ) {
			if (deg[i] == 1 ){
				pq.push(i);
			}
		}
   		while ( res.size() < n - 1 ) {

			if ( deg[parent[pq.top()]] == 2 ){
				int u = pq.top();
				res.push_back(parent[u]);
				deg[parent[u]]--;
				pq.pop();
			if (parent[parent[u]] != inf ) {
			    int v = parent[u];
			    if ( pq.empty() || v < pq.top() ) {
			        res.push_back(parent[v]);
			    }
			    else pq.push(v);
			
				if (--deg[parent[v]] == 1 && parent[parent[v]] != inf ) {
				    pq.push(parent[v]);
				}
			
			}
			
		        continue;
			}
			else if ( --deg[parent[pq.top()]] != 1 ) {
				res.push_back(parent[pq.top()]);
				
				pq.pop();
			} 
		}
     for ( int i = 0 ; i < n - 1; i++ ){
         cout<<res[i]<<" ";
     }
		
	}
		int main(){
			inp();
			memset(visited,0,sizeof(visited));
			parent[0] = inf;
			dfs(0);
			solve();
		
			return 0;
		}
	
	
/* a[1] = n;   VD a[1] = 10
	cnt = 1;										(9 1)                       (8 2)
	sinh: int i = cnt;                           i = 1;                         i = 2;
		 while ( i >= 1 && a[i] == 1 ) i--;      i = 1 && a[i=1] = 10			i = 2 && a[i=2] = 1 => i-- = 1
		 i == 0 : ok = 0;
		 else {
		 a[i]--;							     a[i = 1] = 9					a[1] = 8
		 int d = cnt - i + 1;					 d = 1 - 1 + 1 = 1				d = 2 - 1 + 1 = 2
		 cnt = i;								 cnt = i = 1;					cnt = 1
		 int q = d/a[i];						q = 1/9 = 0					q = 2/8 = 0
		 int r = d % a[i];		 					r = 1					r = 2
			if(r) {									r = 1 != 0				
			cnt++;									cnt = 2					cnt = 2
			a[cnt] = r;                          a[2] = 1;					a[2] = 2;
		}
 		if (q) {
 		for j = 1 -> q
 		cnt++;
 		a[cnt] = a[i];
 	}
 }
		*/
		
		
/*		9                  
		0 4
		0 6
		4 2
		4 1
		2 8
		2 9
		6 3
		6 5
		3 7
		
		11
		0 3
		3 1
		1 11
		0 6
		0 8
		3 2
		6 5
		6 4
		5 7
		5 9
		5 10
		
		12
		0 1
		0 4
		0 3
		1 5
		1 2
		4 9
		9 8
		3 7
		3 6
		3 10
		6 12
		6 11
		
		8
		0 4
		0 5
		4 6
		4 3
		6 7
		6 8
		6 1
		0 2
		
		20
		0 4
		0 8
		0 7
		0 12
		4 1
		4 6
		8 15
		8 9
		12 19
		12 20
		6 3
		6 2
		9 11
		9 10
		9 13
		2 5
		3 16
		16 17
		16 18
		3 14
		
		10
		0 9
		0 7
		9 3
		9 6
		9 2
		7 4
		2 1
		2 5
		1 10
		1 8
		*/
