// Copyright 2021 Oganyan Robert

#include <gtest/gtest.h>
#include <vector>
#include <omp.h>
#include "../../modules/task_1/oganyan_r_mark_components/mark_components.h"


TEST(Comparing_to_a_sample, rectangle_image) {
    int width = 3;
    int height = 5;
    std::vector<int> source_image{
            0, 1, 1,
            0, 0, 0,
            1, 1, 1,
            0, 1, 0,
            0, 0, 0,
    };
    std::vector<int> result_image{
            0, 2, 2,
            0, 0, 0,
            3, 3, 3,
            0, 3, 0,
            0, 0, 0,
    };
    std::pair<std::vector<int>, int> res_image;
    ASSERT_NO_THROW(res_image = MarkComponentsSeq(&source_image, height, width));
    ASSERT_EQ(res_image.second, 2);
}

TEST(Wrong_data, wrong_img_2) {
    std::vector<int> source_image{};
    std::vector<int> result_image{};
    int width = 5;
    int height = 2;
    ASSERT_ANY_THROW(MarkComponentsSeq(&source_image, height, width));
}


TEST(Comparing_to_a_sample, square_image_1) {
    int width = 6;
    int height = 6;
    std::vector<int> source_image{
            0, 1, 0, 0, 0, 0,
            1, 1, 1, 0, 0, 1,
            0, 0, 0, 0, 1, 1,
            0, 1, 0, 1, 0, 0,
            1, 1, 1, 0, 0, 0,
            0, 0, 0, 0, 1, 1,
    };
    std::vector<int> result_image{
            0, 2, 0, 0, 0, 0,
            2, 2, 2, 0, 0, 3,
            0, 0, 0, 0, 3, 3,
            0, 4, 0, 5, 0, 0,
            4, 4, 4, 0, 0, 0,
            0, 0, 0, 0, 6, 6,
    };
    std::pair<std::vector<int>, int> res_image;
    ASSERT_NO_THROW(res_image = MarkComponentsSeq(&source_image, height, width));
    ASSERT_EQ(res_image.second, 5);
}

TEST(Wrong_data, wrong_width_and_height_3) {
    std::vector<int> source_image{
            0, 0, 1,
            1, 0, 1,
            0, 0, 0,
    };
    std::vector<int> result_image{
            0, 0, 2,
            3, 0, 2,
            0, 0, 0,
    };
    int width = 1;
    int height = 3;
    ASSERT_ANY_THROW(MarkComponentsSeq(&source_image, height, width));
}

TEST(Comparing_to_a_big_sample, square_image_1) {
    int width = 15;
    int height = 15;
    std::vector<int> source_image{
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    };
    std::vector<int> result_image{
            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    };
    std::pair<std::vector<int>, int> res_image;
    ASSERT_NO_THROW(res_image = MarkComponentsSeq(&source_image, height, width));
    ASSERT_EQ(res_image.second, 1);
}

TEST(Wrong_data, wrong_width_and_height_1) {
    std::vector<int> source_image = {
            0, 1, 1,
            1, 0, 0,
            0, 0, 0,
    };
    std::vector<int> result_image = {
            0, 2, 2,
            3, 0, 0,
            0, 0, 0,
    };
    int width = 4;
    int height = 3;
    ASSERT_ANY_THROW(MarkComponentsSeq(&source_image, height, width));
}

TEST(Comparing_to_a_big_sample, square_image_2) {
    int width = 10;
    int height = 10;
    std::vector<int> source_image{
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            1, 0, 1, 1, 1, 1, 1, 1, 0, 1,
            1, 0, 1, 0, 0, 0, 0, 1, 0, 1,
            1, 0, 1, 0, 1, 1, 0, 1, 0, 1,
            1, 0, 1, 0, 1, 1, 0, 1, 0, 1,
            1, 0, 1, 0, 0, 0, 0, 1, 0, 1,
            1, 0, 1, 1, 1, 1, 1, 1, 0, 1,
            1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    };
    std::vector<int> result_image{
            2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
            2, 0, 0, 0, 0, 0, 0, 0, 0, 2,
            2, 0, 3, 3, 3, 3, 3, 3, 0, 2,
            2, 0, 3, 0, 0, 0, 0, 3, 0, 2,
            2, 0, 3, 0, 4, 4, 0, 3, 0, 2,
            2, 0, 3, 0, 4, 4, 0, 3, 0, 2,
            2, 0, 3, 0, 0, 0, 0, 3, 0, 2,
            2, 0, 3, 3, 3, 3, 3, 3, 0, 2,
            2, 0, 0, 0, 0, 0, 0, 0, 0, 2,
            2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    };
    std::pair<std::vector<int>, int> res_image;
    ASSERT_NO_THROW(res_image = MarkComponentsSeq(&source_image, height, width));
    ASSERT_EQ(res_image.second, 3);
}

TEST(Wrong_data, wrong_img) {
    std::vector<int> source_image;
    std::vector<int> result_image;
    int width = 0;
    int height = 0;
    ASSERT_ANY_THROW(MarkComponentsSeq(&source_image, height, width));
}


TEST(Comparing_to_a_sample, square_image_2) {
    int width = 5;
    int height = 5;
    std::vector<int> source_image{
            0, 1, 0, 1, 1,
            0, 0, 0, 1, 1,
            1, 0, 0, 0, 1,
            0, 0, 1, 1, 1,
            0, 0, 0, 0, 1,
    };
    std::vector<int> result_image{
            0, 2, 0, 3, 3,
            0, 0, 0, 3, 3,
            4, 0, 0, 0, 3,
            0, 0, 3, 3, 3,
            0, 0, 0, 0, 3,
    };
    std::pair<std::vector<int>, int> res_image;
    ASSERT_NO_THROW(res_image = MarkComponentsSeq(&source_image, height, width));
    ASSERT_EQ(res_image.second, 3);
}

TEST(Wrong_data, wrong_img_1) {
    std::vector<int> source_image{};
    std::vector<int> result_image{};
    int width = 0;
    int height = 0;
    ASSERT_ANY_THROW(MarkComponentsSeq(&source_image, height, width));
}

TEST(Wrong_data, wrong_width_and_height_2) {
    std::vector<int> source_image{
            0, 1, 1,
            0, 0, 1,
            1, 1,
    };
    std::vector<int> result_image{
            0, 2, 2,
            0, 0, 2,
            2, 2,
    };
    int width = 3;
    int height = 3;
    ASSERT_ANY_THROW(MarkComponentsSeq(&source_image, height, width));
}
/*
TEST(Comparing_to_a_big_sample, square_image_3) {
    int width = 10;
    int height = 10;
    std::vector<int> source_image{
            0, 1, 0, 1, 0, 1, 1, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 1, 1, 0, 0,
            0, 0, 1, 1, 0, 1, 0, 0, 1, 0,
            1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            1, 0, 1, 0, 1, 1, 1, 1, 0, 0,
            1, 0, 1, 1, 1, 1, 1, 0, 0, 1,
            0, 1, 1, 0, 0, 0, 0, 1, 0, 0,
            0, 0, 0, 1, 1, 0, 1, 0, 1, 1,
            1, 0, 1, 0, 0, 0, 0, 0, 1, 1,
            1, 0, 1, 0, 1, 0, 1, 0, 1, 1,
    };
    std::vector<int> result_image{
            0, 2, 0, 3, 0, 4, 4, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 4, 4, 0, 0,
            0, 0, 5, 5, 0, 6, 0, 0, 7, 0,
            8, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            8, 0, 9, 0, 9, 9, 9, 9, 0, 0,
            8, 0, 9, 9, 9, 9, 9, 0, 0, 10,
            0, 9, 9, 0, 0, 0, 0, 11, 0, 0,
            0, 0, 0, 12, 12, 0, 13, 0, 14, 14,
            15, 0, 16, 0, 0, 0, 0, 0, 14, 14,
            15, 0, 16, 0, 17, 0, 18, 0, 14, 14,
    };
   int n = 10;
  int m = 10;
    std::pair<std::vector<int>, int> res_image = MarkComponentsSeq(&source_image, height, width);
//    std::cout<<res_image.second<<"\n";
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            std::cout << res_image.first[i * m + j] << " ";
//        }
//        std::cout << "\n";
//    }
    auto res_image2 = MarkComponentsPar(&source_image, n, m);
//    std::cout<<res_image2.second<<"\n";
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            std::cout << res_image2.first[i * m + j] << " ";
//        }
//        std::cout << "\n";
//    }
    //ASSERT_NO_THROW(res_image =);
    ASSERT_EQ(res_image.second, res_image2.second);
}
*/

TEST(kek, kek) {
    int n = 450, m = 450;
    std::vector<int> a(n * m);
    for (int i = 0; i < n * m; i++) {
        a[i] = rand() % 2;
    }
    auto par = a;
    double start = omp_get_wtime();
    auto ans = MarkComponentsSeq(&a, n, m);
    double end = omp_get_wtime();

    std::cout << "Sequential: " << (end - start) << "\n";

    std::cout << " \n";
//    std::cout << ans.second << "\n";
//
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            std::cout << ans.first[i * j + j] << " ";
//        }
//        std::cout << "\n";
//    }
//    std::cout << " \n";

    start = omp_get_wtime();
    auto ans2 = MarkComponentsPar(&par, n, m);
    end = omp_get_wtime();
    std::cout << "Parallel: " << (end - start) << "\n";

    std::cout << " \n";
//    std::cout << ans2.second << "\n";
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            std::cout << ans2.first[i * j + j] << " ";
//        }
//        std::cout << "\n";
//    }
//    std::cout << " \n";


//    ASSERT_EQ(ans.second, ans2.second);
}

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
