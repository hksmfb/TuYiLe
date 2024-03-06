#ifndef FUNCTION_RENDER_RENDERBASE_H_
#define FUNCTION_RENDER_RENDERBASE_H_

#include <unordered_map>
#include <string>

#include "core_math_vectransform.h"

namespace functionlayer {
namespace render {
class RenderBase {
	public:
		void Draw();
	private:
    corelayer::VecTransform transform_;
    std::unordered_map<std::string, float> floatlist_;
    std::unordered_map<std::string, bool> boollist_;
    std::unordered_map<std::string, int> intlist_;
    std::unordered_map<std::string, glm::mat4> mat4list_;
    std::unordered_map<std::string, glm::vec3> vec3list_;
};

}
}

#endif