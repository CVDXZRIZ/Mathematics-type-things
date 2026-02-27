#include<iostream>
#include<cmath>
using namespace std;

// Factorial function, used for the Taylor Series expansion of the sine function.
int fac(int a){
    int i=1;
    int r=1;
    while (r<=a){
        i*=r;
        r++;
    }
    return i;
}

//processing sine, using the Taylor Series to expand the sine function.
double psin(double a){
    double result = 0;
    int i=1;
    int m=-1;
    while (i<=7){
        result+=(pow(a,i*2-1)/fac(i*2-1))*(pow(m,i+1));
        i++;
    }
    return result;
}

//simplification of the sine funtion
//also turns the input from degree to radian
//since the Taylor Series is based on the radian input
double sin(double a){
    double result;
    while (a>=360){
        a-=360;
    }
    while (a<0){
        a+=360;
    }
    while (a>90){
        a=180-a;
    }
    double b=(a/180)*3.141592653589793;
    return psin(b);
}


int main(){
    cout<<"================================="<<endl;
    cout<<"Sine Calculator"<<endl;
    double y;
    cout<<"Input the angle (in degree): ";
    cin>>y;
    double b = sin(y);
    cout<<"Sine of "<<y<<" degree is: "<<b<<endl;
    cout<<"================================="<<endl;
    return 0;
}