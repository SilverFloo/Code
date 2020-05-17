#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<(a);i++)
using namespace std;
long long mi=2e9;
long long ans=2e9;
int n;
int p;
const int MAX = 123460;
long long tab[MAX];
void find(int s,int l,int r){

if(l==r){
long long cc=tab[s];
long long aa=tab[p]-tab[s];
long long bb=tab[n]-tab[p];
//printf("%d %d/%d %d %d\n",s,p,cc,aa,bb);
long long x1=max(max(aa,bb),cc);
long long x2=min(min(aa,bb),cc);
ans=min(ans,x1-x2);return ;
}
int m=(l+r)/2;
//printf("%d %d %d--",l,r,m);
long long aa=tab[m]-tab[s];
long long bb=tab[n]-tab[m];
//printf("%d",m);
if(abs(aa-bb)<mi){
mi=abs(aa-bb);
p=m;
}
if(aa>=bb){find(s,l,m);}
else find(s,m+1,r);
}
int main(){

scanf("%d",&n);
tab[0]=0;
FOR(i,n){scanf("%d",&tab[i+1]);tab[i+1]+=tab[i];}

for(int i=1;i<n-1;i++){
mi=2e9;
find(i,i,n);
}

printf("%lld",ans);

}/*
10
9 8 7 1 2 5 4 6 3 1
*/
