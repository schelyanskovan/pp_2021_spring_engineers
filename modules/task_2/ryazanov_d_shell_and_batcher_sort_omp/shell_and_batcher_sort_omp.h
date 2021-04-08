// Copyright 2021 Dmitry Ryazanov
#ifndef MODULES_TASK_2_RYAZANOV_D_SHELL_AND_BATCHER_SORT_OMP_SHELL_AND_BATCHER_SORT_OMP_H_
#define MODULES_TASK_2_RYAZANOV_D_SHELL_AND_BATCHER_SORT_OMP_SHELL_AND_BATCHER_SORT_OMP_H_

#include <omp.h>
#include <vector>
#include <algorithm>
#include <stdexcept>

std::vector<int> getRandomVector(int sz);
std::vector<int> SortShell(const std::vector<int>& vec);
std::vector<int> SortShellOMP(const std::vector<int>& vec);
void print(std::vector<int> const& a);
std::vector<int> sh(const std::vector<int>& vec, int l, int r);
std::vector<int> uns(const std::vector<int>& vec, int l, int r);
std::vector<int> unsOMP(const std::vector<int>& vec, int l, int r);
std::vector<int> BatcherSort(const std::vector<int>& vec);
std::vector<int> BatcherSortOMP(const std::vector<int>& vec);


#endif  // MODULES_TASK_2_RYAZANOV_D_SHELL_AND_BATCHER_SORT_OMP_SHELL_AND_BATCHER_SORT_OMP_H_
