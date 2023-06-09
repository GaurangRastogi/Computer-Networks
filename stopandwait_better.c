#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
#include<time.h>
int main(){
    int num;
    printf("Enter the number of frames: ");
    scanf("%d",&num);
    int j=0;
    while(j<num){
        int prob=rand()%3;
        if(prob==0){
            j++;
            printf("Acknowldgement recived");
        }
        else if(prob==1){
            printf("Acknowledge failed");
        }
        else printf("Data lost");
        printf("\n");
        sleep(1);
    }
    return 0;
}