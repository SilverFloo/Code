#include<bits/stdc++.h>
using namespace std;
bool p[10000000];
int main(){
p[0]=1;
p[1]=1;
for(int i=2;i<1000000;i++){
if(!p[i]){
for(int j=i<<1;j<1000000;j+=i)p[j]=1;
}
}
int n;
scanf("%d",&n);
for(int i=0;i<1000000;i++){
if(!p[i])n--;
if(n==0){printf("%d",i);break;}
}

}
