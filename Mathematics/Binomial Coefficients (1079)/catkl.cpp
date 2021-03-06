#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = 1000000007; // faster if const

ll modpow(ll b, ll e) {
    ll ans = 1;
    for (; e; b = b * b % mod, e /= 2)
        if (e & 1) ans = ans * b % mod;
    return ans;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    constexpr int N=1e6+1;
    vector<ll> f(N), invf(N);
    
    const ll LIM = N;
    ll* inv = new ll[LIM] - 1; inv[1] = 1;
    rep(i,2,LIM) inv[i] = mod - (mod / i) * inv[mod % i] % mod;
    
    f[0]=invf[0]=1;
    rep(i, 1, N) f[i]=f[i-1]*i%mod;
    rep(i, 1, N) invf[i]=invf[i-1]*inv[i]%mod;
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << f[a]*invf[b]%mod*invf[a-b]%mod << '\n';
    }
    return 0;
}
