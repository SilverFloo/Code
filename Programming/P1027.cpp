#include<bits/stdc++.h>
using namespace std;
main(){
bool status[7];
int score[7]={};
for(int i=0;i<7;i++){status[i]=true;}
char vote[100000];
int l=7;
scanf("%s",&vote);
while(vote[0]!='!'){

for(int i=0;i<strlen(vote);i++){score[vote[i]-'A']++;}
int m=100000,mi;
for(int i=0;i<7;i++){
if(score[i]<m&&status[i]){m=score[i];mi=i;}
else if(score[i]==m&&status[i]){mi=-1;}
}
if(mi!=-1&&l!=1){l--;
status[mi]=false;
}scanf("%s",&vote);
}
for(int i=0;i<7;i++){score[i]=score[i]*100+10*(7-i);
if(status[i])score[i]++;
}
sort(score,score+7);
printf("%d\n",l);
for(int i=6;i>=0;i--){
if(score[i]%10==1){printf("%c %d\n",7-((score[i]%100)/10)+'A',score[i]/100);}
}

}
