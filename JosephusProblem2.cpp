#include <bits/stdc++.h>
using namespace std;
void print(vector<int> &v, int k)
{
    // for (auto i : v)
    //     cout << i << " ";
    // cout << endl;
    if (v.size() == k)
    {
        cout << v[k - 1] << " ";
        for (int i = 0; i < k - 1; i++)
            cout << v[i] << " ";
        return;
    }
    vector<int> temp;
    int n = v.size();
    int lim = k * (n / k);
    for (int i = 0; i < lim; i++)
    {
        if (i % k == k - 1)
            cout << v[i] << " ";
        else
            temp.push_back(v[i]);
    }
    for (int i = n - 1; i >= lim; i--)
        temp.insert(temp.begin(), v[i]);
    print(temp, k);
}
int main()
{
    int n, k;
    cin >> n >> k;
    if (k == 0 || n<=k)
    {
        for (int i = 1; i <= n; i++)
            cout << i << " ";
        return 0;
    }
    k++;
    vector<int> v;
    int lim = k * (n / k);
    for (int i = 1; i <= lim; i++)
    {
        if (i % k == 0)
            cout << i << " ";
        else
            v.push_back(i);
    }
    for (int i = n; i > lim; i--)
        v.insert(v.begin(), i);
    print(v, k);
}
//Digit Queries
// 1 2 3 4 5 6 7 8 9 1  0  1  1  1  2  1  3  1  4  1  5  1  6  1  7  1  8  1  9  2  0
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31