#include "../src/cat.h"
#include "../src/toy.h"

#include <gtest/gtest.h>

TEST(CatTest, Constructor)
{
    ASSERT_THROW(Cat Olsen("", 30), std::string);
    ASSERT_THROW(Cat Lisa("Lisa", 110), std::string);
}

TEST(CatTest, CopyConstructor)
{
    Cat Adam("Adam", 22);
    Toy Orange("Orange");
    Adam.addNewToy(Orange);
    Cat Adam1(Adam);
    ASSERT_EQ(Adam1.getName(), "Adam");
    ASSERT_EQ(Adam1.getWeight(), 22);
    ASSERT_EQ(Adam1.getToy(0).getName(), "Orange");
}

TEST(CatTest, CopyAssignment)
{
    Cat Merry("Merry", 33);
    Toy Guava("Guava");
    Merry.addNewToy(Guava);
    Cat Merry1;
    Merry1 = Merry;
    ASSERT_EQ(Merry1.getName(), "Merry");
    ASSERT_EQ(Merry1.getWeight(), 33);
    ASSERT_EQ(Merry1.getToy(0).getName(), "Guava");
}

TEST(CatTest, AddNewToy)
{
    Cat Lucy("Lucy", 40);
    Toy Grape("Grape");
    Toy Box("Box");
    Lucy.addNewToy(Grape);
    Lucy.addNewToy(Box);
    ASSERT_EQ(Lucy.getToy(0).getName(), "Grape");
    ASSERT_EQ(Lucy.getToy(1).getName(), "Box");
}

TEST(CatTest, GetToy)
{
    Cat Lala("Lala", 43);
    Toy Yellow("Yellow");
    Toy Brown("Brown");
    Toy Green("Green");

    Lala.addNewToy(Yellow);
    Lala.addNewToy(Brown);
    Lala.addNewToy(Green);
    ASSERT_EQ(Lala.getToy(0).getName(), "Yellow");
    ASSERT_EQ(Lala.getToy(1).getName(), "Brown");
    ASSERT_EQ(Lala.getToy(2).getName(), "Green");
    ASSERT_THROW(Lala.getToy(3), std::string);
    ASSERT_THROW(Lala.getToy(-1), std::string);
}

TEST(CatTest, IsHeavierThan)
{
    Cat God("God", 28);
    Cat Devil("Devil", 36);
    ASSERT_FALSE(God.isHeavierThan(Devil));
}