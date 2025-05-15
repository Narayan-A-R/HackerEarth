#include<bits/stdc++.h>

using namespace std;
const int N=1e4+10;
int vowelInNames[N];
int common1(int * vowelInNames,int N){
    int cnt=0;
    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < N; i++)
        {
            if(vowelInNames[i]&&(1<<j)) cnt++;
        }
    }
    return cnt;
}
int common2(int * vowelInNames,int N){
    int cnt=0;
    for (int k = 0; k < 4; k++)
    {
        for (int j = k+1; j < 5; j++)
        {
            for (int i = 0; i < N; i++)
            {
                if(vowelInNames[i]&&(1<<j) && vowelInNames[i]&&(1<<k)) cnt++;
            }
        }
    }
    return cnt;
}
int common3(int * vowelInNames,int N){
    int cnt=0;
    for (int l = 0; l < 3; l++)
    {
        for (int k = l+1; k < 4; k++)
        {
            for (int j = k+1; j < 5; j++)
            {
                for (int i = 0; i < N; i++)
                {
                    if(vowelInNames[i]&&(1<<j) && vowelInNames[i]&&(1<<k)&& vowelInNames[i]&&(1<<l)) cnt++;
                }
            }
        }
    }
    return cnt;
}
int common4(int * vowelInNames,int N){
    int cnt=0;
    for (int m = 0; m < 2; m++)
    {
        for (int l = m+1; l < 3; l++)
        {
            for (int k = l+1; k < 4; k++)
            {
                for (int j = k+1; j < 5; j++)
                {
                    for (int i = 0; i < N; i++)
                    {
                        if(vowelInNames[i]&&(1<<j) && vowelInNames[i]&&(1<<k)&& vowelInNames[i]&&(1<<l) && vowelInNames[i]&&(1<<m)) cnt++;
                    }
                }
            }
        }
    }
    return cnt;
}

int common5(int * vowelInNames,int N){
    int cnt=0;
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
                        for (int i = 0; i < N; i++)
                        {
                            if(vowelInNames[i]&&(1<<j) && vowelInNames[i]&&(1<<k)&& vowelInNames[i]&&(1<<l) && vowelInNames[i]&&(1<<m) && vowelInNames[i]&&(1<<n)) cnt++;
                        }
                        
                    }
                    
                }
                
            }
            
        }
        
    }
    return cnt;
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
                if (str[i]== 'a') vowelsInbits|(1<<4);
                if (str[i]== 'e') vowelsInbits|(1<<3);
                if (str[i]== 'i') vowelsInbits|(1<<2);
                if (str[i]== 'o') vowelsInbits|(1<<1);
                if (str[i]== 'u') vowelsInbits|(1<<0);
            }
            vowelInNames[i]=vowelsInbits;
        }

        
        int common=common1(vowelInNames,n)-common2(vowelInNames,n)+common3(vowelInNames,n)-common4(vowelInNames,n)+common5(vowelInNames,n);

        if (common>=3)
        {
            int m=1;
            for (int i = common; i >common-3 && common >=3; i--)
            {
                m*=i;
            }
            int ans=m/6;
            cout<<ans<<'\n';
        }
        else
        {
            cout<<0<<'\n';
        }
        
        
        // if( vowelsInNames[k]&(1<<i) && && vowelInNames[k]&(1<<j) && vowelInNames[l]&(1<<j))
        // either a is common or e is common or i is common or o is common or u is common
        //  a b c
        // 
    }
    
    return 0;
}