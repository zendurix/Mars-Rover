#include "pch.h"

#include "primitives3d.h"
#include "Renderer.h"
#include "math.h"


void render(void);
void render_object(Object3d* object);




int main(int argc, char **argv)
{
	Cube cube = Cube(10.0, Vec3(0.2, 0.2, 0.2), Vec3(45.0, 45.0, 45.0), Vec3(0.0, 1.0, 0.0));
	Cylinder cylinder = Cylinder(30.0, 10.0,  Vec3(-0.5, -0.5, -0.5), Vec3(45.0, 45.0, 45.0), Vec3(0.0, 0.0, 1.0));
	Sphere sphere = Sphere(30.0, Vec3(0.6, 0.6, 0.6), Vec3(45.0, 45.0, 45.0), Vec3(0.9, 0.3, 0.2));

	Renderer::render_objects.push_back(std::make_shared<Cube>(cube));
	Renderer::render_objects.push_back(std::make_shared<Cylinder>(cylinder));
	Renderer::render_objects.push_back(std::make_shared<Sphere>(sphere));


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("OPENGL");
	glutInitWindowSize(800, 600);
	glutDisplayFunc(Renderer::render);
	glutMainLoop();
	return 0;
}



