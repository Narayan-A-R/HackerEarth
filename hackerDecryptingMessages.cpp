#include<bits/stdc++.h>

using namespace std;

const int N=1e6+10;
int a[N]={0};
// int hp[N]={0};
// int lp[N]={0};
vector<int> isPrime(N,0);
vector<int> v;
vector<vector<int>> allPrimeFactors(N,v);
int isPowerOfArr[N]={0};

int main(){
    int n,q;
    cin>>n>>q;
    for (int i = 0; i <n; i++)
    {
        cin>>a[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        for (long long int j = a[i]; j < N; j*=j)
        {
            isPowerOfArr[j]=1;
        }
    }

    
    for (int i = 2; i < N; i++)
    {
        if (isPrime[i] == 0)
        {
            for (int j = i; j < N; j+=i)
            {
                allPrimeFactors[j].push_back(i);
                isPrime[j]++;
                // hp[j]=i;
                // if (lp[j]==0)
                // {
                //     lp[j]==i;
                // }
                
            }
        }
    }

    unordered_map<int,string> xtoAns;
    for (int x = 2; x < N; x++)
    {
        int found=0;
        if (isPrime[x])
        {
            xtoAns[x]="NO\n";
        }
        
        for (auto it = allPrimeFactors[x].begin(); it != allPrimeFactors[x].end(); it++)
        {
            if (found)
            {
                break;
            }
            for (auto itr=it; itr!=allPrimeFactors[x].end(); itr++)
            {
                int ans=x/((*it)*(*itr));
                if (found)
                {
                    break;
                }
                
                if (*it == *itr && (x/(*it))%(*it)!=0)
                {
                    xtoAns[x]="NO\n";
                    continue;
                }
                
                if (isPowerOfArr[ans] )
                {
                    xtoAns[x]="YES\n";
                    found=1;
                }
                else{
                    xtoAns[x]="NO\n";
                }
            }
        }
        
    }
    

    
    // for(auto value:allPrimeFactors[429]){
    //     cout<<value<<" ";
    // }

    // for (size_t i = 0; i < 430; i++)
    // {
    //     cout<<isPowerOfArr[i]<<" "<<i<<" \n";
    // }
    
    // for (auto it = allPrimeFactors[42].begin(); it != allPrimeFactors[42].end(); it++)
    // {
    //     for (auto itr=it; itr!=allPrimeFactors[42].end(); itr++)
    //     {
    //         int ans=42/((*it)*(*itr));
    //         cout<<ans<<" ans\n";
    //         cout<<*it<<" --"<<*itr<<" ++\n";
    //         if (*it == *itr && (42/(*it))%(*it)!=0)
    //         {
    //             xtoAns[42]="NO\n";
    //             int sol=(42/(*it))%(*it)!=0;
    //             cout<<"----------"<<sol<<" -------exp\n\n\n";
    //             continue;
    //         }
            

    //         // cout<<sol<<" sol\n\n";
    //         if (isPowerOfArr[ans])
    //         {
    //             xtoAns[42]="YES\n";
    //         }
    //         else{
    //             xtoAns[42]="NO\n";
    //         }
    //     }
    // }
    while (q--)
    {
        int x;
        cin>>x;
        cout<<xtoAns[x];

    }

// 
// 79 7
// 72 11 72 59 100 21 23 87 88 20 12 52 88 52 52 18 15 27 27 78 56 80 86 94 46 100 76 2 86 60 13 54 74 85 27 63 66 92 97 70 82 15 92 2 100 38 59 51 94 73 29 20 42 49 87 76 64 37 81 27 65 61 41 32 60 74 38 47 93 32 75 17 58 65 55 4 10 63 51
// 474
// 168
// 28
// 476
// 908
// 2
// 4  ans is supposed to be yes, 2 x 2 = 4, if we divide 4 by 1 we get it as multiple of 2 primes , but no element 1 in array
    return 0;
}   