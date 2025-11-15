#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define taskname "temp"
#define getbit(x, y) ((x) >> (y) & 1)
#define mod(x, k) ((((x) % (k)) + (k)) % (k))
#define compress(x) (x).pb(-INF); sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end());
using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int MAX = 2e7;

bitset<MAX + 1>snt;
unordered_map<ll, bool>cache;

void sieve(){
        snt.set();
        snt[0] = 0;
        snt[1] = 0;
        for (ll i = 2; i * i <= MAX; ++i){
                if (snt[i]){
                        for (ll j = i * i; j <= MAX; j += i){
                                snt[j] = 0;
                        }
                }
        }
}

ll mul_mod(ll a, ll b, ll m){
        ll res = 0;
        a = mod(a, m);
        while (b){
                if (b & 1){
                        res = res + a;
                        res = mod(res, m);
                }
                a = a * 2;
                a = mod(a, m);
                b >>= 1;
        }
        return res;
}

ll pow_mod(ll a, ll b, ll m){
        ll res = 1;
        a = mod(a, m);
        while (b){
                if (b & 1){
                        res = mul_mod(res, a, m);
                }
                a = mul_mod(a, a, m);
                b >>= 1;
        }
        return res;
}

bool miller_check(ll n, ll a, ll d, ll s){
        if (n % a == 0){
                return false;
        }
        ll x = pow_mod(a, d, n);
        if (x == 1 || x == n - 1){
                return true;
        }
        for (ll i = 1; i < s; ++i){
                x = mul_mod(x, x, n);
                if (x == n - 1){
                        return true;
                }
        }
        return false;
}

bool rabin_miller(ll n){
        if (n < 2){
                return false;
        }
        for (ll p : {2, 3, 5, 7, 11, 13, 17}){
                if (n == p){
                        return true;
                }
                if (n % p == 0){
                        return false;
                }
        }
        ll s = 0, d = n - 1;
        while ((d & 1) == 0){
                d >>= 1;
                s++;
        }
        for (ll a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}){
                if (!miller_check(n, mod(a, n), d, s)){
                        return false;
                }
        }
        return true;
}

bool prime(ll n){
        if (n <= MAX){
                return snt[n];
        }
        return rabin_miller(n);
}

bool check(ll n){
        while (n > 0){
                if (!prime(n)){
                        return false;
                }
                n /= 10;
        }
        return true;
}

void solve(){
        ll n;
        cin >> n;
        cout << (check(n) ? "PHAI" : "KHONG");
}

int main(){
        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        if (fopen(taskname".INP", "r")){
                freopen(taskname".INP", "r", stdin);
                freopen(taskname".OUT", "w", stdout);
        }
        sieve();
        ll testcase = 1;
        //cin >> testcase;
        for (ll test = 1; test <= testcase; ++test){
                solve();
        }
        return 0;
}

/*
        INPUT:

*/

/*
         /\\
        (-.-)
        /> \> <3 signed by s1mpu
*/

