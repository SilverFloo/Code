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
vector<int> x[100000];
int main(){
    for(int i=1;i<=500;i++){
    clock_t a = clock();
    for(int j=0;j<100000;j++)x[i].pb(1);
    clock_t b = clock();
    printf("%d %f\n",i,double(b-a)/CLOCKS_PER_SEC);
    }
}
