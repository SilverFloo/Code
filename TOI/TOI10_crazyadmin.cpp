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
int p[105];
int main(){
int n,m;
int mx=0;
cin>>n>>m;
FOR(i,m){scanf("%d",&p[i]);if(p[i]>mx)mx=p[i];}
for(int i=mx;i<150000;i++){
int maxx=0;
int data=0;
int line=0;
int ch=1;
FOR(j,m){
if(data+p[j]>i){maxx=max(maxx,data);data=p[j];line++;}
else data+=p[j];
if(line>n){ch=0;break;}
}
maxx=max(maxx,data);line++;
if(line<=n)if(ch){printf("%d",i);break;}
}

}


