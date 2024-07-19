#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;
int main(){
    long long int n;
    cin>>n;
    
    long long int ans = 0;
    while(n){
        ans += (n/5);
        n/=5;
    }
    cout<<ans;
}