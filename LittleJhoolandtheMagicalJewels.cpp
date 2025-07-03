#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        int hash[4]={0};
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i]=='r') hash[0]++;
            if(s[i]=='u') hash[1]++;
            if(s[i]=='b') hash[2]++;
            if(s[i]=='y') hash[3]++;
        }
        int quantity=hash[0];
        for(int i=0;i<4;i++) quantity=min(quantity,hash[i]);
        cout<<quantity<<"\n";
    }
    
    return 0;
}