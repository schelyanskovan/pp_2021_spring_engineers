// Copyright 2021 Kustova Anastasiya
#include <math.h>
#include <tbb/tbb.h>
#include <iostream>
#include <vector>
#include <tuple>
#include "../../../modules/task_3/kustova_a_gauss_tbb/filter_gaussa_block.h"
/*
std::vector<int> gaussianFilter(const std::vector<int> & img, int width,
    int height, int radius, float sigma, int count_thread) {
    std::vector<int> resultImage(height * width);
    int size = 2 * radius + 1;
    std::vector<float> kernel(size * size);
    int l = 0;
    int k = 0;
    kernel = createGaussianKernel(radius, sigma);
    std::vector<std::vector<int>> array;
    int grid_size = ceil(static_cast<double>(sqrt(count_thread)));
    int block_height = height / grid_size;
    int block_width = width / grid_size;
    while (l < height) {
        k = 0;
        while (k < width) {
            std::vector<int> tup = { l, k };
            array.push_back(tup);
            k += block_width;
        }
        l += block_height;
    }
	tbb::task_scheduler_init init(count_thread);
        for (int t = 0; t < static_cast<int>(array.size()); t++) {
			int id = (int)tbb::this_tbb_thread::get_id();
            if (t % count_thread == tbb::this_tbb_thread::get_id()) {
				std::cout << tbb::this_tbb_thread::get_id() <<" ";
                int j_start = array[t][0];
                int j_finish = array[t][0] + block_height;
                int i_start = array[t][1];
                int i_finish = array[t][1] + block_width;
                for (int i = i_start; i < i_finish && i < width; i++) {
                    for (int j = j_start; j < j_finish && j < height; j++) {
                        int color = calculateNewPixelColor(img, width, height, i, j, radius, kernel);
                        resultImage[j * width + i] = color;
                    }
                }
            }
        }
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			int color = calculateNewPixelColor(img, width, height, i, j, radius, kernel);
			resultImage[i * width + j] = color;
		}
	}

    return resultImage;
}*/
class ParallelProcessing {
private:
	const std::vector<int> &img;
	std::vector<int> &res;
	std::vector<float> kernel;
	int rows, cols, radius;

public:
	void operator()(const tbb::blocked_range<int> &r) const {
		for (int i = r.begin(); i != r.end(); ++i) {
			for (int j = 0; j < cols; ++j) {
				/*double r = 0, g = 0, b = 0;
				int gaussianIndex = 0;
				for (int l = -gaussianKernelSize / 2; l <= gaussianKernelSize / 2; ++l) {
					for (int k = -gaussianKernelSize / 2; k <= gaussianKernelSize / 2; ++k) {
						int idX = std::max(0, std::min(i + l, rows - 1));
						int idY = std::max(0, std::min(j + k, cols - 1));
						Pixel p = img[idX * cols + idY];
						r += gaussianKernel[gaussianIndex] * p.r;
						g += gaussianKernel[gaussianIndex] * p.g;
						b += gaussianKernel[gaussianIndex] * p.b;
						++gaussianIndex;
					}
				}
				Pixel &p = (*res)[i * cols + j];
				p.r = std::max(0, std::min(static_cast<int>(r), 255));
				p.g = std::max(0, std::min(static_cast<int>(g), 255));
				p.b = std::max(0, std::min(static_cast<int>(b), 255));*/
				int size = radius * 2 + 1;
				double sumColor = 0;
				for (int l = -radius; l <= radius; l++) {
					for (int k = -radius; k <= radius; k++) {
						int idX = Clamp(i + k, 0, rows - 1);
						int idY = Clamp(j + l, 0, cols - 1);
						int neighborColor = img[idY * rows + idX];
						sumColor += neighborColor * kernel[(k + radius) * size + l + radius];
					}
				}
				res[j * rows + i] = Clamp(static_cast<int>(sumColor), 0, 255);
			}
		}
	}

	ParallelProcessing(const std::vector<int> &img, std::vector<int> &res, int rows, 
		int cols, std::vector<float> kernel, int radius) :
		img(img),
		res(res),
		rows(rows),
		cols(cols),
		kernel(kernel),
	radius(radius){}
};


std::vector<int> gaussianFilter(const std::vector<int> & img, int rows,
    int cols, int radius, float sigma, int count_thread) {
	std::vector<int> res(img);
	int size = 2 * radius + 1;
	std::vector<float> kernel(size * size);
	kernel = createGaussianKernel(radius, sigma);
	tbb::task_scheduler_init init(count_thread);
	ParallelProcessing pp(img, res, rows, cols, kernel, radius);
	tbb::parallel_for(tbb::blocked_range<int>(0, rows), pp);
	return res;
}
std::vector<float> createGaussianKernel(int radius, float sigma) {
    int size = 2 * radius + 1;
    std::vector<float> kernel(size * size);
    float norm = 0;
    for (int i = -radius; i <= radius; i++) {
        for (int j = -radius; j <= radius; j++) {
            kernel[(i + radius)* size + j + radius] = static_cast<float>(exp(-(i * i + j * j) / (2 * sigma * sigma)));
            norm = norm + kernel[(i + radius) * size + j + radius];
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            kernel[i * size + j] = kernel[i * size + j] / norm;
        }
    }
    return kernel;
}

int calculateNewPixelColor(std::vector<int> img, int width, int height,
    int x, int y, int radius, std::vector<float> kernel) {
    int size = radius * 2 + 1;
    double sumColor = 0;
    for (int l = -radius; l <= radius; l++) {
        for (int k = -radius; k <= radius; k++) {
            int idX = Clamp(x + k, 0, width - 1);
            int idY = Clamp(y + l, 0, height - 1);
            int neighborColor = img[idY * width + idX];
            sumColor += neighborColor * kernel[(k + radius) * size + l + radius];
        }
    }
    return Clamp(static_cast<int>(sumColor), 0, 255);
}
int Clamp(int value, int min, int max) {
    if (value < min) {
        return min;
    }
    if (value > max) {
        return max;
    }
    return value;
}

