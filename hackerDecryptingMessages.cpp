#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;
int a[N]={0};

const int capacity=1e6+10;
int twoPrimes[capacity]={-1};

int main(){
    int n,q;
    cin>>n>>q;
    for (int i = 0; i <n; i++)
    {
        cin>>a[i];
        cout<<a[i]<<" ";
    }
    cout<<"\n\n";
    for (int i = 0; i < n; i++)
    {
        for (int j=i; j < n; j++)
        {
            int ans=a[i]*a[j];
            //cout<<a[i]<<"-=-="<<a[j]<<"??\n";
            //cout<<ans<<"-- ";
            while( ans< capacity){
                twoPrimes[ans]=a[j];
                ans*=a[j];
                //cout<<ans<<" ";
            }
            //cout<<'\n';
        }
        
    }
    for (int i = 0; i <100; i++)
    {
        //cout<<a[i]<<" ";
    }
    
    while (q--)
    {
        int x;
        cin>>x;
        if (twoPrimes[x])
        {
            cout<<"Yes\n";
        }
        else
        {
            cout<<"NO\n";
        }
        
    }
    
    return 0;
}