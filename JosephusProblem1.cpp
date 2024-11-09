#include <bits/stdc++.h>
using namespace std;
void print(vector<int> &v)
{   
    if(v.size()==1){
        cout<<v[0];
        return ;
    }
    vector<int>temp;
    int n = v.size();
    for(int i=0;i<n;i++){
        if(i&1)
        cout<<v[i]<<" ";
        else
        temp.push_back(v[i]);
    }
    if(n&1)
    temp.pop_back(),temp.insert(temp.begin(),v[n-1]);
    print(temp);
}
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
            v.push_back(i);
        else
            cout << i << " ";
    }
    if (n & 1)
        v.pop_back(),v.insert(v.begin(), n);
    print(v);
}