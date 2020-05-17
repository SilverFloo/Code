#include<bits/stdc++.h>
using namespace std;
pair<pair<int,int>,int> f[3000000], s[3000000];
int find(int l,int r,pair<int ,int> xx){

    if(l>r)return -1;
    int m=(l+r)/2;
    if(xx.first==s[m].first.first&&xx.second==s[m].first.second){return m;}
    else if(xx.first<s[m].first.first||(xx.first==s[m].first.first&&xx.second<s[m].first.second)){return find(l,m-1,xx);}
    else {return find(m+1,r,xx);}

}
int main(){
pair<int,int> ans;int n;int co=0;
scanf("%d %d %d",&ans.first,&ans.second,&n);
pair<int,int> a[1500],b[1500];
for(int i=0;i<n;i++){
scanf("%d %d",&a[i].first,&a[i].second);
}
for(int i=0;i<n;i++){
scanf("%d %d",&b[i].first,&b[i].second);}

for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
f[co].first.first=a[i].first+b[j].first;
f[co].first.second=a[i].second+b[j].second;
f[co].second=co;
co++;
}
}


pair<int,int> c[1500],d[1500];
for(int i=0;i<n;i++){
scanf("%d %d",&c[i].first,&c[i].second);
}
for(int i=0;i<n;i++){
scanf("%d %d",&d[i].first,&d[i].second);}
co=0;
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
s[co].first.first=c[i].first+d[j].first;
s[co].first.second=c[i].second+d[j].second;
s[co].second=co;
co++;
}
}

sort(f,f+co);
sort(s,s+co);
for(int i=0;i<co;i++){
int x= find(0,co-1,make_pair(ans.first-f[i].first.first,ans.second-f[i].first.second));
if(x!=-1){
printf("%d %d\n%d %d\n",a[f[i].second/n].first,a[f[i].second/n].second,b[f[i].second%n].first,b[f[i].second%n].second);
printf("%d %d\n%d %d\n",c[s[x].second/n].first,c[s[x].second/n].second,d[s[x].second%n].first,d[s[x].second%n].second);


}
}

}
