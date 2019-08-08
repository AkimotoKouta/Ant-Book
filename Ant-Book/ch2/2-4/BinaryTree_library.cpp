#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

int main(){
    set<int> s;

    s.insert(1);
    s.insert(3);
    s.insert(5);

    set<int>::iterator ite;

    ite = s.find(1);
    if(ite == s.end()) puts("not found");
    else puts("found");

    ite = s.find(2);
    if(ite == s.end()) puts("not found");
    else puts("found");

    s.erase(3);

    if (s.count(3) != 0) puts("found");
    else puts("not found");

    for (ite = s.begin(); ite != s.end(); ++ite){
        printf("%d\n", *ite);
    }

    map<int, const char*> m;

    m.insert(make_pair(1, "ONE"));
    m.insert(make_pair(10,"TEN"));
    m[100] = "HUNDRED";

    map<int, const char*>::iterator mite;
    mite = m.find(1);
    puts(mite->second);

    mite = m.find(2);
    if(mite == m.end()) puts("not found");
    else puts(mite->second);

    puts(m[10]);

    m.erase(10);

    for(mite = m.begin(); mite != m.end(); ++mite){
        printf("%d: %s\n", mite->first, mite->second);
    }
    return 0;
}