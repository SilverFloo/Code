#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m;
scanf("%d %d",&n,&m);
int a[n],b[m];
for(int i=0;i<n;i++){scanf("%d",&a[i]);}
for(int i=0;i<m;i++){scanf("%d",&b[i]);}
int sa=0,sb=0;
int la=0,lb=0;
int c=0;
while(la!=n&&lb!=m){
if(sa<sb){sa+=a[la];la++;}
else {sb+=b[lb];lb++;}
//printf("%d %d\n",sa,sb);
if(sa==sb){c++;sa=0;sb=0;}
}
printf("%d",c+1);
}
