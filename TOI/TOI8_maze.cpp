#include<bits/stdc++.h>
using namespace std;
const int MAX=200;
int tab[MAX][MAX];
bool visit[MAX][MAX];
bool visit2[MAX][MAX];
queue<int> qi,qj,ql;
void push(int a,int b,int c){
qi.push(a);
qj.push(b);
ql.push(c);
}
int main(){
int n,m;
int si,sj,ei,ej;
scanf("%d %d",&n,&m);
scanf("%d %d %d %d",&si,&sj,&ei,&ej);si--;sj--;ei--;ej--;

for(int i=0;i<n;i++){
for(int j=0;j<m;j++)scanf("%d",&tab[i][j]);
}
int ans=2e9;
push(si,sj,1);
visit[si][sj]=1;
while(!qi.empty()){

int i=qi.front();
int j=qj.front();
int l=ql.front();
qi.pop();
qj.pop();
ql.pop();


if(i==ei&&j==ej){ans=min(ans,l);}
if(i>0)if(!visit[i-1][j]){
if(tab[i-1][j]==1){push(i-1,j,l+1);visit[i-1][j]=1;}
if(tab[i-1][j]==0)tab[i-1][j]=l+1;
}

if(i<n-1)if(!visit[i+1][j]){
if(tab[i+1][j]==1){push(i+1,j,l+1);visit[i+1][j]=1;}
if(tab[i+1][j]==0)tab[i+1][j]=l+1;
}

if(j>0)if(!visit[i][j-1]){
if(tab[i][j-1]==1){push(i,j-1,l+1);visit[i][j-1]=1;}
if(tab[i][j-1]==0)tab[i][j-1]=l+1;
}

if(j<m-1)if(!visit[i][j+1]){
if(tab[i][j+1]==1){push(i,j+1,l+1);visit[i][j+1]=1;}
if(tab[i][j+1]==0)tab[i][j+1]=l+1;
}

}

if(ans!=2e9){printf("0 %d",ans);exit(0);}

int count =0;
push(ei,ej,1);
visit2[ei][ej]=1;
while(!qi.empty()){

int i=qi.front();
int j=qj.front();
int l=ql.front();
qi.pop();
qj.pop();
ql.pop();

if(tab[i][j]>1){count++;ans=min(ans,tab[i][j]+l-1);continue;}








if(i>0)if(!visit2[i-1][j]){
if(tab[i-1][j]>=1){push(i-1,j,l+1);visit2[i-1][j]=1;}

}

if(i<n-1)if(!visit2[i+1][j]){
if(tab[i+1][j]>=1){push(i+1,j,l+1);visit2[i+1][j]=1;}

}

if(j>0)if(!visit2[i][j-1]){
if(tab[i][j-1]>=1){push(i,j-1,l+1);visit2[i][j-1]=1;}

}

if(j<m-1)if(!visit2[i][j+1]){
if(tab[i][j+1]>=1){push(i,j+1,l+1);visit2[i][j+1]=1;}

}

}

printf("%d\n%d",count,ans);

}
