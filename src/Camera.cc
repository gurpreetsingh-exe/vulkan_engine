#include "Camera.hh"

void Camera::updateModel() {
    m_Model = glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), m_UpDirection);
}

void Camera::updateView() {
    m_View = glm::lookAt(m_Position, m_Position + m_Direction, m_UpDirection);
}

void Camera::updateProjection() {
    m_Projection = glm::perspective(glm::radians(m_Fov),
        m_ViewportWidth / m_ViewportHeight,
        m_ClipNear, m_ClipFar);

    m_Projection[1][1] *= -1;
}

void Camera::onUpdate() {
    updateModel();
    updateProjection();
    updateView();
}
