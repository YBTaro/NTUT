#include "../src/dog.h"
#include <stdexcept>

class DogTest : public ::testing::Test
{
protected:
  void SetUp() override
  {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Dog::amount());
  }

  void TearDown() override
  {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Dog::amount());
  }

  const double DELTA = 0.001;
};

TEST_F(DogTest, AmountConstructor)
{
  Dog dog("Dog", 30);
  ASSERT_EQ(1, Dog::amount());
}

TEST_F(DogTest, AmountCopyConstructor)
{
  Dog dog_1("Dog", 30);
  Dog dog_2 = dog_1;
  ASSERT_EQ(2, Dog::amount());
}

TEST_F(DogTest, AmountPolymorphism)
{
  Pet *pet = new Dog("Dog", 30);
  ASSERT_EQ(1, Pet::amount());
  ASSERT_EQ(1, Dog::amount());
  delete pet;
}

TEST(MyDogTest, DogContstucture)
{
  Dog d1("Jack", 20);
  ASSERT_EQ(d1.name(), "Jack");
  ASSERT_NEAR(d1.weight(), 20, 0.001);
}

TEST(MyDogTest, DogContstuctureError)
{
  ASSERT_THROW(Dog d1("Leo", 7), std::range_error);
  ASSERT_THROW(Dog d2("Leo", 56), std::range_error);
}

TEST(MyDogTest, DogFeed)
{
  Dog d1("Lab", 48);
  d1.feed();
  ASSERT_NEAR(d1.weight(), 48.8, 0.001);
  d1.feed();
  ASSERT_NEAR(d1.weight(), 49.6, 0.001);
  ASSERT_THROW(d1.feed(), std::out_of_range);
}