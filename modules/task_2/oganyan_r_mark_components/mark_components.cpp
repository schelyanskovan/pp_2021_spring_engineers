// Copyright 2021 Oganyan Robert

#include <iostream>
#include <omp.h>
#include "../../modules/task_1/oganyan_r_mark_components/mark_components.h"

static const std::vector<std::pair<int, int>> directions{
        // {-1, -1},
        {-1, 0},
        //  {-1, 1},
        {0,  -1},
        {0,  1},
        // {1,  -1},
        {1,  0},
        // {1,  1},
};

void Link_paral(std::vector<int> *img, int *number, int width, int height, std::map<int, std::vector<int>>* dsu) {
    std::vector<int> used(width * height, 0);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if ((*img)[i*width + j] == 0) {
                continue;
            }
            used[i * width + j] = 1;
            for (auto &neighbor: directions) {
                if (i + neighbor.first >= height || i + neighbor.first < 0
                    || j + neighbor.second >= width || j + neighbor.second < 0) {
                    continue;
                }
                if ((*img)[(i + neighbor.first) * width + j + neighbor.second] == 0) {
                    continue;
                }
                int cur_color = (*img)[i * width + j];
                int neighbour_color = (*img)[(i + neighbor.first) * width + j + neighbor.second];

                if (!used[(i + neighbor.first) * width + j + neighbor.second]) {
                    if ( neighbour_color != cur_color) {
                        for (auto elem: (*dsu)[neighbour_color]) {
                            used[elem] = 1;
                            (*img)[elem] = cur_color;

                        }
                        (*number) --;
                    }
                }
            }
        }
    }

}


void bfs(std::vector<int> *img, std::pair<int, int> start,
         int *number, int width, int height, std::map<int, std::vector<int>> *dsu, bool is_paral) {
    if ((*img)[start.first * width + start.second] != 1) {
        return;
    }
    std::queue<std::pair<int, int>> q;
    q.push({start});
    if (is_paral) {
        (*dsu)[*number + 1].push_back(start.first * width + start.second);
    }
    (*img)[start.first * width + start.second] = ++(*number);
    while (!q.empty()) {
        auto cur{q.front()};
        q.pop();
        for (auto &neighbor : directions) {
            if (cur.first + neighbor.first >= height || cur.first + neighbor.first < 0
                || cur.second + neighbor.second >= width || cur.second + neighbor.second < 0) {
                continue;
            }
            if ((*img)[(cur.first + neighbor.first) * width + cur.second + neighbor.second] == 1) {
                q.push({(cur.first + neighbor.first), cur.second + neighbor.second});
                if (is_paral) {
                    if ((*dsu)[*number].empty()) {
                        (*dsu)[*number].reserve(1000);
                    }
                    (*dsu)[*number].push_back((cur.first + neighbor.first) * width + cur.second + neighbor.second);
                }
                (*img)[(cur.first + neighbor.first) * width + cur.second + neighbor.second] = (*number);
            }
        }
    }
    return;
}


std::pair<std::vector<int>, int> MarkComponentsSeq(std::vector<int> *img, int height, int width) {
    if ((*img).size() == 0) {
        throw std::invalid_argument("Size of the image cant be negative");
    }
    if (static_cast<int>((*img).size()) != width * height) {
        throw std::invalid_argument("Size of the image is not correct");
    }
    auto img_new = *img;
    int count_comp{1};
    for (int i{0}; i < height; ++i) {
        for (int j{0}; j < width; ++j) {
            bfs(&img_new, {i, j}, &count_comp, width, height);
        }
    }
    return {img_new, count_comp - 1};
}


std::pair<std::vector<int>, int> MarkComponentsPar(std::vector<int> *img, int height, int width) {
    if ((*img).size() == 0) {
        throw std::invalid_argument("Size of the image cant be negative");
    }
    if (static_cast<int>((*img).size()) != width * height) {
        throw std::invalid_argument("Size of the image is not correct");
    }
    auto img_new = *img;
    int count_comp{1};
    omp_set_num_threads(4);
    std::map<int, std::vector<int>> dsu;
#pragma omp parallel default(none) shared(img_new, width, height, count_comp, dsu)
    {
#pragma omp for
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                bfs(&img_new, {i, j}, &count_comp, width, height, &dsu, true);
            }
        }
    }

    Link_paral(&img_new, &count_comp, width, height, &dsu);

    return {img_new, count_comp - 1};
}


