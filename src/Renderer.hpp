#ifndef RENDERER_HPP
#define RENDERER_HPP

class Object3d;
class ComplexObject3d;
class Map;
class Rover;

// Because glutDisplayFunc can't take pointers to bound functions (like class methods)
// Renderer is namespace instead of class
// This is not a problem, because this program uses only one renderer
namespace Renderer
{
    inline std::shared_ptr<Map> map = nullptr;
    inline std::shared_ptr<Rover> rover = nullptr;
    inline std::vector<std::shared_ptr<ComplexObject3d>> complex_render_objects;
    inline float scale = 0.01f;
    inline float camera_rotate_y = 0.0f;
    inline float camera_rotate_x = 60.0f;

    void render(void);
    void handle_input(int key, int a, int b);
    void render_map();
}

#endif // RENDERER_HPP