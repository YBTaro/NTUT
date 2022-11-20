#include "../src/vector_space.h"

const double DELTA = 0.001;

// TEST example below.
// Using 'EXPECT' instead of 'ASSERT' here is because if 'ASSERT' fails,
// the delete statement will NOT be executed, which causes memory leak.

TEST(VectorTest, add_TA) {
  double u[3] = {1, 2, 3};
  double v[3] = {1.5, 2.5, 3.5};

  double * result = add(u, 3, v, 3);

  EXPECT_NEAR(2.5, result[0], DELTA);
  EXPECT_NEAR(4.5, result[1], DELTA);
  EXPECT_NEAR(6.5, result[2], DELTA);

  delete [] result;   // heap allocation in 'add'
}

TEST(VectorTest, scale_TA) {
  double u[3] = {1.5, 2.5, 3.5};

  double * result = scale(u, 3, 1.2);

  EXPECT_NEAR(1.8, result[0], DELTA);
  EXPECT_NEAR(3.0, result[1], DELTA);
  EXPECT_NEAR(4.2, result[2], DELTA);

  delete [] result;  // heap allocation in 'scale'
}

TEST(VectorTest, add_1){
  double u[3]={2.3, 3.1, 6.0};
  double v[3]={1.0, 2.0, 3.0};
  double *result=add(u,3,v,3);

  ASSERT_NEAR(3.3, result[0], DELTA);
  ASSERT_NEAR(5.1, result[1], DELTA);
  ASSERT_NEAR(9.0, result[2], DELTA);

  delete [] result;
}

TEST(VectorTest, add_2){
  double u[4]={3.2, 4.0, 1.0, 1.0};
  double v[4]={2.2, 2.0, 3.1, 2.0};
  double *result=add(u,4,v,4);

  ASSERT_NEAR(5.4, result[0], DELTA);
  ASSERT_NEAR(6.0, result[1], DELTA);
  ASSERT_NEAR(4.1, result[2], DELTA);
  ASSERT_NEAR(3.0, result[3], DELTA);

  delete [] result;
}

TEST(VectorTest, add_dif_dim){
  double u[4]={3.2, 4.0, 1.0, 1.0};
  double v[3]={2.2, 2.0, 3.1};

  ASSERT_THROW( add(u,4,v,3), std::string);
}

TEST(VectorTest, add_negative){
  double u[4]={3.2, 4.0, 1.0, 1.0};
  double v[3]={2.2, 2.0, 3.1};

  ASSERT_THROW( add(u,-2,v,3), std::string);
}

TEST(VectorTest, sacle_1){
  double u[3]={1.0,2.0,3.0};
  double *result=scale(u,3,2);

  ASSERT_NEAR(2.0, result[0], DELTA);
  ASSERT_NEAR(4.0, result[1], DELTA);
  ASSERT_NEAR(6.0, result[2], DELTA);

  delete [] result;
}

TEST(VectorTest, sacle_2){
  double u[4]={1.3, 4.5, 2.3, 2.0};
  double *result=scale(u,4,4);

  ASSERT_NEAR(5.2, result[0], DELTA);
  ASSERT_NEAR(18.0, result[1], DELTA);
  ASSERT_NEAR(9.2, result[2], DELTA);
  ASSERT_NEAR(8.0, result[3], DELTA);

  delete [] result;
}


TEST(VectorTest, sacle_negative){
  double u[2]={1.0, 2.0};
  
  ASSERT_THROW( scale(u,0,3), std::string);
}
