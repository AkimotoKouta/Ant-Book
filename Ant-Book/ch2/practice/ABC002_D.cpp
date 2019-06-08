#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

const int MAX_N = 12;
const int MAX_M = 66;
int N, M;
bool relation[MAX_N][MAX_N];

int dfs(vector<int> member, int depth){
    if(depth==N){
        bool nakayosi = true;
        REP(i,member.size()){
            FOR(j,i+1,member.size()){
                nakayosi = nakayosi && relation[member[i]-1][member[j]-1];
            }
        }
        if(nakayosi){
            return member.size();
        }else{
            return 0;
        }
    }
    vector<int> next_member(member);
    next_member.push_back(depth+1);
    return max(dfs(member,depth+1),dfs(next_member,depth+1));
}

void solve(){
    vector<int> member;
    int ans = dfs(member,0);
    printf("%d\n",ans);
}

int main(){
    scanf("%d",&N);
    scanf("%d",&M);
    REP(i,M){
        int x, y;
        scanf("%d %d",&x,&y);
        relation[x-1][y-1] = true;
    }
    solve();
}