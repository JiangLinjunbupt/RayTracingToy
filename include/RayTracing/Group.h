#ifndef _GROUP_H_
#define _GROUP_H_

#include <RayTracing/Hitable.h>
#include <vector>

namespace RayTracing {
	class Group : public Hitable{
		HITABLE_SETUP(Group)
	public:
		Group(Material::CPtr material = NULL);

		// 返回 true 说明光线继续传播
		// 返回 false 说明光线传播结束
		virtual HitRst RayIn(CppUtility::Other::Ptr<Ray> & ray) const;
		inline void push_back(Hitable::CPtr hitable) { (*this) << hitable; }
		Group & operator <<(Hitable::CPtr hitable);
		virtual const AABB GetBoundingBox() const { return box; }
		const std::vector<Hitable::CPtr> & GetChildren() const { return children; }
	private:
		std::vector<Hitable::CPtr> children;
		AABB box;
	};
}
#endif //!_GROUP_H_

