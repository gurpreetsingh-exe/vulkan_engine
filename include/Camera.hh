#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
    Camera(float fov, glm::vec2 viewport, float zNear, float zFar)
        : m_Fov(fov), m_ViewportWidth(viewport.x), m_ViewportHeight(viewport.y), m_ClipNear(zNear), m_ClipFar(zFar) {}

public:
    const glm::mat4& getModel() const { return m_Model; }
    const glm::mat4& getView() const { return m_View; }
    const glm::mat4& getProjection() const { return m_Projection; }
    void onUpdate();

private:
    void updateModel();
    void updateView();
    void updateProjection();

private:
    glm::mat4 m_Model;
    glm::mat4 m_View;
    glm::mat4 m_Projection;

    float m_ViewportWidth;
    float m_ViewportHeight;
    float m_Fov;
    float m_ClipNear;
    float m_ClipFar;

    glm::vec3 m_Position = glm::vec3(2.0f, 2.0f, 2.0f);
    glm::vec3 m_Direction = glm::vec3(-1.0f);
    glm::vec3 m_UpDirection = glm::vec3(0.0f, 0.0f, 1.0f);
};
