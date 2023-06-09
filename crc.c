
#include<stdio.h>
#include<stdlib.h>
int main(){
    int i,j,keylen,msglen;
    char input[100],key[10];
    printf("Enter the size of keylength and messagelength: ");
    scanf("%d%d",&keylen,&msglen);
    printf("Enter the input data and key data: ");
    scanf("%s%s",input,key);
    for(int i=0;i<keylen;i++){
        input[msglen+i]='0';
    }
    for(int i=0;i<msglen+keylen-1;i++){
        printf("%c",input[i]);
    }
    printf("\n");
    for(int i=0;i<msglen;i++){
        if(input[i]=='0'){
            continue;
        }
        else{
            for(int j=0;j<keylen;j++){
                if(input[i+j]=='0'&&key[j]=='0'||input[i+j]=='1'&&key[j]=='1'){
                    input[i+j]='0';
                }
                else{
                    input[i+j]='1';
                }
            }
        }
    }
    for(int i=0;i<msglen+keylen-1;i++){
        printf("%c",input[i]);
    }
}