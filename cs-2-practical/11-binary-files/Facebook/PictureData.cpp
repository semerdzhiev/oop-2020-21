#include "PictureData.h"

#include <utility>
PictureData::PictureData(std::string description, unsigned int numberOfLikes, unsigned int numberOfComments,
                         std::vector<Comment> comments) : description(std::move(description)),
                         numberOfLikes(numberOfLikes),numberOfComments(numberOfComments),comments(std::move(comments)){}