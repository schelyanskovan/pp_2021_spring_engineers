// Copyright 2021 Zhafyarov Oleg
#ifndef MODULES_TASK_2_ZHAFYAROV_O_GRAHAM_PASS_OMP_GRAHAM_PASS_H_
#define MODULES_TASK_2_ZHAFYAROV_O_GRAHAM_PASS_OMP_GRAHAM_PASS_H_

#include <omp.h>
#include <vector>

bool CompareVectors(const std::vector<std::pair<int,int>>& vec1,
                    const std::vector<std::pair<int,int>>& vec2);
std::vector<std::pair<int,int>> RandomVector(int size);
double Rotation(std::pair<int,int> a, std::pair<int,int> b,
                std::pair<int,int> c);
std::vector<std::pair<int,int>> GrahamPassSeq(const std::vector<std::pair<int,int>>& basisVec);
std::vector<std::pair<int,int>> GrahamPassOmp(const std::vector<std::pair<int,int>>& basisVec);

#endif  // MODULES_TASK_2_ZHAFYAROV_O_GRAHAM_PASS_OMP_GRAHAM_PASS_H_
