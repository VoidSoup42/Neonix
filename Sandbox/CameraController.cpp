#include "CameraController.hpp"

CameraController::CameraController(Neonix::Camera* camera, float moveSpeed, float sensitivity)
    : m_camera(camera), m_moveSpeed(moveSpeed), m_sensitivity(sensitivity)
{
    m_position = glm::vec3(0.0f, 0.0f, 3.0f);
    m_rotation = glm::vec2(0.0f, 270.0f); // pitch, yaw
    m_firstMouse = true;
    UpdateCamera();
}

void CameraController::Update(float deltaTime)
{
    // Check if right mouse button state changed
    bool rightMousePressed = Neonix::Input::IsMouseButtonPressed(GLFW_MOUSE_BUTTON_RIGHT);
    
    if (!rightMousePressed)
    {
        m_firstMouse = true;
        return;
    }

    // Get mouse movement
    double mouseX, mouseY;
    Neonix::Input::GetMousePosition(mouseX, mouseY);
    
    if (m_firstMouse)
    {
        m_lastX = mouseX;
        m_lastY = mouseY;
        m_firstMouse = false;
        return;
    }
    
    glm::vec2 mouseDelta(mouseX - m_lastX, m_lastY - mouseY); // Inverted Y for intuitive control
    m_lastX = mouseX;
    m_lastY = mouseY;

    // Update rotation
    m_rotation.x += mouseDelta.y * m_sensitivity; // pitch
    m_rotation.y += mouseDelta.x * m_sensitivity; // yaw

    // Clamp pitch to prevent camera flipping
    m_rotation.x = glm::clamp(m_rotation.x, -89.0f, 89.0f);

    // Calculate movement direction
    glm::vec3 forward(
        cos(glm::radians(m_rotation.y)) * cos(glm::radians(m_rotation.x)),
        sin(glm::radians(m_rotation.x)),
        sin(glm::radians(m_rotation.y)) * cos(glm::radians(m_rotation.x))
    );
    glm::vec3 right = glm::normalize(glm::cross(forward, glm::vec3(0.0f, 1.0f, 0.0f)));
    glm::vec3 up = glm::normalize(glm::cross(right, forward));

    // Handle keyboard input
    glm::vec3 moveDir(0.0f);
    if (Neonix::Input::IsKeyPressed(GLFW_KEY_W))    moveDir += forward;
    if (Neonix::Input::IsKeyPressed(GLFW_KEY_S))    moveDir -= forward;
    if (Neonix::Input::IsKeyPressed(GLFW_KEY_D))    moveDir += right;
    if (Neonix::Input::IsKeyPressed(GLFW_KEY_A))    moveDir -= right;
    if (Neonix::Input::IsKeyPressed(GLFW_KEY_E))    moveDir += up;
    if (Neonix::Input::IsKeyPressed(GLFW_KEY_Q))    moveDir -= up;

    if (glm::length(moveDir) > 0.0f)
        m_position += glm::normalize(moveDir) * m_moveSpeed * deltaTime;

    UpdateCamera();
}

void CameraController::UpdateCamera()
{
    glm::vec3 forward(
        cos(glm::radians(m_rotation.y)) * cos(glm::radians(m_rotation.x)),
        sin(glm::radians(m_rotation.x)),
        sin(glm::radians(m_rotation.y)) * cos(glm::radians(m_rotation.x))
    );

    m_camera->viewMatrix = glm::lookAt(m_position, m_position + forward, glm::vec3(0.0f, 1.0f, 0.0f));
}
