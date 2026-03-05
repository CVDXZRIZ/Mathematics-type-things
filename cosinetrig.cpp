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