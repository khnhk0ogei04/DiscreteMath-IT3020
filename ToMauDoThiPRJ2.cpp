#include<bits/stdc++.h>
using namespace std;
	int n,m,ok;
	int colored[10001] = {0};
	vector<int>adj[10001];
    vector<int>a; vector<int>b;
    queue<int>q;
	int deg[10001];
	string idcolor[33] = {" ","red","green","blue","orange","purple","yellow","brown","gray","black","azure","ivory","teal","silver","maroon","charcoal","aquamarine","coral","fuchsia","wheat","lime","crimson","olive","cyan","plum"};
	void inp(){
		cin>>n>>m;
		int u,v;
		for ( int i = 1 ; i <= m ; i++ ){
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
            a.push_back(u);
            b.push_back(v);
		}
		for ( int i = 1 ; i <= n ; i++ ){
			deg[i] = adj[i].size();
		}
	}

	bool check(int u, int c){
		for ( int v: adj[u] ){
			if (colored[v] == c) return false;
		}
		return true;
	}
	void solve(){
		int cnt = 0, color= 1;
		while ( cnt < n ){
			for ( int i = 1 ; i <= n ; i++ ){
			if (!colored[i] && check(i,color)){
				colored[i] = color;
				cnt++;
			}
		}
	color++;	
}
}

	void PrintSol(){
		std::cout<<"graph dothi"<<"\n"<<"{";
		for ( int i = 1 ; i <= n; i++ ){
			std::cout<<i<<" [fillcolor="<<idcolor[colored[i]]<<", style = filled];"<<endl;
		}
		
		for ( int i = 0; i < a.size() ; i++ ){
		    std::cout<<a[i]<<"--"<<b[i]<<";"<<endl;
		}
		std::cout<<"}";
	}
		int main(){
			freopen("dothi.txt","r",stdin);
			freopen("dothitomau.dot","w",stdout);
			ios_base::sync_with_stdio(false);
			cin.tie(NULL);
		inp();
		solve();
		PrintSol();
		return 0;
	}
 /* 23 22
1 4
1 7
1 10
1 13
4 5
4 2
7 11
10 14
13 3
13 12
2 6
2 9
2 8
6 17
8 15
8 19
15 21
15 20
16 22
16 23
12 16
12 18
	*/


