#include "catch.hpp"
#include "CommandStack.hpp"
#include <string>

int globalVariable;
class TestCommand : public Command {
public:
    TestCommand(int t) : m_t(t) {}
    void execute() override {
        prev = globalVariable;
        globalVariable = m_t;
    }
    void undo()    override {
        globalVariable = prev;
    }

private:
    int m_t;
    int prev;
};

TEST_CASE("Command Stack Test") {
    globalVariable = 0;
    CommandStack *cs = &CommandStack::getInstance();
    cs->clear();

    SECTION("Add a command") {
        TestCommand *c = new TestCommand(24);
        c->execute();
        c->addtoCommandStack();

        REQUIRE(globalVariable == 24);
        REQUIRE(cs->getSize() == 1);
    }

    SECTION("Move up and down the stack") {
        TestCommand *c1 = new TestCommand(24);
        TestCommand *c2 = new TestCommand(34);
        TestCommand *c3 = new TestCommand(44);
        TestCommand *c4 = new TestCommand(54);

        c1->execute();
        c2->execute();
        c3->execute();
        c4->execute();

        c1->addtoCommandStack();
        c2->addtoCommandStack();
        c3->addtoCommandStack();
        c4->addtoCommandStack();

        REQUIRE(globalVariable == 54);
        cs->undo();
        REQUIRE(globalVariable == 44);
        cs->undo();
        REQUIRE(globalVariable == 34);
        cs->undo();
        REQUIRE(globalVariable == 24);
        cs->redo();
        REQUIRE(globalVariable == 34);
        REQUIRE(cs->getSize() == 4);
    }

    SECTION("Adding a command when current in not last removes existing history") {
        TestCommand *c1 = new TestCommand(24);
        TestCommand *c2 = new TestCommand(34);
        TestCommand *c3 = new TestCommand(44);
        TestCommand *c4 = new TestCommand(54);

        c1->execute();
        c2->execute();
        c3->execute();
        c4->execute();

        c1->addtoCommandStack();
        c2->addtoCommandStack();
        c3->addtoCommandStack();
        c4->addtoCommandStack();

        REQUIRE(cs->getSize() == 4);

        cs->undo();
        cs->undo();
        cs->undo();

        REQUIRE(cs->getSize() == 4);

        TestCommand *c5 = new TestCommand(999);
        c5->execute();
        REQUIRE(globalVariable == 999);
        INFO("Adding this command to stack wipes out commands on top of the current");
        c5->addtoCommandStack();

        REQUIRE(cs->getSize() == 2);
        cs->undo();
        cs->undo();
        REQUIRE(globalVariable == 0);
    }

    SECTION("Bla bla bla") {
        TestCommand *c1 = new TestCommand(24);
        TestCommand *c2 = new TestCommand(34);

        c1->addtoCommandStack();
        c1->execute();

        REQUIRE(globalVariable == 24);
        cs->undo();
        REQUIRE(globalVariable == 0);
        REQUIRE(cs->getSize() == 1);

        c2->addtoCommandStack();
        c2->execute();

        REQUIRE(cs->getSize() == 1);
        REQUIRE(globalVariable == 34);
        cs->undo();
        REQUIRE(globalVariable == 0);


    }
}
