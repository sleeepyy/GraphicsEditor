#include "model.h"
#include <opencv2/opencv.hpp>
#include "viewmodel.h"
#include "notification.h"
#include <QDebug>
#include <iostream>
Model::Model()
{

}

void Model::open_file(std::string path){

//    std::cout << path << std::endl;
    image = cv::imread(path);
    originImg = image;
    if(image.empty()){
        qInfo() << "false";
    }else{
        notify();
    }
}

cv::Mat& Model::get(){
    return image;
}

cv::Mat& Model::getOrigin(){
    return originImg;
}

//void Model::bind(std::shared_ptr<ViewModel> viewmodel){
//    this->viewmodel = viewmodel;
//}

void Model::set_update_display_data_notification(std::shared_ptr<Notification> notification){
    this->update_display_data_notification = notification;
}

void Model::notify(){
    update_display_data_notification->exec();
}

void Model::alterBright(int nbright){
    image = originImg;
    cv::Mat tmpImg = cv::Mat::zeros(image.size(), image.type());
    if(tmpImg.empty() == true){
        qInfo() << "false";
        return ;
    }
    for(int y = 0; y<image.rows; y++){
        for(int x = 0; x<image.cols;x++){
            for(int c = 0;c<3;c++){
                tmpImg.at<cv::Vec3b>(y,x)[c] = cv::saturate_cast<uchar>(image.at<cv::Vec3b>(y,x)[c]+nbright);
            }
        }
    }
    image = tmpImg;
    if(image.empty()){
        qInfo() << "false";
    }else{
        notify();
    }
}

void Model::alterContrast(int nContrast){
    image = originImg;
    cv::Mat tmpImg = cv::Mat::zeros(image.size(), image.type());
    if(tmpImg.empty() == true){
        qInfo() << "false";
        return ;
    }
    for(int y = 0; y<image.rows; y++){
        for(int x = 0; x<image.cols;x++){
            for(int c = 0;c<3;c++){
                tmpImg.at<cv::Vec3b>(y,x)[c] = cv::saturate_cast<uchar>((nContrast*0.01)*(image.at<cv::Vec3b>(y,x)[c]));
            }
        }
    }
    image = tmpImg;
    if(image.empty()){
        qInfo() << "false";
    }else{
        notify();
    }
}
