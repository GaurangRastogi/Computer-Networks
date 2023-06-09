#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
#include<time.h>
int main(){
    char ip[20];
    printf("Enter IP Address: ");
    scanf("%s",ip);
    int list[4],x=0,sum=0;
    list[0]=0;list[1]=0;list[2]=0;list[3]=0;
    for(int i=0;i<15&&ip[i]!='/'&&ip[i]!='\0';i++){
        if(ip[i]=='.'){
            list[x]=sum;
            sum=0;
            x++;    
        }
        else{
           sum=sum*10+(ip[i]-'0'); 
        }
    }
    list[x]=sum;
    printf("%d.%d.%d.%d\n",list[0],list[1],list[2],list[3]);
    int n;
    printf("enter the number of groups: ");
    scanf("%d",&n);
    int c[n],p[n];
    printf("enter the number of customers and their ports requirement in each group\n");
    for(int i=0;i<n;i++){
        scanf("%d%d",&c[i],&p[i]);
    }
    for(int i=0;i<n;i++){
        printf("------Group------ %d\n",i+1);
        int mask=32-ceil(log(c[i])/log(2));
        for(int i=0;i<c[i];i++){
            printf("From %d.%d.%d.%d/%d\n",list[0],list[1],list[2],list[3],mask);
            list[3]+=p[i]-1;
            if(list[3]>255){
                list[2]++;
                list[3]=list[3]%256;
            }
            printf("To %d.%d.%d.%d/%d\n",list[0],list[1],list[2],list[3],mask);
            list[3]++;
            if(list[3]>255){
                list[2]++;
                list[3]=list[3]%256;
            }
        }
    }
    sleep(5);
    return 0;
}