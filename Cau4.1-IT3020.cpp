#include <bits/stdc++.h>
#include <fstream>
const int MAXN = 1e4 + 1;
using namespace std::chrono; 

auto start = high_resolution_clock::now();
std::vector<std::string> v;
bool visited[MAXN];
int n = 5757;
std::string a, b;
std::vector<int> adj[MAXN];
std::vector<int>t_adj[MAXN]; 
std::stack<int>st;
bool check(std::string s1, std::string s2) {
    int cnt = 0;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] == s2[i]) cnt++;
    }
    return cnt == 4;

}

void xuli() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j && check(v[i], v[j])) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
}                              
void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }
}

int connected() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            cnt++;
        }
    }
    return cnt;
}
int parent[MAXN];
std::queue<int>q;
void bfs(int s, int t) {
	q.push(s);
    visited[s] = true;
  	while (!q.empty()){
  		int u = q.front(); q.pop();
  		for ( int v: adj[u] ){
  			if (!visited[v]){
  				parent[v] = u;
  				q.push(v);
  				visited[v] = 1;
			  }
		  }
	    }
	}

void caub() {
    int k1, k2;
    for (int i = 1; i <= n; i++) {
        if (v[i] == a) k1 = i;
    }
    for (int i = 1; i <= n; i++) {
        if (v[i] == b) k2 = i;
    }
	
    std::memset(visited, false, sizeof(visited));
    bfs(k1, k2);
    if (visited[k2]) {
    	std::vector<int>tmp;
    	while ( k2 != k1 ){
    	    tmp.push_back(k2);
    	    k2 = parent[k2];
		}
		tmp.push_back(k1);
		std::reverse(tmp.begin(),tmp.end());
		for ( auto x: tmp ){
			std::cout<<v[x]<<" ";
		}
	}
	else std::cout<<"Khong co duong di";
}

int main() {
	std::ios::sync_with_stdio(false);
    auto start = high_resolution_clock::now();
    std::ifstream f("sgb-words.txt");

    v.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        f >> v[i];
    }

    f.close();
    xuli();

    std::cout << "Cau a: Connected components: " << connected() << std::endl;

    std::cout << "Cau b: Nhap a va b: ";
    std::cin >> a >> b;

    caub();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    std::cerr << '\n' << duration.count();

    return 0;
}