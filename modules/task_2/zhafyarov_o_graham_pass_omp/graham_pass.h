// Copyright 2021 Zhafyarov Oleg
#ifndef MODULES_TASK_2_ZHAFYAROV_O_GRAHAM_PASS_OMP_GRAHAM_PASS_H_
#define MODULES_TASK_2_ZHAFYAROV_O_GRAHAM_PASS_OMP_GRAHAM_PASS_H_

#include <omp.h>
#include <vector>

struct point {
  int x;
  int y;
};

std::vector<point> RandomVector(int size);
double Rotation(point a, point b, point c);
std::vector<size_t> GrahamPassSeq(const std::vector<point>& basisVec,
                                  int* count);
std::vector<size_t> GrahamPassOmp(const std::vector<point>& basisVec,
                                  int* count);

#endif  // MODULES_TASK_2_ZHAFYAROV_O_GRAHAM_PASS_OMP_GRAHAM_PASS_H_
