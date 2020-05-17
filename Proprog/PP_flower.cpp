#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<(a);i++)
using namespace std;
const int MAX=1e6;

int par[MAX*2+10];
bool visit[MAX*2+10];
int root(int i){

while(par[par[i]]!=i){
par[i]=par[par[i]];
i=par[par[i]];
}return i;
}
void merge(int a,int b){
par[root(a)]=root(b);}

int main(){
int t=0;
scanf("%d",&t);
while(t--){
for(int i=0;i<MAX*2;i++){par[i]=i;visit[i]=0;}
int count=0;
int n;
scanf("%d",&n);
for(int i=0;i<n;i++){
int x,y;
scanf("%d %d",&x,&y);x--;y--;//printf("%d %d",visit[x],visit[y+MAX]);
if(visit[x]==0&&visit[MAX+y]==0){merge(x,MAX+y);count++;}
else if(visit[x]&&visit[y+MAX]){if(root(x)!=root(y+MAX)){merge(x,MAX+y);count--;}}
else if(visit[x]){merge(MAX+y,x);}
else merge(x,MAX+y);
visit[x]=1;visit[y+MAX]=1;//printf(" %d\n",count);
}
printf("%d\n",(count+1)/2);
}
}
/*
1
10
1 10
2 10
5 6
3 7
4 5
5 4
6 9
9 6
1 3
5 5
*/
