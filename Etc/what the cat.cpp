#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<(a);i++)
#define pi pair<int,int>
using namespace std;

int main(){
int k,m;
scanf("%d %d",&k,&m);
map<int,int> cat;
FOR(i,k){
int c=0;
FOR(j,m){int x;scanf("%1d",&x);c<<=1;c=c|x;}
cat[c]=i;
//printf("%d/",c);
}

int close=1<<(m-1);
close--;
int t;
scanf("%d",&t);
while(t--){
set<int> ans;
int l;
scanf("%d",&l);
int now=0;
for(int i=0;i<l;i++){
//printf("%d %d ",i,m);
//printf("%d-",close);
int x;
scanf("%1d",&x);
if(i>=m){now=now&(close);}
now<<=1;now=now|x;
if(i>=m-1){//printf("%d-",now);
if(cat.find(now)!=cat.end())ans.emplace(cat[now]);}
}
if(ans.size()==0)printf("OK");
for(auto i:ans)printf("%d ",i+1);
printf("\n");
}


}
