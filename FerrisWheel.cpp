#include <bits/stdc++.h>
using namespace std;
int solve(int a[],int n){
    sort(a,a+n);
}
int main() {
    int n,x;
    cin>>n>>x;
    int ar[n];
    for(int i=0;i<n;i++)
    cin>>ar[i];
    cout<<solve(ar,n);
}