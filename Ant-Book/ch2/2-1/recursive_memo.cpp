#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 10^6;

int n,memo[MAX_N];

int fib(int n){
    if(n<=1) return n;
    if(memo[n]!=0) return memo[n];
    return memo[n] = fib(n - 1) + fib(n - 2);
}

int main(){
    scanf("%d",&n);
    int ans = fib(n);
    printf("%d",ans);
}
