#include "../src/toy.h"

#include <gtest/gtest.h>

TEST(ToyTest, ToyName)
{
    Toy Apple("Apple");
    ASSERT_EQ("Apple", Apple.getName());
}