#include "catch.hpp"
#include "Circle.hpp"
#include "Group.hpp"

#include <exception>
#include <stdexcept>

TEST_CASE("getParentGroup test") {
    Group g;
    Circle *c = new Circle();
    g.addVisualEntity(c);

    REQUIRE(c->getParentGroup() == &g);
    REQUIRE(c->getIndex() == 0);
}

TEST_CASE("selfDestruct test") {

    Circle *c = new Circle();
    c->setRadius(608);

    SECTION("Kills itself using parent") {
        Group g;
        g.addVisualEntity(c);
        REQUIRE(g.getSize() == 1);

        c->selfDestruct();
        REQUIRE(c->getRadius() != 608);
        REQUIRE(g.getSize() == 0);
    }

    SECTION("Will throw exception if no parent") {
        REQUIRE_THROWS_AS(c->selfDestruct(), std::runtime_error);
    }


}

