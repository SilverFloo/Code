#include<bits/stdc++.h>
using namespace std;
int main(){
int n,k;
cin>>n>>k;
int m[n],f[n];
for(int i=0;i<n;i++){scanf("%d %d",&m[i],&f[i]);}
for(int i=0;i<n;i++){

if(f[i]==m[i]){f[i]=0;m[i]=0;}
else if(f[i]>m[i]){
f[i]-=m[i];m[i]=0;
for(int j=1;j<=k&&f[i]>0&&i+j<n;j++){if(f[i]>=m[i+j]){f[i]-=m[i+j];m[i+j]=0;}
else if(m[i+j]>f[i]){m[i+j]-=f[i];f[i]=0;}
}
if(f[i]!=0){printf("NO");exit(0);}
}
else{
m[i]-=f[i];f[i]=0;

for(int j=1;j<=k&&m[i]>0&&i+j<n;j++){if(m[i]>=f[i+j]){m[i]-=f[i+j];f[i+j]=0;}
else if(f[i+j]>m[i]){f[i+j]-=m[i];m[i]=0;}
}
//printf("%d %d %d\n",i,m[i],f[i]);
if(f[i]!=0){printf("NO");exit(0);}

}
}
printf("YES");
}
