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
ii tab[100005];
int main(){
    int n;
    cin>>n;
    FOR(i,n){scanf("%d %d",&tab[i].s,&tab[i].f);}
    sort(tab,tab+n);
    ll a,b;
    double mx=0;
    ll sum=0;
    FOR(i,n){

        sum+=(ll)tab[i].s;
//printf("%d %d->",tab[i].f,sum);
        if((double)sum/tab[i].f>mx){
        mx=(double)sum/tab[i].f;
        a=(ll)tab[i].f;
        b=(ll)sum;
        }
    }
    printf("%lld %lld",b,a);
}
