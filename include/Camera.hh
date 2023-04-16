#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Event.hh"

class Camera {
public:
  Camera(float fov, glm::vec2 viewport, float zNear, float zFar)
      : m_Fov(fov), m_ViewportWidth(viewport.x), m_ViewportHeight(viewport.y),
        m_ClipNear(zNear), m_ClipFar(zFar) {

    updateModel();
    updateProjection();
    updateView();
  }

public:
  const glm::mat4& getModel() const { return m_Model; }
  const glm::mat4& getView() const { return m_View; }
  const glm::mat4& getProjection() const { return m_Projection; }
  void onUpdate(Event& e);
  void onResize(uint32_t width, uint32_t height) {
    if (m_ViewportWidth != width || m_ViewportHeight != height) {
      m_ViewportWidth = width;
      m_ViewportHeight = height;
      m_NeedsUpdate = true;
    }
  }

private:
  void updateModel();
  void updateView();
  void updateProjection();
  void _update(Event& e);

private:
  glm::mat4 m_Model;
  glm::mat4 m_View;
  glm::mat4 m_Projection;

  float m_ViewportWidth;
  float m_ViewportHeight;
  float m_Fov;
  float m_ClipNear;
  float m_ClipFar;

  bool m_NeedsUpdate = false;

  glm::vec3 m_Position = glm::vec3(2.0f, 2.0f, 2.0f);
  glm::vec3 m_Direction = glm::vec3(-1.0f);
  glm::vec3 m_Right = glm::vec3(1.0f, 0.0f, 0.0f);

  glm::vec2 m_LastMousePos = glm::vec2(0.0f);
};
