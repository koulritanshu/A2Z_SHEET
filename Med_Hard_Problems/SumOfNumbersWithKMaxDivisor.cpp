// https://www.codechef.com/problems/COUNTN

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long ll;

vector<ll> p;
map<ll, ll> mp;
void solve()
{
    ll n;
    cin >> n;
    if (n == 1)
    {
        cout << 0 << endl;
    }
    else if (n % 2 == 0)
    {
        cout << n * 2 << endl;
    }
    else if (mp.find(n) != mp.end())
    {
        cout << n * mp[n] << endl;
    }
    else
    {
        ll index = -1;
        for (ll i = 0; i < p.size(); i++)
        {
            if (n % p[i] == 0)
            {
                index = i;
                break;
            }
        }
        cout << (n * mp[p[index]]) << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<bool> sieve(1000001, true);
    sieve[0] = sieve[1] = false;
    for (ll i = 2; i * i <= 1000001; i++)
    {
        if (sieve[i])
        {
            for (ll j = i * i; j <= 1000001; j += i)
            {
                sieve[j] = false;
            }
        }
    }
    for (ll j = 2; j <= 1000001; j++)
    {
        if (sieve[j])
        {
            p.push_back(j);
        }
    }
    mp[2] = 2;
    ll sum = 2;

    for (ll j = 1; j < p.size(); j++)
    {
        mp[p[j]] = sum + p[j];
        sum = sum + p[j];
    }
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}