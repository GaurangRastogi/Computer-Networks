#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
#include<time.h>
int main(){
        char ip[50];
        printf("Enter ip address: ");
        scanf("%s",ip);
        int list[4],j=0,d=0;
        printf("%s\n",ip);
        for(int i=0;i<15&&ip[i]!='/'&&ip[i]!='\0';i++){
                if(ip[i]=='.'){
                        list[j]=d;
                        d=0;
                        j++;
                }
                else    d=d*10+ip[i]-'0';
        }
        list[j]=d;
        int n;
        printf("\nEnter no of groups: ");
        scanf("%d",&n);
        int customers[n],ports[n];
        printf("Enter no of customers in each group and each customer port requirement: \n");
        for(int i=0;i<n;i++)    scanf("%d%d",&customers[i],&ports[i]);
        for(int i=0;i<n;i++){
                printf("\t------- Group %d -------\n",i+1);
                int temp=32-(ceil(log(ports[i])/log(2)));
                for(int k=0;k<customers[i];k++){
                        printf("Customer  %d  ip is %d.%d.%d.%d/%d",k+1,list[0],list[1],list[2],list[3],temp);
                        list[3]+=ports[i]-1;
                        if(list[3]>255)    {list[2]++;list[3]%=256;}
                        printf(" to  %d.%d.%d.%d/%d\n",list[0],list[1],list[2],list[3],temp);
                        list[3]++;
                        if(list[3]>255)    {list[2]++;list[3]%=256;}
                }
        }
        sleep(1);
        return 0;
}