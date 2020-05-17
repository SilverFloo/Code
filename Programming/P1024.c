#include<stdio.h>
#include<math.h>
main(){
int n;
scanf("%d",&n);
int x[n+1];
x[0]=0;
int i,y,j;

for(i=0;i<n;i++){scanf("%d",&y);x[i+1]=x[i]+y;}
int diff=1000000;
int mi,mj;
for(i=1;i<n;i++){
for(j=i+1;j<n;j++){
int a=x[i]-x[0];
int b=x[j]-x[i];
int c=x[n]-x[j];
int max=a>b?a:b;
max=max>c?max:c;
int min=a<b?a:b;
min=min<c?min:c;

if(max-min<diff)
{
diff=max-min;
mi=i;mj=j;
}}
}
printf("%d %d",mi+1,mj+1);
}
