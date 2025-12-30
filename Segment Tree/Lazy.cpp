/*
        problem: https://oj.vnoi.info/problem/segtree_itlazy
        author: s1mp3ra
*/
//⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣾⢿⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣛⣫⣿⡿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣴⡶⠞⠛⠛⠛⠛⠛⠛⠓⠶⣶⣤⣀⣼⣿⣿⣿⣷⣽⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⡟⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⡇⢩⡿⢹⡿⠿⠋⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⢠⣤⣤⣶⣶⣶⣶⣶⣶⣶⣶⣾⣧⣼⢣⣿⣀⣴⡾⠟⠛⠿⢶⣦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣤⡀⠈⠀⠙⠻⢶⣤⣄⣀⣀⠀⢠⣶⣿⡟⣼⡟⠛⠛⠛⠷⣦⣄⡀⠀⠉⠛⠿⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠛⢷⣦⣤⣤⣤⣬⣭⣽⣟⣛⣛⣿⡟⣿⣾⣿⣀⠀⠀⠀⠈⠙⠻⢦⣄⡀⠀⠈⠙⢷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⡶⠞⠛⠋⠉⠉⠉⠀⠀⠉⠉⠉⠙⣿⣶⠿⠻⠿⢿⣿⣶⣶⣤⣤⣤⣤⣽⣿⣦⡀⠀⠀⠙⣷⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⡿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠁⠀⠀⠀⠀⠀⠉⠉⠛⠷⣦⣌⡉⠁⠈⠻⠀⠀⠀⠈⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⢀⡀⠀⠀⠀⠀⠀⠀⠀⣀⣠⡾⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣷⡶⠶⢶⡶⠶⠾⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⢻⡛⠛⠿⠿⠿⠿⠛⠛⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠸⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣶⣾⣶⣶⡶⠶⢶⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠻⣷⣄⠀⠀⠀⠀⠀⠀⢀⣴⡿⣋⣭⣷⠶⠶⠶⢶⣤⣸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⠟⠋⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⠹⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⠈⢙⣿⠆⠀⠀⠀⢰⣿⢯⣾⣿⣧⣄⠀⠀⠀⠀⠈⠻⣧⡀⠀⠀⠀⠀⠀⠀⠀⣠⣾⢿⣿⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⡀⠀⠀⠀⠘⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⣰⡿⠃⠀⠀⠀⣴⡟⢁⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠸⣷⠀⠀⠀⠀⠀⢀⣴⠟⠁⠈⣿⣀⣀⠀⠀⠀⠀⠀⢀⣼⣿⣷⣀⠀⠀⠀⠘⣷⡄⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⣴⡟⠀⠀⠀⢠⣾⠋⠀⢸⣿⣿⣿⣿⡿⠃⠀⠀⠀⠀⠀⠀⢹⡆⠀⠀⠀⣠⡿⠁⣠⣶⠿⠛⠛⠛⠛⠷⣦⡀⣠⣿⣿⠅⢙⣿⣦⣤⣀⡀⠹⣷⣄⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⣸⡟⠀⠀⠀⢠⡿⠃⠀⠀⠘⣷⡈⠉⠉⠀⠀⠀⠀⠀⠀⠀⢠⣿⡆⠀⠀⢰⡿⠁⣼⣯⣥⣤⣄⠀⠀⠀⠀⠈⢿⣿⣿⣅⡀⠀⢀⣿⡿⠛⠁⠀⠀⠙⢷⣦⣀⠀⠀⠀⠀
//⠀⢠⡿⠀⠀⢀⣠⡾⠁⠀⠀⠀⠀⠘⢿⣦⡀⠀⠀⠀⠀⠀⣀⣴⠟⠉⣿⡄⠀⣿⠀⢸⣿⣿⣿⣿⣿⡧⠀⠀⠀⠀⠘⣿⠉⠻⣿⣿⣿⡟⠀⠀⠀⠀⠀⠀⠀⠊⢻⣷⠀⠀⠀
//⠀⣿⠇⠀⠀⠏⣀⡀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠷⠶⠶⠶⠟⠋⠁⠀⠀⠈⠻⣶⣏⠀⢸⡟⢿⣿⡿⠟⠁⠀⠀⠀⠀⠀⣿⣆⠀⠈⢿⡟⠀⠀⠀⠀⠀⢠⣀⣠⣶⠟⠁⠀⠀⠀
//⢀⣿⠀⠀⠀⢰⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢾⣆⠀⠀⠀⠀⠀⠀⠈⠛⠂⠘⢿⣄⠀⠀⠀⠀⠀⠀⠀⠀⣼⡟⣿⡆⠀⠘⠃⠀⠀⢠⡄⠀⠘⣿⡉⠀⠀⠀⠀⠀⠀
//⠸⣿⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣿⣷⣶⣶⣾⣷⣄⣀⠀⣀⣤⠈⠛⢷⣤⣄⣀⣀⣠⣴⠾⢿⣄⣹⡇⠀⠀⠀⠀⠀⠸⣿⠀⠀⠙⢷⣤⡀⠀⠀⠀⠀
//⠀⣿⡀⠀⠀⠘⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣿⠟⠛⠋⠉⠉⠉⠉⠙⠛⠻⣿⠉⠀⠀⠀⠈⠉⠉⠉⠉⠁⠀⠈⠻⣿⡧⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠉⠛⠷⣶⣤⡀
//⠀⠹⣷⡀⢀⡀⠙⢷⣄⠀⠀⠀⠀⠀⠀⠀⠀⣰⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢼⡟⠀⠀⠀⠀⠀⠀⠀⢹⠀⠀⠀⠀⠀⠀⠀⣠⡾⠁
//⠀⠀⠙⢷⣿⣷⡀⠀⠙⢿⣦⣄⡀⠀⠀⠀⠀⣿⣁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡿⠇⠀⠀⠀⠀⠀⠀⢸⡀⠀⠀⠀⠀⠀⣾⠛⠀⠀
//⠀⠀⠀⠀⠙⠛⠿⣦⣄⣸⣧⣿⣿⣷⣤⣄⡀⠀⠈⠛⠦⢤⣀⡀⠀⠀⠀⠀⠀⣰⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⡟⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⣀⠀⠀⠀⠀⣿⠀⠀⠀
//⠀⠀⠀⠀⠀⠀⠀⠈⠙⠛⠿⢿⣿⣯⣋⢻⣿⢷⣶⣤⣄⣀⠈⠉⠙⠒⠒⠒⠺⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⢏⡄⠀⠀⠀⠀⠀⠀⠀⠀⣿⢀⣿⣦⡀⠀⢠⣿⠀⠀⠀
//⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡾⣿⠟⠛⠿⢷⣶⣿⣿⡟⣿⣿⣷⣶⣦⣤⣤⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⣯⡿⠃⠀⠀⠀⠀⠀⠀⠀⢸⣿⣾⡟⣿⡇⢀⣼⠇⠀⠀⠀
//⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⠏⢰⡟⢺⣶⣾⠿⠿⢛⢽⣵⣿⢿⣿⠀⢩⣿⣿⣿⣿⣿⠿⢷⣶⣶⣶⣶⣶⣶⣿⠟⠋⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⣿⣾⣿⣷⠿⠃⠀⠀⠀⠀
//⠀⠀⠀⠀⢀⣀⡀⣠⡿⠁⠀⣿⠁⠈⠻⢿⣿⣧⣾⠿⠟⣁⣾⡏⠀⢈⣿⡇⠉⠛⠿⣿⡿⠿⠿⠻⣿⣟⠉⠀⠀⠀⠀⠀⣀⡀⠀⠀⠀⣰⡿⠿⠛⣋⣀⣽⣵⣾⣿⣿⡇⠀⠀
//⠀⠀⠀⠀⣿⠙⢿⣿⣤⣤⣼⡏⠀⠀⠀⠀⠀⠀⢀⠀⣼⣿⣿⠀⢠⣿⣟⠻⣾⣛⣛⠻⢿⣷⣤⣄⣀⡙⠻⠷⠶⠶⠿⣻⡟⠁⠀⣠⣾⣿⣿⣿⣿⣿⣟⣋⣡⣠⣄⣿⡇⠀⠀

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

struct SegTree{
        ll n;
        vector<ll>tree, lazy;
        SegTree(ll n) : n(n){
                tree.assign(4 * n + 1, -INF);
                lazy.assign(4 * n + 1, 0);
        }
        void push(ll node){
                if (lazy[node] != 0){
                        ll val = lazy[node];
                        lazy[node * 2] += val;
                        lazy[node * 2 + 1] += val;
                        tree[node * 2] += val;
                        tree[node * 2 + 1] += val;
                        lazy[node] = 0;
                }
        }
        void build(vector<ll>&a, ll node, ll l, ll r){
                if (l == r){
                        tree[node] = a[l];
                        return;
                }
                ll mid = (l + r) >> 1;
                build(a, 2 * node, l, mid);
                build(a, 2 * node + 1, mid + 1, r);
                tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
        void update(ll node, ll l, ll r, ll ql, ll qr, ll val){
                if (qr < l || r < ql){
                        return;
                }
                if (ql <= l && r <= qr){
                        tree[node] += val;
                        lazy[node] += val;
                        return;
                }
                push(node);
                ll mid = (l + r) >> 1;
                update(2 * node, l, mid, ql, qr, val);
                update(2 * node + 1, mid + 1, r, ql, qr, val);
                tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
        ll query(ll node, ll l, ll r, ll ql, ll qr){
                if (qr < l || r < ql){
                        return -INF;
                }
                else if (ql <= l && r <= qr){
                        return tree[node];
                }
                push(node);
                ll mid = (l + r) >> 1;
                return max(query(2 * node, l, mid, ql, qr), query(2 * node + 1, mid + 1, r, ql, qr));
        }
        void setup(vector<ll>&a){
                build(a, 1, 1, n);
        }
        void upd(ll l, ll r, ll val){
                update(1, 1, n, l, r, val);
        }
        ll get(ll l, ll r){
                return query(1, 1, n, l, r);
        }
};

void solve(){
        ll n;
        cin >> n;
        vector<ll>a(n + 1, 0);
        for (ll i = 1; i <= n; ++i){
                cin >> a[i];
        }
        SegTree st(n);
        st.setup(a);
        ll q;
        cin >> q;
        for (ll i = 1; i <= q; ++i){
                ll x;
                cin >> x;
                if (x == 1){
                        ll l, r, val;
                        cin >> l >> r >> val;
                        st.upd(l, r, val);
                }
                else{
                        ll l, r;
                        cin >> l >> r;
                        cout << st.get(l, r) << endl;
                }
        }
}

int main(){
        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        if (fopen(taskname".INP", "r")){
                freopen(taskname".INP", "r", stdin);
                freopen(taskname".OUT", "w", stdout);
        }
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
        /> \> <3 signed by s1mp3ra
*/
