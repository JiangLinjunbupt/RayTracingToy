#ifndef _LAMBERTIAN_H_
#define _LAMBERTIAN_H_

#include <RayTracing/Material.h>

#include <glm/glm.hpp>

namespace RayTracing {
	class Texture;

	class Lambertian : public Material {
		MATERIAL_SETUP(Lambertian)
	public:
		Lambertian(float r, float g, float b);
		Lambertian(const glm::rgb & albedo);
		Lambertian(CppUtility::Other::CPtr<Texture> albedo);

		// 返回值为 true 说明光线继续传播
		// 返回值为 false 说明光线不再传播
		virtual bool Scatter(const HitRecord & rec) const;
		
		const CppUtility::Other::CPtr<Texture> GetTexture() const { return albedo; }
	protected:
		CppUtility::Other::CPtr<Texture> albedo;
	};
}

#endif // !_LAMBERTIAN_H_
