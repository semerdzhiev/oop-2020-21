//
// Created by petko on 10/05/2021.
//

#include "UserData.h"

UserData::UserData(std::string name, unsigned short age, std::string regDate, std::vector<PictureData> pictures) :
name(std::move(name)),age(age),regDate(std::move(regDate)),pictures(std::move(pictures))
{}