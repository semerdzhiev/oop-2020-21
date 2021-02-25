#include <iostream>

struct ComplexNumber 
{
    double real, imaginary;
};

ComplexNumber sum(ComplexNumber z1, ComplexNumber z2) 
{
    ComplexNumber result;
    result.real = z1.real + z2.real;
    result.imaginary = z1.imaginary + z2.imaginary;
    return result;
}

//  (a1+ib1)*(a2+ib2) =
// = a1a2 + ia1b2 + ib1a2 + (i^2)b1b2 =
// = a1a2 - b1b2 + i(a1b2 + a2b1)

ComplexNumber product(ComplexNumber z1, ComplexNumber z2) 
{
    ComplexNumber result;
    result.real = z1.real*z2.real - z1.imaginary*z2.imaginary;
    result.imaginary = z1.real*z2.imaginary + z2.real*z2.imaginary;
    return result;    
}

void print(ComplexNumber z) 
{
    std:: cout << "Number: " << z.real << " + " << z.imaginary << "i" << std::endl;
} //TODO: if negative?

int main() 
{
    ComplexNumber num1 = {1,2};
    ComplexNumber num2 = {3,4};

    print(sum(num1,num2));
    print(product(num1,num2));
    return 0;
}

