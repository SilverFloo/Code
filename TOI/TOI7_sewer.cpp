#include<bits/stdc++.h>
#define p push
using namespace std;
bool visit[105][105];
int main(){
int n,m;

cin>>n>>m;char tab[n][m];
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
scanf(" %c",&tab[i][j]);
}
}
queue<int> qi,qj,qt;
qi.p(0);
qj.p(0);
qt.p(0);

while(!qi.empty()){
int i=qi.front();
int j=qj.front();
int t=qt.front();
//printf("%d %d %c\n",i,j,tab[i][j]);
qi.pop();
qj.pop();
qt.pop();
if(visit[i][j]){
printf("%d\n%d %d",t+1,i+1,j+1);
exit(0);
}
visit[i][j]=1;
if(tab[i][j]=='R'||tab[i][j]=='B')if(!visit[i][j+1])if(j+1<m){qi.p(i);qj.p(j+1);qt.p(t+1);}
if(tab[i][j-1]=='R'||tab[i][j-1]=='B')if(!visit[i][j-1])if(j-1>=0){qi.p(i);qj.p(j-1);qt.p(t+1);}
if(tab[i][j]=='D'||tab[i][j]=='B')if(!visit[i+1][j])if(i+1<n){qi.p(i+1);qj.p(j);qt.p(t+1);}
if(tab[i-1][j]=='D'||tab[i-1][j]=='B')if(!visit[i-1][j])if(i-1>=0){qi.p(i-1);qj.p(j);qt.p(t+1);}

}
}
