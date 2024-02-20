// Image.cpp : Implementation of image object
//

#include "Image.h"
#include <algorithm> // For std::sort

Image::Image(const std::string& file_path, int width, int height)
    : file_path(file_path), width(width), height(height) {}

void Image::add_bounding_box(const BoundingBox& box) {
    bounding_boxes.push_back(box);
}

const std::string& Image::get_file_path() const {
    return file_path;
}

std::vector<BoundingBox>& Image::get_bounding_boxes() {
    return bounding_boxes;
}

void Image::sort_bounding_boxes_by_x() {
    std::sort(bounding_boxes.begin(), bounding_boxes.end(),
        [](const BoundingBox& a, const BoundingBox& b) {
            return a.get_x() < b.get_x();
        });
}

void Image::sort_bounding_boxes_by_y() {
    std::sort(bounding_boxes.begin(), bounding_boxes.end(),
        [](const BoundingBox& a, const BoundingBox& b) {
            return a.get_y() < b.get_y();
        });
}

void Image::sort_bounding_boxes_by_confidence() {
    std::sort(bounding_boxes.begin(), bounding_boxes.end(),
        [](const BoundingBox& a, const BoundingBox& b) {
            // Handle optional confidence values; sort those without confidence to the end
            if (!a.get_confidence().has_value()) return false;
            if (!b.get_confidence().has_value()) return true;
            return a.get_confidence().value() > b.get_confidence().value();
        });
}
