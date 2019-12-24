#include <opencv2/opencv.hpp>
#include <vector>
#include <string>

bool equal(cv::Mat& l1, cv::Mat& l2) {
  int error = 0;
  for (int i = 0;i < l1.rows;++i) {
    for (int j = 0;j < l1.cols;++j){
      if (l1.at<int>(i,j)!= l2.at<int>(i,j)) ++error;
      if (error > 10) return false;
    }
  }
  return true;
}
int main(int argc, char** argv) {
  cv::Mat table=cv::imread("../design.png", cv::IMREAD_GRAYSCALE);

  std::vector<cv::Mat> block(64);
  for (auto i = 0;i < 64;++i) {
    std::string s= "../pieces/p_";
    s += std::to_string(i+1);
    s += ".png";
    block[i] = cv::imread(s, cv::IMREAD_GRAYSCALE);
  }
  for (auto i = 0;i < 32;++i) {
    for (auto j = 0;j < 32;++j) {
      std::cout<< block[0].at<int>(i,j) <<' ';
    }
    std::cout << '\n';
  }

  for (auto i = 0;i < 8;++i) {
    for (auto j = 0;j < 8;++j) {
      cv::Rect roi(i,j,table.rows/8, table.cols/8);
      cv::Mat roi_rect = table(roi);
      for (auto k = 0;k < 64;++k) {
        if (equal(roi_rect, block[k])) std::cout << k;
      }
    }
  }
}
