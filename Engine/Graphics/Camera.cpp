#include "Camera.hpp"
#include <glm/gtc/matrix_transform.hpp>

namespace Neonix
{
    Camera::Camera(float fov, float aspectRatio, float nearPlane, float farPlane) : m_aspect(aspectRatio), m_nearPlane(nearPlane), m_farPlane(farPlane), m_fov(fov)
    {
        using namespace glm;
        m_proj = perspective(radians(fov), aspectRatio, nearPlane, farPlane);
        viewMatrix = lookAt(vec3(0.0f, 0.0f, 3.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0));
    }

    void Camera::SetAspectRatio(float aspectRatio)
    {
        m_aspect = aspectRatio;
        m_proj = glm::perspective(glm::radians(m_fov), m_aspect, m_nearPlane, m_farPlane);
    }
}