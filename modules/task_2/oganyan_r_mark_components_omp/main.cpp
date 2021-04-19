// Copyright 2021 Oganyan Robert

#include <gtest/gtest.h>
#include <omp.h>
#include "../../modules/task_2/oganyan_r_mark_components_omp/mark_components_omp.h"

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
    std::pair<std::vector<int>, int> res_image_seq;
    std::pair<std::vector<int>, int> res_image_paral;
    ASSERT_NO_THROW(res_image_seq = MarkComponentsSeq(&source_image, height, width));
    ASSERT_NO_THROW(res_image_paral = MarkComponentsPar(&source_image, height, width));
    ASSERT_EQ(res_image_seq.second, 2);
    ASSERT_EQ(res_image_seq.second, res_image_paral.second);
}

TEST(Wrong_data, wrong_img_2) {
    std::vector<int> source_image{};
    std::vector<int> result_image{};
    int width = 5;
    int height = 2;
    ASSERT_ANY_THROW(MarkComponentsSeq(&source_image, height, width));
    ASSERT_ANY_THROW(MarkComponentsPar(&source_image, height, width));
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
    std::pair<std::vector<int>, int> res_image_seq;
    std::pair<std::vector<int>, int> res_image_paral;
    ASSERT_NO_THROW(res_image_seq = MarkComponentsSeq(&source_image, height, width));
    ASSERT_NO_THROW(res_image_paral = MarkComponentsPar(&source_image, height, width));
    ASSERT_EQ(res_image_seq.second, 5);
    ASSERT_EQ(res_image_seq.second, res_image_paral.second);
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
    ASSERT_ANY_THROW(MarkComponentsPar(&source_image, height, width));
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
    std::pair<std::vector<int>, int> res_image_seq;
    std::pair<std::vector<int>, int> res_image_paral;
    ASSERT_NO_THROW(res_image_seq = MarkComponentsSeq(&source_image, height, width));
    ASSERT_NO_THROW(res_image_paral = MarkComponentsPar(&source_image, height, width));
    ASSERT_EQ(res_image_seq.second, 1);
    ASSERT_EQ(res_image_seq.second, res_image_paral.second);
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
    ASSERT_ANY_THROW(MarkComponentsPar(&source_image, height, width));
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
    std::pair<std::vector<int>, int> res_image_seq;
    std::pair<std::vector<int>, int> res_image_paral;
    ASSERT_NO_THROW(res_image_seq = MarkComponentsSeq(&source_image, height, width));
    ASSERT_NO_THROW(res_image_paral = MarkComponentsPar(&source_image, height, width));
    ASSERT_EQ(res_image_seq.second, 3);
    ASSERT_EQ(res_image_seq.second, res_image_paral.second);
}

TEST(Wrong_data, wrong_img) {
    std::vector<int> source_image;
    std::vector<int> result_image;
    int width = 0;
    int height = 0;
    ASSERT_ANY_THROW(MarkComponentsSeq(&source_image, height, width));
    ASSERT_ANY_THROW(MarkComponentsPar(&source_image, height, width));
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
    std::pair<std::vector<int>, int> res_image_seq;
    std::pair<std::vector<int>, int> res_image_paral;
    ASSERT_NO_THROW(res_image_seq = MarkComponentsSeq(&source_image, height, width));
    ASSERT_NO_THROW(res_image_paral = MarkComponentsPar(&source_image, height, width));
    ASSERT_EQ(res_image_seq.second, 3);
    ASSERT_EQ(res_image_seq.second, res_image_paral.second);
}

TEST(Wrong_data, wrong_img_1) {
    std::vector<int> source_image{};
    std::vector<int> result_image{};
    int width = 0;
    int height = 0;
    ASSERT_ANY_THROW(MarkComponentsSeq(&source_image, height, width));
    ASSERT_ANY_THROW(MarkComponentsPar(&source_image, height, width));
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
    ASSERT_ANY_THROW(MarkComponentsPar(&source_image, height, width));
}


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

    std::pair<std::vector<int>, int> res_image_seq;
    std::pair<std::vector<int>, int> res_image_paral;
    ASSERT_NO_THROW(res_image_seq = MarkComponentsSeq(&source_image, height, width));
    ASSERT_NO_THROW(res_image_paral = MarkComponentsPar(&source_image, height, width));
    ASSERT_EQ(res_image_seq.second, 17);
    ASSERT_EQ(res_image_seq.second, res_image_paral.second);
}

TEST(Comparing_random_img, small_image) {
    int n = 50, m = 50;
    std::vector<int> seq(n * m);
    for (int i = 0; i < n * m; ++i) {
        seq[i] = rand() % 2;
    }
    auto paral = seq;

    std::cout<<n<<"x"<<m<<": \n";
    double start = omp_get_wtime();
    auto ans = MarkComponentsSeq(&seq, n, m);
    double end = omp_get_wtime();
    std::cout << "Sequential: " << (end - start) << "\n";
    std::cout << " \n";

    start = omp_get_wtime();
    auto ans2 = MarkComponentsPar(&paral, n, m);
    end = omp_get_wtime();
    std::cout << "Parallel: " << (end - start) << "\n";

    std::cout << " \n";

    ASSERT_EQ(ans.second, ans2.second);
}

TEST(Comparing_random_img, small_image_2) {
    int n = 100, m = 100;
    std::vector<int> seq(n * m);
    for (int i = 0; i < n * m; ++i) {
        seq[i] = rand() % 2;
    }
    auto paral = seq;
    std::cout<<n<<"x"<<m<<": \n";
    double start = omp_get_wtime();
    auto ans = MarkComponentsSeq(&seq, n, m);
    double end = omp_get_wtime();
    std::cout << "Sequential: " << (end - start) << "\n";
    std::cout << " \n";

    start = omp_get_wtime();
    auto ans2 = MarkComponentsPar(&paral, n, m);
    end = omp_get_wtime();
    std::cout << "Parallel: " << (end - start) << "\n";

    std::cout << " \n";

    ASSERT_EQ(ans.second, ans2.second);
}

TEST(Comparing_random_img, middle_image) {
    int n = 500, m = 500;
    std::vector<int> seq(n * m);
    for (int i = 0; i < n * m; ++i) {
        seq[i] = rand() % 2;
    }
    auto paral = seq;
    std::cout<<n<<"x"<<m<<": \n";
    double start = omp_get_wtime();
    auto ans = MarkComponentsSeq(&seq, n, m);
    double end = omp_get_wtime();
    std::cout << "Sequential: " << (end - start) << "\n";
    std::cout << " \n";

    start = omp_get_wtime();
    auto ans2 = MarkComponentsPar(&paral, n, m);
    end = omp_get_wtime();
    std::cout << "Parallel: " << (end - start) << "\n";

    std::cout << " \n";

    ASSERT_EQ(ans.second, ans2.second);
}

TEST(Comparing_random_img, middle_image_2) {
    int n = 750, m = 750;
    std::vector<int> seq(n * m);
    for (int i = 0; i < n * m; ++i) {
        seq[i] = rand() % 2;
    }
    auto paral = seq;
    std::cout<<n<<"x"<<m<<": \n";
    double start = omp_get_wtime();
    auto ans = MarkComponentsSeq(&seq, n, m);
    double end = omp_get_wtime();
    std::cout << "Sequential: " << (end - start) << "\n";
    std::cout << " \n";

    start = omp_get_wtime();
    auto ans2 = MarkComponentsPar(&paral, n, m);
    end = omp_get_wtime();
    std::cout << "Parallel: " << (end - start) << "\n";

    std::cout << " \n";

    ASSERT_EQ(ans.second, ans2.second);
}

TEST(Comparing_random_img, middle_image_3) {
    int n = 1000, m = 1000;
    std::vector<int> seq(n * m);
    for (int i = 0; i < n * m; ++i) {
        seq[i] = rand() % 2;
    }
    auto paral = seq;
    std::cout<<n<<"x"<<m<<": \n";
    double start = omp_get_wtime();
    auto ans = MarkComponentsSeq(&seq, n, m);
    double end = omp_get_wtime();
    std::cout << "Sequential: " << (end - start) << "\n";
    std::cout << " \n";

    start = omp_get_wtime();
    auto ans2 = MarkComponentsPar(&paral, n, m);
    end = omp_get_wtime();
    std::cout << "Parallel: " << (end - start) << "\n";

    std::cout << " \n";

    ASSERT_EQ(ans.second, ans2.second);
}

TEST(Comparing_random_img, big_image) {
    int n = 2000, m = 2000;
    std::vector<int> seq(n * m);
    for (int i = 0; i < n * m; ++i) {
        seq[i] = rand() % 2;
    }
    auto paral = seq;
    std::cout<<n<<"x"<<m<<": \n";
    double start = omp_get_wtime();
    auto ans = MarkComponentsSeq(&seq, n, m);
    double end = omp_get_wtime();
    std::cout << "Sequential: " << (end - start) << "\n";
    std::cout << " \n";

    start = omp_get_wtime();
    auto ans2 = MarkComponentsPar(&paral, n, m);
    end = omp_get_wtime();
    std::cout << "Parallel: " << (end - start) << "\n";

    std::cout << " \n";

    ASSERT_EQ(ans.second, ans2.second);
}

TEST(Comparing_random_img, big_image_2) {
    int n = 3000, m = 3000;
    std::vector<int> seq(n * m);
    for (int i = 0; i < n * m; ++i) {
        seq[i] = rand() % 2;
    }
    auto paral = seq;
    std::cout<<n<<"x"<<m<<": \n";
    double start = omp_get_wtime();
    auto ans = MarkComponentsSeq(&seq, n, m);
    double end = omp_get_wtime();
    std::cout << "Sequential: " << (end - start) << "\n";
    std::cout << " \n";

    start = omp_get_wtime();
    auto ans2 = MarkComponentsPar(&paral, n, m);
    end = omp_get_wtime();
    std::cout << "Parallel: " << (end - start) << "\n";

    std::cout << " \n";

    ASSERT_EQ(ans.second, ans2.second);
}

TEST(Comparing_random_img, big_image_3) {
    int n = 5000, m = 5000;
    std::vector<int> seq(n * m);
    for (int i = 0; i < n * m; ++i) {
        seq[i] = rand() % 2;
    }
    auto paral = seq;
    std::cout<<n<<"x"<<m<<": \n";
    double start = omp_get_wtime();
    auto ans = MarkComponentsSeq(&seq, n, m);
    double end = omp_get_wtime();
    std::cout << "Sequential: " << (end - start) << "\n";
    std::cout << " \n";

    start = omp_get_wtime();
    auto ans2 = MarkComponentsPar(&paral, n, m);
    end = omp_get_wtime();
    std::cout << "Parallel: " << (end - start) << "\n";

    std::cout << " \n";

    ASSERT_EQ(ans.second, ans2.second);
}


int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
