#ifndef VMATH_VEC3_H
#define VMATH_VEC3_H

#include <array>

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
		[[nodiscard]] auto Magnitude() const -> float;
		auto Normalize() -> void;

		auto operator()(size_t _ind) -> float&;
		auto operator()(size_t _ind) const -> const float&;
		auto operator+=(const Vec3& _vec3) -> Vec3&;
		auto operator-=(const Vec3& _vec3) -> Vec3&;
		auto operator*=(float _valToMul) -> Vec3&;
		auto operator/=(float _valToDiv) -> Vec3&;
	};

	[[nodiscard]] auto Normalized(const Vec3& _vec3) -> Vec3;

	auto operator==(const Vec3& _lhs, const Vec3& _rhs) -> bool;
	auto operator+(const Vec3& _lhs, const Vec3& _rhs) -> Vec3;
	auto operator-(const Vec3& _lhs, const Vec3& _rhs) -> Vec3;
	auto operator*(const Vec3& _vec3, float _valToMul) -> Vec3;
	auto operator/(const Vec3& _vec3, float _valToDiv) -> Vec3;
	auto operator-(const Vec3& _vec3) -> Vec3;
}// namespace VMath

#endif// VMATH_VEC3_H
