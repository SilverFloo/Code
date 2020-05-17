#include<bits/stdc++.h>
using namespace std;
main(){
int n,k;
scanf("%d %d",&n,&k);
if(n==1||k==1){printf("1");return 0;}
int a[100005];
a[0]=1;
for(int i=1;i<k;i++){
a[i]=(a[i-1]*2)%2009;
}
a[k]=((1<<k)-1)%2009;
int x=a[k];


for(int i=k+1;i<n;i++){
x+=-a[i-k-1]+a[i-1];
while(x<0)x+=2009;
x%=2009;
a[i]=x;
}
printf("%d",a[n-1]);
}
