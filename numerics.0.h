/**
 * @file	numerics.0.h
 * @brief	HiCxx 的数学模块
 * @author	侧云
*/

#pragma once

#include <cmath>
#include <iostream>

namespace HiCxx
{
	constexpr float MF_PI = 3.14159265f;
	constexpr float MF_PIDIV2 = MF_PI / 2;
	constexpr float MF_TAO = MF_PI * 2;

	struct float2;
	struct float3;
	struct float4;
	struct float3x2;
	struct float4x4;
	struct plane;
	struct quaternion;
	struct float2x2;
	struct float2x3;

	constexpr float2 operator+(float2 const& value1, float2 const& value2) noexcept;
	constexpr float2 operator-(float2 const& value1, float2 const& value2) noexcept;
	constexpr float2 operator*(float2 const& value1, float2 const& value2) noexcept;
	constexpr float2 operator*(float2 const& value1, float const value2) noexcept;
	constexpr float2 operator*(float const value1, float2 const& value2) noexcept;
	constexpr float2 operator/(float2 const& value1, float2 const& value2) noexcept;
	constexpr float2 operator/(float2 const& value1, float const value2) noexcept;
	constexpr float2 operator+(float2 const& value1) noexcept;
	constexpr float2 operator-(float2 const& value1) noexcept;
	constexpr float2& operator+=(float2& value1, float2 const& value2) noexcept;
	constexpr float2& operator-=(float2& value1, float2 const& value2) noexcept;
	constexpr float2& operator*=(float2& value1, float2 const& value2) noexcept;
	constexpr float2& operator*=(float2& value1, float const value2) noexcept;
	constexpr float2& operator/=(float2& value1, float2 const& value2) noexcept;
	constexpr float2& operator/=(float2& value1, float const value2) noexcept;
	constexpr bool operator==(float2 const& value1, float2 const& value2) noexcept;
	constexpr bool operator!=(float2 const& value1, float2 const& value2) noexcept;

	float length(float2 const& value1) noexcept;
	float length_squared(float2 const& value1) noexcept;
	float distance(float2 const& value1, float2 const& value2) noexcept;
	float distance_squared(float2 const& value1, float2 const& value2) noexcept;
	float distance(float2 const& value1, float2x2 const& value2) noexcept;
	float distance_directed(float2 const& value1, float2x2 const& value2) noexcept;
	float cos(float2 const& value1, float2 const& value2) noexcept;
	float acos(float2 const& value1, float2 const& value2) noexcept;
	float dot(float2 const& vector1, float2 const& vector2) noexcept;
	float cross(float2 const& vector1, float2 const& vector2) noexcept;
	float2 abs(float2 const& value1) noexcept;
	float2 sqrt(float2 const& value1) noexcept;
	float2 squared(float2 const& value1) noexcept;
	float2 rotate(float2 const& value1, float const rad) noexcept;
	float2 rotate90(float2 const& value1) noexcept;
	float2 normalize(float2 const& value1) noexcept;
	float2 reflect(float2 const& value, float2 const& normal) noexcept;
	float2 min(float2 const& value1, float2 const& value2) noexcept;
	float2 max(float2 const& value1, float2 const& value2) noexcept;
	float2 projection(float2 const& value1, float2 const& value2) noexcept;
	float2 projection(float2 const& value1, float2x2 const& value2) noexcept;
	float2 clamp(float2 const& value1, float2 const& min, float2 const& max) noexcept;
	float2 lerp(float2 const& value1, float2 const& value2, float const amount) noexcept;
	float2 transform(float2 const& position, float3x2 const& matrix) noexcept;
	float2 transform(float2 const& position, float4x4 const& matrix) noexcept;
	float2 transform_normal(float2 const& normal, float3x2 const& matrix) noexcept;
	float2 transform_normal(float2 const& normal, float4x4 const& matrix) noexcept;
	float2 transform(float2 const& value, quaternion const& rotation) noexcept;
	bool is_parallel(float2 const& value1, float2 const& value2) noexcept;
	bool is_intersecting(float2 const& value1, float2 const& value2) noexcept;

	struct float2
	{
		constexpr float2(float const x, float const y) noexcept;
		constexpr explicit float2(float3 const& value) noexcept;
		constexpr explicit float2(float4 const& value) noexcept;
		constexpr explicit float2(float const value = 0) noexcept;

		constexpr static float2 zero() noexcept;
		constexpr static float2 one() noexcept;
		constexpr static float2 unit_x() noexcept;
		constexpr static float2 unit_y() noexcept;

		float length() const noexcept;
		float length_squared() const noexcept;
		float distance(float2 const& value2) const noexcept;
		float distance_squared(float2 const& value2) const noexcept;
		float distance(float2x2 const& value2) const noexcept;
		float distance_directed(float2x2 const& value2) const noexcept;
		float cos(float2 const& value2) const noexcept;
		float acos(float2 const& value2) const noexcept;
		float dot(float2 const& vector2) const noexcept;
		float cross(float2 const& vector2) const noexcept;
		float2 abs() const noexcept;
		float2 sqrt() const noexcept;
		float2 squared() const noexcept;
		float2 rotate(float const rad) const noexcept;
		float2 rotate90() const noexcept;
		float2 normalize() const noexcept;
		float2 reflect(float2 const& normal) const noexcept;
		float2 min(float2 const& value2) const noexcept;
		float2 max(float2 const& value2) const noexcept;
		float2 projection(float2 const& value2) const noexcept;
		float2 projection(float2x2 const& value2) const noexcept;
		float2 clamp(float2 const& minValue, float2 const& maxValue) const noexcept;
		float2 lerp(float2 const& value2, float const amount) const noexcept;
		float2 transform(float3x2 const& matrix) const noexcept;
		float2 transform(float4x4 const& matrix) const noexcept;
		float2 transform_normal(float3x2 const& matrix) const noexcept;
		float2 transform_normal(float4x4 const& matrix) const noexcept;
		float2 transform(quaternion const& rotation) const noexcept;
		bool is_parallel(float2 const& value2) const noexcept;
		bool is_intersecting(float2 const& value2) const noexcept;

		float& operator[](unsigned int const i) noexcept;
		const float& operator[](unsigned int const i) const noexcept;

		union
		{
			struct { float x; float y; };
			float value[2];
			float data[2];
		};
	};

	constexpr float3 operator+(float3 const& value1, float3 const& value2) noexcept;
	constexpr float3 operator-(float3 const& value1, float3 const& value2) noexcept;
	constexpr float3 operator*(float3 const& value1, float3 const& value2) noexcept;
	constexpr float3 operator*(float3 const& value1, float const value2) noexcept;
	constexpr float3 operator*(float const value1, float3 const& value2) noexcept;
	constexpr float3 operator/(float3 const& value1, float3 const& value2) noexcept;
	constexpr float3 operator/(float3 const& value1, float const value2) noexcept;
	constexpr float3 operator+(float3 const& value1) noexcept;
	constexpr float3 operator-(float3 const& value1) noexcept;
	constexpr float3& operator+=(float3& value1, float3 const& value2) noexcept;
	constexpr float3& operator-=(float3& value1, float3 const& value2) noexcept;
	constexpr float3& operator*=(float3& value1, float3 const& value2) noexcept;
	constexpr float3& operator*=(float3& value1, float const value2) noexcept;
	constexpr float3& operator/=(float3& value1, float3 const& value2) noexcept;
	constexpr float3& operator/=(float3& value1, float const value2) noexcept;
	constexpr bool operator==(float3 const& value1, float3 const& value2) noexcept;
	constexpr bool operator!=(float3 const& value1, float3 const& value2) noexcept;

	float length(float3 const& value1) noexcept;
	float length_squared(float3 const& value1) noexcept;
	float distance(float3 const& value1, float3 const& value2) noexcept;
	float distance_squared(float3 const& value1, float3 const& value2) noexcept;
	float distance(float3 const& value1, float2x3 const& value2) noexcept;
	float distance_directed(float3 const& value1, float2x3 const& value2) noexcept;
	float cos(float3 const& value1, float3 const& value2) noexcept;
	float acos(float3 const& value1, float3 const& value2) noexcept;
	float dot(float3 const& value1, float3 const& value2) noexcept;
	float3 cross(float3 const& value1, float3 const& value2) noexcept;
	float3 abs(float3 const& value1) noexcept;
	float3 sqrt(float3 const& value1) noexcept;
	float3 squared(float3 const& value1) noexcept;
	float3 rotate(float3 const& value1, float const radX, float const radY, float const radZ) noexcept;
	float3 rotate_x(float3 const& value1, float const rad) noexcept;
	float3 rotate_y(float3 const& value1, float const rad) noexcept;
	float3 rotate_z(float3 const& value1, float const rad) noexcept;
	float3 rotate90_x(float3 const& value1) noexcept;
	float3 rotate90_y(float3 const& value1) noexcept;
	float3 rotate90_z(float3 const& value1) noexcept;
	float3 normalize(float3 const& value1) noexcept;
	float3 reflect(float3 const& value, float3 const& normal) noexcept;
	float3 min(float3 const& value1, float3 const& value2) noexcept;
	float3 max(float3 const& value1, float3 const& value2) noexcept;
	float3 projection(float3 const& value1, float3 const& value2) noexcept;
	float3 projection(float3 const& value1, plane const& value2) noexcept;
	float3 clamp(float3 const& value1, float3 const& min, float3 const& max) noexcept;
	float3 lerp(float3 const& value1, float3 const& value2, float const amount) noexcept;
	float3 transform(float3 const& position, float4x4 const& matrix);
	float3 transform_normal(float3 const& normal, float4x4 const& matrix);
	float3 transform(float3 const& value, quaternion const& rotation);
	bool is_parallel(float3 const& value1, float3 const& value2) noexcept;

	struct float3
	{
		constexpr float3(float const x, float const y, float const z) noexcept;
		constexpr explicit float3(float2 const& value, float const z = 0) noexcept;
		constexpr explicit float3(float4 const& value) noexcept;
		constexpr explicit float3(float const value = 0) noexcept;

		constexpr static float3 zero() noexcept;
		constexpr static float3 one() noexcept;
		constexpr static float3 unit_x() noexcept;
		constexpr static float3 unit_y() noexcept;
		constexpr static float3 unit_z() noexcept;

		float length() const noexcept;
		float length_squared() const noexcept;
		float distance(float3 const& value2) const noexcept;
		float distance_squared(float3 const& value2) const noexcept;
		float distance(float2x3 const& value2) const noexcept;
		float distance_directed(float2x3 const& value2) const noexcept;
		float cos(float3 const& value2) const noexcept;
		float acos(float3 const& value2) const noexcept;
		float dot(float3 const& value2) const noexcept;
		float3 cross(float3 const& value2) const noexcept;
		float3 abs() const noexcept;
		float3 sqrt() const noexcept;
		float3 squared() const noexcept;
		float3 rotate(float const radX, float const radY, float const radZ) const noexcept;
		float3 rotate_x(float const rad) const noexcept;
		float3 rotate_y(float const rad) const noexcept;
		float3 rotate_z(float const rad) const noexcept;
		float3 rotate90_x() const noexcept;
		float3 rotate90_y() const noexcept;
		float3 rotate90_z() const noexcept;
		float3 normalize() const noexcept;
		float3 reflect(float3 const& normal) const noexcept;
		float3 min(float3 const& value2) const noexcept;
		float3 max(float3 const& value2) const noexcept;
		float3 projection(float3 const& value2) const noexcept;
		float3 projection(plane const& value2) const noexcept;
		float3 clamp(float3 const& minValue, float3 const& maxValue) const noexcept;
		float3 lerp(float3 const& value2, float const amount) const noexcept;
		float3 transform(float4x4 const& matrix) const noexcept;
		float3 transform_normal(float4x4 const& matrix) const noexcept;
		float3 transform(quaternion const& rotation) const noexcept;
		bool is_parallel(float3 const& value2) const noexcept;

		float& operator[](unsigned int const i) noexcept;
		const float& operator[](unsigned int const i) const noexcept;

		union
		{
			struct { float x; float y; float z; };
			float value[3];
			float data[3];
		};
	};

	constexpr float4 operator+(float4 const& value1, float4 const& value2) noexcept;
	constexpr float4 operator-(float4 const& value1, float4 const& value2) noexcept;
	constexpr float4 operator*(float4 const& value1, float4 const& value2) noexcept;
	constexpr float4 operator*(float4 const& value1, float const value2) noexcept;
	constexpr float4 operator*(float const value1, float4 const& value2) noexcept;
	constexpr float4 operator/(float4 const& value1, float4 const& value2) noexcept;
	constexpr float4 operator/(float4 const& value1, float const value2) noexcept;
	constexpr float4 operator+(float4 const& value1) noexcept;
	constexpr float4 operator-(float4 const& value1) noexcept;
	constexpr float4& operator+=(float4& value1, float4 const& value2) noexcept;
	constexpr float4& operator-=(float4& value1, float4 const& value2) noexcept;
	constexpr float4& operator*=(float4& value1, float4 const& value2) noexcept;
	constexpr float4& operator*=(float4& value1, float const value2) noexcept;
	constexpr float4& operator/=(float4& value1, float4 const& value2) noexcept;
	constexpr float4& operator/=(float4& value1, float const value2) noexcept;
	constexpr bool operator==(float4 const& value1, float4 const& value2) noexcept;
	constexpr bool operator!=(float4 const& value1, float4 const& value2) noexcept;

	float length(float4 const& value1) noexcept;
	float length_squared(float4 const& value1) noexcept;
	float distance(float4 const& value1, float4 const& value2) noexcept;
	float distance_squared(float4 const& value1, float4 const& value2) noexcept;
	float dot(float4 const& value1, float4 const& value2) noexcept;
	float4 abs(float4 const& value1) noexcept;
	float4 sqrt(float4 const& value1) noexcept;
	float4 squared(float4 const& value1) noexcept;
	float4 normalize(float4 const& value1) noexcept;
	float4 reflect(float4 const& value, float4 const& normal) noexcept;
	float4 min(float4 const& value1, float4 const& value2) noexcept;
	float4 max(float4 const& value1, float4 const& value2) noexcept;
	float4 clamp(float4 const& value1, float4 const& min, float4 const& max) noexcept;
	float4 lerp(float4 const& value1, float4 const& value2, float const amount) noexcept;
	float4 transform(float4 const& vector, float4x4 const& matrix) noexcept;
	float4 transform4(float3 const& position, float4x4 const& matrix) noexcept;
	float4 transform4(float2 const& position, float4x4 const& matrix) noexcept;
	float4 transform(float4 const& value, quaternion const& rotation) noexcept;
	float4 transform4(float3 const& value, quaternion const& rotation) noexcept;
	float4 transform4(float2 const& value, quaternion const& rotation) noexcept;

	struct float4
	{
		constexpr float4(float const x, float const y, float const z, float const w) noexcept;
		constexpr explicit float4(float2 const& value, float const z = 0, float const w = 0) noexcept;
		constexpr explicit float4(float3 const& value, float const w = 0) noexcept;
		constexpr explicit float4(plane const& value) noexcept;
		constexpr explicit float4(quaternion const& value) noexcept;
		constexpr explicit float4(float const value = 0) noexcept;

		constexpr static float4 zero() noexcept;
		constexpr static float4 one() noexcept;
		constexpr static float4 unit_x() noexcept;
		constexpr static float4 unit_y() noexcept;
		constexpr static float4 unit_z() noexcept;
		constexpr static float4 unit_w() noexcept;

		float length() const noexcept;
		float length_squared() const noexcept;
		float distance(float4 const& value2) const noexcept;
		float distance_squared(float4 const& value2) const noexcept;
		float dot(float4 const& value2) const noexcept;
		float4 abs() const noexcept;
		float4 sqrt() const noexcept;
		float4 squared() const noexcept;
		float4 normalize() const noexcept;
		float4 reflect(float4 const& normal) const noexcept;
		float4 min(float4 const& value2) const noexcept;
		float4 max(float4 const& value2) const noexcept;
		float4 clamp(float4 const& minValue, float4 const& maxValue) const noexcept;
		float4 lerp(float4 const& value2, float const amount) const noexcept;
		float4 transform(float4x4 const& matrix) const noexcept;
		float4 transform(quaternion const& rotation) const noexcept;

		float& operator[](unsigned int const i) noexcept;
		const float& operator[](unsigned int const i) const noexcept;

		union
		{
			struct { float x; float y; float z; float w; };
			float value[4];
			float data[4];
		};
	};

	constexpr float3x2 operator+(float3x2 const& value1, float3x2 const& value2) noexcept;
	constexpr float3x2 operator-(float3x2 const& value1, float3x2 const& value2) noexcept;
	constexpr float3x2 operator*(float3x2 const& value1, float3x2 const& value2) noexcept;
	constexpr float3x2 operator*(float3x2 const& value1, float const value2) noexcept;
	constexpr float3x2 operator*(float const value1, float3x2 const& value2) noexcept;
	constexpr float3x2 operator/(float3x2 const& value1, float const value2) noexcept;
	constexpr float3x2 operator+(float3x2 const& value) noexcept;
	constexpr float3x2 operator-(float3x2 const& value) noexcept;
	constexpr float3x2& operator+=(float3x2& value1, float3x2 const& value2) noexcept;
	constexpr float3x2& operator-=(float3x2& value1, float3x2 const& value2) noexcept;
	constexpr float3x2& operator*=(float3x2& value1, float3x2 const& value2) noexcept;
	constexpr float3x2& operator*=(float3x2& value1, float const value2) noexcept;
	constexpr float3x2& operator/=(float3x2& value1, float const value2) noexcept;
	constexpr bool operator==(float3x2 const& value1, float3x2 const& value2) noexcept;
	constexpr bool operator!=(float3x2 const& value1, float3x2 const& value2) noexcept;

	bool is_identity(float3x2 const& value) noexcept;
	float determinant(float3x2 const& value) noexcept;
	float2 translation(float3x2 const& value) noexcept;
	bool invert(float3x2 const& matrix, float3x2* const result) noexcept;
	float3x2 lerp(float3x2 const& matrix1, float3x2 const& matrix2, float const amount) noexcept;

	float3x2 make_float3x2_translation(float2 const& position) noexcept;
	float3x2 make_float3x2_translation(float const xPosition, float const yPosition) noexcept;
	float3x2 make_float3x2_scale(float const xScale, float const yScale) noexcept;
	float3x2 make_float3x2_scale(float const xScale, float const yScale, float2 const& centerPoint) noexcept;
	float3x2 make_float3x2_scale(float2 const& scales) noexcept;
	float3x2 make_float3x2_scale(float2 const& scales, float2 const& centerPoint) noexcept;
	float3x2 make_float3x2_scale(float const scale) noexcept;
	float3x2 make_float3x2_scale(float const scale, float2 const& centerPoint) noexcept;
	float3x2 make_float3x2_skew(float const radiansX, float const radiansY) noexcept;
	float3x2 make_float3x2_skew(float const radiansX, float const radiansY, float2 const& centerPoint) noexcept;
	float3x2 make_float3x2_rotation(float const radians) noexcept;
	float3x2 make_float3x2_rotation(float radians, float2 const& centerPoint) noexcept;

	struct float3x2
	{
		constexpr static float3x2 identity() noexcept;

		constexpr float3x2(float const m11 = 0, float const m12 = 0,
						   float const m21 = 0, float const m22 = 0,
						   float const m31 = 0, float const m32 = 0) noexcept;
		constexpr float3x2(float2 const& r1, float2 const& r2 = float2::zero(), float2 const& r3 = float2::zero()) noexcept;

		bool is_identity() const noexcept;
		float determinant() const noexcept;
		float2 translation() const noexcept;
		bool invert(float3x2* const result) const noexcept;
		float3x2 lerp(float3x2 const& matrix2, float const amount) const noexcept;

		float2& operator[](unsigned int const i) noexcept;
		const float2& operator[](unsigned int const i) const noexcept;

		union
		{
			struct
			{
				float m11, m12;
				float m21, m22;
				float m31, m32;
			};
			struct
			{
				float2 r1;
				float2 r2;
				float2 r3;
			};
			float m[3][2];
			float value[6];
			float2 data[3];
			float2 row[3];
		};
	};

	constexpr float4x4 operator+(float4x4 const& value1, float4x4 const& value2) noexcept;
	constexpr float4x4 operator-(float4x4 const& value1, float4x4 const& value2) noexcept;
	constexpr float4x4 operator*(float4x4 const& value1, float4x4 const& value2) noexcept;
	constexpr float4x4 operator*(float4x4 const& value1, float const value2) noexcept;
	constexpr float4x4 operator*(float const value1, float4x4 const& value2) noexcept;
	constexpr float4x4 operator+(float4x4 const& value) noexcept;
	constexpr float4x4 operator-(float4x4 const& value) noexcept;
	constexpr float4x4& operator+=(float4x4& value1, float4x4 const& value2) noexcept;
	constexpr float4x4& operator-=(float4x4& value1, float4x4 const& value2) noexcept;
	constexpr float4x4& operator*=(float4x4& value1, float4x4 const& value2) noexcept;
	constexpr float4x4& operator*=(float4x4& value1, float const value2) noexcept;
	constexpr bool operator==(float4x4 const& value1, float4x4 const& value2) noexcept;
	constexpr bool operator!=(float4x4 const& value1, float4x4 const& value2) noexcept;

	bool is_identity(float4x4 const& value) noexcept;
	float determinant(float4x4 const& value) noexcept;
	float3 translation(float4x4 const& value) noexcept;
	bool invert(float4x4 const& matrix, float4x4* const result) noexcept;
	bool decompose(float4x4 const& matrix, float3* const scale, quaternion* rotation, float3* const translation) noexcept;
	float4x4 transform(float4x4 const& value, quaternion const& rotation) noexcept;
	float4x4 transpose(float4x4 const& matrix) noexcept;
	float4x4 lerp(float4x4 const& matrix1, float4x4 const& matrix2, float const amount) noexcept;

	float4x4 make_float4x4_billboard(float3 const& objectPosition, float3 const& cameraPosition, float3 const& cameraUpVector, float3 const& cameraForwardVector) noexcept;
	float4x4 make_float4x4_constrained_billboard(float3 const& objectPosition, float3 const& cameraPosition, float3 const& rotateAxis, float3 const& cameraForwardVector, float3 const& objectForwardVector) noexcept;
	float4x4 make_float4x4_translation(float3 const& position) noexcept;
	float4x4 make_float4x4_translation(float const xPosition, float const yPosition, float const zPosition) noexcept;
	float4x4 make_float4x4_scale(float const xScale, float const yScale, float const zScale) noexcept;
	float4x4 make_float4x4_scale(float const xScale, float const yScale, float const zScale, float3 const& centerPoint) noexcept;
	float4x4 make_float4x4_scale(float3 const& scales) noexcept;
	float4x4 make_float4x4_scale(float3 const& scales, float3 const& centerPoint) noexcept;
	float4x4 make_float4x4_scale(float const scale) noexcept;
	float4x4 make_float4x4_scale(float const scale, float3 const& centerPoint) noexcept;
	float4x4 make_float4x4_rotation_x(float const radians) noexcept;
	float4x4 make_float4x4_rotation_x(float const radians, float3 const& centerPoint) noexcept;
	float4x4 make_float4x4_rotation_y(float const radians) noexcept;
	float4x4 make_float4x4_rotation_y(float const radians, float3 const& centerPoint) noexcept;
	float4x4 make_float4x4_rotation_z(float const radians) noexcept;
	float4x4 make_float4x4_rotation_z(float const radians, float3 const& centerPoint) noexcept;
	float4x4 make_float4x4_from_axis_angle(float3 const& axis, float const acos) noexcept;
	float4x4 make_float4x4_perspective_field_of_view(float const fieldOfView, float const aspectRatio, float const nearplaneDistance, float const farplaneDistance);
	float4x4 make_float4x4_perspective(float const width, float const height, float const nearplaneDistance, float const farplaneDistance);
	float4x4 make_float4x4_perspective_off_center(float const left, float const right, float const bottom, float const top, float const nearplaneDistance, float const farplaneDistance);
	float4x4 make_float4x4_orthographic(float const width, float const height, float const zNearplane, float const zFarplane) noexcept;
	float4x4 make_float4x4_orthographic_off_center(float const left, float const right, float const bottom, float const top, float const zNearplane, float const zFarplane) noexcept;
	float4x4 make_float4x4_look_at(float3 const& cameraPosition, float3 const& cameraTarget, float3 const& cameraUpVector) noexcept;
	float4x4 make_float4x4_world(float3 const& position, float3 const& forward, float3 const& up) noexcept;
	float4x4 make_float4x4_from_quaternion(quaternion const& quaternion) noexcept;
	float4x4 make_float4x4_from_yaw_pitch_roll(float const yaw, float const pitch, float const roll) noexcept;
	float4x4 make_float4x4_shadow(float3 const& lightDirection, plane const& plane) noexcept;
	float4x4 make_float4x4_reflection(plane const& value) noexcept;

	struct float4x4
	{
		constexpr static float4x4 identity() noexcept;

		constexpr float4x4(float const m11 = 0, float const m12 = 0, float const m13 = 0, float const m14 = 0,
						   float const m21 = 0, float const m22 = 0, float const m23 = 0, float const m24 = 0, 
						   float const m31 = 0, float const m32 = 0, float const m33 = 0, float const m34 = 0,
						   float const m41 = 0, float const m42 = 0, float const m43 = 0, float const m44 = 0) noexcept;
		constexpr float4x4(float4 const& r1, float4 const& r2 = float4::zero(), float4 const& r3 = float4::zero(), float4 const& r4 = float4::zero()) noexcept;
		constexpr explicit float4x4(float3x2 const& value) noexcept;

		bool is_identity() const noexcept;
		float determinant() const noexcept;
		float3 translation() const noexcept;
		bool invert(float4x4* const result) noexcept;
		bool decompose(float3* const scale, quaternion* rotation, float3* const translation) const noexcept;
		float4x4 transform(quaternion const& rotation) const noexcept;
		float4x4 transpose() const noexcept;
		float4x4 lerp(float4x4 const& matrix2, float const amount) const noexcept;

		float4& operator[](unsigned int const i) noexcept;
		const float4& operator[](unsigned int const i) const noexcept;

		union
		{
			struct
			{
				float m11, m12, m13, m14;
				float m21, m22, m23, m24;
				float m31, m32, m33, m34;
				float m41, m42, m43, m44;
			};
			struct
			{
				float4 r1;
				float4 r2;
				float4 r3;
				float4 r4;
			};
			float m[4][4];
			float value[16];
			float4 data[4];
			float4 row[4];
		};
	};

	constexpr plane operator+(plane const& value) noexcept;
	constexpr plane operator-(plane const& value) noexcept;
	constexpr bool operator==(plane const& value1, plane const& value2) noexcept;
	constexpr bool operator!=(plane const& value1, plane const& value2) noexcept;

	plane normalize(plane const& value) noexcept;
	plane transform(plane const& plane, float4x4 const& matrix) noexcept;
	plane transform(plane const& plane, quaternion const& rotation) noexcept;
	float3 one_point_on(plane const& plane) noexcept;
	float dot(plane const& plane, float4 const& value) noexcept;
	float dot_coordinate(plane const& plane, float3 const& value) noexcept;
	float dot_normal(plane const& plane, float3 const& value) noexcept;
	bool is_antarafacial(plane const& value1, float3 const& value2) noexcept;

	plane make_plane_from_vertices(float3 const& point1, float3 const& point2, float3 const& point3) noexcept;

	struct plane
	{
		constexpr plane(float const x = 0, float const y = 0, float const z = 0, float const d = 0) noexcept;
		constexpr explicit plane(float3 const& normal, float const d) noexcept;
		constexpr explicit plane(float4 const& value) noexcept;
		constexpr explicit plane(quaternion const& value) noexcept;

		plane normalize() const noexcept;
		plane transform(float4x4 const& matrix) const noexcept;
		plane transform(quaternion const& rotation) const noexcept;
		float3 one_point_on() const noexcept;
		float dot(float4 const& value) const noexcept;
		float dot_coordinate(float3 const& value) const noexcept;
		float dot_normal(float3 const& value) const noexcept;

		float& operator[](unsigned int const i) noexcept;
		const float& operator[](unsigned int const i) const noexcept;

		union
		{
			struct { float a; float b; float c; float d; };
			float3 normal;
			float value[4];
			float data[4];
		};
	};

	constexpr quaternion operator+(quaternion const& value1, quaternion const& value2) noexcept;
	constexpr quaternion operator-(quaternion const& value1, quaternion const& value2) noexcept;
	constexpr quaternion operator*(quaternion const& value1, quaternion const& value2) noexcept;
	constexpr quaternion operator*(quaternion const& value1, float const value2) noexcept;
	constexpr quaternion operator*(float const value1, quaternion const& value2) noexcept;
	constexpr quaternion operator/(quaternion const& value1, quaternion const& value2) noexcept;
	constexpr quaternion operator/(quaternion const& value1, float const value2) noexcept;
	constexpr quaternion operator+(quaternion const& value) noexcept;
	constexpr quaternion operator-(quaternion const& value) noexcept;
	constexpr quaternion& operator+=(quaternion& value1, quaternion const& value2) noexcept;
	constexpr quaternion& operator-=(quaternion& value1, quaternion const& value2) noexcept;
	constexpr quaternion& operator*=(quaternion& value1, quaternion const& value2) noexcept;
	constexpr quaternion& operator*=(quaternion& value1, float const value2) noexcept;
	constexpr quaternion& operator/=(quaternion& value1, quaternion const& value2) noexcept;
	constexpr quaternion& operator/=(quaternion& value1, float const value2) noexcept;
	constexpr bool operator==(quaternion const& value1, quaternion const& value2) noexcept;
	constexpr bool operator!=(quaternion const& value1, quaternion const& value2) noexcept;

	bool is_identity(quaternion const& value) noexcept;
	float length(quaternion const& value) noexcept;
	float length_squared(quaternion const& value) noexcept;
	float dot(quaternion const& quaternion1, quaternion const& quaternion2) noexcept;
	quaternion normalize(quaternion const& value) noexcept;
	quaternion conjugate(quaternion const& value) noexcept;
	quaternion inverse(quaternion const& value) noexcept;
	quaternion slerp(quaternion const& quaternion1, quaternion const& quaternion2, float const amount) noexcept;
	quaternion lerp(quaternion const& quaternion1, quaternion const& quaternion2, float const amount) noexcept;
	quaternion concatenate(quaternion const& value1, quaternion const& value2) noexcept;

	quaternion make_quaternion_from_axis_angle(float3 const& axis, float const acos) noexcept;
	quaternion make_quaternion_from_yaw_pitch_roll(float const yaw, float const pitch, float const roll) noexcept;
	quaternion make_quaternion_from_rotation_matrix(float4x4 const& matrix) noexcept;

	struct quaternion
	{
		constexpr static quaternion identity() noexcept;

		constexpr quaternion(float const x = 0, float const y = 0, float const z = 0, float const w = 0) noexcept;
		constexpr explicit quaternion(float2 const& value, float const z = 0, float const w = 0) noexcept;
		constexpr explicit quaternion(float3 const& value, float const w = 0) noexcept;
		constexpr explicit quaternion(float4 const& value) noexcept;
		constexpr explicit quaternion(plane const& value) noexcept;
		constexpr explicit quaternion(float const value = 0) noexcept;

		bool is_identity() const noexcept;
		float length() const noexcept;
		float length_squared() const noexcept;
		float dot(quaternion const& quaternion2) const noexcept;
		quaternion normalize() const noexcept;
		quaternion conjugate() const noexcept;
		quaternion inverse() const noexcept;
		quaternion slerp(quaternion const& quaternion2, float const amount) const noexcept;
		quaternion lerp(quaternion const& quaternion2, float const amount) const noexcept;
		quaternion concatenate(quaternion const& value2) const noexcept;

		float& operator[](unsigned int const i) noexcept;
		const float& operator[](unsigned int const i) const noexcept;

		union
		{
			struct { float x; float y; float z; float w; };
			struct { float X; float Y; float Z; float W; };
			float value[4];
			float data[4];
		};
	};

	bool is_parallel(float2x2 const& value1, float2x2 const& value2) noexcept;
	bool is_intersecting(float2x2 const& value1, float2x2 const& value2) noexcept;
	float2 intersection(float2x2 const& value1, float2x2 const& value2) noexcept;

	struct float2x2
	{
		constexpr float2x2(float const x1 = 0, float const y1 = 0, float const x2 = 0, float const y2 = 0) noexcept;
		constexpr float2x2(float2 const& value1, float2 const& value2) noexcept;
		constexpr explicit float2x2(float4 const& value) noexcept;

		constexpr static float2x2 zero() noexcept;
		constexpr static float2x2 one() noexcept;
		constexpr static float2x2 unit_x() noexcept;
		constexpr static float2x2 unit_y() noexcept;

		bool is_parallel(float2x2 const& value2) const noexcept;
		bool is_intersecting(float2x2 const& value2) const noexcept;
		float2 intersection(float2x2 const& value2) const noexcept;

		float2& operator[](unsigned int const i) noexcept;
		const float2& operator[](unsigned int const i) const noexcept;

		union
		{
			struct { float x1; float y1; float x2; float y2; };
			struct { float2 p; float2 v; };
			float value[4];
			float2 data[2];
		};
	};

	bool is_parallel(float2x3 const& value1, float2x3 const& value2) noexcept;
	bool is_antarafacial(float2x3 const& value1, float2x3 const& value2) noexcept;
	bool is_intersecting(float2x3 const& value1, float2x3 const& value2) noexcept;
	float3 intersection(float2x3 const& value1, float2x3 const& value2) noexcept;

	struct float2x3
	{
		constexpr float2x3(float const x1 = 0, float const y1 = 0, float const z1 = 0,
						float const x2 = 0, float const y2 = 0, float const z2 = 0) noexcept;
		constexpr float2x3(float3 const& value1, float3 const& value2) noexcept;

		constexpr static float2x3 zero() noexcept;
		constexpr static float2x3 one() noexcept;
		constexpr static float2x3 unit_x() noexcept;
		constexpr static float2x3 unit_y() noexcept;
		constexpr static float2x3 unit_z() noexcept;

		bool is_parallel(float2x3 const& value2) const noexcept;
		bool is_antarafacial(float2x3 const& value2) const noexcept;
		bool is_intersecting(float2x3 const& value2) const noexcept;
		float3 intersection(float2x3 const& value2) const noexcept;

		float3& operator[](unsigned int const i) noexcept;
		const float3& operator[](unsigned int const i) const noexcept;

		union
		{
			struct { float x1; float y1;; float z1; float x2; float y2; ; float z2; };
			struct { float3 p; float3 v; };
			float value[6];
			float3 data[2];
		};
	};

	::std::ostream& operator<<(::std::ostream& os, float2 const& value) noexcept;
	::std::ostream& operator<<(::std::ostream& os, float3 const& value) noexcept;
	::std::ostream& operator<<(::std::ostream& os, float4 const& value) noexcept;
	::std::ostream& operator<<(::std::ostream& os, float3x2 const& value) noexcept;
	::std::ostream& operator<<(::std::ostream& os, float4x4 const& value) noexcept;
	::std::ostream& operator<<(::std::ostream& os, plane const& value) noexcept;
	::std::ostream& operator<<(::std::ostream& os, quaternion const& value) noexcept;
	::std::ostream& operator<<(::std::ostream& os, float2x2 const& value) noexcept;
	::std::ostream& operator<<(::std::ostream& os, float2x3 const& value) noexcept;
}