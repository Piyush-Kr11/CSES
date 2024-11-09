#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main() {
    lli n;
    cin>>n;
    lli a[n];
    for(lli i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    lli median = (n&1)?a[n/2]:((a[n/2] + a[n/2 - 1])>>1);
    lli ans = 0;
    for(lli i=0;i<n;i++)
    ans += abs(a[i]-median);
    cout<<ans;
}