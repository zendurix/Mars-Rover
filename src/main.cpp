#include "pch.h"

#include "primitives3d.h"
#include "math.h"


void render(void);


std::vector<Object3d*> render_objects;
float scale = 0.01f;

int main(int argc, char **argv)
{
	Cube cube = Cube(10.0, Vec3(0.2, 0.2, 0.2), Vec3(45.0, 45.0, 45.0), Vec3(0.0, 1.0, 0.0));
	Cylinder cylinder = Cylinder(30.0, 10.0,  Vec3(-0.5, -0.5, -0.5), Vec3(45.0, 45.0, 45.0), Vec3(0.0, 0.0, 1.0));
	Sphere sphere = Sphere(30.0, Vec3(0.6, 0.6, 0.6), Vec3(45.0, 45.0, 45.0), Vec3(0.9, 0.3, 0.2));

	render_objects.push_back(&cube);
	render_objects.push_back(&cylinder);
	render_objects.push_back(&sphere);



	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("OPENGL");
	glutInitWindowSize(800, 600);
	glutDisplayFunc(render);
	glutMainLoop();
	return 0;
}


void render(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
		
	for (auto* object : render_objects)
	{			
		glLoadIdentity();
		glRotatef(object->get_rotation().x, 1, 0, 0);
		glRotatef(object->get_rotation().y, 0, 1, 0);
		glRotatef(object->get_rotation().z, 0, 0, 1);
		glTranslatef(object->get_position().x, object->get_position().y, object->get_position().z);
		glScalef(scale, scale, scale);
		object->render();
		glPolygonMode(GL_BACK,GL_LINE);
	}
	
	glFlush();
	glutSwapBuffers();
}


