#include "Renderer.h"
#include "pch.h"

#include "Object3d.h"


void Renderer::render(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
		
	for (auto object : Renderer::render_objects)
	{			
		render_object(object);
	}

	for (auto complex_object : Renderer::complex_render_objects)
	{
		for (auto object : complex_object->get_objects3d())
		{			
			render_object(object);
		}
	}
	
	glFlush();
	glutSwapBuffers();
}

void Renderer::render_object(std::shared_ptr<Object3d> object)
{
	float rot_y = object->get_rotation().z;
	float rot_z = object->get_rotation().y;


	glLoadIdentity();
	glRotatef(object->get_rotation().x + Renderer::camera_rotate_x, 1, 0, 0);
	glRotatef(rot_z, 0, 1, 0);
	glRotatef(rot_y + Renderer::camera_rotate_y, 0, 0, 1);
	glTranslatef(object->get_position().x, object->get_position().y, object->get_position().z);
	glScalef(scale, scale, scale);
	object->render();
}


void Renderer::handle_input(int key, int a, int b) 
{
	switch (key)
	{
	case GLUT_KEY_F1:
		Renderer::scale -= 0.001;
		break;
	case GLUT_KEY_F2:
		Renderer::scale += 0.001;
		break;
	}
  	glutPostRedisplay();
}