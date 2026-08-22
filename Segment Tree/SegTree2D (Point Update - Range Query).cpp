#include <bits/stdc++.h>
#define ll                      long long
#define ull                     unsigned long long
#define fi                      first
#define se                      second
#define pb                      push_back
#define endl                    '\n'

#define getbit(x, k)            ((x) >> (k) & 1)
#define onbit(x, k)             ((x) | (1 << (k)))
#define offbit(x, k)            ((x) & ~(1 << (k)))
#define mod(x, k)               ((((x) % (k)) + (k)) % (k))
#define compress(x)             sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end());
#define debug(x)                cerr << #x <<  " = " << x << endl;

#define fastio                  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define imissher(hnuyqnuax)     if (fopen("test.INP", "r")) {freopen("test.INP", "r", stdin);} else if (fopen(hnuyqnuax".INP", "r")) {freopen(hnuyqnuax".INP", "r", stdin); freopen(hnuyqnuax".OUT", "w", stdout);}

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

template <class T> bool maximize(T &a, const T &b){
        return (a < b ? (a = b, true) : false);
}

template <class T> bool minimize(T &a, const T &b){
        return (a > b ? (a = b, true) : false);
}

struct SegTree2D{
        ll n, m;
        vector<vector<ll>>tree;

        SegTree2D(ll _n, ll _m){
                n = _n, m = _m;
                tree.assign(4 * n + 1, vector<ll>(4 * m + 1, 0));
        }

        // --- BUILD ---

        void buildY(vector<vector<ll>>&a, ll nodeX, ll lX, ll rX, ll nodeY, ll lY, ll rY){
                if (lY == rY){
                        if (lX == rX){
                                tree[nodeX][nodeY] = a[lX][lY];
                        }
                        else{
                                tree[nodeX][nodeY] = tree[nodeX << 1LL][nodeY] + tree[(nodeX << 1LL) | 1LL][nodeY];
                        }
                        return;
                }
                else{
                        ll midY = (lY + rY) >> 1LL;
                        buildY(a, nodeX, lX, rX, nodeY << 1LL, lY, midY);
                        buildY(a, nodeX, lX, rX, (nodeY << 1LL) | 1LL, midY + 1, rY);
                        tree[nodeX][nodeY] = tree[nodeX][nodeY << 1LL] + tree[nodeX][(nodeY << 1LL) | 1LL];
                }
        }

        void buildX(vector<vector<ll>>&a, ll nodeX, ll lX, ll rX){
                if (lX != rX){
                        ll midX = (lX + rX) >> 1LL;
                        buildX(a, nodeX << 1LL, lX, midX);
                        buildX(a, (nodeX << 1LL) | 1LL, midX + 1, rX);
                }
                buildY(a, nodeX, lX, rX, 1, 1, m);
        }

        void setup(vector<vector<ll>>&a){
                buildX(a, 1, 1, n);
        }

        // -- UPDATE --

        void updateY(ll nodeX, ll lX, ll rX, ll nodeY, ll lY, ll rY, ll x, ll y, ll val){
                if (lY == rY){
                        if (lX == rX){
                                tree[nodeX][nodeY] = val;
                        }
                        else{
                                tree[nodeX][nodeY] = tree[nodeX << 1LL][nodeY] + tree[(nodeX << 1LL) | 1LL][nodeY];
                        }
                        return;
                }
                else{
                        ll midY = (lY + rY) >> 1LL;
                        if (y <= midY){
                                updateY(nodeX, lX, rX, nodeY << 1LL, lY, midY, x, y, val);
                        }
                        else{
                                updateY(nodeX, lX, rX, (nodeY << 1LL) | 1LL, midY + 1, rY, x, y, val);
                        }
                        tree[nodeX][nodeY] = tree[nodeX][nodeY << 1LL] + tree[nodeX][(nodeY << 1LL) | 1LL];
                }
        }

        void updateX(ll nodeX, ll lX, ll rX, ll x, ll y, ll val){
                if (lX != rX){
                        ll midX = (lX + rX) >> 1LL;
                        if (x <= midX){
                                updateX(nodeX << 1LL, lX, midX, x, y, val);
                        }
                        else{
                                updateX((nodeX << 1LL) | 1LL, midX + 1 , rX, x, y, val);
                        }
                }
                updateY(nodeX, lX, rX, 1, 1, m, x, y, val);
        }

        void upd(ll x, ll y, ll val){
                updateX(1, 1, n, x, y, val);
        }

        // --- QUERY ---

        ll queryY(ll nodeX, ll lX, ll rX, ll nodeY, ll lY, ll rY, ll qxA, ll qyA, ll qxB, ll qyB){
                if (lY > qyB || qyA > rY){
                        return 0;
                }
                else if (qyA <= lY && rY <= qyB){
                        return tree[nodeX][nodeY];
                }
                else{
                        ll midY = (lY + rY) >> 1LL;
                        return queryY(nodeX, lX, rX, nodeY << 1LL, lY, midY, qxA, qyA, qxB, qyB) + queryY(nodeX, lX, rX, (nodeY << 1LL) | 1LL, midY + 1, rY, qxA, qyA, qxB, qyB);
                }
        }

        ll queryX(ll nodeX, ll lX, ll rX, ll qxA, ll qyA, ll qxB, ll qyB){
                if (lX > qxB || qxA > rX){
                        return 0;
                }
                else if (qxA <= lX && rX <= qxB){
                        return queryY(nodeX, lX, rX, 1, 1, m, qxA, qyA, qxB, qyB);
                }
                else{
                        ll midX = (lX + rX) >> 1LL;
                        return queryX(nodeX << 1LL, lX, midX, qxA, qyA, qxB, qyB) + queryX((nodeX << 1LL) | 1LL, midX + 1, rX, qxA, qyA, qxB, qyB);
                }
        }

        ll get(ll xA, ll yA, ll xB, ll yB){
                return queryX(1, 1, n, xA, yA, xB, yB);
        }
};

void anhlamgixungdangvoiem(){
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>>matrix(n + 1, vector<ll>(m + 1, 0));
        for (ll i = 1; i <= n; ++i){
                for (ll j = 1; j <= m; ++j){
                        cin >> matrix[i][j];
                }
        }
        SegTree2D st(n, m);
        st.setup(matrix);
        ll q;
        cin >> q;
        for (ll i = 1; i <= q; ++i){
                ll type;
                cin >> type;
                if (type == 1){
                        ll x, y, val;
                        cin >> x >> y >> val;
                        st.upd(x, y, val);
                }
                else if (type == 2){
                        ll xA, yA, xB, yB;
                        cin >> xA >> yA >> xB >> yB;
                        cout << st.get(xA, yA, xB, yB) << endl;
                }
        }
}

int main(){
        fastio;
        imissher("temp");
        ll testcase = 1;
        //cin >> testcase;
        for (ll test = 1; test <= testcase; ++test){
                anhlamgixungdangvoiem();
        }
        return 0;
}

/*
         /\\
        (-.-)   Xin gửi đến người tôi thương, thầm thương thầm nhớ nay còn vấn vương
        />  \>  Híu hắt gió bên sông, đứng trông người xưa chưa lần hồi âm...
*/
