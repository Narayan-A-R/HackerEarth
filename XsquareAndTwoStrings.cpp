#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string s1,s2;
        cin>>s1>>s2;
        int hash1[26]={0};
        int hash2[26]={0};
        int found=0;
        for (int i = 0; i < s1.size(); i++)
        {
            hash1[s1[i]-'a']=1;
        }
        for (int i = 0; i < s2.size(); i++)
        {
            hash2[s2[i]-'a']=1;
        }
        for (int i = 0; i < 26; i++)
        {
            if(hash1[i]&hash2[i]){
                cout<<"Yes\n";
                found=1;
                break;
            }
        }
        if(!found) cout<<"No\n";
    }
    
    return 0;
}