#include<bits/stdc++.h>
using namespace std;
pair<int,int> f[3000000];int s[3000000]
int main(){
pair<int,int> a;int n;
scanf("%d %d %d",&a.first,&a.second,&n);
pair<int,int> a[1500],b[1500];
for(int i=;i<n;i++){
scanf("%d %d",&a[i].first,&a[i].second);
}
pair<int,int> a[1500],b[1500];
for(int i=;i<n;i++){
scanf("%d %d",&b[i].first,&b[i].second);
int c=0;
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
f[c].first=a[i].first+b[i].first;
f[c].second=a[i].second+b[i].second;
}
}
}
}
