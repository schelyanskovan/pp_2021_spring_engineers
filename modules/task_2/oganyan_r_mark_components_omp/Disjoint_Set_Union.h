// Copyright 2021 Oganyan Robert

#ifndef MODULES_TASK_2_OGANYAN_R_MARK_COMPONENTS_OMP_DISJOINT_SET_UNION_H_
#define MODULES_TASK_2_OGANYAN_R_MARK_COMPONENTS_OMP_DISJOINT_SET_UNION_H_

#include <vector>
#include <utility>

template<typename T>
class Disjoint_Set_Union {
 private:
    std::vector<T> rank;
    std::vector<T> parent;

 public:
    explicit Disjoint_Set_Union(int size) : rank(size), parent(size) {
    }

    void make_set(int v) {
        parent[v] = v;
        rank[v] = 0;
    }

    void Init() {
        for (std::size_t i = 0; i < rank.size(); ++i) {
            make_set(i);
        }
    }

    void Init(int size) {
        rank.resize(size);
        parent.resize(size);
        for (int i = 0; i < size; ++i) {
            make_set(i);
        }
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (rank[a] < rank[b])
                std::swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                ++rank[a];
        }
    }

    const std::vector<T> get_rank() {
        return this->rank;
    }

    const std::vector<T> get_parent() {
        return this->parent;
    }
};

#endif  //  MODULES_TASK_2_OGANYAN_R_MARK_COMPONENTS_OMP_DISJOINT_SET_UNION_H_
