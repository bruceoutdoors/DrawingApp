#include "catch.hpp"
#include "Selection.hpp"
#include "Circle.hpp"

TEST_CASE("copy constructor and equals operator") {
    Selection *sel = new Selection();

    Circle *c1 = new Circle();
    Circle *c2 = new Circle();

    sel->add(c1);
    sel->add(c2);

    REQUIRE(sel->getSize() == 2);

    Selection *sel2 = new Selection();
    Selection *sel3;

    sel3 = sel;   // copy pointer
    *sel2 = *sel; // copy contents

    REQUIRE(sel->getSize()  == 2);
    REQUIRE(sel2->getSize() == 2);

    sel2->remove(1);

    REQUIRE(sel->getSize()  == 2);
    REQUIRE(sel2->getSize() == 1);
    REQUIRE(sel3->getSize() == 2);
}
