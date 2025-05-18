#include<bits/stdc++.h>

using namespace std;

const int N=1e6+10;
vector<int> graph[N];
bool visited[N]={false};

void dfs(int vertex){

    visited[vertex]=true;
    for (int child:graph[vertex])
    {
        if(visited[child]) continue;
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
    
    int cnt=0;
    for (int i = 1; i <= n; i++)
    {
        if(visited[i]) continue;
        dfs(i);
        cnt++;
    }
    cout<<cnt<<'\n';
    return 0;
}