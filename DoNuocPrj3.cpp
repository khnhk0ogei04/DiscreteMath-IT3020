#include<bits/stdc++.h>
#define ll long long
#define db double
#define FOR(i,l,r) for ( int i = l ; i <= r ; i++ )
#define FOD(i,l,r) for ( int i = l ; i >= r ; i-- )
    
    std::set<std::vector<int>> visited;
    std::vector<int>noderoot;
    std::vector<std::string>v1;
    std::vector<std::vector<std::string>>v;
    int ok = 0;
    void dfs ( std::vector<int>node )
    {
    if (!ok){
    visited.insert(node);
    // std::cout<<node[0]<<" "<<node[1]<<" "<<node[2]<<std::endl;
    FOR(i,0,2){
        if ( node[i] == 10 ) {
            v1.push_back(std::string(1,'1'));
            v1.push_back(std::string(1,'0'));
            v1.push_back(std::string(1,','));
        }
        else {
            v1.push_back(std::string(1,node[i]+'0'));
            v1.push_back(std::string(1,','));
        }
        }
        v1.pop_back();
        v.push_back(v1);
        v1.clear();
    
    }
    while(!ok){
    if ( node[1] == 2 || node[2] == 2 ) {
        ok = 1;
        break;
    }
    for (int i = 0; i <= 2 ; i++) 
    {
        int maxv;
        for (int j = 0 ; j <= 2 ; j++)
        {
            if (j == 0) maxv = 10;
            else {
                if (j == 1) maxv = 7;
                else maxv = 4;
            }
            if (i != j && node[i] > 0 && node[j] < maxv) 
            {
                int luongnuocdo =std::min(node[i],maxv - node[j]);
                std::vector<int> nodenext(3);
                nodenext[i] = node[i] - luongnuocdo;
                nodenext[j] = node[j] + luongnuocdo;
                nodenext[3 - i - j] = node[3 - i - j];
                
                if (visited.find(nodenext) == visited.end()) dfs(nodenext);
                
            }
        }
    }
}
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    noderoot.push_back(0);
    noderoot.push_back(7);
    noderoot.push_back(4);
    dfs(noderoot);
    std::cout<<"graph test{"<<std::endl;
    for ( int i = 0 ; i < v.size()-1 ; i++ ){
        std::string a,b;
        a += '"'; b += '"';
        for ( auto x : v[i] ){
            a = a + x;
        }
        a += '"';
        for ( auto x : v[i+1] ){
            b = b + x;
        }
        b += '"';
        std::cout<<a<<"--"<<b;
        std::cout<<std::endl;
    }
    std::cout<<"}";
    return 0;
}