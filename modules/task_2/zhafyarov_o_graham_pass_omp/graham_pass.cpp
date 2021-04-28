// Copyright 2021 Zhafyarov Oleg
#include "../../../modules/task_2/zhafyarov_o_graham_pass_omp/graham_pass.h"
#include <time.h>
#include <random>
#include <vector>

std::vector<size_t> Convert(const std::vector<point>& basisVec) {
  std::vector<size_t> result(basisVec.size());
  for (int i = 0; i < static_cast<int>(basisVec.size()); i++) {
    result[i] = i;
  }
  return result;
}

bool CompareVectors(const std::vector<point> &vec1,
                    const std::vector<point> &vec2) {
  if (vec1.size() != vec2.size()) {
    return false;
  }

  for (int i = 0; i < static_cast<int>(vec1.size()); i++) {
    if (vec1[i].x != vec2[i].x || vec1[i].y != vec2[i].y) {
      return false;
    }
  }

  return true;
}

std::vector<point> RandomVector(int size) {
  bool flag = false;
  std::vector<point> vec_tmp(size);
  std::mt19937 gen;
  gen.seed(static_cast<unsigned int>(time(0)));
  for (int i = 0; i < size; i++) {
    vec_tmp[i].x = gen() % 1700 + 100;
    vec_tmp[i].y = gen() % 900 + 100;
  }
  while (!flag) {
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if (i == j) {
          continue;
        }
        if (vec_tmp[i].x == vec_tmp[j].x &&
        vec_tmp[i].y == vec_tmp[j].y) {
          vec_tmp[i].x = gen() % 1700 + 100;
          vec_tmp[i].y = gen() % 900 + 100;
          i = 0;
          j = 0;
        }
      }
    }
    flag = true;
  }
  return vec_tmp;
}

double Rotation(point a, point b, point c) {
  return((b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x));
}

std::vector<size_t> GrahamPassSeq(const std::vector<point>& basis_vec,
                                  const std::vector<size_t>& IndexBasisVec) {
  std::vector<size_t> result_index;
  std::vector<size_t> result_index_tmp;

  std::vector<int> vec_tmp;

  int min = 0;

  for (int i = 1; i < static_cast<int>(basis_vec.size()); i++) {
    min = basis_vec.at(min).x > basis_vec.at(i).x ||
          (basis_vec.at(min).x == basis_vec.at(i).x &&
           basis_vec.at(min).y > basis_vec.at(i).y)
          ? i
          : min;
  }

  vec_tmp.push_back(min);

  for (int i = 0; i < static_cast<int>(basis_vec.size()); i++) {
    if (i == min) {
      continue;
    }
    vec_tmp.push_back(i);
  }

  for (int i = 2; i < static_cast<int>(basis_vec.size()); i++) {
    int j = i;
    while (j > 1 && Rotation(basis_vec.at(min), basis_vec.at(vec_tmp.at(j - 1)),
                             basis_vec.at(vec_tmp.at(j))) < 0) {
      std::swap(vec_tmp.at(j), vec_tmp.at(j - 1));
      j--;
    }
  }

  result_index.push_back(vec_tmp.at(0));
  result_index.push_back(vec_tmp.at(1));

  for (int i = 2; i < static_cast<int>(basis_vec.size()); i++) {
    while (Rotation(basis_vec.at(result_index.at(result_index.size() - 2)),
                    basis_vec.at(result_index.at(result_index.size() - 1)),
                    basis_vec.at(vec_tmp.at(i))) <= 0) {
      if (result_index.size() <= 2) {
        break;
      }
      result_index.pop_back();
    }
    result_index.push_back(vec_tmp.at(i));
  }

  for (size_t index : result_index) {
    result_index_tmp.push_back(IndexBasisVec[index]);
  }

  return result_index_tmp;
}


std::vector<size_t> GrahamPassOmp(const std::vector<point>& basis_vec,
                                  const std::vector<size_t>& IndexBasisVec) {
  std::vector<size_t> result_after;
  std::vector<size_t> result_index;

  int block = static_cast<int>(basis_vec.size()) / omp_get_max_threads();
  int remainder = static_cast<int>(basis_vec.size()) % omp_get_max_threads();

  if (4 * omp_get_max_threads() >= static_cast<int>(basis_vec.size())) {
    result_index = GrahamPassSeq(basis_vec, IndexBasisVec);
    return result_index;
  }

#pragma omp parallel
  {
    int id = omp_get_thread_num();
    std::vector<size_t> index_thread;
    std::vector<point> result_thread;
    std::vector<size_t> result_tmp_index;

    if (id == 0) {
      result_thread.reserve(block + remainder);
      result_thread.insert(result_thread.begin(), basis_vec.begin(),
                           basis_vec.begin() + block + remainder);
      index_thread.reserve(block + remainder);
      index_thread.insert(index_thread.begin(), IndexBasisVec.begin(),
                          IndexBasisVec.begin() + block + remainder);
    } else {
      result_thread.reserve(basis_vec.size() / omp_get_num_threads());
      result_thread.insert(result_thread.begin(),
                           basis_vec.begin() + remainder + id * block,
                           basis_vec.begin() + remainder + id * block + block);
      index_thread.reserve(basis_vec.size() / omp_get_num_threads());
      index_thread.insert(index_thread.begin(),
                          IndexBasisVec.begin() + remainder + id * block,
                          IndexBasisVec.begin() + remainder +
                          id * block + block);
    }

#pragma omp barrier

    result_tmp_index = GrahamPassSeq(result_thread, index_thread);

#pragma omp critical
    {
      for (size_t result_from_tmp : result_tmp_index) {
        result_after.push_back(result_from_tmp);
      }
    }
  }

  std::vector<point> result(result_after.size());
  for (int i = 0; i < static_cast<int>(result_after.size()); i++) {
    result[i] = basis_vec[result_after[i]];
  }

  std::vector<size_t> result_index_all;

  result_index_all = GrahamPassSeq(result, result_after);

  return result_index_all;
}
