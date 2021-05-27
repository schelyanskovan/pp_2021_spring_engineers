// Copyright 2021 Krasilnikov Alexey
#include "../../modules/task_4/krasilnikov_a_sobel_operator_std/sobel_operator_std.h"

#include <cmath>
#include <algorithm>
#include <vector>

void SobelOperator_parallel(unsigned char* image, int height, int weight) {
    std::vector<u_char> ans(height * weight);
    std::vector<std::thread> threads;
    for (int q = 1; q < 5; ++q) {
        threads.emplace_back([&, q](){
            for (int i = q; i < height - 1; i += 4) {
                for (int j = 1; j < weight - 1; ++j) {
                    auto Gy = image[(i + 1) * weight + (j - 1)] -
                              image[(i - 1) * weight + (j - 1)] +
                              2 * image[(i + 1) * weight + (j)] -
                              2 * image[(i - 1) * weight + (j)] +
                              image[(i + 1) * weight + (j + 1)] -
                              image[(i - 1) * weight + (j + 1)];
                    auto Gx = image[(i + 1) * weight + (j + 1)] -
                              image[(i - 1) * weight + (j - 1)] +
                              2 * image[(i) * weight + (j + 1)] -
                              2 * image[(i) * weight + (j - 1)] +
                              image[(i - 1) * weight + (j + 1)] -
                              image[(i + 1) * weight + (j - 1)];
                    auto pixel = round(
                            std::max(0., std::min(255., sqrt(Gy * Gy + Gx * Gx))));
                    ans[i * weight + j] = static_cast<unsigned char>(pixel);
                }
            }
        });
    }
    for (int q = 0; q < 4; ++q) {
        threads[q].join();
    }
    threads.clear();
    for (int q = 0; q < 4; ++q) {
        threads.emplace_back([&, q]() {
            for (int i = q; i < height * weight; i += 4) {
                image[i] = ans[i];
            }
        });
    }
    for (int q = 0; q < 4; ++q) {
        threads[q].join();
    }
}

void SobelOperator(unsigned char* image, int height, int weight) {
    std::vector<unsigned char> ans(height * weight);
    for (int i = 1; i < height - 1; ++i) {
        for (int j = 1; j < weight - 1; ++j) {
            auto Gy = image[(i + 1) * weight + (j - 1)] -
                      image[(i - 1) * weight + (j - 1)] +
                      2 * image[(i + 1) * weight + (j)] -
                      2 * image[(i - 1) * weight + (j)] +
                      image[(i + 1) * weight + (j + 1)] -
                      image[(i - 1) * weight + (j + 1)];
            auto Gx = image[(i + 1) * weight + (j + 1)] -
                      image[(i - 1) * weight + (j - 1)] +
                      2 * image[(i) * weight + (j + 1)] -
                      2 * image[(i) * weight + (j - 1)] +
                      image[(i - 1) * weight + (j + 1)] -
                      image[(i + 1) * weight + (j - 1)];
            auto pixel = round(
                    std::max(0., std::min(255., sqrt(Gy * Gy + Gx * Gx))));
            ans[i * weight + j] = static_cast<unsigned char>(pixel);
        }
    }
    for (int i = 0; i < height * weight; ++i) {
        image[i] = ans[i];
    }
}
