//https://www.codecube.in.th/task/169
#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
#define ll long long
using namespace std;
const int INF=1e9;
int s[100006],a[1000006],b[1000006],lps[1000006];
int main(){
    for(int i=1;i<=100000;i++){
        for(int j=i;j<=100000;j+=i){
            s[j]++;
        }
    }
    int n,m;
    cin>>n>>m;
    FOR(i,n){
        int x;
        scanf("%d",&x);
        a[i]=s[x];
    }

    FOR(i,m){
        int x;
        scanf("%d",&x);
        b[i]=s[x];
    }
    int i=1,j=0;
    while(i<m){
        if(b[i]==b[j]){
            lps[i]=j+1;
            i++;j++;
        }
        else{
            if(j>0){j=lps[j-1];}
            else i++;
        }
    }
    i=0,j=0;
    int ans=0;
    while(i<n){
        if(a[i]==b[j]){
        i++;j++;
        if(i-j<=n-m)ans=max(j,ans);
        if(j==m){printf("%d",m);return 0;}
        }
        else{
        if(j>0){j=lps[j-1];}
        else {i++;}
        }
    }
    printf("%d",ans);

}
