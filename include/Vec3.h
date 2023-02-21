#ifndef VMATH_VEC3_H
#define VMATH_VEC3_H

#include <array>
#include <ostream>

namespace VMath
{
	class Vec3
	{
		std::array<float, 3> mVec3{};

	public:
		Vec3() = default;

		Vec3(float _valX, float _valY, float _valZ)
				: mVec3{ _valX, _valY, _valZ }
		{
		}

		[[nodiscard]] auto X() const -> float;
		[[nodiscard]] auto Y() const -> float;
		[[nodiscard]] auto Z() const -> float;

		auto operator()(size_t _ind) -> float&;
		auto operator()(size_t _ind) const -> const float&;
		auto operator+=(const Vec3& _vec3) -> Vec3&;
		auto operator-=(const Vec3& _vec3) -> Vec3&;
		auto operator*=(float _valToMul) -> Vec3&;
		auto operator/=(float _valToDiv) -> Vec3&;
	};

	[[nodiscard]] auto Magnitude(const Vec3& _vec3) -> float;
	[[nodiscard]] auto Normalize(const Vec3& _vec3) -> Vec3;
	[[nodiscard]] auto Dot(const Vec3& _lhs, const Vec3& _rhs) -> float;
	[[nodiscard]] auto Cross(const Vec3& _lhs, const Vec3& _rhs) -> Vec3;

	auto operator==(const Vec3& _lhs, const Vec3& _rhs) -> bool;
	auto operator+(const Vec3& _lhs, const Vec3& _rhs) -> Vec3;
	auto operator-(const Vec3& _lhs, const Vec3& _rhs) -> Vec3;
	auto operator*(const Vec3& _vec3, float _valToMul) -> Vec3;
	auto operator/(const Vec3& _vec3, float _valToDiv) -> Vec3;
	auto operator-(const Vec3& _vec3) -> Vec3;

	auto operator<<(std::ostream& _ostream, const Vec3& _vec3) -> std::ostream&;
}// namespace VMath

#endif// VMATH_VEC3_H
