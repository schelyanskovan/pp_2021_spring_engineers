// Copyright 2021 Stoicheva Darya

#ifndef MODULES_TASK_2_STOICHEVA_D_DIJKSTRA_DIJKSTRA_OMP_H_
#define MODULES_TASK_2_STOICHEVA_D_DIJKSTRA_DIJKSTRA_OMP_H_

#include <vector>
#include <string>
#include <random>
#include <limits>

// #define DEBUG_PRINT

std::vector<int> dijkstra_omp(const std::vector<int>& graph, int start, int end);
void print_graph(std::vector<int> graph, const size_t points, std::string prefix = "");
void print_vector(const std::vector<int> vector, const size_t size, const std::string prefix = {},
    const std::string label = {}, std::ostream& out = std::cout);

template<typename T>
void print_vector(const std::vector<T> vector, const size_t size, const std::string prefix = {},
    const std::string label = {}, std::ostream& out = std::cout);
std::vector<int> dijkstra(const std::vector<int>& graph, int start, int end);
std::vector<int> getRandomVector(int  sz);
int getParallelOperations(std::vector<int> vec, const std::string& ops);
int getSequentialOperations(std::vector<int> vec, const std::string& ops);

#endif  // MODULES_TASK_2_STOICHEVA_D_DIJKSTRA_DIJKSTRA_OMP_H_
