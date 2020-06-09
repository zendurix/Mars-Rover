#include "Map.h"
#include "pch.h"


void Map::render() 
{
    float xs = 200.0f;
    float ys = 200.0f;
    float size = 100.0f;
    float xPos, yPos, H;
    for (int j = 0; j < ys; j++)
    {
      yPos = size * j;
      for (int i = 0; i < xs; i++)
      {
        xPos = size * i;
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.7, 0.1 + 0.001 * (i % 100), 0.1 + 0.01 * (j % 10));
        glVertex3d((xPos + 0), (yPos + 0), 0);
        glVertex3d((xPos + size), (yPos + 0), 0);
        glVertex3d((xPos + size), (yPos + size), 0);
        glVertex3d((xPos + 0), (yPos + size), 0);
        glEnd();
      }
    }
}