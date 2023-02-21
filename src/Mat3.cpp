#include "Mat3.h"
#include "Utils.h"

namespace VMath
{
	auto Mat3::operator()(size_t _indI, size_t _indJ) -> float&
	{
		auto& col = VUtils::At(mMat3, _indJ);
		return col(_indI);
	}

	auto Mat3::operator()(size_t _indI, size_t _indJ) const -> const float&
	{
		const auto& col = VUtils::At(mMat3, _indJ);
		return col(_indI);
	}

	auto Mat3::operator()(size_t _ind) -> Vec3&
	{
		return VUtils::At(mMat3, _ind);
	}

	auto Mat3::operator()(size_t _ind) const -> const Vec3&
	{
		return VUtils::At(mMat3, _ind);
	}

	auto operator*(const Mat3& _lhs, const Mat3& _rhs) -> Mat3
	{
		return {{ _lhs(0, 0) * _rhs(0, 0) + _lhs(0, 1) * _rhs(1, 0) + _lhs(0, 2) * _rhs(2, 0),
		          _lhs(0, 0) * _rhs(0, 1) + _lhs(0, 1) * _rhs(1, 1) + _lhs(0, 2) * _rhs(2, 1),
		          _lhs(0, 0) * _rhs(0, 2) + _lhs(0, 1) * _rhs(1, 2) + _lhs(0, 2) * _rhs(2, 2) },
		        { _lhs(1, 0) * _rhs(0, 0) + _lhs(1, 1) * _rhs(1, 0) + _lhs(1, 2) * _rhs(2, 0),
		          _lhs(1, 0) * _rhs(0, 1) + _lhs(1, 1) * _rhs(1, 1) + _lhs(1, 2) * _rhs(2, 1),
		          _lhs(1, 0) * _rhs(0, 2) + _lhs(1, 1) * _rhs(1, 2) + _lhs(1, 2) * _rhs(2, 2) },
		        { _lhs(2, 0) * _rhs(0, 0) + _lhs(2, 1) * _rhs(1, 0) + _lhs(2, 2) * _rhs(2, 0),
		          _lhs(2, 0) * _rhs(0, 1) + _lhs(2, 1) * _rhs(1, 1) + _lhs(2, 2) * _rhs(2, 1),
		          _lhs(2, 0) * _rhs(0, 2) + _lhs(2, 1) * _rhs(1, 2) + _lhs(2, 2) * _rhs(2, 2) }};
	}

	auto operator*(const Mat3& _mat3, const Vec3& _vec3) -> Vec3
	{
		return { _mat3(0, 0) * _vec3(0) + _mat3(0, 1) * _vec3(1) + _mat3(0, 2) * _vec3(2),
		         _mat3(1, 0) * _vec3(0) + _mat3(1, 1) * _vec3(1) + _mat3(1, 2) * _vec3(2),
		         _mat3(2, 0) * _vec3(0) + _mat3(2, 1) * _vec3(1) + _mat3(2, 2) * _vec3(2) };
	}
} // namespace VMath