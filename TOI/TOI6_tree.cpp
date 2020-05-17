#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;
int main(){
int xx=5;
while(xx--){
int n;
scanf("%d",&n);
pair<int,int> f[n],s[n];
for(int i=0;i<n-1;i++){scanf("%d %d",&f[i].first,&f[i].second);if(f[i].x>f[i].y)swap(f[i].x,f[i].y);}
for(int i=0;i<n-1;i++){scanf("%d %d",&s[i].first,&s[i].second);if(s[i].x>s[i].y)swap(s[i].x,s[i].y);}
sort(f,f+n);
sort(s,s+n);
int ch=0;
for(int i=1;i<n;i++){
//printf("%d %d %d %d\n",f[i].first,f[i].second,s[i].first,s[i].second);
if(f[i].first!=s[i].first||f[i].second!=s[i].second){ch=1;}}
if(!ch)printf("Y");
else printf("N");
}


}
