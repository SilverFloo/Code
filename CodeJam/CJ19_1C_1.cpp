#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define db(a) printf("<%d> ",a)
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
int tab[3][505];
string s[256];
stack<char> x;
int find(int l,int r,int i){

    if(l==r){
      if(s[l][i]=='R')x.push('P');
      else if(s[l][i]=='P')x.push('S');
      else x.p('R');
      return 1;
    }
    int m=l;
    for(;m<=r;m++){
        if(s[m][i]!=s[l][i])break;
    }
    if(m==r+1){
        if(s[l][i]=='R')x.push('P');
      else if(s[l][i]=='P')x.push('S');
      else x.p('R');
      return 1;
    }
   // printf("%c %c %c <%d %d %d>/",s[m][i],s[l][i],s[r][i],l,r,i);
    if(s[m][i]!=s[r][i])return 0;

    if(s[l][i]=='P'&&s[m][i]=='R'){
        if(find(l,m-1,i+1)==1){
        x.p('P');return 1;
        }
        else return 0;
    }
    if(s[l][i]=='P'&&s[m][i]=='S'){
            if(find(m,r,i+1)==1){
            x.p('S');return 1;
            }
            else return 0;
    }
    if(s[l][i]=='R'&&s[m][i]=='S'){
        if(find(l,m-1,i+1)==1){
        x.p('R');return 1;
        }
        else return 0;
    }
}
int main(){
    int T;
    cin>>T;
    FOR(k,T){
        int n;
        cin>>n;
        FOR(i,n){
           cin>>s[i];
           while(s[i].size()<500)s[i].append(s[i]);
        }
        sort(s,s+n);
        printf("Case #%d: ",k+1);
        if(find(0,n-1,0)==0)printf("IMPOSSIBLE");
        else {
                while(!x.empty()){printf("%c",x.top());x.pop();}

        }
        printf("\n");
    }

}
