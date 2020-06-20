#include "Renderer.hpp"
#include "pch.hpp"

#include "Object3d.hpp"
#include "Map.hpp"
#include "Rover.hpp"


void Renderer::render(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
		
	render_map();
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
	float rot_y = object->get_rotation().y;
	float rot_z = object->get_rotation().z;

	glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		glRotatef(object->get_rotation().x + Renderer::camera_rotate_x, 1, 0, 0);
		glRotatef(rot_z, 0, 1, 0);
		glRotatef(rot_y + Renderer::camera_rotate_y, 0, 0, 1);
		glTranslatef((object->get_position().x * scale), (object->get_position().y * scale), (object->get_position().z * scale));
		glScalef(scale, scale, scale);
		object->render();
	glPopMatrix();
}

void Renderer::render_map()
{
	for (auto object : map->get_objects3d())
	{
		float rot_y = object->get_rotation().y;
	float rot_z = object->get_rotation().z;

	glPushMatrix();

	//glLoadIdentity();
	glRotatef(object->get_rotation().x + Renderer::camera_rotate_x, 1, 0, 0);
	glRotatef(rot_z, 0, 1, 0);
	glRotatef(rot_y + Renderer::camera_rotate_y, 0, 0, 1);
	glTranslatef(object->get_position().x * scale, object->get_position().y * scale, object->get_position().z * scale);
	glScalef(scale, scale, scale);
	object->render();
	
	glPopMatrix();
	}
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
	case GLUT_KEY_RIGHT:
		Renderer::rover->rotate(Vec3(0.0, 0.0, -5.0));
		break;
	case GLUT_KEY_LEFT:
		Renderer::rover->rotate(Vec3(0.0, 0.0, 5.0)); 
		break;
	case GLUT_KEY_UP:
		Renderer::rover->move(Vec3(0.0, 0.0, -3.0));
		break;
	case GLUT_KEY_DOWN:
		Renderer::rover->move(Vec3(0.0, 0.0, 3.0));
		break;

	case GLUT_KEY_F3:
		Renderer::camera_rotate_y += 3.0;
		break;
	case GLUT_KEY_F4:
		Renderer::camera_rotate_y -= 3.0;
		break;
	}
  	glutPostRedisplay();
}