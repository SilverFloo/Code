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
ll tab[(int)1e5+5];
int main(){
int n;
cin>>n;
ll sumL=0;
ll sumR=0;
FOR1(i,n){
char c;int x;
scanf(" %c%d",&c,&x);
if(c=='L')sumL+=x,tab[i]=x;
else sumR+=x,tab[i]=-x;
tab[i]+=tab[i-1];
}
ll mn=1e18,mx=0,al=1e18,ar=0;
ii l,r;
int tmpl=0,tmpr=0;
FOR1(i,n){
    if(al>tab[i]-mx||(al==tab[i]-mx&&l.s-l.f>i-tmpl)){
        al=tab[i]-mx;
        l.s=i;
        l.f=tmpl;
    }
    if(ar<tab[i]-mn||(ar==tab[i]-mn&&r.s-r.f>i-tmpr)){
        ar=tab[i]-mn;
        r.s=i;
        r.f=tmpr;
    }
    if(tab[i]<=mn){
        mn=tab[i];
        tmpr=i+1;
    }
    if(tab[i]>=mx){
        mx=tab[i];
        tmpl=i+1;
    }
}
sumL-=al;
sumR+=ar;
//printf("%lld %lld",sumR,sumL);
if(sumR>=sumL){
    printf("R %lld %d %d",sumR,r.f,r.s);
}
else{
    printf("L %lld %d %d",sumL,l.f,l.s);
}
}
