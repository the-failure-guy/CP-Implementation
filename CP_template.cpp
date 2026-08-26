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
#define imissher(hnuyqnuax)     if (fopen(hnuyqnuax".INP", "r")) {freopen(hnuyqnuax".INP", "r", stdin); freopen(hnuyqnuax".OUT", "w", stdout);}

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

template <class T> bool maximize(T &a, const T &b){
        return (a < b ? (a = b, true) : false);
}

template <class T> bool minimize(T &a, const T &b){
        return (a > b ? (a = b, true) : false);
}

void anhlamgixungdangvoiem(){

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

