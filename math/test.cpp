#include <iostream>
#include <functional>
#include <variant>
#include "vec.hpp"

#if 0
int main() {
	math::vec2 v1(-1, 0.5);
	math::vec2 v2(0, 1);
	std::cout << v1 << std::endl;
	std::cout << v2 << std::endl;
	std::cout << math::dot(v1, v2.yy) << std::endl;
	std::cout << math::dot(v1.xx, v2.yy) << std::endl;

	math::vec4 point(1, 2, 3, 4);
	std::cout << math::dot(point, point.wxyz) << std::endl;
	std::cout << point + 1.f << std::endl;
	std::cout << 1.f + point << std::endl;

	point.xywz = math::vec4(12, 22, 11, 10);
	std::cout << point << std::endl;
}
#endif