#include "../src/cat.h"
#include "../src/dog.h"
#include "../src/pet.h"
#include "../src/yard.h"

#include <gtest/gtest.h>
#include <vector>

class YardTest : public ::testing::Test
{
protected:
  Yard *Y= new Yard();
  Pet *p1, *p2, *p3, *p4, *p5, *p6;
  void SetUp() override
  {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Cat::amount());
    ASSERT_EQ(0, Dog::amount());
    p1 = new Cat("Lucy", 6);
    p2 = new Cat("Jack", 4);
    p3 = new Cat("John", 2.6);
    p4 = new Dog("Louis", 27);
    p5 = new Dog("Lisa", 39);
    p6 = new Dog("Kate", 33);

    Y->addPet(p1);
    Y->addPet(p2);
    Y->addPet(p3);
    Y->addPet(p4);
    Y->addPet(p5);
    Y->addPet(p6);
  }

  void TearDown() override
  {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Cat::amount());
    ASSERT_EQ(0, Dog::amount());
  }

  const double DELTA = 0.001;
};

bool weightGreaterThan4(Pet *p)
{
  return p->weight() > 4;
}
TEST_F(YardTest, PassByFunction)
{
  std::vector<Pet *> A = {p1, p4, p5, p6};
  ASSERT_EQ(Y->getPetWithCondition(weightGreaterThan4), A);
  delete Y;
}

TEST_F(YardTest, PassByLambda)
{
  std::vector<Pet *> A = {p1, p4, p5, p6};
  std::vector<Pet *> B = Y->getPetWithCondition([](Pet *p){ return p->weight() > 4; });
  ASSERT_EQ(B, A);
  delete Y;
}

class WeightGreaterThan4
{
public:
  bool operator()(Pet *p)
  {
    return p->weight() > 4;
  }
};

TEST_F(YardTest, PassByFunctor)
{
  std::vector<Pet *> A = {p1, p4, p5, p6};
  WeightGreaterThan4 WGT4;
  ASSERT_EQ(Y->getPetWithCondition(WGT4), A);
  delete Y;
}

TEST_F(YardTest, YardCopyConstructor)
{
  Yard Z(*Y);

  ASSERT_EQ(12, Pet::amount());
  ASSERT_EQ(6, Cat::amount());
  ASSERT_EQ(6, Dog::amount());

  std::vector<Pet *> A= Y->getPetWithCondition([](Pet *p){ return true;});
  std::vector<Pet *> B= Z.getPetWithCondition([](Pet *p){ return true;});

  for(int i=0;i<A.size();i++){
    ASSERT_NE(A[i],B[i]);
    ASSERT_EQ(A[i]->name(),B[i]->name());
    ASSERT_EQ(A[i]->weight(),B[i]->weight());
    ASSERT_EQ(A[i]->kind(),B[i]->kind());
  }
  delete Y;
}

TEST_F(YardTest, YardCopyAssignment)
{
  Yard Z;
  Z = *Y;

  ASSERT_EQ(12, Pet::amount());
  ASSERT_EQ(6, Cat::amount());
  ASSERT_EQ(6, Dog::amount());

  std::vector<Pet *> A= Y->getPetWithCondition([](Pet *p){ return true;});
  std::vector<Pet *> B= Z.getPetWithCondition([](Pet *p){ return true;});
  
  for(int i=0;i<A.size();i++){
    ASSERT_NE(A[i],B[i]);
    ASSERT_EQ(A[i]->name(),B[i]->name());
    ASSERT_EQ(A[i]->weight(),B[i]->weight());
    ASSERT_EQ(A[i]->kind(),B[i]->kind());
  }
  delete Y;
}

TEST_F(YardTest, DestructorTest){
  delete Y;
  ASSERT_EQ(0, Pet::amount());
  ASSERT_EQ(0, Cat::amount());
  ASSERT_EQ(0, Dog::amount());
}