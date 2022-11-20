#include "../src/cat.h"
#include <stdexcept>

TEST(CatTest, CatContstucture)
{
    Cat c1("Lucy", 3);
    ASSERT_EQ(c1.name(), "Lucy");
    ASSERT_NEAR(c1.weight(), 3, 0.001);
}

TEST(CatTest, CatContstuctureError)
{
    ASSERT_THROW(Cat c1("Jess", 7), std::range_error);
}

TEST(CatTest, CatFeed)
{
    Cat c1("God", 5.6);
    c1.feed();
    ASSERT_NEAR(c1.weight(), 5.8, 0.001);
    c1.feed();
    ASSERT_NEAR(c1.weight(), 6.0, 0.001);
    ASSERT_THROW(c1.feed(), std::out_of_range);
}