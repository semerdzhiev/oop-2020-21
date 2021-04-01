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