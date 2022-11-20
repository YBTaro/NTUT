#include "../src/dog.h"
#include <stdexcept>

TEST(DogTest, DogContstucture)
{
    Dog d1("Jack", 20);
    ASSERT_EQ(d1.name(), "Jack");
    ASSERT_NEAR(d1.weight(), 20, 0.001);
}

TEST(DogTest, DogContstuctureError)
{
    ASSERT_THROW(Dog d1("Leo", 7), std::range_error);
}

TEST(DogTest, DogFeed)
{
    Dog d1("Lab", 48);
    d1.feed();
    ASSERT_NEAR(d1.weight(), 48.8, 0.001);
    d1.feed();
    ASSERT_NEAR(d1.weight(), 49.6, 0.001);
    ASSERT_THROW(d1.feed(), std::out_of_range);
}