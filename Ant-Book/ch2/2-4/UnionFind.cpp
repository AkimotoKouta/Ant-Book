#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

const int MAX_N = 50000;

int par[MAX_N], rankuf[MAX_N];

void init(int n){
    FOR(i, 0, n){
        rankuf[i] = 0;
        par[i] = i;
    }
}

int find(int x){
    if(par[x] == x) {
        return x;
    }else{
        return par[x] = find(par[x]);
    }
}

void unite(int x, int y){
    x = find(x);
    y = find(y);
    if (x==y) return;

    if(rankuf[x] < rankuf[y]){
        par[x] = y;
    }else{
        par[y] = x;
        if(rankuf[x] == rankuf[y]) rankuf[x]++;
    }
}

bool same(int x, int y){
    return find(x) == find(y);
}

const int MAX_K = 100000;
int N, K;
int T[MAX_N], X[MAX_K], Y[MAX_K];

void solve(){
    init (N*3);
    int ans = 0;
    FOR(i, 0, K){
        int t = T[i];
        int x = X[i] - 1, y = Y[i] - 1;

        if(x < 0 || N <= x || y < 0 || N <= y){
            ans++;
            continue;
        }

        if (t==1){
            if(same(x, y+N) || same(x, y + 2 * N)){
                ans++;
            }else{
                unite(x, y);
                unite(x + N, y + N);
                unite(x + N * 2, y + N * 2);
            }
        }else{
            if(same(x, y) || same(x, y + 2 * N)){
                ans++;
            }else{
                unite(x, y + N);
                unite(x + N, y + N * 2);
                unite(x + N * 2, y);
            }
        }
    }
    printf("%d\n",ans);
}

int main(){
    scanf("%d",&N);
    scanf("%d",&K);
    FOR(i, 0 ,K){
        scanf("%d %d %d",&T[i],&X[i],&Y[i]);
    }
    solve();
}