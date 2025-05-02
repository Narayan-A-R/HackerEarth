#include<bits/stdc++.h>

using namespace std;
const int M=1e9+7;

int binMultiply(long long int a,long long int b){
    int ans=0;
    while (b>0)
    {
        if (b&1)
        {
            ans=(ans+a)%M;
        }
        a=(a+a)%M;
        b=b>>1;
    }
    return ans;
}
int totalPasswords(int n, int k){
    int ans=1;
    for (int i = k; i!=(k-n); i--)
    {
        ans=binMultiply(ans,i)%M;
    }
    ans%=M;
    return ans;
}
int main(){
    int t;
    cin>>t;

    while (t--)
    {
        int n,k;
        cin>>n>>k;
        cout<<totalPasswords(n,k)<<'\n';
    }
    
    return 0;
}