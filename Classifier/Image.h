// Image.h : Defines an image object
//

#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <vector>
#include <optional>
#include "BoundingBox.h"

class Image {
public:
    Image(const std::string& file_path, int width, int height);

    void add_bounding_box(const BoundingBox& box);
    const std::string& get_file_path() const;
    std::vector<BoundingBox>& get_bounding_boxes();

    // Sorting functions
    void sort_bounding_boxes_by_x();
    void sort_bounding_boxes_by_y();
    void sort_bounding_boxes_by_confidence();

private:
    std::string file_path; // Image file path
    int width, height; // Image dimensions
    std::vector<BoundingBox> bounding_boxes; // List of bounding boxes
};

#endif // IMAGE_H
