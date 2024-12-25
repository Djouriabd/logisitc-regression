#include<iostream>
#include<cmath>
using namespace std;

float linear_regression(float w,float b,int x){
return (w*x)+b;}

float logistic(float x) {
    return 1 / (1 + exp(-x));
}

int main(){
    float t1[5],t2[5],fx,z;
    int y;
    for (int i=0;i<5;i++){
        cout <<"give me the values of the first table:";
        cin >> t1[i];
    }
    for (int i=0;i<5;i++){
        cout <<"give me the values of the second table:";
        cin >> t2[i];
    }
    cout <<"give me the prediction number u want:";
    cin >> y;
    for (int i=0;i<5;i++){
    fx=linear_regression(t1[i],t2[i],y);
    cout << "prediction:  " << fx << endl;
    z=logistic(fx);
    cout << "logistic:  " << z <<endl;
    }

    return 0;
}
