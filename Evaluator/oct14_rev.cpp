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
char x[1005];
void rev(int i){
    if(x[i]=='\0')return;
    rev(i+1);
    printf("%c",x[i]);
}
int main(){
    scanf("%s",x);
    rev(0);
}
