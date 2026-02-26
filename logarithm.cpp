#include <iostream>
#include <cmath>
using namespace std;

// Processing log, using the Taylor Series to expand the ln(x) fuction.
// Basically only useful for value close to 1.
double plog(double a) {
    double result;
    int i = 1;
    int m = -1;
    while (i <= 100) {
        result += pow(a-1, i)/i*(pow(m,i+1));
        i++;
    }

    return result;
}

// Main log function, using the property of logarithm that log(a) = log(d^m * a/d^m) = m*log(d) + log(a/d^m)
// A small enough value of 'd' should be good enough for the Taylor Series to estimate.
double ln(double a) {
    double result;
    float d = 1.2;
    int i = 1;
    int m = 0;
    while (d <= a) {
        a/=d;
        i+=1;
        m+=1;
    }
    return result = m*plog(1.2) + plog(a);
}

int main(){
    cout<<"============================"<<endl;
    cout<<"Natural Logarithm Calculator"<<endl;
    double y;
    cout<<"Input the number: ";
    cin>>y;
    if(y<=0){
        cout<<"Sowwy, logarithms only works for positife numbews (or atleast I haven't understood it yet :p )"<<endl;
        return 0;
    }
    double b = ln(y);
    cout<<"Natural Logarithm of "<<y<<" is: "<<b<<endl;
    cout<<"============================"<<endl;
    return 0;
}


















