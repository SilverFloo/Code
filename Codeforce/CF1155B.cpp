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
int main(){
    int n;
    cin>>n;
    int x=(n-11)/2;
    int y=x;
    FOR(i,n){
        char c;
        scanf(" %c",&c);
        if(c!='8'){
            x--;
        }
        else{
            y--;
        }
        if(y==-1){printf("YES");return 0;}
        if(x==-1){printf("NO");return 0;}
    }
}
