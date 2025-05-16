#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int vowelInNames[N];
int choose(int n){
    if (n<3) return 0;

    int m=1;
    for (int i = n; i >n-3 && n >=3; i--)
    {
        m*=i;
    }
    return m/6;

}
int common1(int * vowelInNames,int capacity){
    int sum=0;
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
int common2(int * vowelInNames,int capacity){
    int sum=0;
    for (int k = 0; k < 4; k++)
    {
        for (int j = k+1; j < 5; j++)
        {
            int cnt=0;
            for (int i = 0; i < capacity-1; i++)
            {
                if(vowelInNames[i]&(1<<j) && vowelInNames[i+1]&(1<<k)) cnt++;
            }
            sum+=choose(cnt);
        }
    }
    return sum;
}
int common3(int * vowelInNames,int capacity){
    int sum=0;
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
int common4(int * vowelInNames,int capacity){
    int sum=0;
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

int common5(int * vowelInNames,int capacity){
    int sum=0;
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



        int common=  common1(vowelInNames,n)
                    -common2(vowelInNames,n)
                    +common3(vowelInNames,n)
                    -common4(vowelInNames,n)
                    +common5(vowelInNames,n);

        // cout<<common1(vowelInNames,n)<<"  --- 1\n";
        // cout<<common2(vowelInNames,n)<<"  --- 2\n";
        // cout<<common3(vowelInNames,n)<<"  --- 3\n";
        // cout<<common4(vowelInNames,n)<<"  --- 4\n";
        // cout<<common5(vowelInNames,n)<<"  --- 5\n";
        // cout<<common<<"  ---------------\n";
        cout<<common<<'\n';
        
        
        
    }
    
    return 0;
}