#include "CameraController.hpp"

CameraController::CameraController(Neonix::Camera *camera, float moveSpeed, float sensitivity)
    : m_camera(camera), m_moveSpeed(moveSpeed), m_sensitivity(sensitivity),
      m_position(0.0f, 1.0f, 3.0f), m_rotation(0.0f, 270.0f), m_velocity(0.0f),
      m_firstMouse(true), m_lastX(0.0), m_lastY(0.0), m_smoothTime(0.1f)
{
    UpdateCamera();
}

void CameraController::Update(float deltaTime)
{
    bool rightMousePressed = Neonix::Input::IsMouseButtonPressed(GLFW_MOUSE_BUTTON_RIGHT);

    if (!rightMousePressed)
    {
        m_firstMouse = true;
        return;
    }

    double mouseX, mouseY;
    Neonix::Input::GetMousePosition(mouseX, mouseY);

    if (m_firstMouse)
    {
        m_lastX = mouseX;
        m_lastY = mouseY;
        m_firstMouse = false;
        return;
    }

    glm::vec2 mouseDelta(mouseX - m_lastX, m_lastY - mouseY);
    m_lastX = mouseX;
    m_lastY = mouseY;

    m_rotation.x += mouseDelta.y * m_sensitivity;
    m_rotation.y += mouseDelta.x * m_sensitivity;
    m_rotation.x = glm::clamp(m_rotation.x, -89.0f, 89.0f);

    glm::vec3 forward(
        glm::cos(glm::radians(m_rotation.y)) * glm::cos(glm::radians(m_rotation.x)),
        glm::sin(glm::radians(m_rotation.x)),
        glm::sin(glm::radians(m_rotation.y)) * glm::cos(glm::radians(m_rotation.x)));
    glm::vec3 right = glm::normalize(glm::cross(forward, glm::vec3(0.0f, 1.0f, 0.0f)));
    glm::vec3 up = glm::normalize(glm::cross(right, forward));

    glm::vec3 direction(0.0f);
    if (Neonix::Input::IsKeyPressed(GLFW_KEY_W))    direction += forward;
    if (Neonix::Input::IsKeyPressed(GLFW_KEY_S))    direction -= forward;
    if (Neonix::Input::IsKeyPressed(GLFW_KEY_D))    direction += right;
    if (Neonix::Input::IsKeyPressed(GLFW_KEY_A))    direction -= right;
    if (Neonix::Input::IsKeyPressed(GLFW_KEY_E))    direction += up;
    if (Neonix::Input::IsKeyPressed(GLFW_KEY_Q))    direction -= up;

    float speed = m_moveSpeed;
    if (Neonix::Input::IsKeyPressed(GLFW_KEY_LEFT_SHIFT))
        speed *= 0.3f;

    if (Neonix::Input::IsKeyPressed(GLFW_KEY_LEFT_CONTROL))
        speed *= 2.0f;

    if (glm::length(direction) > 0.0f)
    {
        direction = glm::normalize(direction);
        glm::vec3 targetVelocity = direction * speed;
        m_velocity = glm::mix(m_velocity, targetVelocity, 1.0f - std::exp(-deltaTime / m_smoothTime));
    }
    else
    {
        m_velocity = glm::mix(m_velocity, glm::vec3(0.0f), 1.0f - std::exp(-deltaTime / m_smoothTime));
    }

    m_position += m_velocity * deltaTime;
    UpdateCamera();
}

void CameraController::UpdateCamera()
{
    glm::vec3 forward(
        glm::cos(glm::radians(m_rotation.y)) * glm::cos(glm::radians(m_rotation.x)),
        glm::sin(glm::radians(m_rotation.x)),
        glm::sin(glm::radians(m_rotation.y)) * glm::cos(glm::radians(m_rotation.x)));

    m_camera->viewMatrix = glm::lookAt(m_position, m_position + forward, glm::vec3(0.0f, 1.0f, 0.0f));
}
