//P35
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
int N,M;
const int MAX_N = 100, MAX_M = 100;
char field[MAX_N][MAX_M+1];

void dfs(int x, int y){
    field[x][y] = '.';

    FOR(dx,-1,2){
        FOR(dy,-1,2){
            int nx = x + dx, ny = y + dy;
            if(0<=nx && nx<N && 0<=ny && ny<M && field[nx][ny]=='W'){
                dfs(nx, ny);
            }
        }
    }
    return;
}

void solve(){
    int res = 0;
    REP(i,N){
        REP(j,M){
            if(field[i][j] == 'W'){
                dfs(i, j);
                res++;
            }
        }
    }
    printf("%d\n", res);
}
int main(){
    scanf("%d",&N);
    scanf("%d",&M);
    REP(i,N) scanf("%s",field[i]);
    solve();
}