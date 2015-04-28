#include "catch.hpp"
#include "Group.hpp"
#include "Circle.hpp"

SCENARIO("Visual Entities are added to a Group", "[Group]") {
    Group *g = new Group();
    GIVEN("A new empty Group") {
        REQUIRE(g->getSize() == 0);
    }

    GIVEN("Added stuff") {
        Circle *c = new Circle();
        g->addVisualEntity(c);
        REQUIRE(g->getSize() == 1);
    }

    delete g;
}

