#include<bits/stdc++.h>
using namespace std;
int n;
int f[1234575];
int d[1234575];
void print(int i){
if(f[i]==-1)return;
print(f[i]);
if(d[i]==1)printf("*3");
else printf("/2");
}
int main(){
scanf("%d",&n);
f[1]=-1;
queue<int> q;
q.push(1);
while(q.size()!=0){
int i=q.front();
q.pop();if(i==n){break;}
if(i*3<=1234567)if(f[i*3]==0){f[i*3]=i;d[i*3]=1;q.push(i*3);}
if(f[i>>1]==0){f[i>>1]=i;d[i>>1]=2;q.push(i>>1);}
}
printf("1");
print(n);
}
