#ifndef _OP_MATERIAL_H_
#define _OP_MATERIAL_H_

#include <RayTracing/Material.h>

#include <functional>

namespace RayTracing {
	class OpMaterial : public Material{
		MATERIAL_SETUP(OpMaterial)
	public:
		OpMaterial(const std::function<bool(const HitRecord & rec)> & op);

		virtual bool Scatter(const HitRecord & rec) const;
	protected:
		std::function<bool(const HitRecord & rec)> op;
	};
}

#endif // !_OP_MATERIAL_H_
