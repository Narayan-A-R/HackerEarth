#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int hp[N]={0};
int canRemove[N]={0};
int hsh[N]={0};

vector<int> distinctPF(int x){
    vector<int> ans;
    while (x>1){
        int pf=hp[x];
        while(x%pf==0){
            x/=pf;
        }
        ans.push_back(pf);
    }
    return ans;
}

int main(){
    for (int i = 2; i < N; i++){
        if (hp[i]==0){
            for (int  j = i; j < N; j+=i){
                hp[j]=i;
            }
        }
    }
    
    int n,q;
    cin>>n>>q;
    for (int i = 0; i <n; i++){
        int x;
        cin>>x;
        hsh[x]=1;
    }
    for (int i = 2; i <N; i++)
    {
        if (hsh[i])
        {
            for (long long int j = i; j < N; j*=i)
            {
                canRemove[j]=1;
            }
        }
    }
    while (q--)
    {
        int x;
        cin>>x;
        vector<int> pf=distinctPF(x);
        bool isPossible=false;
        for (int i = 0; i < pf.size(); i++)
        {
            for (int j = i; j < pf.size(); j++)
            {
                int product=pf[i]*pf[j];
                if (i==j && x%product!=0)
                {
                    continue;
                }
                int toRemove=x/product;
                if (canRemove[toRemove]==1 || toRemove==1)
                {
                    isPossible=true;
                    break;
                }
                
            }
            if (isPossible)
            {
                break;
            }
        }
        if (isPossible)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }


    return 0;
}   