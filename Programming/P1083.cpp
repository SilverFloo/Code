#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int ans[1000000];
main(){
int n;
scanf("%d",&n);
scanf("%d",&a[0]);ans[0]=0;
for(int i=1;i<n;i++){scanf("%d",&a[i]);
if(a[i-1]>a[i])ans[i]=ans[i-1];
if(a[i-1]<a[i])ans[i]=ans[i-1]+a[i]-a[i-1];
//printf("%d ",ans[i]);

}
int q;
scanf("%d",&q);
for(int i=0;i<q;i++){
int x,y;
scanf("%d %d",&x,&y);
printf("%d\n",ans[y-1]-ans[x-1]);
}


}
