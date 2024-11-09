#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    
    map<int,int>mp;
    int start = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        mp[a[i]]++;
        while(mp[a[i]]>1){
            mp[a[start]]--;
            start++;
        }
        ans = max(ans,i-start + 1);
    }
    cout<<ans;
}