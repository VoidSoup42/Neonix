#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Neonix
{
    class Camera
    {
    public:
        Camera(float fov, float aspectRatio, float nearPlane, float farPlane);

        glm::mat4 viewMatrix;

        inline glm::mat4& GetProj() { return m_proj; }
        inline glm::mat4& GetView() { return viewMatrix; }

        void SetAspectRatio(float aspectRatio);
        
    private:
        glm::mat4 m_proj;
        
        float m_aspect;
        float m_nearPlane;
        float m_farPlane;
        float m_fov;
    };
}