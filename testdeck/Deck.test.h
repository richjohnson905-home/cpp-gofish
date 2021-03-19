
// The fixture for testing class Foo.
class DeckTestFixture {

protected:

    // You can do set-up work for each test here.
    DeckTestFixture();

    // You can do clean-up work that doesn't throw exceptions here.
    virtual ~DeckTestFixture();

    virtual void SetUp();

    virtual void TearDown();

    Deck m_deck;
};