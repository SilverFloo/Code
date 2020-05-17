#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    cin>>n>>m;
    int st[n*m];
    for(int i=0;i<n*m;i++){st[i]=i;}
    double ans=2e9;
    double x[n+2][m+2];
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%lf",&x[i][j]);
    do{
        double nans=0;int ch=1;
        double tmp[n+2][m+2];
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)tmp[i][j]=x[i][j];
        for(int i=0;i<n*m;i++){
            int f=st[i]/m+1,s=st[i]%m+1;
            //printf("%d ",st[i]);
            nans+=tmp[f][s];//printf("%d %d %d\n",st[i],f,s);
            if(nans>ans){ch=0;break;}
            tmp[f-1][s]+=0.1*tmp[f][s];
            tmp[f+1][s]+=0.1*tmp[f][s];
            tmp[f][s+1]+=0.1*tmp[f][s];
            tmp[f][s-1]+=0.1*tmp[f][s];
            tmp[f-1][s+1]+=0.1*tmp[f][s];
            tmp[f-1][s-1]+=0.1*tmp[f][s];
            tmp[f+1][s+1]+=0.1*tmp[f][s];
            tmp[f+1][s-1]+=0.1*tmp[f][s];
        }
        if(nans<ans&&ch)ans=nans;
   }    while(next_permutation(st,st+n*m));
    printf("%.2lf",ans);
}
