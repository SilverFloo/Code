#include<bits/stdc++.h>
using namespace std;
main(){
int n;
scanf("%d",&n);

int h[n],pos[n];
for(int i=0;i<n;i++){
scanf("%d %d",&pos[i],&h[i]);
}

int Ml=0,pl,co=1,po=n-1,con=pos[n-1]-h[n-1];
for(int i=n-1;i>=0;i--){

if(con<pos[i]&&i!=po){co++;if(pos[i]-h[i]<con)con=pos[i]-h[i];}
else{if(co>=Ml){Ml=co;pl=po;}con=pos[i]-h[i];co=1;po=i;}
}if(co>=Ml){Ml=co;pl=po;}
int Mr=0,pr;co=1;po=0;con=pos[0]+h[0];
for(int i=0;i<n;i++){

if(con>pos[i]&&i!=po){co++;if(pos[i]+h[i]>con)con=pos[i]+h[i];}
else{if(co>Mr){Mr=co;pr=po;}con=pos[i]+h[i];co=1;po=i;}
}if(co>Mr){Mr=co;pr=po;}

if(Ml>Mr)printf("%d L ",pl+1);
else if(Ml==Mr){
if(pl<=pr)printf("%d L ",pl+1);
else printf("%d R ",pr+1);
}
else printf("%d R",pr+1);
}
