#include<stdio.h>
int max(int a, int b){
    return (a>b) ? a : b ;
}
int main(){
    int n,i,W,w;
    printf("Enter the Number of Elements :");
    scanf("%d",&n);
    int wt[n], val[n];
    printf("Enter Weights of the Elements :");
    for(i=0;i<n;i++){
        scanf("%d", &wt[i]);
    }
    printf("Enter Profit Values :");
    for(i=0;i<n;i++){
        scanf("%d", &val[i]);
    }u
    printf("Enter the Knapsack Capacity :");
    scanf("%d",&W);
    int dp[n+1][W+1];
    for(i=0;i<=n;i++){
        for(w=0;w<=W;w++){
            if(i==0||w==0){
                dp[i][w]=0;
            }
            else if(wt[i-1]<=w){
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]] , dp[i - 1][w]);
            }
            else{
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    printf("Maximum Profit = %d",dp[n][W]);
    return 0; 
}