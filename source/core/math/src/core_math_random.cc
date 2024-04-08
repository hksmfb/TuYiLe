#include "core_math_random.h"

namespace TuYiLe{
namespace corelayer {
namespace math{

Random::Random() {
  e_.seed(42);
}

Random::~Random() {

}

float Random::Rand(float start, float end) {
  std::uniform_real_distribution<float> u(start, end);
  return u(e_);
}

Random* randomgenerator = nullptr;

}
}
}