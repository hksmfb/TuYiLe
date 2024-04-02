#include "resource_shader_default.h"

namespace TuYiLe {
namespace resourcelayer {
namespace shader {

Default::Default() {
  this->vertex_shader_code = R"(
#version 330 core
layout (location = 0) in vec3 inPosition;
layout (location = 1) in vec3 inNormal;
layout (location = 2) in vec2 inCoord;

out vec3 Normal;
out vec2 Coord;

void main() {
  gl_Position = vec4(Position, 1.0);
  Normal = inNormal;
  Coord = inCoord;
}
  )";
  this->fragment_shader_code = R"(
#version 330 core
out vec4 FragColor;

in vec3 Normal;
in vec2 Coord;

void main() {
FragColor = vec4(Normal, 1.0f);
}
  )";
}

Default::~Default() {

}

}
}
}