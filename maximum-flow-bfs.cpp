#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<queue>
#include<vector>
#include<stdio.h>
#define ll long long
#define MAXN 1005
#define inf 1e9 + 7
using namespace std;
	void minimize( int &a, int b ){
		if ( a > b )
		a = b;
	}
	int n,m,source,target;
	std::vector<int>adj[MAXN];
	int C[MAXN][MAXN],F[MAXN][MAXN];
	int d[MAXN];
	bool findpath( int source, int target ){
		std::queue<int>q;
		for (int i = 1 ; i <= n ; i++){
			d[i] = 0;
		}
		d[source] = inf;
		q.push(source);
		while (q.size()){
			int u = q.front();
			q.pop();
			if ( u == target ) return true;
			for ( int v: adj[u] ){
				if (d[v] == 0 && C[u][v] > F[u][v]){
					d[v] = u;
					q.push(v);
				}
			}
		}
		return false;
	}
	void tangluong(){
		int u,v,delta = inf;
		for ( v = target; (u = d[v]) != inf; v = u )
		minimize(delta,C[u][v] - F[u][v]);
		for ( v = target; v != source; v = u ){
			u = d[v];
			F[u][v] += delta;
			F[v][u] -= delta;
		}
	}
	int key(int u){
		int sum = 0;
		for ( int v: adj[u] ){
			sum += F[u][v];
		}
		return sum;
	}
	int main(int argc,const char**argv){
		std::cin>>n>>m>>source>>target;
		for ( int i = 1 ; i <= m ; i++ ){
			int p,q,w;
			std::cin>>p>>q>>w;
			adj[p].push_back(q);
			adj[q].push_back(p);
			C[p][q] = w;
		}
		while(findpath(source,target))
		tangluong();
		std::cout<<key(source);
	}