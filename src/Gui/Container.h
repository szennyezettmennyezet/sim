#ifndef CONTAINER_INCLUDED
#define CONTAINER_INCLUDED

#include "GL/gl.h"

#include "Element.h"

#include <vector>

namespace Gui {

	class Container : public Element {

		std::vector<Gui::Element*> childElements;

		protected:
			virtual void drawElement() = 0;

		public:

			void addElement(Element *element)  {
					childElements.push_back(element);
			}

			void draw() {
				drawElement();

				for (unsigned int i = 0; i < childElements.size(); i++) {
					childElements.at(i)->draw();
				}

			}



	};

};



#endif // ELEMENT_INCLUDED
