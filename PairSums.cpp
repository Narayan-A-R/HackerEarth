#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    unordered_map<int,int> map;
    int found=0;
    for(int i=0;i<n;i++) map[k-a[i]]=i;
    for(int i=0;i<n;i++) if(map.find(a[i])!=map.end() && i!= map[a[i]]){
        found=1;
        cout<<"YES\n";
        break;
    }
    if(!found) cout<<"NO\n";
    return 0;
}