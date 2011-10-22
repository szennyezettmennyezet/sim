#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif
#ifdef __APPLE__
#include <SDL/SDL.h>
#else
#include <SDL.h>
#endif

#include "SDL_opengl.h"
#include "Game.h"

#include "Gui/Element.h"
#include "Gui/Panel.h"
#include "Gui/Container.h"


Game *game;

int main ( int argc, char** argv )
{
   if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE,            8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,          8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,           8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,          8);

    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,          16);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,            32);

    SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE,        8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE,    8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE,        8);
    SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE,    8);

    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS,  1);

    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES,  2);

    SDL_Surface *surface;

    if((surface = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_OPENGL)) == NULL) {
        return false;
    }


	game = new Game();

	Gui::Panel *panel = new Gui::Panel(20, 20, 100, 100);

	Gui::Panel *panel2 = new Gui::Panel(20, 20, 100, 100);

	panel->addElement(panel2);

    glClearColor(0, 0, 0, 0);

    glViewport(0, 0, 640, 480);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //glOrtho(0, 640, 480, 0, 100, -100);
    //glFrustum(-320, 320, -320, 320, 0.1, 100);
	//glFrustum (-1.0, 1.0, -1.0, 1.0, 0.1, 100.0);
	gluPerspective(45.0f,(GLfloat)640/(GLfloat)480,0.1f,100.0f);




    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_TEXTURE_2D);

    glLoadIdentity();

    glShadeModel(GL_SMOOTH);                        // Enables Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);                   // Black Background
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);          // Really Nice Perspective Calculations

    // program main loop
    bool done = false;
    while (!done)
    {
        // message processing loop
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
                // exit if the window is closed
            case SDL_QUIT:
                done = true;
                break;

                // check for keypresses
            case SDL_KEYDOWN:
                {
                    // exit if ESCAPE is pressed
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        done = true;

					switch (event.key.keysym.sym) {
						case SDLK_DOWN:
							game->cameraPosition.y -= 5;
							break;
						case SDLK_UP:
							game->cameraPosition.y += 5;
							break;
						case SDLK_LEFT:
							game->cameraPosition.x -= 5;
							break;
						case SDLK_RIGHT:
							game->cameraPosition.x += 5;
							break;
					}

                    break;
                }
            } // end switch
        } // end of message processing

        // DRAWING STARTS HERE

        // clear screen
        //SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));
        glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
        game->draw();
        glLoadIdentity();

           // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // Clear The Screen And The Depth Buffer
    glLoadIdentity();                       // Reset The V
    glTranslatef(-1.5f,0.0f,-6.0f);

    glBegin(GL_TRIANGLES);                      // Drawing Using Triangles
    glVertex3f( 0.0f, 1.0f, 0.0f);              // Top
    glVertex3f(-1.0f,-1.0f, 0.0f);              // Bottom Left
    glVertex3f( 1.0f,-1.0f, 0.0f);              // Bottom Right
glEnd();


glTranslatef(3.0f,0.0f,0.0f);

glBegin(GL_QUADS);                      // Draw A Quad
        glVertex3f(-1.0f, 1.0f, 0.0f);              // Top Left
        glVertex3f( 1.0f, 1.0f, 0.0f);              // Top Right
        glVertex3f( 1.0f,-1.0f, 0.0f);              // Bottom Right
        glVertex3f(-1.0f,-1.0f, 0.0f);              // Bottom Left
    glEnd();

                //panel->draw();

    SDL_GL_SwapBuffers();    } // end main loop

    // free loaded bitmap

    // all is well ;)
    printf("Exited cleanly\n");
    return 0;
}
