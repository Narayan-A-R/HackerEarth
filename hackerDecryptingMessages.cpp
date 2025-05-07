#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;
int a[N]={0};

const int capacity=1e6+10;
int twoPrimes[capacity]={-1};

vector<int> isPrime(N,1);
int highestPrime[N]={0};
int lowestPrime[N]={0};

int main(){
    int n,q;
    cin>>n>>q;
    for (int i = 0; i <n; i++)
    {
        cin>>a[i];
        cout<<a[i]<<" ";
    }
    cout<<"\n\n";

    isPrime[0]=0;
    isPrime[1]=0;
    cout<<isPrime[2]<<"-=-=-=-\n";
    for (int i = 2; i < N; i++)
    {
        if (isPrime[i] == 1)
        {
            for (int j = 2*i; j < N; j+=i)
            {
                highestPrime[j]=i;
                if (lowestPrime[j]==0)
                {
                    lowestPrime[j]=i;
                }
                
            }
        }
    }
    

    while (q--)
    {
        int x;
        cin>>x;

        int found=0;
        for (int i = 0; i < n ; i++)
        {
            int temp=x;
            cout<<x<<"--\n";
            while (temp%a[i]==0 )
            {
                cout<<lowestPrime[temp]<<" ++ "<< highestPrime[temp]<<" -- \n";
                if (lowestPrime[temp]*highestPrime[temp]==temp)
                {
                    cout<<"YES\n";
                    found=1;
                    break;
                }
                temp/=a[i];
            }
            if (found)
            {
                break;
            }
        }
        if (!found)
        {
            cout<<"NO\n";
        }
        
        
    }
    
    return 0;
}