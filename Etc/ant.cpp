#include<bits/stdc++.h>
main(){
int t,l,n;
scanf("%d%d%d",&l,&t,&n);
int ant[n];
for(int i=0;i<n;i++){
char x;
scanf("%d %c",&ant[i],&x);
if(x=='L')ant[i]-=t;
else ant[i]+=t;
}
for(int i=0;i<n;i++){
while(ant[i]<0||ant[i]>l){
if(ant[i]<0)ant[i]*=-1;
else ant[i]=l-(ant[i]-l);
}

}
std::sort(ant,ant+n);
for(int i=0;i<n;i++)printf("%d ",ant[i]);

}
