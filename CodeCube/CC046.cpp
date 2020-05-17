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
const int MAX=2e5+5;
int fenwick[MAX];
void update(int p,int v){
for(int i=p;i<MAX;i+=i&-i){
fenwick[i]+=v;
}
}
int query(int p){
int sum=0;
for(int i=p;i>0;i-=i&-i){
sum+=fenwick[i];
}
return sum;
}
int main(){
    int n,q;
    cin>>n>>q;
    map<int,int> idx;
    int x[q][3];
    FOR(i,q){
    scanf("%d",&x[i][0]);
    if(x[i][0]){
    scanf("%d %d",&x[i][1],&x[i][2]);
    idx[x[i][1]]=1;
    idx[x[i][2]]=1;
    }
    else {
    scanf("%d",&x[i][1]);
    idx[x[i][1]]=1;
    }
    }
    int i=1;
    for(auto &a:idx)a.s=i,i++;
    FOR(i,q){
    if(x[i][0]==1){
    update(idx[x[i][1]],1);
   // printf("<%d %d",x[i][1],idx[x[i][1]]);
    update(idx[x[i][2]]+1,-1);
    //printf("/%d %d>",x[i][2],idx[x[i][2]]+1);
    }
    else {
            //printf("%d",idx[x[i][1]]);
    int a=query(idx[x[i][1]]);
//printf("%d ",a);
    a%=6;
 //   printf("%d",a);
    if(a==0)printf("sleep\n");
    else if(a==1||a==3||a==5)printf("eat\n");
    else printf("work\n");
    }
    }
}
/*
5 6
1 1 5
0 1
0 2
0 3
0 4
0 5
*/
