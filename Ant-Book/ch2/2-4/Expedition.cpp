#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

int L,P,N;
const int MAX_N = 10000;
int A[MAX_N+1], B[MAX_N+1];
void solve(){
    A[N] = L;
    B[N] = 0;
    N++;

    priority_queue<int> que;
    int ans = 0, pos = 0, tank = P;

    FOR(i,0,N){
        int distance = A[i] - pos;

        while(tank - distance < 0){
            if(que.empty()){
                puts("-1");
                return;
            }
            tank += que.top();
            que.pop();
            ans++;
        }

        tank -= distance;
        pos = A[i];
        que.push(B[i]);
    }
    printf("%d\n",ans);
}

int main(){
    scanf("%d",&N);
    scanf("%d",&L);
    scanf("%d",&P);
    FOR(i,0,N) scanf("%d",&A[i]);
    FOR(i,0,N) scanf("%d",&B[i]);
    solve();
}