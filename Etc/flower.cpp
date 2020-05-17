#include<bits/stdc++.h>
using namespace std;
const int MAX =1e6+5;
int parx[MAX];
int pary[MAX];
int rootx(int i){
while(parx[parx[i]]!=i){
i=parx[parx[i]];
parx[i]=parx[parx[i]];
}
return i;
}

int rooty(int i){
while(pary[pary[i]]!=i){
i=pary[pary[i]];
pary[i]=pary[pary[i]];
}
return i;
}

int main(){
int t;
scanf("%d",&t);
while(t--){
int n;
scanf("%d",&n);int c=1;int count =0;
for(int i=0;i<n;i++){
int x,y;
scanf("%d %d",&x,&y);printf("--%d %d--",rootx(4),rooty(3));
if(rootx(x)==0&&rooty(y)==0){parx[x]=c;pary[y]=c;c++;count++;}
else if(rootx(x)!=0&&rooty(y)!=0){if(rootx(x)!=rooty(y)){printf("-%d %d-",rootx(x),rooty(y));count--;}parx[x]=rooty(y);}
else if(rootx(x)==0){printf("in");parx[x]=rooty(y);}
else pary[y]=rootx(x);
printf(">%d<",count);
}
printf("%d\n",count);
for(int i=0;i<MAX;i++){parx[i]=0;pary[i]=0;}

}

}
