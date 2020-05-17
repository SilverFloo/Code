#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<a;i++)
#define pb emplace_back
#define all(a) a.begin(),a.end()
using namespace std;
int can[(int)1e7+5];
int main(){

int n,m,t,l;
cin>>n>>m>>t>>l;

FOR(i,n){

int a;
scanf("%d",&a);
can[a+1]++;
}
FOR1(i,1e7+3){
can[i]+=can[i-1];
}
while(t--){

int rail[m];
FOR(i,m){
scanf("%d",&rail[i]);
rail[i]++;
}
sort(rail,rail+m);
int ans=0;
int s=rail[0],e=rail[0];
FOR1(i,m){
//printf("%d/",rail[i]-l-1);
if(rail[i]-l-1<=e+l)e=rail[i];
else{
s-=l+1;
e+=l;
if(s<0)s=0;
//if(e>1e7)e=1e7;printf(">%d %d\n",s,e);
ans+=can[e]-can[s];
s=rail[i];e=rail[i];
}

}
s-=l+1;
e+=l;
if(s<0)s=0;
if(e>1e7)e=1e7;
ans+=can[e]-can[s];
//printf(">%d %d<\n",s,e);

printf("%d\n",ans);

}

}
