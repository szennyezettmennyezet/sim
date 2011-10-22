#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include "GL/gl.h"

#include <iostream>

#include <vector>

struct Vertex4 {
    float x;
    float y;
    float z;
    float w;
};

struct Color4 {
    float r;
    float g;
    float b;
    float a;

};


class Game {
    Vertex4 *vertices;
    Color4 *colors;

	std::vector<Vertex4> cube;
	std::vector<Color4> cubeColors;


	double rotX, rotY;

    public:
		Vertex4 cameraPosition;
		Vertex4 cameraRotation;


        Game() {

        	cameraPosition.x = 0;
        	cameraPosition.y = 0;
        	cameraPosition.z = 0;
        	cameraPosition.w = 1;

        	cameraRotation.x = 0.0;
        	cameraRotation.y = 0.0;
        	cameraRotation.z = 0.0;
        	cameraRotation.w = 0.0;


        	std::cout << "draw" << std::endl;
            vertices = new Vertex4[4];
            vertices[0].x = 0;	vertices[0].y = 0;	vertices[0].z = 0;  vertices[0].w = 1;
            vertices[1].x = 30;	vertices[1].y = 0;	vertices[1].z = 0;  vertices[1].w = 1;
            vertices[2].x = 30;	vertices[2].y = 30;	vertices[2].z = 0;  vertices[2].w = 1;
            vertices[3].x = 0;	vertices[3].y = 30;	vertices[3].z = 0;  vertices[3].w = 1;
            colors = new Color4[4];
            colors[0].r = 1.0;	colors[0].g = 0.0;	colors[0].b = 0.0;	colors[0].a = 0.0;
            colors[1].r = 1.0;	colors[1].g = 1.0;	colors[1].b = 0.0;	colors[1].a = 0.0;
            colors[2].r = 1.0;	colors[2].g = 0.0;	colors[2].b = 1.0;	colors[2].a = 0.0;
            colors[3].r = 1.0;	colors[3].g = 1.0;	colors[3].b = 1.0;	colors[3].a = 0.0;

			rotX = rotY = 0;

			Vertex4 vertex;vertex.w = 0.0;
			Color4 color;


			color.r = 1.0; color.g = 0.0; color.b = 0.0; color.a = 0.0;
			vertex.x =  0.0; vertex.y =  0.0; vertex.z =  0.0; cube.push_back(vertex); cubeColors.push_back(color);
			vertex.x =  0.0; vertex.y = 40.0; vertex.z =  0.0; cube.push_back(vertex); cubeColors.push_back(color);
			vertex.x = 40.0; vertex.y = 40.0; vertex.z =  0.0; cube.push_back(vertex); cubeColors.push_back(color);
			vertex.x =  0.0; vertex.y =  0.0; vertex.z =  0.0; cube.push_back(vertex); cubeColors.push_back(color);
			vertex.x = 40.0; vertex.y = 40.0; vertex.z =  0.0; cube.push_back(vertex); cubeColors.push_back(color);
			vertex.x = 40.0; vertex.y =  0.0; vertex.z =  0.0; cube.push_back(vertex); cubeColors.push_back(color);

			vertex.x =  0.0; vertex.y =  0.0; vertex.z = 40.0; cube.push_back(vertex); cubeColors.push_back(color);
			vertex.x =  0.0; vertex.y = 40.0; vertex.z = 40.0; cube.push_back(vertex); cubeColors.push_back(color);
			vertex.x = 40.0; vertex.y = 40.0; vertex.z = 40.0; cube.push_back(vertex); cubeColors.push_back(color);
			vertex.x =  0.0; vertex.y =  0.0; vertex.z = 40.0; cube.push_back(vertex); cubeColors.push_back(color);
			vertex.x = 40.0; vertex.y = 40.0; vertex.z = 40.0; cube.push_back(vertex); cubeColors.push_back(color);
			vertex.x = 40.0; vertex.y =  0.0; vertex.z = 40.0; cube.push_back(vertex); cubeColors.push_back(color);

			color.r = 0.0; color.g = 1.0; color.b = 0.0; color.a = 0.0;
			vertex.x =  0.0; vertex.y =  0.0; vertex.z =  0.0; cube.push_back(vertex); cubeColors.push_back(color);
			vertex.x =  0.0; vertex.y =  0.0; vertex.z = 40.0; cube.push_back(vertex); cubeColors.push_back(color);
			vertex.x = 40.0; vertex.y =  0.0; vertex.z = 40.0; cube.push_back(vertex); cubeColors.push_back(color);
			vertex.x =  0.0; vertex.y =  0.0; vertex.z =  0.0; cube.push_back(vertex); cubeColors.push_back(color);
			vertex.x = 40.0; vertex.y =  0.0; vertex.z = 40.0; cube.push_back(vertex); cubeColors.push_back(color);
			vertex.x = 40.0; vertex.y =  0.0; vertex.z =  0.0; cube.push_back(vertex); cubeColors.push_back(color);

			vertex.x =  0.0; vertex.y = 40.0; vertex.z =  0.0; cube.push_back(vertex); cubeColors.push_back(color);
			vertex.x =  0.0; vertex.y = 40.0; vertex.z = 40.0; cube.push_back(vertex); cubeColors.push_back(color);
			vertex.x = 40.0; vertex.y = 40.0; vertex.z = 40.0; cube.push_back(vertex); cubeColors.push_back(color);
			vertex.x =  0.0; vertex.y = 40.0; vertex.z =  0.0; cube.push_back(vertex); cubeColors.push_back(color);
			vertex.x = 40.0; vertex.y = 40.0; vertex.z = 40.0; cube.push_back(vertex); cubeColors.push_back(color);
			vertex.x = 40.0; vertex.y = 40.0; vertex.z =  0.0; cube.push_back(vertex); cubeColors.push_back(color);

			color.r = 0.0; color.g = 0.0; color.b = 1.0; color.a = 0.0;
			vertex.x =  0.0; vertex.y =  0.0; vertex.z =  0.0; cube.push_back(vertex); cubeColors.push_back(color);
			vertex.x =  0.0; vertex.y =  0.0; vertex.z = 40.0; cube.push_back(vertex); cubeColors.push_back(color);
			vertex.x =  0.0; vertex.y = 40.0; vertex.z = 40.0; cube.push_back(vertex); cubeColors.push_back(color);
			vertex.x =  0.0; vertex.y =  0.0; vertex.z =  0.0; cube.push_back(vertex); cubeColors.push_back(color);
			vertex.x =  0.0; vertex.y = 40.0; vertex.z = 40.0; cube.push_back(vertex); cubeColors.push_back(color);
			vertex.x =  0.0; vertex.y = 40.0; vertex.z =  0.0; cube.push_back(vertex); cubeColors.push_back(color);

			vertex.x = 40.0; vertex.y =  0.0; vertex.z =  0.0; cube.push_back(vertex); cubeColors.push_back(color);
			vertex.x = 40.0; vertex.y =  0.0; vertex.z = 40.0; cube.push_back(vertex); cubeColors.push_back(color);
			vertex.x = 40.0; vertex.y = 40.0; vertex.z = 40.0; cube.push_back(vertex); cubeColors.push_back(color);
			vertex.x = 40.0; vertex.y =  0.0; vertex.z =  0.0; cube.push_back(vertex); cubeColors.push_back(color);
			vertex.x = 40.0; vertex.y = 40.0; vertex.z = 40.0; cube.push_back(vertex); cubeColors.push_back(color);
			vertex.x = 40.0; vertex.y = 40.0; vertex.z =  0.0; cube.push_back(vertex); cubeColors.push_back(color);
        }

        void drawCube() {
			glTranslatef(-20, -20, 0.0);
			glBegin(GL_TRIANGLES);
			for (unsigned int i = 0; i< cube.size(); i++) {
				glColor3fv(&cubeColors.at(i).r);
				glVertex3fv(&cube.at(i).x);
            }
			glEnd();
        }


        void draw() {

        	rotX += 0.01;
        	rotY += 0.01;

			//glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glLoadIdentity();



            //for (unsigned int x = 0; x < 10; x++) {
                //for (unsigned int y = 0; y < 10; y++) {
                    glLoadIdentity();

                    glTranslated(-cameraPosition.x, cameraPosition.y, 20.0);

					//cameraRotation.x = 45;

                    //glRotated(cameraRotation.x, 1.0, 0.0, 0.0);
                    //glRotated(rotY, 0.0, 1.0, 0.0);

					glPushMatrix();
						glTranslatef(100, 100, 0.0);
						drawCube();
					glPopMatrix();

					glPushMatrix();
						glTranslatef(150, 100, 0.0);
						drawCube();
					glPopMatrix();

					glPushMatrix();
						glTranslatef(100, 180, 0.0);
						drawCube();
					glPopMatrix();

					//glBegin(GL_QUADS);
						/*for (unsigned int i = 0; i < 4; i++) {
							glColor3fv(&colors[i].r);
							glVertex3fv(&vertices[i].x);
							//glColor3f(colors[i].r, colors[i].g, colors[i].b);
							//glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);
						}*/
                        /*glColor3f(1, 0, 0); glVertex3f(0, 0, 0);
                        glColor3f(1, 1, 0); glVertex3f(30, 0, 0);
                        glColor3f(1, 0, 1); glVertex3f(30, 30, 0);
                        glColor3f(1, 1, 1); glVertex3f(0, 30, 0);*/
                    //glEnd();
                //}
            //}
        }

};




#endif // GAME_INCLUDED
