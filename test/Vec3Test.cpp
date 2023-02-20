#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-function-cognitive-complexity"
#pragma ide diagnostic ignored "cppcoreguidelines-avoid-magic-numbers"

#define GSL_MSVC_USE_STL_NOEXCEPTION_WORKAROUND
#include <catch2/catch_test_macros.hpp>
#include <Vec3.h>

using VMath::Vec3;

TEST_CASE("Vec3", "[Vectors]")
{
	auto zeroVec3 = Vec3();
	auto vec3 = Vec3{ 1.F, 2.F, 3.F };

	SECTION("Constructors and indexing work as intended.")
	{
		REQUIRE(vec3 == Vec3{ 1.F, 2.F, 3.F });
		REQUIRE(zeroVec3 == Vec3{ 0.F, 0.F, 0.F });
		REQUIRE(vec3.X() == 1.F);
		REQUIRE(vec3.Y() == 2.F);
		REQUIRE(vec3.Z() == 3.F);
		REQUIRE(vec3(0) == vec3.X());
		REQUIRE(vec3(1) == vec3.Y());
		REQUIRE(vec3(2) == vec3.Z());

		REQUIRE_THROWS(vec3(4));
		REQUIRE_THROWS(vec3(-1));
	}

	SECTION("Math Operations work as intended.")
	{
		auto lhs = Vec3{ 4.F, 6.F, 8.F };
		auto rhs = Vec3{ 2.F, 2.F, 2.F };

		lhs += Vec3{ 3.F, 4.F, 5.F };
		REQUIRE(lhs == Vec3{ 7.F, 10.F, 13.F });
		lhs -= Vec3{ 3.F, 4.F, 5.F };
		REQUIRE(lhs == Vec3{ 4.F, 6.F, 8.F });
		lhs *= 2.F;
		REQUIRE(lhs == Vec3{ 8.F, 12.F, 16.F });
		lhs /= 2.F;
		REQUIRE(lhs == Vec3{ 4.F, 6.F, 8.F });

		REQUIRE(lhs + rhs == Vec3{ 6.F, 8.F, 10.F });
		REQUIRE(lhs - rhs == Vec3{ 2.F, 4.F, 6.F });
		REQUIRE(lhs * 2.F == Vec3{ 8.F, 12.F, 16.F });
		REQUIRE(lhs / 2.F == Vec3{ 2.F, 3.F, 4.F });
		REQUIRE(-lhs == Vec3{ -4.F, -6.F, -8.F });
	}
}

#pragma clang diagnostic pop