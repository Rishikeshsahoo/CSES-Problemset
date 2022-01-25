#include<bits/stdc++.h>
using namespace std;

#define MODs 1000000007
#define all(x) x.begin(), x.end()
#define debug(v) for(long long i=0;i<v.size();i++)cout<<v[i]<<" ";cout<<endl;
#define debugP(v) for(long long i=0;i<v.size();i++)cout<<v[i].first<<" "<<v[i].second<<endl;cout<<endl;
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define endli "\n"

void init()
{

#ifndef ONLINE_JUDGE

    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);

#endif // ONLINE_JUDGE

}
bool prime[10000];
void func()
{
    memset(prime, true, sizeof(prime)); int n = 10000;
    for (int p = 2; p * p <= n; p++)
        if (prime[p] == true)
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
}
bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.first < b.first) return a.first < b.first;
    else if (a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
}

int SieveOfEratosthenes(int num)
{
    int n = 10000;
    for (int p = 2; p <= n; p++)
        if (prime[p])
        {
            if ((num - p) % p == 0)continue;
            else
            {
                return p;
            }
        }
}


int power(int a , int b, int MOD)
{
    if (b == 0) return 1;
    if (b == 1) return a ;
    int temp = power(a, (b / 2), MOD);
    if (b % 2 == 0) return (temp * temp) % MOD;
    else return (((temp * temp) % MOD) * a) % MOD;
}
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int r = power(b, c, MODs - 1);
    int fans = power(a, r, MODs);
    cout <<  fans << endli;
}


signed main()
{
    init();
    fast;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;

}