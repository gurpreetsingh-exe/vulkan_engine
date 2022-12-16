#include "Camera.hh"

void Camera::updateModel() {
    m_Model = glm::mat4(1.0f);
}

void Camera::updateView() {
    m_View = glm::lookAt(m_Position, m_Position + m_Direction, glm::vec3(0.0f, 0.0f, 1.0f));
}

void Camera::updateProjection() {
    m_Projection = glm::perspective(glm::radians(m_Fov),
        m_ViewportWidth / m_ViewportHeight,
        m_ClipNear, m_ClipFar);

    m_Projection[1][1] *= -1;
}

void Camera::_update(Event& e) {
    glm::vec2 delta = (e.mouse - m_LastMousePos) * 0.28f;
    if (e.ctrl && e.alt && e.button == Event::MouseButtonLeft) {
        m_Position += m_Direction * delta.x * 0.06f;
    } else if (e.button == Event::MouseButtonRight) {
        glm::vec3 upDir = glm::vec3(0.0f, 0.0f, 1.0f);
        glm::mat4 rot_mat = glm::rotate(m_Model, glm::radians(delta.x), upDir);
        rot_mat = glm::rotate(rot_mat, glm::radians(-delta.y), m_Right);
        m_Position = glm::vec3(glm::vec4(m_Position, 1.0f) * rot_mat);
        m_Direction = glm::normalize(-m_Position);
        m_Right = glm::cross(upDir, m_Direction);
    }

    updateProjection();
    updateView();

    m_LastMousePos = e.mouse;
}

void Camera::onUpdate(Event& e) {
    if (m_NeedsUpdate) {
        m_NeedsUpdate = false;
        _update(e);
        return;
    }
    if (e.kind == Event::None || m_LastMousePos == e.mouse) {
        return;
    }
    if (e.kind != Event::MouseClickDrag) {
        m_LastMousePos = e.mouse;
        return;
    }
    _update(e);
}
