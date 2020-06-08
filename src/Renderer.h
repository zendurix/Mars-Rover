#ifndef RENDERER_H
#define RENDERER_H

class Object3d;
class ComplexObject3d;

// Because glutDisplayFunc can't take pointers to bound functions (like class methods)
// Renderer is namespace instead of class
// This is not a problem, because this program uses only one renderer
namespace Renderer
{
    inline std::vector<std::shared_ptr<Object3d>> render_objects;
    inline std::vector<std::shared_ptr<ComplexObject3d>> complex_render_objects;
    inline float scale = 0.01f;


    void render(void);
    void render_object(std::shared_ptr<Object3d> object);
}

#endif // RENDERER_H