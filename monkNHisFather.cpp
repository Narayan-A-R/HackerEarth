#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        unsigned long long int p;
        cin>>p;
        unsigned long long int money=0;

        while (p>0)
        {
            money+=(p&1);
            p>>=1;
        }

        cout<<money<<'\n';
        
        
    }
    
    return 0;
}