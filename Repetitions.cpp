#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int ans = 0;
    for(int i=0;i<s.length();i++){
        int j=i;
        while(s[j]==s[j+1])j++;
        ans = max(ans, j-i+1);
        i = j;
    }
    cout<<ans;
}