// BoundingBox.h : Defines a bounding box object
//

#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <optional>

class BoundingBox {
public:
    // Constructors with optional confidence and class ID
    BoundingBox(int x, int y, int width, int height, int image_width, int image_height,
        std::optional<float> confidence = std::nullopt, std::optional<int> class_id = std::nullopt);
    BoundingBox(float rel_x, float rel_y, float rel_width, float rel_height, int image_width, int image_height,
        std::optional<float> confidence = std::nullopt, std::optional<int> class_id = std::nullopt);

    // Accessors for coordinates and dimensions
    int get_x() const;
    int get_y() const;
    int get_width() const;
    int get_height() const;
    float get_relative_x() const;
    float get_relative_y() const;
    float get_relative_width() const;
    float get_relative_height() const;

    // Accessors for optional parameters
    std::optional<float> get_confidence() const;
    std::optional<int> get_class_id() const;

private:
    int x, y, width, height; // Absolute coordinates and dimensions
    float rel_x, rel_y, rel_width, rel_height; // Relative coordinates and dimensions
    int image_width, image_height; // Image dimensions
    std::optional<float> confidence; // Confidence level
    std::optional<int> class_id; // Class ID

    // Private methods to update coordinates
    void update_relative_coordinates();
    void update_absolute_coordinates();
};

#endif // BOUNDINGBOX_H

