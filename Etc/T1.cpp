#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
#define ll long long
using namespace std;
const int INF=1e9;
int main(){
    int x[250];
    FOR1(i,250)x[250-i]=i;
    sort(x+150,x+250);
    sort(x+0,x+200);
    sort(x+150,x+250);
    printf("%d,",is_sorted(x,x+250));
    FOR(i,250)printf("%d ",x[i]);
}
