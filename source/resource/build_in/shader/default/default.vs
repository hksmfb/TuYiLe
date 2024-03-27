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