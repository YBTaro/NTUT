#include "../src/cat.h"
#include <stdexcept>

class CatTest : public ::testing::Test {
protected:
  void SetUp() override {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Cat::amount());
  }

  void TearDown() override {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Cat::amount());
  }

  const double DELTA = 0.001;
};


TEST_F(CatTest, AmountConstructor) {
  Cat cat("Cat", 3);
  ASSERT_EQ(1, Cat::amount());
}

TEST_F(CatTest, AmountCopyConstructor) {
  Cat cat_1("Cat", 3);
  Cat cat_2 = cat_1;
  ASSERT_EQ(2, Cat::amount());
}

TEST_F(CatTest, AmountPolymorphism) {
  Pet * pet = new Cat("Cat", 3);
  ASSERT_EQ(1, Pet::amount());
  ASSERT_EQ(1, Cat::amount());
  delete pet;
}


TEST(MyCatTest, CatContstucture)
{
    Cat c1("Lucy", 3);
    ASSERT_EQ(c1.name(), "Lucy");
    ASSERT_NEAR(c1.weight(), 3, 0.001);
}

TEST(MyCatTest, CatContstuctureError)
{
    ASSERT_THROW(Cat c1("Jess", 7), std::range_error);
    ASSERT_THROW(Cat c2("Jess", 1), std::range_error);
}

TEST(MyCatTest, CatFeed)
{
    Cat c1("God", 5.6);
    c1.feed();
    ASSERT_NEAR(c1.weight(), 5.8, 0.001);
    c1.feed();
    ASSERT_NEAR(c1.weight(), 6.0, 0.001);
    ASSERT_THROW(c1.feed(), std::out_of_range);
}