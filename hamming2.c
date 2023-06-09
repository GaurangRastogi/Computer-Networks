#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int parity_len(int n){
    int num=1,k=0;
    while(n+k+1>num){
        num*=2;
        k++;
    }
    return k;
}
int main(){
    int n,j=0,x=0;
    printf("Enter the length of data: ");
    scanf("%d",&n);
    int data[n],np=parity_len(n);
    for(int i=n-1;i>=0;i--){
        scanf("%d",&data[i]);
    }
    int hamming_code[n+np],val_of_2=1,parity_pos[np];
    for(int i=0;i<n+np;i++){
        if(i+1==val_of_2){
            hamming_code[i]=-1;
            parity_pos[x]=i+1;
            x++;
            val_of_2*=2;
        }
        else hamming_code[i]=data[j++];
    }
    //calculation
    for(int i=0;i<np;i++){
        j=parity_pos[i]-1;
        int count=0;
        while(j<n+np){
            int temp=parity_pos[i];
            while(temp--&&j<n+np){
                count+=hamming_code[j];
                j++;
            }
            j+=parity_pos[i];
        }
        hamming_code[parity_pos[i]-1]=(count+1)%2;
    }
    int l=0,h=n+np-1;
    while(l<h){
        int temp=hamming_code[l];
        hamming_code[l]=hamming_code[h];
        hamming_code[h]=temp;
        l++;
        h--;
    }
    for(int i=0;i<n+np;i++) printf("%d ",hamming_code[i]);
    //Recovering code;
    int recovered_code[n+np];
    printf("\nEnter the code: ");
    for(int i=n-1;i>=0;i--){
        scanf("%d",&recovered_code[i]);
    }
    int ans=0,curr=pow(2,np)-1;
    for(int i=0;i<np;i++){
        j=parity_pos[i]-1;
        int count=0;
        while(j<n+np){
            int temp=parity_pos[i];
            while(temp--&&j<n+np){
                count+=hamming_code[j];
                j++;
            }
            j+=parity_pos[i];
        }
        ans+=(count+1)%2*pow(2,i);
    }
    printf("Error occurred at: %d",curr-ans);

}