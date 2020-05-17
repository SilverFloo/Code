#include<stdio.h>
#include<math.h>
main(){
int n;
scanf("%d",&n);
int a[5]={};
for(int i=0;i<n;i++){
int x;
for(int j=0;j<5;j++){scanf("%d",&x);a[j]+=x;}
}

int ans=0;
ans+=a[0];
a[0]=0;

while(a[1]!=0){
if(a[3]!=0){a[3]--;a[1]--;ans++;}
else{a[4]-=2;a[1]--;ans++;}
}

ans+=a[2]/2;
a[2]=a[2]%2;
if(a[2]==1){
if(a[3]>=2){a[3]-=2;a[2]--;ans++;}
else if(a[3]==1){a[3]--;a[4]-=2;a[2]--;ans++;}
else{a[4]-=4;a[2]--;ans++;}
}


while(a[3]>0){
if(a[3]/4>0){a[3]-=4;ans++;}
else if(a[3]==3){a[3]-=3;a[4]-=2;ans++;}
else if(a[3]==2){a[3]-=2;a[4]-=4;ans++;}
else {a[3]--;a[4]-=6;ans++;}
}
if(a[4]>0)ans+=ceil((float)a[4]/8);
printf("%d",ans);
}
