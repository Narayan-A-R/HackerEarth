#include<bits/stdc++.h>
#include<bitset>
using namespace std;
const int N=1e4+10;
int vowelInNames[N];
long long int choose(long long int n){
    if (n<3) return 0;
    //long long int m=1;
    // for (int i = n; i >n-3 && n >=3; i--)
    // {
    //     m*=i;
    // }
    return n*(n-1)*(n-2)/6;

}
long long int common1(int * vowelInNames,int capacity){
    long long int sum=0;
    for (int j = 0; j < 5; j++)
    {
        int cnt=0;
        for (int i = 0; i < capacity; i++)
        {
            if(vowelInNames[i]&(1<<j)) cnt++;
        }
        sum+=choose(cnt);
    }
    return sum;
}
long long int common2(int * vowelInNames,int capacity){
    long long int sum=0;
    for (int k = 0; k < 4; k++)
    {
        for (int j = k+1; j < 5; j++)
        {
            int cnt=0;
            for (int i = 0; i < capacity; i++)
            {
                if(vowelInNames[i]&(1<<j) && vowelInNames[i]&(1<<k)) cnt++;
            }
            sum+=choose(cnt);
        }
    }
    return sum;
}
long long int common3(int * vowelInNames,int capacity){
    long long int sum=0;
    for (int l = 0; l < 3; l++)
    {
        for (int k = l+1; k < 4; k++)
        {
            for (int j = k+1; j < 5; j++)
            {
                int cnt=0;
                for (int i = 0; i < capacity; i++)
                {
                    if(vowelInNames[i]&(1<<j) && vowelInNames[i]&(1<<k) && vowelInNames[i]&(1<<l)) cnt++;
                }
                sum+=choose(cnt);
            }
        }
    }
    return sum;
}
long long int common4(int * vowelInNames,int capacity){
    long long int sum=0;
    for (int m = 0; m < 2; m++)
    {
        for (int l = m+1; l < 3; l++)
        {
            for (int k = l+1; k < 4; k++)
            {
                for (int j = k+1; j < 5; j++)
                {
                    int cnt=0;
                    for (int i = 0; i < capacity; i++)
                    {
                        if(vowelInNames[i]&(1<<j) && vowelInNames[i]&(1<<k) && vowelInNames[i]&(1<<l) && vowelInNames[i]&(1<<m)) cnt++;
                    }
                    sum+=choose(cnt);
                }
            }
        }
    }
    return sum;
}
long long int common5(int * vowelInNames,int capacity){
    long long int sum=0;
    for (int n = 0; n < 1; n++)
    {
        for (int m = n+1; m < 2; m++)
        {
            for (int l = m+1; l < 3; l++)
            {
                for (int k = l+1; k < 4; k++)
                {
                    for (int j = k+1; j < 5; j++)
                    {
                        int cnt=0;
                        for (int i = 0; i < capacity; i++)
                        {
                            if(vowelInNames[i]&(1<<j) && vowelInNames[i]&(1<<k) && vowelInNames[i]&(1<<l) && vowelInNames[i]&(1<<m) && vowelInNames[i]&(1<<n)) cnt++;
                        }
                        sum+=choose(cnt);
                        
                    }
                    
                }
                
            }
            
        }
        
    }
    return sum;
}


int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        for (int i = 0; i <n; i++)
        {
            string str;
            cin>>str;

            int vowelsInbits=0;
            for (int j = 0; j < str.size(); j++)
            {
                if (str[j]== 'a') vowelsInbits|=(1<<4);
                if (str[j]== 'e') vowelsInbits|=(1<<3);
                if (str[j]== 'i') vowelsInbits|=(1<<2);
                if (str[j]== 'o') vowelsInbits|=(1<<1);
                if (str[j]== 'u') vowelsInbits|=(1<<0);
            }
            vowelInNames[i]=vowelsInbits;
        }
        
        


        // long long int common=  common1(vowelInNames,n)
        //             -common2(vowelInNames,n)
        //             +common3(vowelInNames,n)
        //             -common4(vowelInNames,n)
        //             +common5(vowelInNames,n);

        // cout<<common1(vowelInNames,n)<<"  --- 1\n";
        // cout<<common2(vowelInNames,n)<<"  --- 2\n";
        // cout<<common3(vowelInNames,n)<<"  --- 3\n";
        // cout<<common4(vowelInNames,n)<<"  --- 4\n";
        // cout<<common5(vowelInNames,n)<<"  --- 5\n";
        // cout<<common<<"  ---------------\n";
        //cout<<common<<'\n';
        long long int sum=0;
        for (int mask = 1; mask < (1<<5); mask++)
        {
            long long int cnt=0;
            for (int i = 0; i < n; i++)
            {
                if((vowelInNames[i]&mask) ==  mask) cnt++;
            }
            if(__builtin_popcount(mask)&1){
                sum+=choose(cnt);
            }else{
                sum-=choose(cnt);
            }
        }
        cout<<sum<<'\n';
        
    }
    
    
    return 0;
}

// 00000
// 11111
// 22222
// 33333
// 44444
// 10000
// 20000
// 30000
// 40000
// 11111
// 21111
// 31111
// 41111
// 12222
// 22222
// 32222
// 42222
// 13333
// 23333
// 33333
// 43333
// 21000
// 31000
// 41000
// 22000
// 32000
// 42000
// 23000
// 33000
// 43000
// 21100
// 31100
// 41100
// 22100
// 32100
// 42100
// 23100
// 33100
// 43100
// 21200
// 31200
// 41200
// 22200
// 32200
// 42200
// 23200
// 33200
// 43200
// 21200
// 31200
// 41200
// 22200
// 32200
// 42200
// 23200
// 33200
// 43200
// 32100
// 42100
// 43210