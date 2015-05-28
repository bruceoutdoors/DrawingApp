#include "catch.hpp"
#include "Circle.hpp"
#include "Group.hpp"

#include <exception>
#include <stdexcept>

TEST_CASE("Circle cast test") {
    Group g;
    Circle *c = new Circle();
    g.add(c);

    VisualEntity *ve = g.get(0);
    REQUIRE(ve);

    IFillable *fillable = dynamic_cast<IFillable*>(ve);
    REQUIRE(fillable);

    ILine *line = dynamic_cast<ILine*>(ve);
    REQUIRE(line);

    Group *cg = dynamic_cast<Group*>(ve);
    REQUIRE(!cg);
}

TEST_CASE("getParentGroup test") {
    Group g;
    Circle *c = new Circle();
    g.add(c);

    REQUIRE(c->getParentGroup() == &g);
    REQUIRE(c->getIndex() == 0);
}

TEST_CASE("selfDestruct test") {

    Circle *c = new Circle();

    SECTION("Kills itself using parent") {
        Group g;
        g.add(c);
        REQUIRE(g.getSize() == 1);

        c->selfDestruct();
        REQUIRE(g.getSize() == 0);
    }

    SECTION("Will throw exception if no parent") {
        REQUIRE_THROWS_AS(c->selfDestruct(), std::runtime_error);
    }


}

