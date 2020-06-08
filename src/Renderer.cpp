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
	glLoadIdentity();
	glRotatef(object->get_rotation().x, 1, 0, 0);
	glRotatef(object->get_rotation().y, 0, 1, 0);
	glRotatef(object->get_rotation().z, 0, 0, 1);
	glTranslatef(object->get_position().x, object->get_position().y, object->get_position().z);
	glScalef(scale, scale, scale);
	object->render();
}


