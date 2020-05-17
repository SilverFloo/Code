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
int a[(int)1e6+5], b[(int)1e6+5];
int main(){
    int la, lb;
    ll suma = 0, sumb = 0;
    cin>>la>>lb;
    int na = la, nb = lb;
    FOR(i, la) scanf("%d", &a[i]), suma+=a[i];
    FOR(i, lb) scanf("%d", &b[i]), sumb+=b[i];
    int cnt = 0;
    if(suma == sumb){printf("0"); return 0; }
    else if(suma > sumb){
         FOR(i, la){
            if((ll)a[i]*nb > sumb && (ll)a[i]*na < suma){
                nb++; na--;
                suma -= a[i];
                sumb += a[i];
                cnt++;
            }
         }
    }
    else{
        FOR(i, lb){
            if((ll)b[i]*na > suma && (ll)b[i]*nb < sumb){
                na++; nb--;
                sumb -= b[i];
                suma += b[i];
                cnt++;
            }
         }
    }
    printf("%d",cnt);

}
