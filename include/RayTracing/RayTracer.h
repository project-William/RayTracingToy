#ifndef _RAY_TRACER_H_
#define _RAY_TRACER_H_

#include <RayTracing/Hitable.h>
#include <glm/glm.hpp>

namespace RayTracing {
	class RayTracer {
	public:
		RayTracer(size_t depth = 50);

		glm::rgb TraceX(Hitable::CPtr scene, CppUtility::Other::Ptr<Ray> & ray);

		static glm::rgb Trace(Hitable::CPtr scene, CppUtility::Other::Ptr<Ray> & ray, size_t depth = 50);

		size_t depth;
		size_t wholeDepth;
	private:
		glm::rgb TraceX(Hitable::CPtr scene, CppUtility::Other::Ptr<Ray> & ray, size_t depth);
	};
}

#endif // !_RAY_TRACER_H_
