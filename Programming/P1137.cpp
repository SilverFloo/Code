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
const int INF=1e9+5;
ll tab[1000005];
int main(){
    int n;

    cin>>n;
    FOR(i,n){
    scanf("%lld",&tab[i]);
    }
    if(n==1)printf("%lld",tab[0]);
    else if(n==2)printf("%lld",tab[1]);
    else {
            int b=n-1;
    ll sum=0;
    int i;
        for(i=n-1;i>2;i-=2){
            sum+=min(tab[0]+2*tab[1]+tab[i],2*tab[0]+tab[i]+tab[i-1]);
           // printf("%lld ",sum);
        }
        if(i==1)sum+=tab[1];
        else if(i==2)sum+=tab[0]+tab[1]+tab[2];
    printf("%lld",sum);
    }
}

