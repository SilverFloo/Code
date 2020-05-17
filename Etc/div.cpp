#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
if(a%b==0)return b;
return gcd(b,a%b);
}
int ggcd(int a,int b){
if(a>b) return gcd(a,b);
return gcd(b,a);
}
queue<int> q;
int main(){
int t;
scanf("%d",&t);
while(t--){
int n;
scanf("%d",&n);
int ans;
scanf("%d",&ans);
for(int i=1;i<n;i++){int a;scanf("%d",&a);ans=gcd(a,ans);}
printf("%d\n",ans==1?-1:ans);
}

}
