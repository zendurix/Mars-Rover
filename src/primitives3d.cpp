#include "primitives3d.hpp"
#include "pch.hpp"

void Cube::render()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	GLfloat sa[3] = { 0.0f,0.0f,0.0f };
	GLfloat sb[3] = { 10.0f,0.0f,0.0f };
	GLfloat sc[3] = { 10.0f,10.0f,0.0f };
	GLfloat sd[3] = { 0.0f,10.0f,0.0f };
	GLfloat se[3] = { 0.0f,0.0f,-10.0f };
	GLfloat sf[3] = { 10.0f,0.0f,-10.0f };
	GLfloat sg[3] = { 10.0f,10.0f,-10.0f };
	GLfloat sh[3] = { 0.0f,10.0f,-10.0f };
	
	glColor3f(this->color.x, this->color.y, this->color.z);
	glBegin(GL_POLYGON);
		glVertex3fv(sa);
		glVertex3fv(sb);
		glVertex3fv(sc);
		glVertex3fv(sd);
	glEnd();	
	glBegin(GL_POLYGON);
		glVertex3fv(sb);
		glVertex3fv(sf);
		glVertex3fv(sg);
		glVertex3fv(sc);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3fv(sf);
		glVertex3fv(se);
		glVertex3fv(sh);
		glVertex3fv(sg);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3fv(se);
		glVertex3fv(sa);
		glVertex3fv(sd);
		glVertex3fv(sh);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3fv(sa);
		glVertex3fv(sb);
		glVertex3fv(sc);
		glVertex3fv(sd);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex3fv(sa);
		glVertex3fv(sb);
		glVertex3fv(sf);
		glVertex3fv(se);
	glEnd();
}








void circle(float r, Vec3 coord, Vec3 center_color, Vec3 outline_color) {
	center_color.x += 0.3;
	outline_color.y += 0.3;
	double alpha;
	glBegin(GL_TRIANGLE_FAN);
	glColor3d(center_color.x, center_color.y, center_color.z);
	glVertex3d(coord.x, coord.y, coord.z);

	for (double i = 0; i <= 2.0 * PI; i += PI / 64.0)
	{
		alpha = (coord.z <= 0.0) ? i : -i;
		glColor3d(outline_color.x, outline_color.y, outline_color.z);
		glVertex3d(r * sin(alpha), r * cos(alpha), coord.z);
	}
	glEnd();
}


void Cylinder::render()
{
	double alpha;

	// Lower base
	circle(this->radius, Vec3(0.0, 0.0, -this->height / 2.0), this->color, this->color);
	
	// Upeer Base
	circle(this->radius, Vec3(0.0, 0.0, this->height / 2.0), this->color, this->color);	

	// Side wall
	for (alpha = 0.0; alpha <= 2.0 * PI; alpha += PI / 64.0)
	{
		glBegin(GL_TRIANGLE_STRIP);
		for (float i = -this->height / 2.0, j = 0;
			 i <= this->height/ 2.0;
			 i += 0.5, j++)
		{
		glColor3f(this->color.x, this->color.y, this->color.z);
			glVertex3d(this->radius * cos(alpha), this->radius * sin(alpha), i);
			glVertex3d(this->radius * cos(alpha + PI / 64), this->radius * sin(alpha + PI / 64), i);
		}
		glEnd();
	}

}








void Sphere::render()
{
    float gradation = 30;
    float x, y, z;

    for (float alpha = 0.0; alpha < PI; alpha += PI/gradation)
    {        
        glBegin(GL_TRIANGLE_STRIP);
			for (float beta = 0.0; beta < 2.01*PI; beta += PI/gradation)            
			{            
			// glBegin(GL_POLYGON);
				x = radius*cos(beta)*sin(alpha);
				y = radius*sin(beta)*sin(alpha);
				z = radius*cos(alpha);
				glColor3f(this->color.x, this->color.y, this->color.z);
				glVertex3f(x, y, z);
				x = radius*cos(beta)*sin(alpha + PI/gradation);
				y = radius*sin(beta)*sin(alpha + PI/gradation);
				z = radius*cos(alpha + PI/gradation);      
				glColor3f(this->color.x, this->color.y, this->color.z);      
				glVertex3f(x, y, z);       
			// glVertex3f(x, y, z);       
			// glEnd();
			}     
        glEnd();
    }
}


void Rectangle::render() 
{
    glBegin(GL_TRIANGLE_STRIP);
		glColor3f(this->color.x, this->color.y, this->color.z); 
	  	glVertex3d(-this->length/2,  this->height/2, 0.0);
		glVertex3d(-this->length/2, -this->height/2, 0.0);
		glVertex3d( this->length/2,  this->height/2, 0.0);
		glVertex3d( this->length/2, -this->height/2, 0.0);
    glEnd();
}



void Object8points::render()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	GLfloat sa[3] = { this->points[0].x, this->points[0].y, this->points[0].z };
	GLfloat sb[3] = { this->points[1].x, this->points[1].y, this->points[1].z };
	GLfloat sc[3] = { this->points[2].x, this->points[2].y, this->points[2].z };
	GLfloat sd[3] = { this->points[3].x, this->points[3].y, this->points[3].z };
	GLfloat se[3] = { this->points[4].x, this->points[4].y, this->points[4].z };
	GLfloat sf[3] = { this->points[5].x, this->points[5].y, this->points[5].z };
	GLfloat sg[3] = { this->points[6].x, this->points[6].y, this->points[6].z };
	GLfloat sh[3] = { this->points[7].x, this->points[7].y, this->points[7].z };
	
	glBegin(GL_POLYGON);
		glColor3f(this->color.x, this->color.y, this->color.z);
		glVertex3fv(sa);
		glVertex3fv(sb);
		glVertex3fv(sc);
		glVertex3fv(sd);
	glEnd();	
	glBegin(GL_POLYGON);
		glColor3f(this->color.x + 0.3, this->color.y + 0.5, this->color.z);
		glVertex3fv(sb);
		glVertex3fv(sf);
		glVertex3fv(sg);
		glVertex3fv(sc);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(this->color.x, this->color.y + 0.3, this->color.z);
		glVertex3fv(sf);
		glVertex3fv(se);
		glVertex3fv(sh);
		glVertex3fv(sg);
	glEnd();
	glBegin(GL_POLYGON);

	glColor3f(this->color.x + 0.3, this->color.y + 0.3, this->color.z);
		glVertex3fv(se);
		glVertex3fv(sa);
		glVertex3fv(sd);
		glVertex3fv(sh);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(this->color.x, this->color.y + 0.3, this->color.z + 0.3);
		glVertex3fv(sa);
		glVertex3fv(sb);
		glVertex3fv(sc);
		glVertex3fv(sd);
	glEnd();
	glBegin(GL_POLYGON);

	glColor3f(this->color.x + 0.3, this->color.y + 0.3, this->color.z + 0.3);
		glVertex3fv(sa);
		glVertex3fv(sb);
		glVertex3fv(sf);
		glVertex3fv(se);
	glEnd();
}
