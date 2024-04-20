#ifndef CORE_MATH_VECTRANSFORM_H_
#define CORE_MATH_VECTRANSFORM_H_

#define GLM_FORCE_SIMD_AVX2
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

namespace TuYiLe{
namespace corelayer {
namespace math{

struct floatvec2 {
  float x{0};
  float y{0};
  floatvec2& operator+=(const floatvec2& vec) {
    x += vec.x;
    y += vec.y;
    return *this;
  }
  floatvec2 operator+(const floatvec2& vec) const {
    floatvec2 v;
    v.x = this->x + vec.x;
    v.y = this->y + vec.y;
    return v;
  }
  floatvec2 operator-(const floatvec2& vec) const {
    floatvec2 v;
    v.x = this->x - vec.x;
    v.y = this->y - vec.y;
    return v;
  }
  floatvec2 operator*(const float& f) const {
    floatvec2 v;
    v.x = this->x * f;
    v.y = this->y * f;
    return v;
  }
};

struct floatvec3 {
  float x{0};
  float y{0};
  float z{0};
  floatvec3& operator+=(const floatvec3& vec) {
    x += vec.x;
    y += vec.y;
    z += vec.z;
    return *this;
  }
  floatvec3 operator+(const floatvec3& vec) const {
    floatvec3 v;
    v.x = this->x + vec.x;
    v.y = this->y + vec.y;
    v.z = this->z + vec.z;
    return v;
  }
  floatvec3 operator-(const floatvec3& vec) const {
    floatvec3 v;
    v.x = this->x - vec.x;
    v.y = this->y - vec.y;
    v.z = this->z - vec.z;
    return v;
  }
  floatvec3 operator*(const float& f) const {
    floatvec3 v;
    v.x = this->x * f;
    v.y = this->y * f;
    v.z = this->z * f;
    return v;
  }
  glm::vec3 glmvec3() {
    return glm::vec3(x, y, z);
  }
};

class VecTransform {
 public:
  VecTransform();
  ~VecTransform();
  VecTransform& operator=(const VecTransform& trans);
  VecTransform operator+(const VecTransform& trans);
  VecTransform operator-(const VecTransform& trans);
  VecTransform operator*(const float& f);
  bool operator==(const VecTransform& trans);
  VecTransform inverse();
  void Reset();
  void Rotate(const float x, const float y, const float z);
  void Rotate(const floatvec3 rotate);
  void Rotate(const glm::vec3 rotate);
  void SetRotate(const float x, const float y, const float z);
  void SetRotate(const floatvec3 rotate);
  void SetRotate(const glm::vec3 rotate);
  void Scale(const float x, const float y, const float z);
  void Scale(const floatvec3 scale);
  void Scale(const glm::vec3 scale);
  void SetScale(const float x, const float y, const float z);
  void SetScale(const floatvec3 scale);
  void SetScale(const glm::vec3 scale);
  void Translate(const float x, const float y, const float z);
  void Translate(const floatvec3 translate);
  void Translate(const glm::vec3 translate);
  void SetTranslate(const float x, const float y, const float z);
  void SetTranslate(const floatvec3 translate);
  void SetTranslate(const glm::vec3 translate);
  void Transform(VecTransform trans);
  bool IsChange();
  glm::mat4 GetTransform();
    
 private:
  bool changeflag_ {true};
  glm::vec3 rotate_ {glm::vec3(0)};
  glm::vec3 scale_ {glm::vec3(1.0)};
  glm::vec3 translate_ {glm::vec3(0)};
  // bool is_transform_updated_;
  glm::mat4 other_transform_ {glm::mat4(1.0f)};
  glm::mat4 transform_ {glm::mat4(1.0f)};
};

}
}
}

#endif