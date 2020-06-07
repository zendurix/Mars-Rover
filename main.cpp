#include <GL/glut.h>


void render(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);



  glLoadIdentity();
  glRotatef(90, 0, 0, 1);
  glScalef(1.0, 1.0, 1.0);
  glTranslatef(-10000, -10000, 300);


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
