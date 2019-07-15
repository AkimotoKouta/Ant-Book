#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
int n,limit_W;
const int MAX_N = 100;
int weight[MAX_N], value[MAX_N];

//i番目以降の品物から重さの総和がj以下となるように選ぶ
int rec(int i, int j){
    int res;
    if(i == n){
        res = 0;
    }else if(j < weight[i]){
        res = rec(i+1, j);
    }else{
        res = max(rec(i+1, j), rec(i+1, j-weight[i]) + value[i]);
    }
    return res;
}

void solve(){
    printf("%d\n", rec(0,limit_W));
}

int main(){
    scanf("%d",&n);
    FOR(i,0,n) scanf("%d %d",&weight[i],&value[i]);
    scanf("%d",&limit_W);
    solve();
}