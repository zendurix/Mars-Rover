#ifndef MESH_H
#define MESH_H

#include "math.h"

class Vertex
{
public:
    Vec3 position;
    Vec3 normal;
    Vec2 texture_coord;
};

class Texture
{
public:
    unsigned int id;
    std::string type;
};


class Mesh
{
private:
    // vertex array objects
    unsigned int VAO;
    // vertex buffer objects
    unsigned int VBO;
    // element buffer object
    unsigned int EBO;

    void setup();

public:
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;

    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
    void Draw();
};




#endif // MESH_H