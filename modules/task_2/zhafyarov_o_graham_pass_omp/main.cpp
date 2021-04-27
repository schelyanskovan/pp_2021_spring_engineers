// Copyright 2021 Zhafyarov Oleg
#include <gtest/gtest.h>
#include <vector>
#include "./graham_pass.h"

TEST(OpenMP, Six_Point_Check_Omp) {
  const std::vector<point> vec = {{1, 5}, {4, 8}, {8, 2},
                                  {9, 3}, {1, 8}, {7, 7}};
  std::vector<point> result;
  result = GrahamPassOmp(vec);
  const std::vector<point> compare = {{1, 5}, {8, 2}, {9, 3},
                                      {7, 7}, {4, 8}, {1, 8}};
  const bool flag = CompareVectors(result, compare);
  ASSERT_EQ(flag, true);
}

TEST(OpenMP, Nine_Point_Check_Omp) {
  const std::vector<point> vec = { {1, 5}, {4, 8}, {8, 2}, {9, 3}, {1, 8},
    {7, 7}, {5, 5}, {2, 1}, {11, 9} };
  std::vector<point> result;
  result = GrahamPassOmp(vec);
  const std::vector<point> compare = {{1, 5}, {2, 1}, {8, 2},
                                      {9, 3}, {11, 9}, {1, 8}};
  const bool flag = CompareVectors(result, compare);
  ASSERT_EQ(flag, true);
}

TEST(OpenMP, Count_Check_Omp) {
  const std::vector<point> vec = { {1, 1}, {1, 4}, {4, 1}, {4, 4}, {2, 2}};
  std::vector<point> result;
  int count_tmp = 4;
  result = GrahamPassOmp(vec);
  ASSERT_EQ(result.size(), count_tmp);
}

TEST(OpenMP, Negative_Vector_Check) {
  ASSERT_ANY_THROW(std::vector<point> vec = RandomVector(-1));
}

TEST(OpenMP, Many_Points_Omp) {
  int size = 100;
  const std::vector<point> vec = RandomVector(size);
  std::vector<point> result;
  result = GrahamPassOmp(vec);
  ASSERT_GT(static_cast<int>(result.size()), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
