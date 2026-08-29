#include<stdio.h>
#define SIZE 10
int hash[SIZE];
void initialize(){
    int i;
    for(i=0;i<SIZE;i++){
        hash[i]=-1;
    }
}
void insert(int key){
    int index = key%SIZE;
    int i;
    while(hash[(index + (i*i))%SIZE]!=-1 && i<SIZE){
        i++;
    }
    if(i==SIZE){
        printf("Hash Table is full.\n");
    }
    else{
        hash[(index +  (i*i))%SIZE]=key;
    }
}
void display(){
    for(int i=0;i<SIZE;i++){
        if(hash[i]==-1){
            printf("%d --> Empty\n",i);
        }
        else{
            printf("%d --> %d\n",i,hash[i]);
        }
    }
}
int main(){
    initialize();
    int k,n;
    printf("Enter NUmber of Elements :");
    scanf("%d",&n);
    if(n > SIZE){
        printf("Hash Table size is Insuffient.\n");
    }
    else{
        for(int i=0;i<n;i++){
            printf("Enter Any Number :");
            scanf("%d",&k);
            insert(k);
        }
        display();
    }
}