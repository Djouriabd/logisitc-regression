#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float linear_regression(float w,float b,int x){
return (w*x)+b;}

float logistic(float x) {
    return 1 / (1 + exp(-x));
}

int main(){
    float t1[5],t2[5],fx,z;
    int y;
    for (int i=0;i<5;i++){
        printf("give me the values of the first table:");
        scanf("%f",&t1[i]);
    }
    for (int i=0;i<5;i++){
        printf("give me the values of the second table:");
        scanf("%f",&t2[i]);
    }
    printf("give me the prediction number u want:");
    scanf("%d",&y);
    for (int i=0;i<5;i++){
    fx=linear_regression(t1[i],t2[i],y);
    printf("prediction:  \n%.2f  ",fx);
    z=logistic(fx);
    printf("logistic:  \n%.2f  ",z);
    }
    return 0;
}