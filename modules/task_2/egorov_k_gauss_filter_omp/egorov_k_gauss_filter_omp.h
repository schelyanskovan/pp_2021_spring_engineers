// Copyright 2018 Nesterov Alexander
#ifndef MODULES_TEST_TASKS_TEST_OMP_OPS_OMP_H_
#define MODULES_TEST_TASKS_TEST_OMP_OPS_OMP_H_

#include <vector>
#include <string>

std::vector<int> getRandomVector(int  sz);
int clamp(int value, int min, int max);
std::vector<float> calculateKernel3x3(float sigma);
int pColourCalculation(const std::vector<int> &img, int w, int h,
	int x, int y, std::vector<float> kernel);
std::vector<int> filterApply(const std::vector<int> &img,
	int w, int h, float sigma);
std::vector<int> filterApplyParallel(const std::vector<int> &img,
	int w, int h, float sigma);

#endif  // MODULES_TEST_TASKS_TEST_OMP_OPS_OMP_H_
