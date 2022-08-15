#include "shape_quiz18.h"

std::ostream& operator<<(std::ostream& output, const Shape& shape) {
	return shape.print(output);
}