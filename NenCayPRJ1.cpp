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
         std::cout<<res[i]<<" ";
     }
		
	}
		int main(){
			ios_base::sync_with_stdio(false);
			cin.tie(NULL);
			cout.tie(NULL);
			inp();
			memset(visited,0,sizeof(visited));
			parent[0] = inf;
			dfs(0);
			solve();
		
			return 0;
		}
