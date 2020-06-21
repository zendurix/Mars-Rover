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
		glPushMatrix();
			glTranslatef(complex_object->get_position().x * scale, complex_object->get_position().y * scale, complex_object->get_position().z * scale);
			glPushMatrix();
				glScalef(scale, scale, scale);
				glTranslatef(0, 0, 0);
				glRotatef(complex_object->get_rotation().x, 1, 0, 0);
				glRotatef(complex_object->get_rotation().y + Renderer::camera_rotate_y, 0, 0, 1);
				glRotatef(complex_object->get_rotation().z, 0, 1, 0);
				glTranslatef(0, 0, 0);
				for (auto object : complex_object->get_objects3d())
				{			
					object->render();
				}
			glPopMatrix();
		glPopMatrix();
	}
	
	glFlush();
	glutSwapBuffers();
}

void Renderer::render_object(std::shared_ptr<Object3d> object)
{
	float rot_x = object->get_rotation().x;
	float rot_y = object->get_rotation().y;
	float rot_z = object->get_rotation().z;

	glPushMatrix();
	glLoadIdentity();
		glTranslatef(0, 0, 0);
		
		glRotatef(rot_x + Renderer::camera_rotate_x, 1, 0, 0);
		glRotatef(rot_y  + Renderer::camera_rotate_y, 0, 0, 1);
		glRotatef(rot_z, 0, 1, 0);
		glTranslatef(0, 0,0 );

		//glTranslatef((object->get_position().x * scale), (object->get_position().y * scale), (object->get_position().z * scale));
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
	case GLUT_KEY_F3:
		Renderer::camera_rotate_y += 3.0;
		break;
	case GLUT_KEY_F4:
		Renderer::camera_rotate_y -= 3.0;
		break;

	case GLUT_KEY_RIGHT:
		Renderer::rover->set_rotation( Vec3(
			Renderer::rover->get_rotation().x,
			Renderer::rover->get_rotation().y - 5.0,
			Renderer::rover->get_rotation().z
		));
		break;
	case GLUT_KEY_LEFT:
		Renderer::rover->set_rotation( Vec3(
			Renderer::rover->get_rotation().x,
			Renderer::rover->get_rotation().y + 5.0,
			Renderer::rover->get_rotation().z
		));
		break;

	case GLUT_KEY_UP:				
		Renderer::rover->set_position( Vec3(
			Renderer::rover->get_position().x + 2 * cos((rover->get_rotation().x * PI) / 180) ,
			Renderer::rover->get_position().y ,
			Renderer::rover->get_position().z + 2 * sin(-(rover->get_rotation().y * PI) / 180) 
		));
		break;
	case GLUT_KEY_DOWN:
		Renderer::rover->set_position( Vec3(
			Renderer::rover->get_position().x - 1 * cos((rover->get_rotation().x * PI) / 180) ,
			Renderer::rover->get_position().y ,
			Renderer::rover->get_position().z - 1 * sin(-(rover->get_rotation().y * PI) / 180) 
		));
		break;


	}
  	glutPostRedisplay();
}