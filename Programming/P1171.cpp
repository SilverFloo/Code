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
int main(){
    int t;
    cin>>t;
    while(t--){
        char x[25];
        int a;
        scanf("%s %d",x,&a);
        for(int i=0;i<strlen(x);i++){
            if(x[i]-'0'<a)a-=x[i]-'0',printf("%c",x[i]);
            else if(a>0)printf("%d",a),a=0;
            else printf("0");
        }
        printf("\n");
    }

}
