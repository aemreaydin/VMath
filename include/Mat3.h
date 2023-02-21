#ifndef VMATH_MAT3_H
#define VMATH_MAT3_H

#include <array>
#include "Vec3.h"

namespace VMath
{
	class Mat3
	{
		std::array<Vec3, 3> mMat3;

	public:
		Mat3() = default;

		Mat3(Vec3 _col0, Vec3 _col1, Vec3 _col2)
				: mMat3{ _col0, _col1, _col2 }
		{
		}

		auto operator()(size_t _indI, size_t _indJ) -> float&;
		auto operator()(size_t _indI, size_t _indJ) const -> const float&;
		auto operator()(size_t _ind) -> Vec3&;
		auto operator()(size_t _ind) const -> const Vec3&;
	};

	auto operator*(const Mat3& _lhs, const Mat3& _rhs) -> Mat3;
	auto operator*(const Mat3& _mat3, const Vec3& _vec3) -> Vec3;
} // namespace VMath

#endif //VMATH_MAT3_H
