/*迷路の最短路 幅優先探索 P37*/
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

const int MAX_N = 100, MAX_M = 100;
const int INF = 10000000;

typedef pair<int, int> P;

int N,M;
int sx, sy;
int gx, gy;
char maze[MAX_N][MAX_M+1];
int d[MAX_N][MAX_M];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int bfs(){
    queue<P> que;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++) d[i][j] = INF;
    
    que.push(P(sx,sy));
    d[sx][sy] = 0;

    while(que.size()){
        P p = que.front();
        que.pop();
        if(p.first == gx && p.second == gy) break;
        for(int i=0;i<4;i++){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if(0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '#' && d[nx][ny] == INF){
                que.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[gx][gy];
}

void solve(){
    int res = bfs();
    printf("%d",res);
}

int main(){
    scanf("%d",&N);
    scanf("%d",&M);
    REP(i,N) scanf("%s",maze[i]);
    REP(i,N){
        REP(j,M) {
            if(maze[i][j] == 'S'){
                sx = i;
                sy = j;
            } 
            if(maze[i][j] == 'G'){
                gx = i;
                gy = j;
            }
        }
    }
    solve();
}