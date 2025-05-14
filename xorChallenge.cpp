#include<bits/stdc++.h>

using namespace std;

int main(){
    int c;
    cin>>c;
    int k=1;
    unsigned long long int a=0,b=0;
    while (c>1 )
    {
        if (c&1)
        {
            a=(a|k); // setting to 1
            b=(b&(~k)); // setting to 0
        }
        else
        {
            a=a|k;
            b=b|k;
        }
        k<<=1;
        c>>=1;
    }
    a=a&(~k);
    b=b|k;

    cout<<a*1ll*b<<'\n';

    return 0;
}