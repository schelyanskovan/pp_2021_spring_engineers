// Copyright 2021 Zhafyarov Oleg
#include "../../../modules/task_2/zhafyarov_o_graham_pass_omp/graham_pass.h"
#include <time.h>
#include <random>
#include <vector>

bool CompareVectors(const std::vector<std::pair<int,int>> &vec1,
                    const std::vector<std::pair<int,int>> &vec2) {
  if (vec1.size() != vec2.size()) {
    return false;
  }

  for (int i = 0; i < static_cast<int>(vec1.size()); i++) {
    if (vec1[i].first != vec2[i].first || vec1[i].second != vec2[i].second) {
      return false;
    }
  }

  return true;
}

std::vector<std::pair<int,int>> RandomVector(int size) {
  bool flag = false;
  std::vector<std::pair<int,int>> vec_tmp(size);
  std::mt19937 gen;
  gen.seed(static_cast<unsigned int>(time(0)));
  for (int i = 0; i < size; i++) {
    vec_tmp[i].first = gen() % 1700 + 100;
    vec_tmp[i].second = gen() % 900 + 100;
  }
  while (!flag) {
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if (i == j) {
          continue;
        }
        if (vec_tmp[i].first == vec_tmp[j].first && vec_tmp[i].second == vec_tmp[j].second) {
          vec_tmp[i].first = gen() % 1700 + 100;
          vec_tmp[i].second = gen() % 900 + 100;
          i = 0;
          j = 0;
        }
      }
    }
    flag = true;
  }
  return vec_tmp;
}

double Rotation(std::pair<int,int> a, std::pair<int,int> b,
                std::pair<int,int> c) {
  return((b.first - a.first) * (c.second - b.second) - (b.second - a.second) * (c.first - b.first));
}

std::vector<std::pair<int,int>> GrahamPassSeq(const std::vector<std::pair<int,int>>& basis_vec) {
    std::vector<std::pair<int,int>> result_point;

    std::vector<size_t> result_index;

    std::vector<int> vec_tmp;

    int min = 0;

    for (int i = 1; i < static_cast<int>(basis_vec.size()); i++) {
        min = basis_vec.at(min).first > basis_vec.at(i).first ||
              (basis_vec.at(min).first == basis_vec.at(i).first &&
               basis_vec.at(min).second > basis_vec.at(i).second)
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
        while (j > 1 && Rotation(basis_vec.at(min),
                                 basis_vec.at(vec_tmp.at(j - 1)),
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
        result_point.push_back(basis_vec[index]);
    }

    return result_point;
}


std::vector<std::pair<int,int>> GrahamPassOmp(const std::vector<std::pair<int,int>>& basis_vec) {
    std::vector<std::pair<int,int>> result_point;
    std::vector<size_t> result_index;
    std::vector<std::pair<int,int>> result;

    int block = static_cast<int>(basis_vec.size()) / omp_get_max_threads();
    int remainder = static_cast<int>(basis_vec.size()) % omp_get_max_threads();

    if (4 * omp_get_max_threads() >= static_cast<int>(basis_vec.size())) {
        result_point = GrahamPassSeq(basis_vec);
        return result_point;
    }

    std::vector<int> vec_tmp(basis_vec.size());

#pragma omp parallel
    {
        int id = omp_get_thread_num();
        std::vector<std::pair<int,int>> result_thread;
        std::vector<std::pair<int,int>> result_tmp_point;

        if (id == 0) {
            result_thread.reserve(block + remainder);
            result_thread.insert(result_thread.begin(), basis_vec.begin(),
                                 basis_vec.begin() + block + remainder);
        } else {
            result_thread.reserve(basis_vec.size() / omp_get_num_threads());
            result_thread.insert(result_thread.begin(),
                                 basis_vec.begin() + remainder + id * block,
                                 basis_vec.begin() + remainder +
                                 id * block + block);
        }

#pragma omp barrier

        result_tmp_point = GrahamPassSeq(result_thread);

#pragma omp critical
        {
            for (std::pair<int,int> result_from_tmp : result_tmp_point) {
                result_point.push_back(result_from_tmp);
            }
        }
    }

    result = GrahamPassSeq(result_point);

    return result;
}
