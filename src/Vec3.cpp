#include "Vec3.h"
#include "Constants.h"
#include <Utils.h>
#include <gsl/gsl>

namespace VMath
{
	auto Vec3::X() const -> float
	{
		return mVec3[0];
	}

	auto Vec3::Y() const -> float
	{
		return mVec3[1];
	}

	auto Vec3::Z() const -> float
	{
		return mVec3[2];
	}

	auto Vec3::operator()(size_t _ind) -> float&
	{
		return VUtils::At(mVec3, _ind);
	}

	auto Vec3::operator()(size_t _ind) const -> const float&
	{
		return VUtils::At(mVec3, _ind);
	}

	auto Vec3::operator+=(const Vec3& _vec3) -> Vec3&
	{
		mVec3[0] += _vec3.X();
		mVec3[1] += _vec3.Y();
		mVec3[2] += _vec3.Z();
		return *this;
	}

	auto Vec3::operator-=(const Vec3& _vec3) -> Vec3&
	{
		mVec3[0] -= _vec3.X();
		mVec3[1] -= _vec3.Y();
		mVec3[2] -= _vec3.Z();
		return *this;
	}

	auto Vec3::operator*=(float _valToMul) -> Vec3&
	{
		mVec3[0] *= _valToMul;
		mVec3[1] *= _valToMul;
		mVec3[2] *= _valToMul;
		return *this;
	}

	auto Vec3::operator/=(float _valToDiv) -> Vec3&
	{
		Expects(_valToDiv != 0.F);
		const auto valToMul = 1.F / _valToDiv;
		mVec3[0] *= valToMul;
		mVec3[1] *= valToMul;
		mVec3[2] *= valToMul;
		return *this;
	}

	auto Magnitude(const Vec3& _vec3) -> float
	{
		return sqrt(_vec3.X() * _vec3.X() + _vec3.Y() * _vec3.Y() + _vec3.Z() * _vec3.Z());
	}

	auto Normalize(const Vec3& _vec3) -> Vec3
	{
		return _vec3 / Magnitude(_vec3);
	}

	auto Dot(const Vec3& _lhs, const Vec3& _rhs) -> float
	{
		return _lhs.X() * _rhs.X() + _lhs.Y() * _rhs.Y() + _lhs.Z() * _rhs.Z();
	}

	auto Cross(const Vec3& _lhs, const Vec3& _rhs) -> Vec3
	{
		return { _lhs.Y() * _rhs.Z() - _lhs.Z() * _rhs.Y(),
		         _lhs.Z() * _rhs.X() - _lhs.X() * _rhs.Z(),
		         _lhs.X() * _rhs.Y() - _lhs.Y() * _rhs.X() };
	}

	auto operator==(const Vec3& _lhs, const Vec3& _rhs) -> bool
	{
		return fabs(_lhs.X() - _rhs.X()) <= EPSILON &&
		       fabs(_lhs.Y() - _rhs.Y()) <= EPSILON &&
		       fabs(_lhs.Z() - _rhs.Z()) <= EPSILON;
	}

	auto operator+(const Vec3& _lhs, const Vec3& _rhs) -> Vec3
	{
		return { _lhs.X() + _rhs.X(), _lhs.Y() + _rhs.Y(), _lhs.Z() + _rhs.Z() };
	}

	auto operator-(const Vec3& _lhs, const Vec3& _rhs) -> Vec3
	{
		return { _lhs.X() - _rhs.X(), _lhs.Y() - _rhs.Y(), _lhs.Z() - _rhs.Z() };
	}

	auto operator*(const Vec3& _vec3, float _valToMul) -> Vec3
	{
		return { _vec3.X() * _valToMul, _vec3.Y() * _valToMul, _vec3.Z() * _valToMul };
	}

	auto operator/(const Vec3& _vec3, float _valToDiv) -> Vec3
	{
		Expects(_valToDiv != 0.F);
		const auto valToMul = 1.F / _valToDiv;
		return { _vec3.X() * valToMul, _vec3.Y() * valToMul, _vec3.Z() * valToMul };
	}

	auto operator-(const Vec3& _vec3) -> Vec3
	{
		return { -_vec3.X(), -_vec3.Y(), -_vec3.Z() };
	}

	auto operator<<(std::ostream& _ostream, const Vec3& _vec3) -> std::ostream&
	{
		_ostream << std::fixed << "Vec3 { X: " << _vec3.X() << ", Y: " << _vec3.Y() << ", Z: " << _vec3.Z() << " }";
		return _ostream;
	}
}// namespace VMath
