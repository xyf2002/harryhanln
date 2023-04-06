#include <GL/freeglut.h>

#include "camera.h"

Camera::Camera(){
	m_pos=Vector3f(0.0f, 0.0f, 0.0f);
	m_targe=Vector3f(0.0f, 0.0f, 1.0f);
	m_up=Vector3f(0.0f, 1.0f, 0.0f);

}

void Camera::SetPosition(){
	m_pos.x=x;
	m_pos.y=y;
	m_pos.z=z;
}

void Camera::OnKeyboard(unsigned char key){
	switch (key){
		case GLUT_KEY_UP:
			m_pos += (m_targe*m_speed); break;
		case GLUT_KEY_DOWN:
			m_pos -= (m_targe*m_speed); break;
		case GLUT_KEY_LEFT:
			{
			Vector3f Left = m_targe.Cross(m_up);
			Left.Normalize();
			Left*=m_speed;
			m_pos+=Left;
			}
		break;
		case GLUT_KEY_RIGHT:
			{
			Vector3f Right = m_up.Cross(m_targe);
			Right.Normalize();
			Right+=m_speed;
			m_pos+=Right;
			}
		break;
		case GLUT_KEY_PAGE_UP:
			m_pos.y+=m_speed;
			break;
		case GLUT_KEY_PAGE_DOWN:
			m_pos.y-=m_speed;
			break;
		case '+':
			m_speed+=0.1;
			printf("Speed Changed to %f\n", m_speed);
			break;
		case '-':
			m_speed-= (m_speed>0.1 ? 0.1 : 0);
			printf("Speed Changed to %f\n", m_speed);
			break;
	}
}

Matrix4f Camera::GetMatrix(){
	Matrix4f CameraTransformation;
	CameraTransformation.InitCameraTransform(m_pos, m_target, m_up);
	return CameraTransformation;
}
