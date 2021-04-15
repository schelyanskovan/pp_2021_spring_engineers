// Copyright 2021 Oganyan Robert

#include <vector>
#include <iostream>
#include <map>
#include <random>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>


#include "../../modules/task_1/oganyan_r_mark_components/mark_components.h"


void convert_to_zeroone(cv::Mat *img) {
    for (int i = 0; i < (*img).rows; ++i) {
        for (int j = 0; j < (*img).cols; ++j) {
            if ((*img).at<uchar>(i, j) < 255) {
                (*img).at<uchar>(i, j) = 1;
            }
            if ((*img).at<uchar>(i, j) == 255) {
                (*img).at<uchar>(i, j) = 0;
            }
        }
    }
}


void convert_to_rdm_color(std::vector<cv::Vec3w> *img) {
    std::default_random_engine generator;
    std::uniform_int_distribution<unsigned int> distribution(0, 255);
    std::map<uint, cv::Vec3w> colors;
    for (uint64_t i = 0; i < (*img).size(); ++i) {
        int cur_num = (*img)[i][0];
        if (cur_num > 1) {
            if (colors.find(cur_num) == colors.end()) {
                cv::Vec3w result;
                for (int j = 0; j < 3; ++j) {
                    result[j] = distribution(generator);
                }
                colors[cur_num] = result;
                (*img)[i] = result;
            } else {
                (*img)[i] = colors[cur_num];
            }
        }
    }
    return;
}

int main(int argc, char *argv[]) {
    std::cout << "Printing arvg info: " << "\n";
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << "\n";
    }

    if (argc < 3) {
        std::cout << "Wrong input" << "\n";
    }

    cv::Mat img = imread(argv[1], cv::IMREAD_GRAYSCALE);
    cv::imwrite("/home/ogrob/pp_2021_spring_engineers/modules/Visualize/results/loh2.png", img);

    //  std::vector<cv::Vec3b> array(img.datastart, img.dataend);
    //  std::vector<uint16_t> before_convert_array(img.datastart, img.dataend);
    convert_to_zeroone(&img);
    std::vector<uint16_t> array(img.datastart, img.dataend);
    std::pair<std::vector<uint16_t>, uint16_t> new_img = MarkComponents(array, img.rows, img.cols);
    cv::Mat kek(img.rows, img.cols, CV_8U, new_img.first.data());
    cv::imwrite("/home/ogrob/pp_2021_spring_engineers/modules/Visualize/results/loh.png", kek);
    std::vector<cv::Vec3w> result_image(new_img.first.begin(), new_img.first.end());
    std::vector<uchar> array2(img.datastart, img.dataend);
    convert_to_rdm_color(&result_image);
    //   cv::Mat new_img(array, img.rows, img.cols);
    cv::Mat final_img(img.rows, img.cols, CV_8UC3, result_image.data());

    for (uint64_t i = 0; i < (result_image).size(); ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << result_image[i][j] << " ";
        }
        std::cout << "\n";
    }
    cv::imwrite(argv[2], final_img, {cv::IMWRITE_JPEG_QUALITY});

    return 0;
}





