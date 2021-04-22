#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../Supermarket/Product.h"
#include "../Supermarket/ProductCollection.h"

TEST_CASE("Product withDiscount works for products without discount", "[withDiscount]") {
    Product p("cubrica", 0.45, 0.45);

    REQUIRE(!p.withDiscount());
}

TEST_CASE("Product withDiscount works for products with discount", "[withDiscount]") {
    Product p("cubrica", 0.45, 0.55);

    REQUIRE(p.withDiscount());
}

TEST_CASE("ProductCollection add and getAt modify the collection", "[add, getAt]") {
    ProductCollection pc;

    Product p("cubrica", 0.45, 0.55);
    pc.add(p);

    REQUIRE(pc.getAt(0).getName() == "cubrica");
}

TEST_CASE("ProductCollection add and getAt pcd", "[add, getAt, withDiscount]") {
    ProductCollection pc;

    Product p("cubrica", 0.45, 0.55);
    pc.add(p);
    ProductCollection pcd = pc.withDiscount();

    REQUIRE(pcd.getAt(0).getName() == "cubrica");
}

TEST_CASE("ProductCollection += and getSize", "[operator+=]") {
    Product p1("cubrica", 0.45, 0.55);
    Product p2("kashkaval", 4.5, 4.5);

    ProductCollection pc;
    pc.add(p1);
    pc.add(p2);

    ProductCollection pc2(pc);
    Product p3("sirene", 3.5, 3.5);
    pc2.add(p3);

    pc += pc2;

    REQUIRE(pc2.getSize() == 3);
}