#include "point.hpp"

namespace math {

template struct point<float, 2>;
template struct point<float, 3>;
template struct point<float, 4>;

template struct point<int, 2>;
template struct point<int, 3>;
template struct point<int, 4>;

template struct point<short, 2>;
template struct point<short, 3>;
template struct point<short, 4>;

}