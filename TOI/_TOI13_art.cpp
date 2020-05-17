#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<a;i++)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
using namespace std;
const int MAXH=1e6+5;
const int MAXW=4e6+5;
int T[MAXH];
void update(int p,int v){
for(int i=p;i>=1;i-=i&-i){
T[i]+=v;
}
}
int query(int p){
int v=0;
for(i=p;i<MAXH;i+=i&-i){
v+=T[i];
}
return v;
}
vector<pair<int,int>> u[MAXW];
int uz[MAXW];
int main(){
int n,m;
cin>>n>>m;
FOR(i,n){
int a,b,c,d;
scanf("%d %d %d %d",&a,&b,&c,&d);
u[a].eb
}


}
