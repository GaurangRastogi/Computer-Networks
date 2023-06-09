#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int n;
    printf("enter no of frames to be sent: ");
    scanf("%d",&n);
    int frames[n],i=0;
    for(int i=0;i<n;i++){
        scanf("%d",&frames[i]);
    }
    i=0;
    while(i<n){

        int probability=rand()%3;
        if(probability==0){
            printf("Frame %d sent and ack recieved\n",frames[i]);
            i++;
        }
        else if(probability==1){
            printf("Frame %d sent but ack lost\n",frames[i]);
        }
        else{
            printf("Frame %d lost\n",frames[i]);
        }
        sleep(1000);
    }
         printf("All the frames sent successfully");
        return 0;
}