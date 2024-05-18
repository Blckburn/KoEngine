#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;

    Camera(glm::vec3 position);
    glm::mat4 GetViewMatrix() const;
};

#endif // CAMERA_H
