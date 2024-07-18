#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n,x;
    cin>>n;
    long long int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    long long int ans = 0;
    for(int i=0;i<n-1;i++){
        long long int diff = a[i+1] - a[i];
        if(diff<0)
        {
            ans += abs(diff);
            a[i+1] += abs(diff);
        }
    }
    cout<<ans;
}