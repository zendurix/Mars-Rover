#include "pch.h"


#include "primitives3d.h"
#include "math.h"


void render(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	
	
	
	glLoadIdentity();
	glRotatef(47, 0, 0, 1);
	glRotatef(47, 0, 1, 0);
	glRotatef(47, 1, 0, 0);
	glScalef(1.0, 1.0, 1.0);
	Cube cube = Cube(3.0, Vec3(1.0, 1.0, 1.0));

	std::cout<<"main";
	cube.render();
	
	
	glFlush();
	glutSwapBuffers();
}

int main(int argc, char **argv)
{


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("OPENGL");
	glutInitWindowSize(1920, 1080);
	glutDisplayFunc(render);
	glutMainLoop();
	return 0;
}
