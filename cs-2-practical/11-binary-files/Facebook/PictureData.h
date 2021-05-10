#pragma once
#include<string>
#include<vector>
#include"Comment.h"
struct PictureData {
    std::string description;
    unsigned int numberOfLikes;
    unsigned int numberOfComments;
    std::vector<Comment> comments;
    explicit PictureData(std::string description="empty",unsigned int numberOfLikes = 0, unsigned int numberOfComments=0,
                std::vector<Comment>  comments={});
};


