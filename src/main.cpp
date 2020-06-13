#include "pch.hpp"

#include "primitives3d.hpp"
#include "Renderer.hpp"
#include "math.hpp"
#include "Map.hpp"
#include "Rover.hpp"



int main(int argc, char **argv)
{
	Map map = Map();
	map.set_position(Vec3(200.0, 200.0, 0.0));

	Rover rover = Rover();

	Cube cube = Cube(10.0, Vec3(20, 20, 20), Vec3(45.0, 45.0, 45.0), Vec3(0.0, 1.0, 0.0));
	Cylinder cylinder = Cylinder(30.0, 10.0,  Vec3(-50, -50, -50), Vec3(45.0, 45.0, 45.0), Vec3(0.0, 0.0, 1.0));
	Sphere sphere = Sphere(30.0, Vec3(60, 60, 60), Vec3(45.0, 45.0, 45.0), Vec3(0.9, 0.3, 0.2));

	
	Renderer::complex_render_objects.push_back(std::make_shared<Map>(map));
	Renderer::complex_render_objects.push_back(std::make_shared<Rover>(rover));
	Renderer::render_objects.push_back(std::make_shared<Cube>(cube));
	Renderer::render_objects.push_back(std::make_shared<Cylinder>(cylinder));
	Renderer::render_objects.push_back(std::make_shared<Sphere>(sphere));


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("OPENGL");
	glutInitWindowSize(800, 600);
	glutDisplayFunc(Renderer::render);
	glutSpecialFunc(Renderer::handle_input);
	glutMainLoop();

	return 0;
}



