#pragma once

#include "../Engine/Graphics/Camera.hpp"
#include "../Engine/Core/Input.hpp"
#include <glm/glm.hpp>

class CameraController
{
public:
    CameraController(Neonix::Camera* camera, float moveSpeed = 3.0f, float sensitivity = 0.1f);
    void Update(float deltaTime);

    inline glm::vec3& GetPosition() { return m_position; }
    inline glm::vec2& GetRotation() { return m_rotation; }

private:
    void UpdateCamera();

public:
    void SetSmoothTime(float smoothTime) { m_smoothTime = smoothTime; }
    float GetSmoothTime() const { return m_smoothTime; }

private:
    Neonix::Camera* m_camera;
    glm::vec3 m_position;
    glm::vec2 m_rotation; // x = pitch, y = yaw
    glm::vec3 m_velocity;
    float m_moveSpeed;
    float m_sensitivity;
    float m_smoothTime;
    bool m_firstMouse;
    double m_lastX;
    double m_lastY;
};
