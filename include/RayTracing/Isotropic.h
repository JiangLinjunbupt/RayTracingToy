#ifndef _ISOTROPIC_H_
#define _ISOTROPIC_H_

#include <RayTracing/Material.h>

namespace RayTracing {
	class Texture;

	class Isotropic : public Material{
		MATERIAL_SETUP(Isotropic)
	public:
		Isotropic(const glm::rgb & color);

		// 返回值为 true 说明光线继续传播
		// 返回值为 false 说明光线不再传播
		virtual bool Scatter(const HitRecord & rec) const;
		const CppUtility::Other::CPtr<Texture> GetTexture() const { return tex; }
	protected:
		CppUtility::Other::CPtr<Texture> tex;
	};
}

#endif // !_ISOTROPIC_H_
