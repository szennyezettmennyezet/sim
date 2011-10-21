#ifndef PANEL_INCLUDED
#define PANEL_INCLUDED

#include "GL/gl.h"
#include "Container.h"

namespace Gui {


	class Panel : public Container {
		int x1;
		int x2;
		int y1;
		int y2;

		public:
			Panel(int x1, int y1, int x2, int y2): x1(x1), y1(y1), x2(x2), y2(y2) {}
			void drawElement() {

				glTranslatef(x1, y1, 0.0);

				glBegin(GL_QUADS);
					glVertex3f(0.0, 0.0, 0.0);
					glVertex3f(0.0, y2, 0.0);
					glVertex3f(x2, y2, 0.0);
					glVertex3f(x2, 0.0, 0.0);
				glEnd();

			}

	};

};



#endif // ELEMENT_INCLUDED
