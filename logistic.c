#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//float linear_regression(float w,float b,int x){
int linear_regression(float w,float b,int x){
return (w*x)+b;}

float logistic(int x) {
    return 1 / (1 + exp(-x));
}

float odd(float y){
    if (y==1||y==0) {return -1;}
    else{
        return y/(1-y);
    }
}

float log_odd(float z){
    return log(z);
}

int main(){
    //float t1[20],t2[20],y;
    int t1[20],t2[20],y;
    for (int i=0;i<10;i++){
        printf("give me the values of the first table:");
        scanf("%d",&t1[i]);
    }
    for (int i=0;i<10;i++){
        printf("give me the values of the second table:");
        scanf("%d",&t2[i]);
    }
    printf("give me the prediction number u want:");
    scanf("%d",&y);
    for (int i=0;i<10;i++){
        //float fx=linear_regression(t1[i],t2[i],y);
        int fx=linear_regression(t1[i],t2[i],y);
        printf("\nthe prediction for the value:%d",fx);
        float z=logistic(fx);
        printf("\nthe logistic for the value:%f",z);
        float k=odd(z);
        printf("\nthe odd value:%f",k);
        float j=log_odd(k);
        printf("\nthe log odd value:%f",j);
        printf("\n+--------------------------------+");
    }
    return 0;
}
