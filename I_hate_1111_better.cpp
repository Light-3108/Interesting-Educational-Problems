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
    const int N = 2e5 + 5;
    const int M = 1000000007;
    int mod(ll x, ll n)
    {
        return (x % n + n) % n;
    }

    void solve()
    {
        ll x; cin>>x;

        ll b = x%11;
        ll ch = x/11; 

        if(ch - (10*b) >= 0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
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
