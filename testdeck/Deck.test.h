#include "catch.hpp"

// The fixture for testing class Foo.
class DeckTest {

protected:

    // You can do set-up work for each test here.
    DeckTest();

    // You can do clean-up work that doesn't throw exceptions here.
    virtual ~DeckTest();

    virtual void SetUp();

    virtual void TearDown();
};