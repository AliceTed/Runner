#include <opencv2/opencv.hpp>

#include <iostream>
#include <ios>
#include <iomanip>
#include <sstream>
int main()
{	
	//出力する動画ファイルの設定 拡張子はWMV1で 15FPS  aspc640*480。
	cv::VideoWriter writer("C:\\Users\\week2\\Desktop\\OutVideo.wmv", cv::VideoWriter::fourcc('W', 'M', 'V', '1'), 15.0, cv::Size(640, 480));
	//動画ファイルが作れたか
	if (!writer.isOpened()) { return -1; }

	cv::Mat image;
	//000000.jpgから001000.jpgまでの画像を動画にしていく。
	for (int i = 0; i < 2338; i++) 
	{
		std::ostringstream ss;
		ss << "C:\\logs\\" << std::setfill('0') << std::right << std::setw(6) << i << ".jpg";

		//名前に対応した画像を取り込み。
		image = cv::imread(ss.str());

		//画像がなければ処理を飛ばす。
		if (image.empty()) 
		{
			std::cout << "no image : " << ss.str() << std::endl;
			continue;
		}
		//動画ファイルに画像を出力。
		writer << image;
	}
	cv::destroyAllWindows();
	return 0;
}