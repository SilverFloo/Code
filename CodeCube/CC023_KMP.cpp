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
char a[1000006],b[1000006];
int lps[1000006];
int main(){
    int n,m;
    cin>>n>>m;
    scanf("%s",a);
    scanf("%s",b);
    int j=0,i=1;
    while(i<m){
        if(b[i]==b[j]){
            lps[i]=j+1;
            j++;i++;
        }
        else {
            if(j>0){j=lps[j-1];}
            else i++;
        }
    }
    FOR(i,m)printf("%d ",lps[i]);

    j=0,i=0;int cnt=0;
    while(i<n){
        //    printf("%d %d\n",i,j);
        if(a[i]==b[j]){
            j++;i++;
            if(j==m)cnt++,j=lps[j-1];
        }
        else {
            if(j>0)j=lps[j-1];
            else i++;
        }
    }
    printf("%d",cnt);
}
