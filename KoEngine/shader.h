#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>

class Shader {
public:
    Shader(const char* vertexPath, const char* fragmentPath);
    void use();
    void setMat4(const std::string& name, const glm::mat4& mat) const;
    void setVec3(const std::string& name, const glm::vec3& value) const;

private:
    unsigned int ID;
    void checkCompileErrors(unsigned int shader, std::string type);
};

#endif // SHADER_H