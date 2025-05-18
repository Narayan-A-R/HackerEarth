#include<bits/stdc++.h>

using namespace std;

const int N=1e6+10;
vector<int> graph[N];

void dfs(int vertex){

    for (int child:graph[vertex])
    {
        dfs(child);
    }
    
}

int main(){
    int n,e;
    cin>>n>>e;

    for (int i = 0; i < e; i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    
    int vertex=1;
    dfs(vertex);
    return 0;
}