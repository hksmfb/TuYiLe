#ifndef CORE_MATH_RANDOM_H_
#define CORE_MATH_RANDOM_H_

#include <cmath>
#include <random>

namespace TuYiLe{
namespace corelayer {
namespace math{

class Random {
 public:
  Random();
  ~Random();
  std::vector<float> NormalDistribution(float mean, float sd, int count);
  float NormalDistribution(float mean, float sd);
  /**
   * @brief Generate a random number list.
   * @param start left close interval.
   * @param end right close interval.
   * @param count how many random number want to generate.
  */
  std::vector<float> Rand(float start, float end, int count);
  float Rand(float start, float end);
  std::vector<int> Rand(int start, int end, int count);
  int Rand(int start, int end);
 private:
  std::default_random_engine e_;
};

extern Random* randomgenerator;

}
}
}

#endif