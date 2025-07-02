#include<bits/stdc++.h>

using namespace std;


int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string needle,haystack;
        cin>>needle>>haystack;

        int needlehash[26]={0};
        for(int i=0;i<needle.size();i++) needlehash[needle[i]-'a']++;

        int hayhash[26]={0};
        for(int i=0;i<needle.size();i++) hayhash[haystack[i]-'a']++;
        
        int vis[26]={0};
        int found=0;
        int cnt=0;
        for(int i=0;i<needle.size();i++) 
        {
            int ithLetter=haystack[i]-'a';
            if(!vis[ithLetter]) cnt+=(min(needlehash[ithLetter],hayhash[ithLetter]));
            vis[ithLetter]=1;
        }
        if(cnt==needle.size()){
            found=1;
            cout<<"YES\n";
        }
        for(int i=needle.size();i<haystack.size() && !found;i++){
            
            int lastLetter=haystack[i]-'a';
            int firstLetter=haystack[i-needle.size()]-'a';
            if(cnt>0 && hayhash[firstLetter]<=needlehash[firstLetter]) cnt--;

            
            hayhash[firstLetter]--;
            hayhash[lastLetter]++;
            if(hayhash[lastLetter]<=needlehash[lastLetter]) cnt++;
            if(cnt==needle.size()){
                found=1;
                cout<<"YES\n";
                break;
            }
        }
        if(!found) cout<<"NO\n";
            
    }   
    
    return 0;
}