#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<a;i++)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
using namespace std;
const int INF=1e9;
ii tab[100005];
long long ans=0;

vector<ii> merge(int l,int r){

if(l==r){
vector<ii> a;
a.pb(tab[l]);
return a;
}
vector<ii> a,b,c;
int m=(l+r)/2;
b=merge(l,m);
c=merge(m+1,r);
int sb=0,sc=0;
for(auto i:b){sb+=i.f;}
for(auto i:c){sc+=i.f;}
int ib=0,ic=0;
while(ib!=b.size()&&ic!=c.size()){
if(b[ib].s<=c[ic].s){
a.pb(b[ib]);
sb-=b[ib].f;
//ans+=(c.size()-ic)*b[ib].f+sc;
ib++;
}
else {
a.pb(c[ic]);
sc-=c[ic].f;
ans+=(b.size()-ib)*c[ic].f+sb;
ic++;
}
}
while(ib!=b.size()){
a.pb(b[ib]);ib++;
}

while(ic!=c.size()){
a.pb(c[ic]);ic++;
}//printf("%d %d ->%d\n",l,r,ans);
return a;
}

int main(){
    int n;
    cin>>n;
    FOR(i,n){
    int a,b;
    scanf("%d %d",&tab[i].f,&tab[i].s);
    }
    sort(tab,tab+n);
    merge(0,n-1);
    printf("%lld",ans);
}
/*
5
1 12
6 16
7 29
3 1
5 9
*/
