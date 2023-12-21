#include <bits/stdc++.h>
#include <fstream>
const int MAXN = 1e4 + 1;
using namespace std::chrono; 

auto start = high_resolution_clock::now();
std::vector<std::string> v;
bool visited[MAXN];
int n = 5757;
std::string s,a,b;
std::map<int,std::string>mp1;
std::map<std::string,int>mp2;
int marked[MAXN],parent[MAXN];
std::vector<int> adj[MAXN];
std::vector<int>t_adj[MAXN]; std::stack<int>st;
	bool check1(std::string s1, std::string s2) {
		int cnt = 0;
		std::string tmp = s2;
    	for ( int i = 1 ; i < s1.length() ; i++ ){
    		for ( int j = 0 ; j < s2.length() ; j++ ){
    			if (s1[i] == tmp[j]){
    				cnt++;
    				tmp[j] = '\0';
    				break;
				}
			}
			if ( i == 1 && cnt < 1 ) break;
			if ( i == 2 && cnt < 2 ) break;
			if ( i == 3 && cnt < 3 ) break;
			if ( i == 4 && cnt < 4 ) break;
		}
		return ( cnt == 4 );
	}
                       
	void process(){
		for ( int i = 1 ; i <= n ; i++ ){
			for ( int j = 1 ; j <= n ; j++ ){
				if ( i != j && check1(v[i],v[j])){
					adj[i].push_back(j);
					t_adj[j].push_back(i);
				}
			}
		}
	}
	void dfs1( int u ){
		visited[u] = true;
		for ( int v: adj[u] ){
			if (!visited[v])
			dfs1(v);
		}
		st.push(u);
	}
	std::vector<std::string>kqua[MAXN];
	int dem = 0;
	void dfs2( int u ){
		kqua[dem].push_back(mp1[u]);
		marked[u] = dem;
		visited[u] = true;
		for ( int v: t_adj[u] ){
			if (!visited[v])
			dfs2(v);
		}
	}
	
	void tpltm(){
    for ( int i = 1 ; i <= n ; i++ ){
        if (!visited[i]) dfs1(i);
    }
    std::memset(visited,false,sizeof(visited));
    while (!st.empty()){
        int u = st.top(); st.pop();
        if (!visited[u]){
            dem++;
            dfs2(u);
        }
    }
    std::cout <<"Cau a: So thanh phan lien thong: "<<dem<< std::endl;
}
	void sametplt(){
		int k1 = mp2[s];
		int k2 = marked[k1];
		std::cout<<kqua[k2].size()<<std::endl;
		for ( auto x : kqua[k2] ) std::cout<<x<<" ";
	}
	void bfs( int s, int t ){
		std::memset(visited,false,sizeof(visited));
		std::queue<int>q;
		q.push(s);
		visited[s] = true;
		while (!q.empty()){
			int u = q.front(); q.pop();
			for ( int v: adj[u] ){
				if (!visited[v]){
					q.push(v);
					visited[v] = true;
					parent[v] = u;
				}
				}
			}
			if (visited[t]) {
				std::vector<int>tmp;
				while ( t != s ){
				tmp.push_back(t);
				t = parent[t];
			}
			tmp.push_back(s);
			std::reverse(tmp.begin(),tmp.end());
			for ( auto x: tmp ) std::cout<<mp1[x]<<" ";
		}
		else std::cout<<"Khong the di chuyen";
	}
	 
	int main() {
	std::ios::sync_with_stdio(false);
    auto start = high_resolution_clock::now();
    std::ifstream f("sgb-words.txt");

    v.resize(5758);
	
    for (int i = 1; i <= 5757; i++) {
        f >> v[i];
        mp1[i] = v[i];
        mp2[v[i]] = i;
    }

    f.close();
	process();
	tpltm();	
	std::cout<<"Cau b: Nhap vao tu u";
	std::cin>>s;
	sametplt();
	std::cout<<std::endl;
	std::cout<<"Cau c: In ra duong di ngan nhat: "<<std::endl;
	std::cout<<"Nhap vao tu u: ";
	std::cin>>a;
	std::cout<<"Nhap vao tu v: ";
	std::cin>>b;
	bfs(mp2[a],mp2[b]);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    std::cerr << '\n' << duration.count();

    return 0;
}