#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float linear_regression(float w,float b,float x){
//int linear_regression(int w,int b,int x){
return (w*x)+b;}

float logistic(float x) {
    return 1.0/(1.0 + exp(-x));}

float odd(float y){
    if (y==1||y==0) {return -1;}
    else{
        return y/(1-y);
    }}

float log_odd(float z){
    return log(z);}

int main(){
    //i took n=20 for the both table to use a sample of 20 lines with 2 columns (the one of csv of salaries)
    float t1[20],t2[20],y;
    //int t1[20],t2[20],y;
    for (int i=0;i<20;i++){
        printf("give me the values of the first table:");
        scanf("%f",&t1[i]);
    }
    for (i=0;i<20;i++){
        printf("give me the values of the second table:");
        scanf("%f",&t2[i]);
    }
    printf("give me the prediction number u want:");
    scanf("%f",&y);
    for (i=0;i<20;i++){
        float fx=linear_regression(t1[i],t2[i],y);
        //int fx=linear_regression(t1[i],t2[i],y);
        printf("\nthe prediction for the value:%f",fx);
        float z=logistic(fx);
        printf("\nthe logistic for the value:%f",z);
        float k=odd(z);
        if (k ==-1){
            printf("can't calculate the odd it took -infinity value");}
        else{
            printf("\nthe odd value:%f",k);
            float j=log_odd(k);
            printf("\nthe log odd value:%f",j);
        }
        printf("\n+--------------------------------+");
    }
    return 0;
}
