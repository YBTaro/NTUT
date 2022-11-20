#include "../src/cat.h"

#include <gtest/gtest.h>

TEST(CatTest, CatName1)
{
    Cat Olsen("Olsen", 20);
    ASSERT_EQ("Olsen", Olsen.getName());
}

TEST(CatTest, CatName2)
{
    Cat John("John", 17);
    ASSERT_EQ("John", John.getName());
}

TEST(CatTest, CatWeight1)
{
    Cat Larry("Larry", 11);
    ASSERT_EQ(11, Larry.getWeight());
}

TEST(CatTest, CatWeight2)
{
    Cat Henry("Henry", 21);
    ASSERT_EQ(21, Henry.getWeight());
}

TEST(CatTest, CatAddNewToy1)
{
    Cat Lisa("Lisa", 16);
    Lisa.addNewToy("fish");
    Lisa.addNewToy("chicken");
    ASSERT_EQ("fish", Lisa.getToy(0));
    ASSERT_EQ("chicken", Lisa.getToy(1));
}

TEST(CatTest, CatAddNewToy2)
{
    Cat Leo("Leo", 13);
    Leo.addNewToy("dog");
    Leo.addNewToy("bird");
    Leo.addNewToy("tofu");
    ASSERT_EQ("dog", Leo.getToy(0));
    ASSERT_EQ("bird", Leo.getToy(1));
    ASSERT_EQ("tofu", Leo.getToy(2));
}

TEST(CatTest, CatGetToy1)
{
    Cat James("James", 20);
    James.addNewToy("apple");
    James.addNewToy("orange");
    James.addNewToy("guava");
    James.addNewToy("grape");

    ASSERT_EQ("apple", James.getToy(0));
    ASSERT_EQ("orange", James.getToy(1));
    ASSERT_EQ("guava", James.getToy(2));
    ASSERT_EQ("grape", James.getToy(3));
}

TEST(CatTest, CatGetToy2)
{
    Cat Rin("Rin", 20);
    Rin.addNewToy("ball");
    Rin.addNewToy("candy");
    Rin.addNewToy("bike");
    Rin.addNewToy("lizard");
    Rin.addNewToy("Marijuana");

    ASSERT_EQ("ball", Rin.getToy(0));
    ASSERT_EQ("candy", Rin.getToy(1));
    ASSERT_EQ("bike", Rin.getToy(2));
    ASSERT_EQ("lizard", Rin.getToy(3));
    ASSERT_EQ("Marijuana", Rin.getToy(4));
}