#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    int n,seg_len;
    printf("Enter the length of msg and seg_len: ");
    scanf("%d%d",&n,&seg_len);
    int msg[n+seg_len],key[seg_len],sent[n+seg_len];
    for(int i=0;i<n+seg_len-1;i++){
        if(i<n) scanf("%d",&msg[i]);
        else msg[i]=0;
        sent[i]=msg[i];
    }
    for(int i=0;i<seg_len;i++){
        scanf("%d",&key[i]);
    }
    for(int i=0;i<n;i++){
        if(msg[i]==0)    continue;
        else{
            for(int j=0;j<seg_len;j++){
                msg[i+j]^=key[j];
            }
        }
    }
    printf("Remainder: ");
    for(int i=n;i<n+seg_len-1;i++){
        printf("%d ",msg[i]);
        sent[i]=msg[i];
    }
    printf("\nCRC: ");
    for(int i=0;i<n+seg_len-1;i++){
        printf("%d ",sent[i]);
    }
}