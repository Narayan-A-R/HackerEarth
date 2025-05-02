#include<bits/stdc++.h>

using namespace std;
const int N=2*1e5+10;
int a[N]={0};
int rangeOfPNQ[N]={0};

int main(){
    int n;
    cin>>n;
    int max=-1;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        rangeOfPNQ[a[i]]++;

        if (a[i]>max)
        {
            max=a[i];
        }
        
    }
    
    int t;
    cin>>t;
    while (t--)
    {
        int p,q;
        cin>>p>>q;
        int count=0;

        if (p<q)
        {
            swap(p,q);
        }
        
        for (int i = p; i <= max; i+=p)
        {
            count+=rangeOfPNQ[i];
        }
		for (int j=q; j <= max; j+=q)
        {
            count+=rangeOfPNQ[j];
        }
		long long int lcm=(p*1LL*q)/__gcd(p,q);
		for (long long int i = lcm; i <= max; i+=lcm)
        {
            count-=rangeOfPNQ[i];
        }
        cout<<count<<'\n';
        
    }

    return 0;
}