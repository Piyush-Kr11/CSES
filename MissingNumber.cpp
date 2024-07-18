#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n,x;
    cin>>n;
    long long int natSum = (n*n + n)>>1;
    long long int arrSum = 0;
    while(--n){
        cin>>x;
        arrSum+=x;
    }
    cout<<natSum - arrSum;
}