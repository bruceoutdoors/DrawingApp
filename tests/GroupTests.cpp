#include "catch.hpp"
#include "Group.hpp"
#include "Circle.hpp"

TEST_CASE("addVisualEntity test") {
    Group g;

    SECTION("A new empty Group") {
        REQUIRE(g.getSize() == 0);
    }

    SECTION("Single shape add test") {
        Circle *c = new Circle();
        g.addVisualEntity(c);
        REQUIRE(g.getSize() == 1);
    }

    SECTION("Multiple shapes add test") {
        for (int i = 0; i < 50; i++) {
            Circle *c = new Circle();
            g.addVisualEntity(c);
            REQUIRE(g.getSize() == i+1);
        }
    }
}

SCENARIO( "removeVisualEntity does not destroy shape; destroyVisualEntity does.") {
    GIVEN( "A Group with some items" ) {
        Group g;
        Circle *c = new Circle();
        g.addVisualEntity(c);

        REQUIRE(g.getSize() == 1);

        WHEN( "A shape is removed with removeVisualEntity" ) {
            g.removeVisualEntity(0);

            THEN( "the size changes, but shape still exists" ) {
                REQUIRE(g.getSize() == 0);
                REQUIRE(c->getIndex() == -1);
            }
        }

        WHEN( "A shape is removed with destroyVisualEntity" ) {
            c->setRadius(509);
            g.destroyVisualEntity(0);

            THEN( "the size changes, but shape is deleted" ) {
                REQUIRE(g.getSize() == 0);
                REQUIRE(c->getRadius() != 509);
                REQUIRE(c->getIndex() < 0);
            }
        }
    }
}
