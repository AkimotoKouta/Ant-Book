#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
typedef long long ll;
const int MAX_N = 10000;
int N, L[MAX_N];
void solve(){
    ll ans = 0;
    //priority_queueの定義が，型，コンテナの型，比較関数を入力としてるので
    //小さい数から出てくるようにするには以下のようになる．
    priority_queue<int, vector<int>, greater<int>> que;
    FOR(i,0,N){
        que.push(L[i]);
    }

    while(que.size()>1){
        int l1, l2;
        l1 = que.top();
        que.pop();
        l2 = que.top();
        que.pop();

        ans += l1 + l2;
        que.push(l1 + l2);
    }
    printf("%lld\n",ans);
}

int main(){
    solve();
}