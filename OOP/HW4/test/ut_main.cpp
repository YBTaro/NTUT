#include <gtest/gtest.h>

#include "./ut_cat.h"
#include "./ut_toy.h"

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
