#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

#define PI 3.14159265358979323846264338327951
const int MAX_N = 1e5 + 5;
const ll INF = 1e9;
const ld eps = 1e-6;
const int N = 1e5 + 10;
const int M = 1e9 + 7;
ll lcm(ll a, ll b)
{
    return (a * b) / (__gcd(a, b));
}
void solve()
{

    ll n; // No of subarrays with xor_sum k;
    cin >> n;
    ll k = 6; // let k = 6

    vector<ll> hash1((2 * n) + 5, 0);
    vector<ll> elm(n);
    for (int i = 0; i < n; i++)
    {
        cin >> elm[i];
    }

    // Find Prefix_Xor

    vector<ll> prefix_xor(n);
    prefix_xor[0] = elm[0];

    for (int i = 1; i < n; i++)
    {
        prefix_xor[i] = elm[i] ^ prefix_xor[i - 1];
    }

    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {

        if (prefix_xor[i] == k)
        {
            cnt++; // if you find prefix_xor = k, increment the counter
        }
        else
        {
            hash1[prefix_xor[i]]++;
            ll check = (prefix_xor[i]) ^ (k); // if check is in our hash then it is sure that there is k on xor_sum. (no of that hash is the number of sub-array with xor_sum k ending at 'i').
            cnt += hash1[check];              // Will this way get's all the subarray??
        }
    }

    cout << cnt << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}
