
#pragma once
#include<string>
#include<vector>
#include"PictureData.h"

struct UserData {
    std::string name;
    unsigned short age;
    std::string regDate;
    std::vector<PictureData> pictures;

    UserData(std::string name, unsigned short age, std::string regDate, std::vecotr<PictureData> pictures);
};


