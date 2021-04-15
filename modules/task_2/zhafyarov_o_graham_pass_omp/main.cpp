// Copyright 2021 Zhafyarov Oleg
#include <gtest/gtest.h>
#include <vector>
#include "./graham_pass.h"

TEST(OpenMP, Six_Point_Check_Omp) {
  std::vector<point> vec = {{1, 5}, {4, 8}, {8, 2}, {9, 3}, {1, 8}, {7, 7}};
  std::vector<size_t> result;
  int count = 0;
  result = GrahamPassOmp(vec, &count);
  std::vector<size_t> compare = { 0, 2, 3, 5, 1, 4 };
  ASSERT_EQ(compare, result);
}

TEST(OpenMP, Nine_Point_Check_Omp) {
  std::vector<point> vec = { {1, 5}, {4, 8}, {8, 2}, {9, 3}, {1, 8},
    {7, 7}, {5, 5}, {2, 1}, {11, 9} };
  std::vector<size_t> result;
  int count = 0;
  result = GrahamPassOmp(vec, &count);
  std::vector<size_t> compare = { 0, 7, 2, 3, 8, 4 };
  ASSERT_EQ(compare, result);
}

TEST(OpenMP, Count_Check_Omp) {
  std::vector<point> vec = { {1, 1}, {1, 4}, {4, 1}, {4, 4}, {2, 2}};
  std::vector<size_t> result;
  int count = 0;
  int count_tmp = 4;
  result = GrahamPassOmp(vec, &count);
  ASSERT_EQ(count, count_tmp);
}

TEST(OpenMP, Negative_Vector_Check) {
  ASSERT_ANY_THROW(std::vector<point> vec = RandomVector(-1));
}

TEST(OpenMP, Test_Time_Seq_And_Omp) {
  int size = 3000;
  int count1 = 0;
  int count2 = 0;
  std::vector<point> vec = RandomVector(size);
  std::vector<size_t> result1;
  std::vector<size_t> result2;

  double start = omp_get_wtime();
  result1 = GrahamPassOmp(vec, &count1);
  double end = omp_get_wtime();
  std::cout << "Omp = " << end - start << std::endl;

  start = omp_get_wtime();
  result2 = GrahamPassSeq(vec, &count2);
  end = omp_get_wtime();
  std::cout << "Seq = " << end - start << std::endl;

  ASSERT_GT(count1, 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
