#include<bits/stdc++.h>
int  a[1000];
main(){
int n;
scanf("%d",&n);
for(int i=0;i<n;i++){
int x;
scanf("%d",&x);
a[x]++;
}
double ans=0;
for(int i=0;i<1000;i++){
for(int j=i;j<1000;j++){
  if(i==j){if(a[i]>1)ans+=(double)(a[i])*(a[i]-1)/2;}
else if(a[i]>=1&&a[j]>=1){
int c=0;
if(i%10==j%10)c++;
if((i/10)%10==(j/10)%10)c++;
if(i/100==j/100)c++;
if(c>=1){ans+=(double)a[i]*a[j];//printf("%d %d\n",i,j);
}
}}
}
printf("%.0lf",ans);
}
