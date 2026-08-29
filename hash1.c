#include<stdio.h>
#define SIZE 10
int hash[SIZE];
void initialize(){
    for(int i=0;i<SIZE;i++){
        hash[i]=-1;
    }
}
void insert(int key){
    int i;
    int index = key % SIZE;
    while(hash[(index + i)%SIZE]!= -1 && i<SIZE)
     i++;
    if(i==SIZE){
        printf("Hash Table is full.\n");
    }
    else{
        hash[(index + i)%SIZE]=key;
    }
}
void display(){
    int i;
    for(i=0;i<SIZE;i++){
        if(hash[i]==-1){
            printf("%d --> Empty\n",i);
        }
        else{
            printf("%d --> %d\n",i,hash[i]);
        }
    }
}
int main(){
    int k,n;
    initialize();
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