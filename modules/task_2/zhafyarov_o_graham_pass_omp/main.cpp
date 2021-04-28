// Copyright 2021 Zhafyarov Oleg
#include <gtest/gtest.h>
#include <vector>
#include "./graham_pass.h"

TEST(OpenMP, Six_Point_Check_Omp) {
  std::vector<point> vec = {{1, 5}, {4, 8}, {8, 2},
                                  {9, 3}, {1, 8}, {7, 7}};
  std::vector<size_t> index_point = Convert(vec);
  std::vector<size_t> result = GrahamPassOmp(vec, index_point);
  std::vector<point> compare = {{1, 5}, {8, 2}, {9, 3},
                                      {7, 7}, {4, 8}, {1, 8}};
  std::vector<point> result_point(result.size());
  for (int i = 0; i < static_cast<int>(result.size()); i++) {
    result_point[i] = vec[result[i]];
  }
  bool flag = CompareVectors(result_point, compare);
  ASSERT_EQ(flag, true);
}

TEST(OpenMP, Nine_Point_Check_Omp) {
  std::vector<point> vec = { {1, 5}, {4, 8},
                                           {8, 2}, {9, 3}, {1, 8},
    {7, 7}, {5, 5}, {2, 1}, {11, 9} };
  std::vector<size_t> index_point = Convert(vec);
  std::vector<size_t> result = GrahamPassOmp(vec, index_point);
  std::vector<point> compare = {{1, 5}, {2, 1}, {8, 2},
                                      {9, 3}, {11, 9}, {1, 8}};
  std::vector<point> result_point(result.size());
  for (int i = 0; i < static_cast<int>(result.size()); i++) {
    result_point[i] = vec[result[i]];
  }
  bool flag = CompareVectors(result_point, compare);
  ASSERT_EQ(flag, true);
}

TEST(OpenMP, Count_Check_Omp) {
  std::vector<point> vec = { {1, 1}, {1, 4},
                                           {4, 1}, {4, 4}, {2, 2}};
  std::vector<size_t> index_point = Convert(vec);
  int count_tmp = 4;
  std::vector<size_t> result = GrahamPassOmp(vec, index_point);
  ASSERT_EQ(result.size(), count_tmp);
}

TEST(OpenMP, x100_Points_Omp) {
  int size = 100;
  std::vector<point> vec = RandomVector(size);
  std::vector<size_t> index_point = Convert(vec);
  std::vector<size_t> result = GrahamPassOmp(vec, index_point);
  ASSERT_GT(static_cast<int>(result.size()), 0);
}

TEST(OpenMP, x300_Points_Omp) {
  int size = 300;
  std::vector<point> vec = RandomVector(size);
  std::vector<size_t> index_point = Convert(vec);
  std::vector<size_t> result = GrahamPassOmp(vec, index_point);
  ASSERT_GT(static_cast<int>(result.size()), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
