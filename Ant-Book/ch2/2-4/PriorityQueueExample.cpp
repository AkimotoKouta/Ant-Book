#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

//大きい順から出る．
int main(){
    priority_queue<int> pque;

    pque.push(5);
    pque.push(2);
    pque.push(4);
    while(!pque.empty()){
        printf("%d\n",pque.top());
        pque.pop();
    }
 }