#pragma once
#include<iostream>
struct Complex {
    int real;
    int imaginary;
};

Complex add(Complex n, Complex m);
Complex multiply(Complex n, Complex m);
void print(Complex number);
