#include "primitives3d.h"


void Cube::render()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	{
		// Parametry wierzcholkow
        std::cout << "render";

		GLfloat sa[3] = { 0.0f,0.0f,0.0f };
		GLfloat sb[3] = { 10.0f,0.0f,0.0f };
		GLfloat sc[3] = { 10.0f,10.0f,0.0f };
		GLfloat sd[3] = { 0.0f,10.0f,0.0f };
		GLfloat se[3] = { 0.0f,0.0f,-10.0f };
		GLfloat sf[3] = { 10.0f,0.0f,-10.0f };
		GLfloat sg[3] = { 10.0f,10.0f,-10.0f };
		GLfloat sh[3] = { 0.0f,10.0f,-10.0f };

		// wierzcholki gornej sciany
		/* DODANO */GLfloat sGa[3] = { 0.0f, 20.0f, 0.0f };
		/* DODANO */GLfloat sGb[3] = { 10.0f, 20.0f, 0.0f };
		/* DODANO */GLfloat sGc[3] = { 10.0f, 20.0f, -10.0f };
		/* DODANO */GLfloat sGd[3] = { 0.0f, 20.0f, -10.0f };


		// Sciany skladowe
		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_POLYGON);
		glVertex3fv(sa);
		glVertex3fv(sb);
		glVertex3fv(sc);
		glVertex3fv(sd);
		glEnd();

		glColor3f(0.0f, 1.0f, 0.0f);
		glBegin(GL_POLYGON);
		glVertex3fv(sb);
		glVertex3fv(sf);
		glVertex3fv(sg);
		glVertex3fv(sc);
		glEnd();

		glColor3f(0.0f, 0.0f, 1.0f);
		glBegin(GL_POLYGON);
		glVertex3fv(sf);
		glVertex3fv(se);
		glVertex3fv(sh);
		glVertex3fv(sg);
		glEnd();

		glColor3f(1.0f, 1.0f, 0.0f);
		glBegin(GL_POLYGON);
		glVertex3fv(se);
		glVertex3fv(sa);
		glVertex3fv(sd);
		glVertex3fv(sh);
		glEnd();


		// gorna sciana
		glColor3f(0.0f, 1.0f, 1.0f);
		glBegin(GL_POLYGON);
		/* ZMIENIONO */glVertex3fv(sGa);
		/* ZMIENIONO */glVertex3fv(sGb);
		/* ZMIENIONO */glVertex3fv(sGc);
		/* ZMIENIONO */glVertex3fv(sGd);
		glEnd();

		glColor3f(1.0f, 0.0f, 1.0f);
		glBegin(GL_POLYGON);
		glVertex3fv(sa);
		glVertex3fv(sb);
		glVertex3fv(sf);
		glVertex3fv(se);
		glEnd();
	}
}
