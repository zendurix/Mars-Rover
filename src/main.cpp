#include "pch.hpp"

#include "primitives3d.hpp"
#include "Renderer.hpp"
#include "math.hpp"
#include "Map.hpp"
#include "Rover.hpp"
#include "Tree.hpp"



int main(int argc, char **argv)
{
	Map map = Map();
	map.set_position_all(Vec3(200.0, 200.0, 0.0));

	Rover rover = Rover();


	std::vector<Tree> forest = {Tree(30.0, 35.0), Tree(59.0, 54.0), Tree(30.0, 45.0), Tree(70.0, 30.0),
		Tree(70.0, 70.0), Tree(90.0, 70.0),Tree(60.0, 20.0),Tree(70.0, 40.0)};


	Renderer::map = std::make_shared<Map>(map);
	Renderer::rover = std::make_shared<Rover>(rover);
	Renderer::complex_render_objects.push_back(Renderer::rover);
	//for (auto tree : forest)
	//	Renderer::complex_render_objects.push_back(std::make_shared<Tree>(tree));

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("OPENGL");
	glutInitWindowSize(800, 600);
	glutDisplayFunc(Renderer::render);
	glutSpecialFunc(Renderer::handle_input);
	glutMainLoop();

	return 0;
}



