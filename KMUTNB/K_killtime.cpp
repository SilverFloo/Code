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
ii tab[100005];
int main(){
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        FOR(i,n){scanf("%d",&tab[i].f);tab[i].s=i;}
        sort(tab,tab+n);
        int cnt=1;
        int pos=INF;
        int num=0;
        while(1){
            while(num<n&&tab[num].s>=pos)num++;

            if(num==n)break;
            pos=tab[num].s;
            cnt++;
        }
        printf("%d\n",cnt%2);
    }
}
