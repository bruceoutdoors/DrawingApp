#include "catch.hpp"
#include "Group.hpp"
#include "Circle.hpp"

TEST_CASE("add test") {
    Group g;

    SECTION("A new empty Group") {
        REQUIRE(g.getSize() == 0);
    }

    SECTION("Single shape add test") {
        Circle *c = new Circle();
        g.add(c);
        REQUIRE(g.getSize() == 1);
    }

    SECTION("Multiple shapes add test") {
        for (int i = 0; i < 50; i++) {
            Circle *c = new Circle();
            g.add(c);
            REQUIRE(g.getSize() == i+1);
        }
    }
}

SCENARIO( "remove does not destroy shape; destroy does.") {
    GIVEN( "A Group with some items" ) {
        Group g;
        Circle *c = new Circle();
        g.add(c);

        REQUIRE(g.getSize() == 1);

        WHEN( "A shape is removed with remove" ) {
            g.remove(0);

            THEN( "the size changes, but shape still exists" ) {
                REQUIRE(g.getSize() == 0);
                REQUIRE(c->getIndex() == -1);
            }
        }

        WHEN( "A shape is removed with destroy" ) {
            c->setRadius(509);
            g.destroy(0);

            THEN( "the size changes, but shape is deleted" ) {
                REQUIRE(g.getSize() == 0);
                REQUIRE(c->getRadius() != 509);
                REQUIRE(c->getIndex() < 0);
            }
        }
    }
}
