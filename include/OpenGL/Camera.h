#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <glm/glm.hpp>

namespace CppUtility {
	namespace OpenGL {
		class Camera
		{
		public:
			enum ENUM_Projection {
				PROJECTION_PERSEPCTIVE,
				PROJECTION_ORTHO
			};

			Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 4.0f), float yaw = YAW, float pitch = PITCH, float rationWH = RATIO_WH, float nearPlane = NEAR_PLANE, float farPlane = FAR_PLANE, glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), ENUM_Projection projectionMode = PROJECTION_MODE);

			glm::mat4 GetViewMatrix();
			glm::mat4 GetProjectionMatrix();

			void SetPerspective();
			void SetOrtho();
			glm::vec3 & GetPos();
		private:
			void updateCameraVectors();

			// Camera Attributes
			glm::vec3 position;
			glm::vec3 front;
			glm::vec3 up;
			glm::vec3 right;
			const glm::vec3 worldUp;
			float fov;
			float rationWH;
			float nearPlane;
			float farPlane;
			float yaw;
			float pitch;
			ENUM_Projection projectionMode;

			// Default camera values
			static const float RATIO_WH;
			static const float NEAR_PLANE;
			static const float FAR_PLANE;
			static const float YAW;
			static const float PITCH;
			static const float FOV;
			static const ENUM_Projection PROJECTION_MODE;
		};
	}
}
#endif//! _CAMERA_H_