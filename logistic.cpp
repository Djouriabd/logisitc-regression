#include<iostream>
#include<cmath>
using namespace std;

float linear_regression(float w,float b,float x){
//int linear_regression(int w,int b,int x){
return (w*x)+b;}

float logistic(float x) {
    return 1.0/(1.0 + exp(-x));
}

float odd(float y){
    if (y==1||y==0){
        return -1;}
    return y/(1-y);
}

float log_odd(float z){
    return log(z);
}

int main(){

    float t1[20],t2[20],y;
    //int t1[20],t2[20],y;
    for (int i=0;i<20;i++){
        cout <<"give me the values of the first table:";
        cin >> t1[i];
    }
    for ( i=0;i<20;i++){
        cout <<"give me the values of the second table:";
        cin >> t2[i];
    }
    cout <<"give me the prediction number u want:";
    cin >> y;
    for ( i=0;i<20;i++){
        float fx=linear_regression(t1[i],t2[i],y);
        cout << "the prediction for the value:  " << fx << endl;
        float z=logistic(fx);
        cout << "the logistic for the value:  " << z << endl;
        float k=odd(z);
        if (k ==-1){
            cout << "can't calculate the odd it took -infinity value"<<endl;
        }
        else{
            cout << "the odd value:   "<< k << endl;
            float j=log_odd(k);
            cout << "the log odd value:   "<< j <<endl;}
        cout << "+---------------------------+" << endl;
    }

    return 0;
}
