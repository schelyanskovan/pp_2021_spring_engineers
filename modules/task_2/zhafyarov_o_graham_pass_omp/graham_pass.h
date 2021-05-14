// Copyright 2021 Zhafyarov Oleg
#ifndef MODULES_TASK_2_ZHAFYAROV_O_GRAHAM_PASS_OMP_GRAHAM_PASS_H_
#define MODULES_TASK_2_ZHAFYAROV_O_GRAHAM_PASS_OMP_GRAHAM_PASS_H_

#include <omp.h>
#include <vector>
<<<<<<< HEAD

struct point {
=======
#include <utility>

struct point{
>>>>>>> e7f861fbfa7268f39b890d9b1fd24a102758d246
  int x;
  int y;
};

<<<<<<< HEAD
std::vector<point> RandomVector(int size);
double Rotation(point a, point b, point c);
std::vector<size_t> GrahamPassSeq(const std::vector<point>& basisVec,
                                  int* count);
std::vector<size_t> GrahamPassOmp(const std::vector<point>& basisVec,
                                  int* count);
=======
bool CompareVectors(const std::vector<point>& vec1,
                    const std::vector<point>& vec2);
std::vector<point> RandomVector(int size);
double Rotation(point a, point b, point c);
std::vector<point> GrahamPassSeq(const std::vector<point>& basisVec);
std::vector<point> GrahamPassOmp(const std::vector<point>& basisVec);
>>>>>>> e7f861fbfa7268f39b890d9b1fd24a102758d246

#endif  // MODULES_TASK_2_ZHAFYAROV_O_GRAHAM_PASS_OMP_GRAHAM_PASS_H_
