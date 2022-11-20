#include "../src/algo.h"
#include "../src/pet.h"
#include "../src/cat.h"
#include "../src/dog.h"
#include <vector>

class AlgoTest : public ::testing::Test
{
protected:
    Pet *p1;
    Pet *p2;
    Pet *p3;
    Pet *p4;
    Pet *p5;
    std::vector<Pet *> A;
    void SetUp() override
    {
        p1 = new Cat("Lucy", 4);
        p2 = new Cat("Jessica", 3);
        p3 = new Dog("Doge", 30);
        p4 = new Dog("Reeze", 40);
        p5 = new Dog("Johnson", 26);
        A = {p1, p2, p3, p4, p5};
    }
    void TearDown() override
    {
        // delete p1;
        // delete p2;
        // delete p3;
        // delete p4;
        // delete p5;
        for (Pet *s : A)
        {
            delete s;
        }
    }
};

bool maxweight(Pet *a, Pet *b)
{
    return a->weight() < b->weight();
}

bool longestname(Pet *a, Pet *b)
{
    return a->name().size() < b->name().size();
}

TEST_F(AlgoTest, MaxWeight)
{
    ASSERT_EQ(*maxPet(A.begin(), A.end(), maxweight), p4);
}

TEST_F(AlgoTest, LongestName)
{
    ASSERT_EQ(*maxPet(A.begin(), A.end(), longestname), p2);
}