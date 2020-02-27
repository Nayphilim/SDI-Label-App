#ifndef IMAGECONVERSION_H
#define IMAGECONVERSION_H

#include<QPixmap>
#include<QImage>
#include<QThread>
#include<opencv2/opencv.hpp>


class imageConversion
{
public:
    imageConversion();

    QPixmap pixmap() const{
        return mPixmap;
    }
private:
    QPixmap mPixmap;
    cv::Mat mFrame;

    QImage cvMatToQImage(const cv::Mat &inMat );
    QPixmap cvMatToQPixmap(const cv::Mat &inMat );

};

#endif // IMAGECONVERSION_H
