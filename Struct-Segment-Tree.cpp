/************************************************************
    Problem: https://oj.vnoi.info/problem/segtree_itez1
    Author: simp_nghan
*************************************************************/
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define endl '\n'
using namespace std;

const int MAX = 1e3;
const int MOD = 1e9 + 7;

class SegmentTree{
private:
    ll n;
    vector<ll>tree,lazy;
    void build(vector<ll>&a,ll node,ll l, ll r){
        if (l == r){
            tree[node] = a[l];
        }
        else{
            ll mid = l + (r - l)/2;
            build(a,2*node,l,mid);
            build(a,2*node+1,mid+1,r);
            tree[node] = max(tree[2*node],tree[2*node + 1]);
        }
    }
    void push(ll node,ll l, ll r){
        if (lazy[node] != 0){
            tree[node] += lazy[node];
            if (l != r){
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    void one_update(ll node, ll l, ll r, ll pos, ll val){
        if (l == r){
            tree[node] = val;
        }
        else{
            ll mid = l + (r - l)/2;
            if (pos <= mid){
                one_update(2*node,l,mid,pos,val);
            }
            else{
                one_update(2*node+1,mid+1,r,pos,val);
            }
            tree[node] = max(tree[2*node],tree[2*node + 1]);
        }
    }
    void update_range(ll node, ll l, ll r, ll ql, ll qr, ll val){
        push(node,l,r);
        if (l > qr || ql > r){
            return;
        }
        else if (l >= ql && r <= qr){
            lazy[node] += val;
            push(node,l,r);
            return;
        }
        else{
            ll mid = l + (r - l)/2;
            update_range(2*node,l,mid,ql,qr,val);
            update_range(2*node+1,mid+1,r,ql,qr,val);
            tree[node] = max(tree[2*node],tree[2*node+1]);
        }
    }
    ll one_query(ll node, ll l, ll r, ll ql, ll qr){
        if (ql > qr){
            return LLONG_MIN;
        }
        else if (ql == l && qr == r){
            return tree[node];
        }
        else{
            ll mid = l + (r - l)/2;
            ll s1 = one_query(2*node,l,mid,ql,min(qr,mid));
            ll s2 = one_query(2*node+1,mid+1,r,max(ql,mid + 1),qr);
            return max(s1,s2);
        }
    }
    ll query_range(ll node, ll l, ll r, ll ql, ll qr){
        push(node,l,r);
        if (l > qr || ql > r){
            return LLONG_MIN;
        }
        else if (l >= ql && r <= qr){
            return tree[node];
        }
        else{
            ll mid = l + (r - l)/2;
            ll s1 = query_range(2*node,l,mid,ql,qr);
            ll s2 = query_range(2*node+1,mid+1,r,ql,qr);
            return max(s1,s2);
        }
    }
public:
    SegmentTree(vector<ll>&a){
        n = a.size();
        tree.resize(4*n+1);
        lazy.resize(4*n+1);
        build(a,1,0,n-1);
    }
    void single_update(ll pos, ll val){
        one_update(1,0,n-1,pos,val);
    }
    void lazy_update(ll l, ll r, ll val){
        update_range(1,0,n-1,l,r,val);
    }
    ll single_query(ll l, ll r){
        return one_query(1,0,n-1,l,r);
    }
    ll lazy_query(ll l, ll r){
        return query_range(1,0,n-1,l,r);
    }
};

void nlpmai(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    for (ll i = 0; i < n; ++i){
        cin>>a[i];
    }
    SegmentTree st(a);
    ll q; cin>>q;
    for (ll i = 1; i <= q; ++i){
        ll k;
        cin>>k;
        if (k == 1){
            ll x,y;
            cin>>x>>y;
            x--;
            st.single_update(x,y);
        }
        else if (k == 2){
            ll x,y;
            cin>>x>>y;
            x--; y--;
            cout<<st.single_query(x,y)<<endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.inp","r",stdin);
    //freopen("input.out","w",stdout);
    ll testcase = 1; //cin>>testcase;
    for (ll test = 1; test <= testcase; ++test) nlpmai();
    return 0;
}

/*
     /\\
    (-.-)
    /> >\ <3 nlpmai
*/

