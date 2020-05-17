#include<bits/stdc++.h>
using namespace std;
int a[20];
int r[20];
int c=0;
void base(int n){
if(n<3){a[c]=n;c++;return;}
a[c]=n%3;c++;
base(n/3);


}
int main(){
int n;
scanf("%d",&n);
base(n);
for(int i=0;i<c;i++){
    if(a[i]==2){r[i]++;a[i+1]++;a[i]=0;}
    else if(a[i]==3){a[i+1]++;a[i]=0;}
}
//for(int i=0;i<=c;i++){}
int co=0,ans=0;
for(int i=c;i>=0;i--){
   // printf("%d %d\n",a[i],r[i]);
    co+=a[i]+r[i];ans*=3;ans+=a[i];}
printf("%d %d",co,ans);
}
