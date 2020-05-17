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
    char s[2000],ans[2000];
int main(){
    int n;
    cin>>n;
    scanf("%s",s);
    if(n==1)printf("%s",s),exit(0);
    int l=strlen(s);

    int pos=-1;

for(int i=n-1;i>=0;i--){
        int cnt=0;
        if(i==n-1){
    int t=0,p=i;
    while(p<l){
    //printf("aa");
    pos++;
    ans[p]=s[pos];
    t++;
    if(t==n)p+=3*n-3,t=0;
    else p++;
    }
    }
    else if(i==0){
         int t=n-1,p=i;
    while(p<l){
   // printf("%d",p);
    pos++;
    ans[p]=s[pos];
    t++;
    if(t==n)p+=3*n-3,t=0;
    else p++;
    }


    }
    else{
        int p=i;
        int t=0;
    while(p<l){
        pos++;
        ans[p]=s[pos];
        t++;
       // printf("<%d %d %d>",i-1,n-i-2,p);
        if(t%2==0){p+=n+2*(i-1)+1;}
        else p+=n+2*(n-i-2)+1;
    }

    }


    }
    FOR(i,l)printf("%c",ans[i]);
}
/*
4
NINGTHISRDSOEIMVWTC*/
