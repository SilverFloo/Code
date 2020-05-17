//https://www.proprog.tk/tasks?tag=Thailand+Olympiad+in+Informatics+2017+%28TOI13+%2F+TOI+2017%29
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
char a[(int)5e6+5];int lps[(int)5e6+5];
int main(){
    int n;
    cin>>n;
    scanf("%s",a);
    int i=1,j=0;
    while(i<n){
        if(a[i]==a[j]){
            lps[i]=j+1;
            i++;j++;
        }
        else {
            if(j>0)j=lps[j-1];
            else i++;
        }
    }
  //  FOR(i,n)printf("%d ",lps[i]);
    i=1;j=0;
    while(i<2*n){
        if(a[i%n]==a[j]){
            i++;j++;
            if(j==n){printf("%d",i-j);return 0;}
        }
        else{
        if(j>0)j=lps[j-1];
        else i++;
        }
    }
    printf("%d",n);
}
