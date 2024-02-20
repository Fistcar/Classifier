// BoundingBox.cpp : Implementation of boudning box object
//

#include "BoundingBox.h"

BoundingBox::BoundingBox(int x, int y, int width, int height, int image_width, int image_height,
    std::optional<float> confidence, std::optional<int> class_id)
    : x(x), y(y), width(width), height(height), image_width(image_width), image_height(image_height),
    confidence(confidence), class_id(class_id) {
    update_relative_coordinates();
}

BoundingBox::BoundingBox(float rel_x, float rel_y, float rel_width, float rel_height, int image_width, int image_height,
    std::optional<float> confidence, std::optional<int> class_id)
    : rel_x(rel_x), rel_y(rel_y), rel_width(rel_width), rel_height(rel_height), image_width(image_width), image_height(image_height),
    confidence(confidence), class_id(class_id) {
    update_absolute_coordinates();
}

void BoundingBox::update_relative_coordinates() {
    rel_x = static_cast<float>(x) / image_width;
    rel_y = static_cast<float>(y) / image_height;
    rel_width = static_cast<float>(width) / image_width;
    rel_height = static_cast<float>(height) / image_height;
}

void BoundingBox::update_absolute_coordinates() {
    x = static_cast<int>(rel_x * image_width);
    y = static_cast<int>(rel_y * image_height);
    width = static_cast<int>(rel_width * image_width);
    height = static_cast<int>(rel_height * image_height);
}

int BoundingBox::get_x() const {
    return x;
}

int BoundingBox::get_y() const {
    return y;
}

int BoundingBox::get_width() const {
    return width;
}

int BoundingBox::get_height() const {
    return height;
}

float BoundingBox::get_relative_x() const {
    return rel_x;
}

float BoundingBox::get_relative_y() const {
    return rel_y;
}

float BoundingBox::get_relative_width() const {
    return rel_width;
}

float BoundingBox::get_relative_height() const {
    return rel_height;
}

std::optional<float> BoundingBox::get_confidence() const {
    return confidence;
}

std::optional<int> BoundingBox::get_class_id() const {
    return class_id;
}