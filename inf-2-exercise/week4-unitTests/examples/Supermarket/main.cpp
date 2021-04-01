#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Product.h"

// n! = 1*2*3* ... *(n-1)*n
/*unsigned int Factorial(unsigned int number) {
    if(number==0)
        return 1;
    return number * Factorial(number - 1);//??
}*/

/*TEST_CASE("Factorials are computed", "[factorial]") {
    REQUIRE(Factorial(1) == 1);
    REQUIRE(Factorial(2) == 2);
    REQUIRE(Factorial(3) == 6);
    REQUIRE(Factorial(10) == 3628800);
    //REQUIRE(Factorial(-3) == 1);
}*/

int main() {
    Product p;
    p.print();

    return 0;
}