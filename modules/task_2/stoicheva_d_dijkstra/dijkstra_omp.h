// Copyright 2021 Stoicheva Darya

#ifndef MODULES_TASK_2_STOICHEVA_D_DIJKSTRA_OMP_H_
#define MODULES_TASK_2_STOICHEVA_D_DIJKSTRA_OMP_H_

#include <vector>
#include <string>

std::vector<int> getRandomVector(int  sz);
int getParallelOperations(std::vector<int> vec, const std::string& ops);
int getSequentialOperations(std::vector<int> vec, const std::string& ops);

#endif  // MODULES_TASK_2_STOICHEVA_D_DIJKSTRA_OMP_H_
