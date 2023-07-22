/**
 * @file	numerics.0.inl
 * @brief	HiCxx 的数学模块
 * @author	侧云
*/

#include "numerics.0.h"
#include "hicxx_defines.h"

namespace HiCxx
{
	constexpr float2 operator+(float2 const& value1, float2 const& value2) noexcept
	{
		return { value1.x + value2.x, value1.y + value2.y };
	}

	constexpr float2 operator-(float2 const& value1, float2 const& value2) noexcept
	{
		return { value1.x - value2.x, value1.y - value2.y };
	}

	constexpr float2 operator*(float2 const& value1, float2 const& value2) noexcept
	{
		return { value1.x * value2.x, value1.y * value2.y };
	}

	constexpr float2 operator*(float2 const& value1, float const value2) noexcept
	{
		return { value1.x * value2, value1.y * value2 };
	}

	constexpr float2 operator*(float const value1, float2 const& value2) noexcept
	{
		return value2 * value1;
	}

	constexpr float2 operator/(float2 const& value1, float2 const& value2) noexcept
	{
		return { value1.x / value2.x, value1.y / value2.y };
	}

	constexpr float2 operator/(float2 const& value1, float const value2) noexcept
	{
		return value1 * (1 / value2);
	}

	constexpr float2 operator+(float2 const& value1) noexcept
	{
		return value1;
	}

	constexpr float2 operator-(float2 const& value1) noexcept
	{
		return { -value1.x, -value1.y };
	}

	constexpr float2& operator+=(float2& value1, float2 const& value2) noexcept
	{
		return value1 = value1 + value2;
	}

	constexpr float2& operator-=(float2& value1, float2 const& value2) noexcept
	{
		return value1 = value1 - value2;
	}

	constexpr float2& operator*=(float2& value1, float2 const& value2) noexcept
	{
		return value1 = value1 * value2;
	}

	constexpr float2& operator*=(float2& value1, float const value2) noexcept
	{
		return value1 = value1 * value2;
	}

	constexpr float2& operator/=(float2& value1, float2 const& value2) noexcept
	{
		return value1 = value1 / value2;
	}

	constexpr float2& operator/=(float2& value1, float const value2) noexcept
	{
		return value1 = value1 / value2;
	}

	constexpr bool operator==(float2 const& value1, float2 const& value2) noexcept
	{
		return value1.x == value2.x && value1.y == value2.y;
	}

	constexpr bool operator!=(float2 const& value1, float2 const& value2) noexcept
	{
		return value1.x != value2.x || value1.y != value2.y;
	}

	inline float length(float2 const& value1) noexcept
	{
		return sqrtf(length_squared(value1));
	}

	inline float length_squared(float2 const& value1) noexcept
	{
		return dot(value1, value1);
	}

	inline float distance(float2 const& value1, float2 const& value2) noexcept
	{
		return length(value1 - value2);
	}

	inline float distance_squared(float2 const& value1, float2 const& value2) noexcept
	{
		return length_squared(value1 - value2);
	}

	inline float distance(float2 const& value1, float2x2 const& value2) noexcept
	{
		return fabs(distance_directed(value1, value2));
	}

	inline float distance_directed(float2 const& value1, float2x2 const& value2) noexcept
	{
		return cross(value2.v, value2.p - value1) / length(value1);
	}

	inline float cos(float2 const& value1, float2 const& value2) noexcept
	{
		return dot(value1, value2) / (value1.length() * value2.length());
	}

	inline float acos(float2 const& value1, float2 const& value2) noexcept
	{
		return acosf(cos(value1, value2));
	}

	inline float dot(float2 const& vector1, float2 const& vector2) noexcept
	{
		return vector1.x * vector2.x + vector1.y * vector2.y;
	}

	inline float cross(float2 const& vector1, float2 const& vector2) noexcept
	{
		return vector1.x * vector2.y - vector1.y * vector2.x;
	}

	inline float2 abs(float2 const& value1) noexcept
	{
		return { value1.x < 0 ? -value1.x : value1.x,
				 value1.y < 0 ? -value1.y : value1.y };
	}

	inline float2 sqrt(float2 const& value1) noexcept
	{
		return { sqrtf(value1.x), sqrtf(value1.y) };
	}

	inline float2 squared(float2 const& value1) noexcept
	{
		return value1 * value1;
	}

	inline float2 rotate(float2 const& value1, float const value2) noexcept
	{
		float const _cos = cosf(value2);
		float const _sin = sinf(value2);
		return { value1.x * _cos - value1.y * _sin, value1.x * _sin + value1.y * _cos };
	}

	inline float2 rotate90(float2 const& value1) noexcept
	{
		return { -value1.y, value1.x };
	}

	inline float2 normalize(float2 const& value1) noexcept
	{
		return value1 / length(value1);
	}

	inline float2 reflect(float2 const& value, float2 const& normal) noexcept
	{
		return value - 2 * dot(value, normal) * normal;
	}

	inline float2 min(float2 const& value1, float2 const& value2) noexcept
	{
		return { value1.x < value2.x ? value1.x : value2.x,
				 value1.y < value2.y ? value1.y : value2.y };
	}

	inline float2 max(float2 const& value1, float2 const& value2) noexcept
	{
		return { value1.x > value2.x ? value1.x : value2.x,
				 value1.y > value2.y ? value1.y : value2.y };
	}

	inline float2 projection(float2 const& value1, float2 const& value2) noexcept
	{
		return value2 * (length(value1) * cos(value1, value2) / length(value2));
	}

	inline float2 projection(float2 const& value1, float2x2 const& value2) noexcept
	{
		return value2.p + value2.v * (dot(value2.v, value1 - value2.p) / dot(value2.v, value2.v));
	}

	inline float2 clamp(float2 const& value1, float2 const& minValue, float2 const& maxValue) noexcept
	{
		return max(min(value1, minValue), maxValue);
	}

	inline float2 lerp(float2 const& value1, float2 const& value2, float const amount) noexcept
	{
		return value1 + (value2 - value1) * amount;
	}

	inline float2 transform(float2 const& position, float3x2 const& matrix) noexcept
	{
		return { position.x * matrix.m11 + position.y * matrix.m21 + matrix.m31,
				 position.x * matrix.m12 + position.y * matrix.m22 + matrix.m32 };
	}

	inline float2 transform(float2 const& position, float4x4 const& matrix) noexcept
	{
		return { position.x * matrix.m11 + position.y * matrix.m21 + matrix.m41,
				 position.x * matrix.m12 + position.y * matrix.m22 + matrix.m42 };
	}

	inline float2 transform_normal(float2 const& normal, float3x2 const& matrix) noexcept
	{
		return { normal.x * matrix.m11 + normal.y * matrix.m21,
				 normal.x * matrix.m12 + normal.y * matrix.m22 };
	}

	inline float2 transform_normal(float2 const& normal, float4x4 const& matrix) noexcept
	{
		return { normal.x * matrix.m11 + normal.y * matrix.m21,
				 normal.x * matrix.m12 + normal.y * matrix.m22 };
	}

	inline float2 transform(float2 const& value, quaternion const& rotation) noexcept
	{
		float const x2 = rotation.x + rotation.x;
		float const y2 = rotation.y + rotation.y;
		float const z2 = rotation.z + rotation.z;

		float const wz2 = rotation.w * z2;
		float const xx2 = rotation.x * x2;
		float const xy2 = rotation.x * y2;
		float const yy2 = rotation.y * y2;
		float const zz2 = rotation.z * z2;

		return { value.x * (1 - yy2 - zz2) + value.y * (xy2 - wz2),
				 value.x * (xy2 + wz2) + value.y * (1 - xx2 - zz2) };
	}

	inline bool is_parallel(float2 const& value1, float2 const& value2) noexcept
	{
		return cross(value1, value2) == 0;
	}

	inline bool is_intersecting(float2 const& value1, float2 const& value2) noexcept
	{
		return !is_parallel(value1, value2);
	}

	constexpr float2::float2(float const x, float const y) noexcept : value{ x, y } {}

	constexpr float2::float2(float3 const& value) noexcept : value{ value.x, value.y } {}

	constexpr float2::float2(float4 const& value) noexcept : value{ value.x, value.y } {}

	constexpr float2::float2(float const value) noexcept : value{ value, value } {}

	constexpr float2 float2::zero() noexcept
	{
		return { 0, 0 };
	}

	constexpr float2 float2::one() noexcept
	{
		return { 1, 1 };
	}

	constexpr float2 float2::unit_x() noexcept
	{
		return { 1, 0 };
	}

	constexpr float2 float2::unit_y() noexcept
	{
		return { 0, 1 };
	}

	inline float float2::length() const noexcept
	{
		return HiCxx::length(*this);
	}

	inline float float2::length_squared() const noexcept
	{
		return HiCxx::length_squared(*this);
	}

	inline float float2::distance(float2 const& value2) const noexcept
	{
		return HiCxx::distance(*this, value2);
	}

	inline float float2::distance_squared(float2 const& value2) const noexcept
	{
		return HiCxx::distance_squared(*this, value2);
	}

	inline float float2::distance(float2x2 const& value2) const noexcept
	{
		return HiCxx::distance(*this, value2);
	}

	inline float float2::distance_directed(float2x2 const& value2) const noexcept
	{
		return HiCxx::distance_directed(*this, value2);
	}

	inline float float2::cos(float2 const& value2) const noexcept
	{
		return HiCxx::cos(*this, value2);
	}

	inline float float2::acos(float2 const& value2) const noexcept
	{
		return HiCxx::acos(*this, value2);
	}

	inline float float2::dot(float2 const& vector2) const noexcept
	{
		return HiCxx::dot(*this, vector2);
	}

	inline float float2::cross(float2 const& vector2) const noexcept
	{
		return HiCxx::cross(*this, vector2);
	}

	inline float2 float2::abs() const noexcept
	{
		return HiCxx::abs(*this);
	}

	inline float2 float2::sqrt() const noexcept
	{
		return HiCxx::sqrt(*this);
	}

	inline float2 float2::squared() const noexcept
	{
		return HiCxx::squared(*this);
	}

	inline float2 float2::rotate(float const value2) const noexcept
	{
		return HiCxx::rotate(*this, value2);
	}

	inline float2 float2::rotate90() const noexcept
	{
		return HiCxx::rotate90(*this);
	}

	inline float2 float2::normalize() const noexcept
	{
		return HiCxx::normalize(*this);
	}

	inline float2 float2::reflect(float2 const& normal) const noexcept
	{
		return HiCxx::reflect(*this, normal);
	}

	inline float2 float2::min(float2 const& value2) const noexcept
	{
		return HiCxx::min(*this, value2);
	}

	inline float2 float2::max(float2 const& value2) const noexcept
	{
		return HiCxx::max(*this, value2);
	}

	inline float2 float2::projection(float2 const& value2) const noexcept
	{
		return HiCxx::projection(*this, value2);
	}

	inline float2 float2::projection(float2x2 const& value2) const noexcept
	{
		return HiCxx::projection(*this, value2);
	}

	inline float2 float2::clamp(float2 const& minValue, float2 const& maxValue) const noexcept
	{
		return HiCxx::clamp(*this, minValue, maxValue);
	}

	inline float2 float2::lerp(float2 const& value2, float const amount) const noexcept
	{
		return HiCxx::lerp(*this, value2, amount);
	}

	inline float2 float2::transform(float3x2 const& matrix) const noexcept
	{
		return HiCxx::transform(*this, matrix);
	}

	inline float2 float2::transform(float4x4 const& matrix) const noexcept
	{
		return HiCxx::transform(*this, matrix);
	}

	inline float2 float2::transform_normal(float3x2 const& matrix) const noexcept
	{
		return HiCxx::transform_normal(*this, matrix);
	}

	inline float2 float2::transform_normal(float4x4 const& matrix) const noexcept
	{
		return HiCxx::transform_normal(*this, matrix);
	}

	inline float2 float2::transform(quaternion const& rotation) const noexcept
	{
		return HiCxx::transform(*this, rotation);
	}

	inline bool float2::is_parallel(float2 const& value2) const noexcept
	{
		return HiCxx::is_parallel(*this, value2);
	}

	inline bool float2::is_intersecting(float2 const& value2) const noexcept
	{
		return HiCxx::is_intersecting(*this, value2);
	}

	inline float& float2::operator[](unsigned int const i) noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 2, L"float2 subscript out of range");
		return this->data[i];
	}

	inline float const& float2::operator[](unsigned int const i) const noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 2, L"float2 subscript out of range");
		return this->data[i];
	}

	constexpr float3 operator+(float3 const& value1, float3 const& value2) noexcept
	{
		return { value1.x + value2.x, value1.y + value2.y, value1.z + value2.z };
	}

	constexpr float3 operator-(float3 const& value1, float3 const& value2) noexcept
	{
		return { value1.x - value2.x, value1.y - value2.y, value1.z - value2.z };
	}

	constexpr float3 operator*(float3 const& value1, float3 const& value2) noexcept
	{
		return { value1.x * value2.x, value1.y * value2.y, value1.z * value2.z };
	}

	constexpr float3 operator*(float3 const& value1, float const value2) noexcept
	{
		return { value1.x * value2, value1.y * value2, value1.z * value2 };
	}

	constexpr float3 operator*(float const value1, float3 const& value2) noexcept
	{
		return value2 * value1;
	}

	constexpr float3 operator/(float3 const& value1, float3 const& value2) noexcept
	{
		return { value1.x / value2.x, value1.y / value2.y, value1.z / value2.z };
	}

	constexpr float3 operator/(float3 const& value1, float const value2) noexcept
	{
		return value1 * (1 / value2);
	}

	constexpr float3 operator+(float3 const& value1) noexcept
	{
		return value1;
	}

	constexpr float3 operator-(float3 const& value1) noexcept
	{
		return { -value1.x, -value1.y, -value1.z };
	}

	constexpr float3& operator+=(float3& value1, float3 const& value2) noexcept
	{
		return value1 = value1 + value2;
	}

	constexpr float3& operator-=(float3& value1, float3 const& value2) noexcept
	{
		return value1 = value1 - value2;
	}

	constexpr float3& operator*=(float3& value1, float3 const& value2) noexcept
	{
		return value1 = value1 * value2;
	}

	constexpr float3& operator*=(float3& value1, float const value2) noexcept
	{
		return value1 = value1 * value2;
	}

	constexpr float3& operator/=(float3& value1, float3 const& value2) noexcept
	{
		return value1 = value1 / value2;
	}

	constexpr float3& operator/=(float3& value1, float const value2) noexcept
	{
		return value1 = value1 / value2;
	}

	constexpr bool operator==(float3 const& value1, float3 const& value2) noexcept
	{
		return value1.x == value2.x && value1.y == value2.y && value1.z == value2.z;
	}

	constexpr bool operator!=(float3 const& value1, float3 const& value2) noexcept
	{
		return value1.x != value2.x || value1.y != value2.y || value1.z != value2.z;
	}

	inline float length(float3 const& value1) noexcept
	{
		return sqrtf(length_squared(value1));
	}

	inline float length_squared(float3 const& value1) noexcept
	{
		return dot(value1, value1);
	}

	inline float distance(float3 const& value1, float3 const& value2) noexcept
	{
		return length(value1 - value2);
	}

	inline float distance_squared(float3 const& value1, float3 const& value2) noexcept
	{
		return length_squared(value1 - value2);
	}

	inline float distance(float3 const& value1, float2x3 const& value2) noexcept
	{
		return fabs(distance_directed(value1, value2));
	}

	inline float distance_directed(float3 const& value1, float2x3 const& value2) noexcept
	{
		return length(cross(value2.v, value2.p - value1)) / length(value1);
	}

	inline float cos(float3 const& value1, float3 const& value2) noexcept
	{
		return dot(value1, value2) / (value1.length() * value2.length());
	}

	inline float acos(float3 const& value1, float3 const& value2) noexcept
	{
		return acosf(cos(value1, value2));
	}

	inline float dot(float3 const& vector1, float3 const& vector2) noexcept
	{
		return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z;
	}

	inline float3 cross(float3 const& vector1, float3 const& vector2) noexcept
	{
		return { vector1.y * vector2.z - vector1.z * vector2.y,
				 vector1.z * vector2.x - vector1.x * vector2.z,
				 vector1.x * vector2.y - vector1.y * vector2.x };
	}

	inline float3 abs(float3 const& value1) noexcept
	{
		return { value1.x < 0 ? -value1.x : value1.x,
				 value1.y < 0 ? -value1.y : value1.y,
				 value1.z < 0 ? -value1.z : value1.z };
	}

	inline float3 sqrt(float3 const& value1) noexcept
	{
		return { sqrtf(value1.x), sqrtf(value1.y), sqrtf(value1.z) };
	}

	inline float3 squared(float3 const& value1) noexcept
	{
		return value1 * value1;
	}

	inline float3 rotate(float3 const& value1, float const radX, float const radY, float const radZ) noexcept
	{
		return rotate_z(rotate_y(rotate_x(value1, radX), radY), radZ);
	}

	inline float3 rotate_x(float3 const& value1, float const rad) noexcept
	{
		float const _sin = sinf(rad);
		float const _cos = cosf(rad);
		return { value1.x, value1.y * _cos - value1.z * _sin, value1.z * _cos + value1.y * _sin };
	}

	inline float3 rotate_y(float3 const& value1, float const rad) noexcept
	{
		float const _sin = sinf(rad);
		float const _cos = cosf(rad);
		return { value1.x * _cos - value1.z * _sin, value1.y, value1.z * _cos + value1.x * _sin };
	}

	inline float3 rotate_z(float3 const& value1, float const rad) noexcept
	{
		float const _sin = sinf(rad);
		float const _cos = cosf(rad);
		return { value1.x * _cos - value1.y * _sin, value1.y * _cos + value1.x * _sin, value1.z };
	}

	inline float3 rotate90_x(float3 const& value1) noexcept
	{
		return { value1.x, -value1.z, value1.y };
	}

	inline float3 rotate90_y(float3 const& value1) noexcept
	{
		return { -value1.z, value1.y, value1.x };
	}

	inline float3 rotate90_z(float3 const& value1) noexcept
	{
		return { -value1.y, value1.x, value1.z };
	}

	inline float3 normalize(float3 const& value1) noexcept
	{
		return value1 / length(value1);
	}

	inline float3 reflect(float3 const& value, float3 const& normal) noexcept
	{
		return value - 2 * dot(value, normal) * normal;
	}

	inline float3 min(float3 const& value1, float3 const& value2) noexcept
	{
		return { value1.x < value2.x ? value1.x : value2.x,
				 value1.y < value2.y ? value1.y : value2.y,
				 value1.z < value2.z ? value1.z : value2.z };
	}

	inline float3 max(float3 const& value1, float3 const& value2) noexcept
	{
		return { value1.x > value2.x ? value1.x : value2.x,
				 value1.y > value2.y ? value1.y : value2.y,
				 value1.z > value2.z ? value1.z : value2.z, };
	}

	inline float3 projection(float3 const& value1, float3 const& value2) noexcept
	{
		return value2 * (length(value1) * cos(value1, value2) / length(value2));
	}

	inline float3 projection(float3 const& value1, plane const& value2) noexcept
	{
		_HICXX_ASSERT(value2.normal != float3::zero(), L"normal is zero vector");
		return value1 - normalize(value2.normal) * dot(value1 - one_point_on(value2), normalize(value2.normal));
	}

	inline float3 clamp(float3 const& value1, float3 const& minValue, float3 const& maxValue) noexcept
	{
		return max(min(value1, minValue), maxValue);
	}

	inline float3 lerp(float3 const& value1, float3 const& value2, float const amount) noexcept
	{
		return value1 + (value2 - value1) * amount;
	}

	inline float3 transform(float3 const& position, float4x4 const& matrix)
	{
		return { position.x * matrix.m11 + position.y * matrix.m21 + position.z * matrix.m31 + matrix.m41,
				 position.x * matrix.m12 + position.y * matrix.m22 + position.z * matrix.m32 + matrix.m42,
				 position.x * matrix.m13 + position.y * matrix.m23 + position.z * matrix.m33 + matrix.m43 };
	}

	inline float3 transform_normal(float3 const& normal, float4x4 const& matrix)
	{
		return { normal.x * matrix.m11 + normal.y * matrix.m21 + normal.z * matrix.m31,
				 normal.x * matrix.m12 + normal.y * matrix.m22 + normal.z * matrix.m32,
				 normal.x * matrix.m13 + normal.y * matrix.m23 + normal.z * matrix.m33 };
	}

	inline float3 transform(float3 const& value, quaternion const& rotation)
	{
		float const x2 = rotation.x + rotation.x;
		float const y2 = rotation.y + rotation.y;
		float const z2 = rotation.z + rotation.z;

		float const wx2 = rotation.w * x2;
		float const wy2 = rotation.w * y2;
		float const wz2 = rotation.w * z2;
		float const xx2 = rotation.x * x2;
		float const xy2 = rotation.x * y2;
		float const xz2 = rotation.x * z2;
		float const yy2 = rotation.y * y2;
		float const yz2 = rotation.y * z2;
		float const zz2 = rotation.z * z2;

		return { value.x * (1 - yy2 - zz2) + value.y * (xy2 - wz2) + value.z * (xz2 + wy2),
				 value.x * (xy2 + wz2) + value.y * (1 - xx2 - zz2) + value.z * (yz2 - wx2),
				 value.x * (xz2 - wy2) + value.y * (yz2 + wx2) + value.z * (1 - xx2 - yy2) };
	}

	inline bool is_parallel(float3 const& value1, float3 const& value2) noexcept
	{
		return cross(value1, value2) == float3::zero();
	}

	constexpr float3::float3(float const x, float const y, float const z) noexcept : value{ x, y, z } {}

	constexpr float3::float3(float2 const& value, float const z) noexcept : value{ value.x, value.y, z } {}

	constexpr float3::float3(float4 const& value) noexcept : value{ value.x, value.y, value.z } {}

	constexpr float3::float3(float const value) noexcept : value{ value, value, value } {}

	constexpr float3 float3::zero() noexcept
	{
		return { 0, 0, 0 };
	}

	constexpr float3 float3::one() noexcept
	{
		return { 1, 1, 1 };
	}

	constexpr float3 float3::unit_x() noexcept
	{
		return { 1, 0, 0 };
	}

	constexpr float3 float3::unit_y() noexcept
	{
		return { 0, 1, 0 };
	}

	constexpr float3 float3::unit_z() noexcept
	{
		return { 0, 0, 1 };
	}

	inline float float3::length() const noexcept
	{
		return HiCxx::length(*this);
	}

	inline float float3::length_squared() const noexcept
	{
		return HiCxx::length_squared(*this);
	}

	inline float float3::distance(float3 const& value2) const noexcept
	{
		return HiCxx::distance(*this, value2);
	}

	inline float float3::distance_squared(float3 const& value2) const noexcept
	{
		return HiCxx::distance_squared(*this, value2);
	}

	inline float float3::distance(float2x3 const& value2) const noexcept
	{
		return HiCxx::distance(*this, value2);
	}

	inline float float3::distance_directed(float2x3 const& value2) const noexcept
	{
		return HiCxx::distance_directed(*this, value2);
	}

	inline float float3::cos(float3 const& value2) const noexcept
	{
		return HiCxx::cos(*this, value2);
	}

	inline float float3::acos(float3 const& value2) const noexcept
	{
		return HiCxx::acos(*this, value2);
	}

	inline float float3::dot(float3 const& value2) const noexcept
	{
		return HiCxx::dot(*this, value2);
	}

	inline float3 float3::cross(float3 const& value2) const noexcept
	{
		return HiCxx::cross(*this, value2);
	}

	inline float3 float3::abs() const noexcept
	{
		return HiCxx::abs(*this);
	}

	inline float3 float3::sqrt() const noexcept
	{
		return HiCxx::sqrt(*this);
	}

	inline float3 float3::squared() const noexcept
	{
		return HiCxx::squared(*this);
	}

	inline float3 float3::rotate(float const radX, float const radY, float const radZ) const noexcept
	{
		return HiCxx::rotate(*this, radX, radY, radZ);
	}

	inline float3 float3::rotate_x(float const radX) const noexcept
	{
		return HiCxx::rotate_x(*this, radX);
	}

	inline float3 float3::rotate_y(float const radX) const noexcept
	{
		return HiCxx::rotate_y(*this, radX);
	}

	inline float3 float3::rotate_z(float const radX) const noexcept
	{
		return HiCxx::rotate_z(*this, radX);
	}

	inline float3 float3::rotate90_x() const noexcept
	{
		return HiCxx::rotate90_x(*this);
	}

	inline float3 float3::rotate90_y() const noexcept
	{
		return HiCxx::rotate90_y(*this);
	}

	inline float3 float3::rotate90_z() const noexcept
	{
		return HiCxx::rotate90_z(*this);
	}

	inline float3 float3::normalize() const noexcept
	{
		return HiCxx::normalize(*this);
	}

	inline float3 float3::reflect(float3 const& normal) const noexcept
	{
		return HiCxx::reflect(*this, normal);
	}

	inline float3 float3::min(float3 const& value2) const noexcept
	{
		return HiCxx::min(*this, value2);
	}

	inline float3 float3::max(float3 const& value2) const noexcept
	{
		return HiCxx::max(*this, value2);
	}

	inline float3 float3::projection(float3 const& value2) const noexcept
	{
		return HiCxx::projection(*this, value2);
	}

	inline float3 float3::projection(plane const& value2) const noexcept
	{
		return HiCxx::projection(*this, value2);
	}

	inline float3 float3::clamp(float3 const& minValue, float3 const& maxValue) const noexcept
	{
		return HiCxx::clamp(*this, minValue, maxValue);
	}

	inline float3 float3::lerp(float3 const& value2, float const amount) const noexcept
	{
		return HiCxx::lerp(*this, value2, amount);
	}

	inline float3 float3::transform(float4x4 const& matrix) const noexcept
	{
		return HiCxx::transform(*this, matrix);
	}

	inline float3 float3::transform_normal(float4x4 const& matrix) const noexcept
	{
		return HiCxx::transform_normal(*this, matrix);
	}

	inline float3 float3::transform(quaternion const& rotation) const noexcept
	{
		return HiCxx::transform(*this, rotation);
	}

	inline bool float3::is_parallel(float3 const& value2) const noexcept
	{
		return HiCxx::is_parallel(*this, value2);
	}

	inline float& float3::operator[](unsigned int const i) noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 3, L"float3 subscript out of range");
		return this->data[i];
	}

	inline float const& float3::operator[](unsigned int const i) const noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 3, L"float3 subscript out of range");
		return this->data[i];
	}

	constexpr float4 operator+(float4 const& value1, float4 const& value2) noexcept
	{
		return { value1.x + value2.x, value1.y + value2.y, value1.z + value2.z, value1.w + value2.w };
	}

	constexpr float4 operator-(float4 const& value1, float4 const& value2) noexcept
	{
		return { value1.x - value2.x, value1.y - value2.y, value1.z - value2.z, value1.w - value2.w };
	}

	constexpr float4 operator*(float4 const& value1, float4 const& value2) noexcept
	{
		return { value1.x * value2.x, value1.y * value2.y, value1.z * value2.z, value1.w * value2.w };
	}

	constexpr float4 operator*(float4 const& value1, float const value2) noexcept
	{
		return { value1.x * value2, value1.y * value2, value1.z * value2, value1.w * value2 };
	}

	constexpr float4 operator*(float const value1, float4 const& value2) noexcept
	{
		return value2 * value1;
	}

	constexpr float4 operator/(float4 const& value1, float4 const& value2) noexcept
	{
		return { value1.x / value2.x, value1.y / value2.y, value1.z / value2.z, value1.w / value2.w };
	}

	constexpr float4 operator/(float4 const& value1, float const value2) noexcept
	{
		return value1 * (1 / value2);
	}

	constexpr float4 operator+(float4 const& value1) noexcept
	{
		return value1;
	}

	constexpr float4 operator-(float4 const& value1) noexcept
	{
		return { -value1.x, -value1.y, -value1.z, -value1.w };
	}

	constexpr float4& operator+=(float4& value1, float4 const& value2) noexcept
	{
		return value1 = value1 + value2;
	}

	constexpr float4& operator-=(float4& value1, float4 const& value2) noexcept
	{
		return value1 = value1 - value2;
	}

	constexpr float4& operator*=(float4& value1, float4 const& value2) noexcept
	{
		return value1 = value1 * value2;
	}

	constexpr float4& operator*=(float4& value1, float const value2) noexcept
	{
		return value1 = value1 * value2;
	}

	constexpr float4& operator/=(float4& value1, float4 const& value2) noexcept
	{
		return value1 = value1 / value2;
	}

	constexpr float4& operator/=(float4& value1, float const value2) noexcept
	{
		return value1 = value1 / value2;
	}

	constexpr bool operator==(float4 const& value1, float4 const& value2) noexcept
	{
		return value1.x == value2.x && value1.y == value2.y && value1.z == value2.z && value1.w == value2.w;
	}

	constexpr bool operator!=(float4 const& value1, float4 const& value2) noexcept
	{
		return value1.x != value2.x || value1.y != value2.y || value1.z != value2.z || value1.w != value2.w;
	}

	inline float length(float4 const& value1) noexcept
	{
		return sqrtf(length_squared(value1));
	}

	inline float length_squared(float4 const& value1) noexcept
	{
		return dot(value1, value1);
	}

	inline float distance(float4 const& value1, float4 const& value2) noexcept
	{
		return length(value1 - value2);
	}

	inline float distance_squared(float4 const& value1, float4 const& value2) noexcept
	{
		return length_squared(value1 - value2);
	}

	inline float dot(float4 const& vector1, float4 const& vector2) noexcept
	{
		return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z + vector1.w * vector2.w;
	}

	inline float4 abs(float4 const& value1) noexcept
	{
		return { value1.x < 0 ? -value1.x : value1.x,
				 value1.y < 0 ? -value1.y : value1.y,
				 value1.z < 0 ? -value1.z : value1.z,
				 value1.w < 0 ? -value1.w : value1.w };
	}

	inline float4 sqrt(float4 const& value1) noexcept
	{
		return { sqrtf(value1.x), sqrtf(value1.y), sqrtf(value1.z), sqrtf(value1.w) };
	}

	inline float4 squared(float4 const& value1) noexcept
	{
		return value1 * value1;
	}

	inline float4 normalize(float4 const& value1) noexcept
	{
		return value1 / length(value1);
	}

	inline float4 reflect(float4 const& value, float4 const& normal) noexcept
	{
		return value - 2 * dot(value, normal) * normal;
	}

	inline float4 min(float4 const& value1, float4 const& value2) noexcept
	{
		return { value1.x < value2.x ? value1.x : value2.x,
				 value1.y < value2.y ? value1.y : value2.y,
				 value1.z < value2.z ? value1.z : value2.z,
				 value1.w < value2.w ? value1.w : value2.w };
	}

	inline float4 max(float4 const& value1, float4 const& value2) noexcept
	{
		return { value1.x > value2.x ? value1.x : value2.x,
				 value1.y > value2.y ? value1.y : value2.y,
				 value1.z > value2.z ? value1.z : value2.z,
				 value1.w > value2.w ? value1.w : value2.w };
	}

	inline float4 clamp(float4 const& value1, float4 const& minValue, float4 const& maxValue) noexcept
	{
		return max(min(value1, minValue), maxValue);
	}

	inline float4 lerp(float4 const& value1, float4 const& value2, float const amount) noexcept
	{
		return value1 + (value2 - value1) * amount;
	}

	inline float4 transform(float4 const& vector, float4x4 const& matrix) noexcept
	{
		return { vector.x * matrix.m11 + vector.y * matrix.m21 + vector.z * matrix.m31 + vector.w * matrix.m41,
				 vector.x * matrix.m12 + vector.y * matrix.m22 + vector.z * matrix.m32 + vector.w * matrix.m42,
				 vector.x * matrix.m13 + vector.y * matrix.m23 + vector.z * matrix.m33 + vector.w * matrix.m43,
				 vector.x * matrix.m14 + vector.y * matrix.m24 + vector.z * matrix.m34 + vector.w * matrix.m44 };
	}

	inline float4 transform4(float3 const& position, float4x4 const& matrix) noexcept
	{
		return { position.x * matrix.m11 + position.y * matrix.m21 + position.z * matrix.m31 + matrix.m41,
				 position.x * matrix.m12 + position.y * matrix.m22 + position.z * matrix.m32 + matrix.m42,
				 position.x * matrix.m13 + position.y * matrix.m23 + position.z * matrix.m33 + matrix.m43,
				 position.x * matrix.m14 + position.y * matrix.m24 + position.z * matrix.m34 + matrix.m44 };
	}

	inline float4 transform4(float2 const& position, float4x4 const& matrix) noexcept
	{
		return { position.x * matrix.m11 + position.y * matrix.m21 + matrix.m41,
				 position.x * matrix.m12 + position.y * matrix.m22 + matrix.m42,
				 position.x * matrix.m13 + position.y * matrix.m23 + matrix.m43,
				 position.x * matrix.m14 + position.y * matrix.m24 + matrix.m44 };
	}

	inline float4 transform(float4 const& value, quaternion const& rotation) noexcept
	{
		float const xx = rotation.x + rotation.x;
		float const yy = rotation.y + rotation.y;
		float const zz = rotation.z + rotation.z;

		float const wx2 = rotation.w * xx;
		float const wy2 = rotation.w * yy;
		float const wz2 = rotation.w * zz;
		float const xx2 = rotation.x * xx;
		float const xy2 = rotation.x * yy;
		float const xz2 = rotation.x * zz;
		float const yy2 = rotation.y * yy;
		float const yz2 = rotation.y * zz;
		float const zz2 = rotation.z * zz;

		return { value.x * (1 - yy2 - zz2) + value.y * (xy2 - wz2) + value.z * (xz2 + wy2),
				 value.x * (xy2 + wz2) + value.y * (1 - xx2 - zz2) + value.z * (yz2 - wx2),
				 value.x * (xz2 - wy2) + value.y * (yz2 + wx2) + value.z * (1 - xx2 - yy2),
				 value.w };
	}

	inline float4 transform4(float3 const& value, quaternion const& rotation) noexcept
	{
		float const xx = rotation.x + rotation.x;
		float const yy = rotation.y + rotation.y;
		float const zz = rotation.z + rotation.z;

		float const wx2 = rotation.w * xx;
		float const wy2 = rotation.w * yy;
		float const wz2 = rotation.w * zz;
		float const xx2 = rotation.x * xx;
		float const xy2 = rotation.x * yy;
		float const xz2 = rotation.x * zz;
		float const yy2 = rotation.y * yy;
		float const yz2 = rotation.y * zz;
		float const zz2 = rotation.z * zz;

		return { value.x * (1 - yy2 - zz2) + value.y * (xy2 - wz2) + value.z * (xz2 + wy2),
				 value.x * (xy2 + wz2) + value.y * (1 - xx2 - zz2) + value.z * (yz2 - wx2),
				 value.x * (xz2 - wy2) + value.y * (yz2 + wx2) + value.z * (1 - xx2 - yy2),
				 1 };
	}

	inline float4 transform4(float2 const& value, quaternion const& rotation) noexcept
	{
		float const xx = rotation.x + rotation.x;
		float const yy = rotation.y + rotation.y;
		float const zz = rotation.z + rotation.z;

		float const wx2 = rotation.w * xx;
		float const wy2 = rotation.w * yy;
		float const wz2 = rotation.w * zz;
		float const xx2 = rotation.x * xx;
		float const xy2 = rotation.x * yy;
		float const xz2 = rotation.x * zz;
		float const yy2 = rotation.y * yy;
		float const yz2 = rotation.y * zz;
		float const zz2 = rotation.z * zz;

		return { value.x * (1 - yy2 - zz2) + value.y * (xy2 - wz2),
				 value.x * (xy2 + wz2) + value.y * (1 - xx2 - zz2),
				 value.x * (xz2 - wy2) + value.y * (yz2 + wx2),
				 1 };
	}

	constexpr float4::float4(float const x, float const y, float const z, float const w) noexcept : value{ x, y, z, w } {}

	constexpr float4::float4(float2 const& value, float const z, float const w) noexcept : value{ value.x, value.y, z, w } {}

	constexpr float4::float4(float3 const& value, float const w) noexcept : value{ value.x, value.y, value.z, w } {}

	constexpr float4::float4(plane const& value) noexcept : value{ value.a, value.b, value.c, value.d } {}

	constexpr float4::float4(quaternion const& value) noexcept : value{ value.x, value.y, value.z, value.w } {}

	constexpr float4::float4(float const value) noexcept : value{ value, value, value, value } {}

	constexpr float4 float4::zero() noexcept
	{
		return { 0, 0, 0, 0 };
	}

	constexpr float4 float4::one() noexcept
	{
		return { 1, 1, 1, 0 };
	}

	constexpr float4 float4::unit_x() noexcept
	{
		return { 1, 0, 0, 0 };
	}

	constexpr float4 float4::unit_y() noexcept
	{
		return { 0, 1, 0, 0 };
	}

	constexpr float4 float4::unit_z() noexcept
	{
		return { 0, 0, 1, 0 };
	}

	constexpr float4 float4::unit_w() noexcept
	{
		return { 0, 0, 0, 1 };
	}

	inline float float4::length() const noexcept
	{
		return HiCxx::length(*this);
	}

	inline float float4::length_squared() const noexcept
	{
		return HiCxx::length_squared(*this);
	}

	inline float float4::distance(float4 const& value2) const noexcept
	{
		return HiCxx::distance(*this, value2);
	}

	inline float float4::distance_squared(float4 const& value2) const noexcept
	{
		return HiCxx::distance_squared(*this, value2);
	}

	inline float float4::dot(float4 const& value2) const noexcept
	{
		return HiCxx::dot(*this, value2);
	}

	inline float4 float4::abs() const noexcept
	{
		return HiCxx::abs(*this);
	}

	inline float4 float4::sqrt() const noexcept
	{
		return HiCxx::sqrt(*this);
	}

	inline float4 float4::squared() const noexcept
	{
		return HiCxx::squared(*this);
	}

	inline float4 float4::normalize() const noexcept
	{
		return HiCxx::normalize(*this);
	}

	inline float4 float4::reflect(float4 const& normal) const noexcept
	{
		return HiCxx::reflect(*this, normal);
	}

	inline float4 float4::min(float4 const& value2) const noexcept
	{
		return HiCxx::min(*this, value2);
	}

	inline float4 float4::max(float4 const& value2) const noexcept
	{
		return HiCxx::max(*this, value2);
	}

	inline float4 float4::clamp(float4 const& minValue, float4 const& maxValue) const noexcept
	{
		return HiCxx::clamp(*this, minValue, maxValue);
	}

	inline float4 float4::lerp(float4 const& value2, float const amount) const noexcept
	{
		return HiCxx::lerp(*this, value2, amount);
	}

	inline float4 float4::transform(float4x4 const& matrix) const noexcept
	{
		return HiCxx::transform(*this, matrix);
	}

	inline float4 float4::transform(quaternion const& rotation) const noexcept
	{
		return HiCxx::transform(*this, rotation);
	}

	inline float& float4::operator[](unsigned int const i) noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 4, L"float4 subscript out of range");
		return this->data[i];
	}

	inline float const& float4::operator[](unsigned int const i) const noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 4, L"float4 subscript out of range");
		return this->data[i];
	}

	constexpr float3x2 operator+(float3x2 const& value1, float3x2 const& value2) noexcept
	{
		return { value1.m11 + value2.m11, value1.m12 + value2.m12,
				 value1.m21 + value2.m21, value1.m22 + value2.m22,
				 value1.m31 + value2.m31, value1.m32 + value2.m32 };
	}

	constexpr float3x2 operator-(float3x2 const& value1, float3x2 const& value2) noexcept
	{
		return { value1.m11 - value2.m11, value1.m12 - value2.m12,
				 value1.m21 - value2.m21, value1.m22 - value2.m22,
				 value1.m31 - value2.m31, value1.m32 - value2.m32 };
	}

	constexpr float3x2 operator*(float3x2 const& value1, float3x2 const& value2) noexcept
	{
		return { value1.m11 * value2.m11 + value1.m12 * value2.m21,
				 value1.m11 * value2.m12 + value1.m12 * value2.m22,
				 value1.m21 * value2.m11 + value1.m22 * value2.m21,
				 value1.m21 * value2.m12 + value1.m22 * value2.m22,
				 value1.m31 * value2.m11 + value1.m32 * value2.m21 + value2.m31,
				 value1.m31 * value2.m12 + value1.m32 * value2.m22 + value2.m32 };
	}

	constexpr float3x2 operator*(float3x2 const& value1, float const value2) noexcept
	{
		return { value1.m11 / value2, value1.m12 / value2,
				 value1.m21 / value2, value1.m22 / value2,
				 value1.m31 / value2, value1.m32 / value2 };
	}

	constexpr float3x2 operator*(float const value1, float3x2 const& value2) noexcept
	{
		return value2 * value1;
	}

	constexpr float3x2 operator/(float3x2 const& value1, float const value2) noexcept
	{
		return value1 * (1 / value2);
	}

	constexpr float3x2 operator+(float3x2 const& value) noexcept
	{
		return value;
	}

	constexpr float3x2 operator-(float3x2 const& value) noexcept
	{
		return { -value.m11, -value.m12,
				 -value.m21, -value.m22,
				 -value.m31, -value.m32 };
	}

	constexpr float3x2& operator+=(float3x2& value1, float3x2 const& value2) noexcept
	{
		return value1 = value1 + value2;
	}

	constexpr float3x2& operator-=(float3x2& value1, float3x2 const& value2) noexcept
	{
		return value1 = value1 - value2;
	}

	constexpr float3x2& operator*=(float3x2& value1, float3x2 const& value2) noexcept
	{
		return value1 = value1 * value2;
	}

	constexpr float3x2& operator*=(float3x2& value1, float const value2) noexcept
	{
		return value1 = value1 * value2;
	}

	constexpr float3x2& operator/=(float3x2& value1, float const value2) noexcept
	{
		return value1 = value1 / value2;
	}

	constexpr bool operator==(float3x2 const& value1, float3x2 const& value2) noexcept
	{
		return value1.m11 == value2.m11 && value1.m12 == value2.m12 &&
			value1.m21 == value2.m21 && value1.m22 == value2.m22 &&
			value1.m31 == value2.m31 && value1.m32 == value2.m32;
	}

	constexpr bool operator!=(float3x2 const& value1, float3x2 const& value2) noexcept
	{
		return value1.m11 != value2.m11 || value1.m12 != value2.m12 ||
			value1.m21 != value2.m21 || value1.m22 != value2.m22 ||
			value1.m31 != value2.m31 || value1.m32 != value2.m32;
	}

	inline bool is_identity(float3x2 const& value) noexcept
	{
		return value == float3x2::identity();
	}

	inline float determinant(float3x2 const& value) noexcept
	{
		return (value.m11 * value.m22) - (value.m21 * value.m12);
	}

	inline float2 translation(float3x2 const& value) noexcept
	{
		return { value.m31,value.m32 };
	}

	inline bool invert(float3x2 const& matrix, float3x2* const result) noexcept
	{
		constexpr static float nan = std::numeric_limits<float>::quiet_NaN();

		float const det = determinant(matrix);

		if (!(::fabs(det) >= FLT_EPSILON))
		{
			*result = float3x2{ nan, nan, nan, nan, nan, nan };
			return false;
		}

		float const invDet = 1 / det;
		*result = float3x2
		{
			matrix.m22 * invDet,
					matrix.m12 * invDet,
					matrix.m21 * invDet,
			matrix.m11 * invDet,
			(matrix.m21 * matrix.m32 - matrix.m31 * matrix.m22) * invDet,
			(matrix.m31 * matrix.m12 - matrix.m11 * matrix.m32) * invDet
		};
		return true;
	}

	inline float3x2 lerp(float3x2 const& matrix1, float3x2 const& matrix2, float const amount) noexcept
	{
		return matrix1 + (matrix2 - matrix1) * amount;
	}

	inline float3x2 make_float3x2_translation(float2 const& position) noexcept
	{
		return { 1, 0,
				 0, 1,
				 position.x, position.y };
	}

	inline float3x2 make_float3x2_translation(float const xPosition, float const yPosition) noexcept
	{
		return { 1, 0,
				 0, 1,
				 xPosition, yPosition };
	}

	inline float3x2 make_float3x2_scale(float const xScale, float const yScale) noexcept
	{
		return { xScale, 0,
				 0, yScale,
				 0, 0 };
	}

	inline float3x2 make_float3x2_scale(float const xScale, float const yScale, float2 const& centerPoint) noexcept
	{
		float const nxScale = 1 - xScale;
		return { xScale, 0,
				 0, yScale,
				 centerPoint.x * nxScale, centerPoint.y * nxScale };
	}

	inline float3x2 make_float3x2_scale(float2 const& scales) noexcept
	{
		return { scales.x, 0,
				 0, scales.y,
				 0, 0 };
	}

	inline float3x2 make_float3x2_scale(float2 const& scales, float2 const& centerPoint) noexcept
	{
		float2 const t = centerPoint * (float2::one() - scales);
		return { scales.x, 0,
				 0, scales.y,
				 t.x, t.y };
	}

	inline float3x2 make_float3x2_scale(float const scale) noexcept
	{
		return { scale, 0,
				 0, scale,
				 0, 0 };
	}

	inline float3x2 make_float3x2_scale(float const scale, float2 const& centerPoint) noexcept
	{
		float2 const t = centerPoint * (1 - scale);
		return { scale, 0,
				 0, scale,
				 t.x, t.y };
	}

	inline float3x2 make_float3x2_skew(float const radiansX, float const radiansY) noexcept
	{
		return { 1, tanf(radiansX),
				 tanf(radiansY), 1,
				 0, 0 };
	}

	inline float3x2 make_float3x2_skew(float const radiansX, float const radiansY, float2 const& centerPoint) noexcept
	{
		float const xTan = tanf(radiansX);
		float const yTan = tanf(radiansY);
		return { 1, yTan,
				 xTan, 1,
				 -centerPoint.y * xTan, -centerPoint.x * yTan };
	}

	inline float3x2 make_float3x2_rotation(float const radians) noexcept
	{
		return make_float3x2_rotation(radians, float2::zero());
	}

	inline float3x2 make_float3x2_rotation(float radians, float2 const& centerPoint) noexcept
	{
		constexpr float epsilon = 0.001f * MF_PI / 180;

		radians = fmodf(radians, MF_TAO);

		if (radians < 0)
			radians += MF_TAO;

		float c, s;
		if (radians < epsilon || radians > MF_TAO - epsilon)
		{
			c = 1;
			s = 0;
		}
		else if (radians > MF_PIDIV2 - epsilon && radians < MF_PIDIV2 + epsilon)
		{
			c = 0;
			s = 1;
		}
		else if (radians > MF_PI - epsilon && radians < MF_PI + epsilon)
		{
			c = -1;
			s = 0;
		}
		else if (radians > MF_PI + MF_PIDIV2 - epsilon && radians < MF_PI + MF_PIDIV2 + epsilon)
		{
			c = 0;
			s = -1;
		}
		else
		{
			c = cosf(radians);
			s = sinf(radians);
		}

		return { c, s,
				 -s, c,
				 centerPoint.x * (1 - c) + centerPoint.y * s, centerPoint.y * (1 - c) - centerPoint.x * s };
	}

	constexpr float3x2 float3x2::identity() noexcept
	{
		return { 1, 0, 0, 1, 0, 0 };
	}

	constexpr float3x2::float3x2(float const m11, float const m12, float const m21, float const m22, float const m31, float const m32) noexcept
		: value{ m11, m12, m21, m22, m31, m32 } {}

	constexpr float3x2::float3x2(float2 const& r1, float2 const& r2, float2 const& r3) noexcept
		: data{ r1, r2, r3 } {}

	inline bool float3x2::is_identity() const noexcept
	{
		return *this == this->identity();
	}

	inline float float3x2::determinant() const noexcept
	{
		return HiCxx::determinant(*this);
	}

	inline float2 float3x2::translation() const noexcept
	{
		return HiCxx::translation(*this);
	}

	inline bool float3x2::invert(float3x2* const result) const noexcept
	{
		return HiCxx::invert(*this, result);
	}

	inline float3x2 float3x2::lerp(float3x2 const& matrix2, float const amount) const noexcept
	{
		return HiCxx::lerp(*this, matrix2, amount);
	}

	inline float2& float3x2::operator[](unsigned int const i) noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 3, L"float3x2 subscript out of range");
		return this->data[i];
	}

	inline float2 const& float3x2::operator[](unsigned int const i) const noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 3, L"float3x2 subscript out of range");
		return this->data[i];
	}

	constexpr float4x4 operator+(float4x4 const& value1, float4x4 const& value2) noexcept
	{
		return { value1.m11 + value2.m11, value1.m12 + value2.m12, value1.m13 + value2.m13, value1.m14 + value2.m14,
				 value1.m21 + value2.m21, value1.m22 + value2.m22, value1.m23 + value2.m23, value1.m24 + value2.m24,
				 value1.m31 + value2.m31, value1.m32 + value2.m32, value1.m33 + value2.m33, value1.m34 + value2.m34,
				 value1.m41 + value2.m41, value1.m42 + value2.m42, value1.m43 + value2.m43, value1.m44 + value2.m44 };
	}

	constexpr float4x4 operator-(float4x4 const& value1, float4x4 const& value2) noexcept
	{
		return { value1.m11 - value2.m11, value1.m12 - value2.m12, value1.m13 - value2.m13, value1.m14 - value2.m14,
				 value1.m21 - value2.m21, value1.m22 - value2.m22, value1.m23 - value2.m23, value1.m24 - value2.m24,
				 value1.m31 - value2.m31, value1.m32 - value2.m32, value1.m33 - value2.m33, value1.m34 - value2.m34,
				 value1.m41 - value2.m41, value1.m42 - value2.m42, value1.m43 - value2.m43, value1.m44 - value2.m44 };
	}
	constexpr float4x4 operator*(float4x4 const& value1, float4x4 const& value2) noexcept
	{
		return { value1.m11 * value2.m11 + value1.m12 * value2.m21 + value1.m13 * value2.m31 + value1.m14 * value2.m41,
				 value1.m11 * value2.m12 + value1.m12 * value2.m22 + value1.m13 * value2.m32 + value1.m14 * value2.m42,
				 value1.m11 * value2.m13 + value1.m12 * value2.m23 + value1.m13 * value2.m33 + value1.m14 * value2.m43,
				 value1.m11 * value2.m14 + value1.m12 * value2.m24 + value1.m13 * value2.m34 + value1.m14 * value2.m44,

				 value1.m21 * value2.m11 + value1.m22 * value2.m21 + value1.m23 * value2.m31 + value1.m24 * value2.m41,
				 value1.m21 * value2.m12 + value1.m22 * value2.m22 + value1.m23 * value2.m32 + value1.m24 * value2.m42,
				 value1.m21 * value2.m13 + value1.m22 * value2.m23 + value1.m23 * value2.m33 + value1.m24 * value2.m43,
				 value1.m21 * value2.m14 + value1.m22 * value2.m24 + value1.m23 * value2.m34 + value1.m24 * value2.m44,

				 value1.m31 * value2.m11 + value1.m32 * value2.m21 + value1.m33 * value2.m31 + value1.m34 * value2.m41,
				 value1.m31 * value2.m12 + value1.m32 * value2.m22 + value1.m33 * value2.m32 + value1.m34 * value2.m42,
				 value1.m31 * value2.m13 + value1.m32 * value2.m23 + value1.m33 * value2.m33 + value1.m34 * value2.m43,
				 value1.m31 * value2.m14 + value1.m32 * value2.m24 + value1.m33 * value2.m34 + value1.m34 * value2.m44,

				 value1.m41 * value2.m11 + value1.m42 * value2.m21 + value1.m43 * value2.m31 + value1.m44 * value2.m41,
				 value1.m41 * value2.m12 + value1.m42 * value2.m22 + value1.m43 * value2.m32 + value1.m44 * value2.m42,
				 value1.m41 * value2.m13 + value1.m42 * value2.m23 + value1.m43 * value2.m33 + value1.m44 * value2.m43,
				 value1.m41 * value2.m14 + value1.m42 * value2.m24 + value1.m43 * value2.m34 + value1.m44 * value2.m44 };
	}

	constexpr float4x4 operator*(float4x4 const& value1, float const value2) noexcept
	{
		return { value1.m11 * value2, value1.m12 * value2, value1.m13 * value2, value1.m14 * value2,
				 value1.m21 * value2, value1.m22 * value2, value1.m23 * value2, value1.m24 * value2,
				 value1.m31 * value2, value1.m32 * value2, value1.m33 * value2, value1.m34 * value2,
				 value1.m41 * value2, value1.m42 * value2, value1.m43 * value2, value1.m44 * value2 };
	}

	constexpr float4x4 operator*(float const value1, float4x4 const& value2) noexcept
	{
		return value2 * value1;
	}

	constexpr float4x4 operator/(float4x4 const& value1, float const value2) noexcept
	{
		return { value1.m11 / value2, value1.m12 / value2, value1.m13 / value2, value1.m14 / value2,
				 value1.m21 / value2, value1.m22 / value2, value1.m23 / value2, value1.m24 / value2,
				 value1.m31 / value2, value1.m32 / value2, value1.m33 / value2, value1.m34 / value2,
				 value1.m41 / value2, value1.m42 / value2, value1.m43 / value2, value1.m44 / value2 };
	}

	constexpr float4x4 operator+(float4x4 const& value) noexcept
	{
		return value;
	}

	constexpr float4x4 operator-(float4x4 const& value) noexcept
	{
		return { -value.m11, -value.m12, -value.m13, -value.m14,
				 -value.m21, -value.m22, -value.m23, -value.m24,
				 -value.m31, -value.m32, -value.m33, -value.m34,
				 -value.m41, -value.m42, -value.m43, -value.m44 };
	}

	constexpr float4x4& operator+=(float4x4& value1, float4x4 const& value2) noexcept
	{
		return value1 = value1 + value2;
	}

	constexpr float4x4& operator-=(float4x4& value1, float4x4 const& value2) noexcept
	{
		return value1 = value1 - value2;
	}

	constexpr float4x4& operator*=(float4x4& value1, float4x4 const& value2) noexcept
	{
		return value1 = value1 * value2;
	}

	constexpr float4x4& operator*=(float4x4& value1, float const value2) noexcept
	{
		return value1 = value1 * value2;
	}

	constexpr float4x4& operator/=(float4x4& value1, float const value2) noexcept
	{
		return value1 = value1 / value2;
	}

	constexpr bool operator==(float4x4 const& value1, float4x4 const& value2) noexcept
	{
		return value1.m11 == value2.m11 && value1.m12 == value2.m12 && value1.m13 == value2.m31 && value1.m14 == value2.m41 &&
			value1.m21 == value2.m21 && value1.m22 == value2.m22 && value1.m23 == value2.m32 && value1.m24 == value2.m42 &&
			value1.m31 == value2.m31 && value1.m32 == value2.m32 && value1.m33 == value2.m33 && value1.m34 == value2.m43 &&
			value1.m41 == value2.m41 && value1.m42 == value2.m42 && value1.m43 == value2.m34 && value1.m44 == value2.m44;
	}

	constexpr bool operator!=(float4x4 const& value1, float4x4 const& value2) noexcept
	{
		return value1.m11 != value2.m11 || value1.m12 != value2.m12 || value1.m13 != value2.m31 || value1.m14 != value2.m41 ||
			value1.m21 != value2.m21 || value1.m22 != value2.m22 || value1.m23 != value2.m32 || value1.m24 != value2.m42 ||
			value1.m31 != value2.m31 || value1.m32 != value2.m32 || value1.m33 != value2.m33 || value1.m34 != value2.m43 ||
			value1.m41 != value2.m41 || value1.m42 != value2.m42 || value1.m43 != value2.m34 || value1.m44 != value2.m44;
	}

	inline bool is_identity(float4x4 const& value) noexcept
	{
		return value == float4x4::identity();
	}

	inline float determinant(float4x4 const& value) noexcept
	{
		float const kp_lo = value.m33 * value.m44 - value.m34 * value.m43;
		float const jp_ln = value.m32 * value.m44 - value.m34 * value.m42;
		float const jo_kn = value.m32 * value.m43 - value.m33 * value.m42;
		float const ip_lm = value.m31 * value.m44 - value.m34 * value.m41;
		float const io_km = value.m31 * value.m43 - value.m33 * value.m41;
		float const in_jm = value.m31 * value.m42 - value.m32 * value.m41;

		return value.m11 * (value.m22 * kp_lo - value.m23 * jp_ln + value.m24 * jo_kn) -
			value.m12 * (value.m21 * kp_lo - value.m23 * ip_lm + value.m24 * io_km) +
			value.m13 * (value.m21 * jp_ln - value.m22 * ip_lm + value.m24 * in_jm) -
			value.m14 * (value.m21 * jo_kn - value.m22 * io_km + value.m23 * in_jm);
	}

	inline float3 translation(float4x4 const& value) noexcept
	{
		return { value.m41, value.m42, value.m43 };
	}

	inline bool invert(float4x4 const& matrix, float4x4* const result) noexcept
	{
		float const a = matrix.m11, b = matrix.m12, c = matrix.m13, d = matrix.m14;
		float const e = matrix.m21, f = matrix.m22, g = matrix.m23, h = matrix.m24;
		float const i = matrix.m31, j = matrix.m32, k = matrix.m33, l = matrix.m34;
		float const m = matrix.m41, n = matrix.m42, o = matrix.m43, p = matrix.m44;

		float const kp_lo = k * p - l * o;
		float const jp_ln = j * p - l * n;
		float const jo_kn = j * o - k * n;
		float const ip_lm = i * p - l * m;
		float const io_km = i * o - k * m;
		float const in_jm = i * n - j * m;

		float const a11 = +(f * kp_lo - g * jp_ln + h * jo_kn);
		float const a12 = -(e * kp_lo - g * ip_lm + h * io_km);
		float const a13 = +(e * jp_ln - f * ip_lm + h * in_jm);
		float const a14 = -(e * jo_kn - f * io_km + g * in_jm);

		float const det = a * a11 + b * a12 + c * a13 + d * a14;

		if (!(::fabs(det) >= FLT_EPSILON))
		{
			constexpr float nan = std::numeric_limits<float>::quiet_NaN();
			*result = { nan, nan, nan, nan,
						nan, nan, nan, nan,
						nan, nan, nan, nan,
						nan, nan, nan, nan };
			return false;
		}
		float const invDet = 1 / det;

		result->m11 = a11 * invDet;
		result->m21 = a12 * invDet;
		result->m31 = a13 * invDet;
		result->m41 = a14 * invDet;

		result->m12 = -(b * kp_lo - c * jp_ln + d * jo_kn) * invDet;
		result->m22 = +(a * kp_lo - c * ip_lm + d * io_km) * invDet;
		result->m32 = -(a * jp_ln - b * ip_lm + d * in_jm) * invDet;
		result->m42 = +(a * jo_kn - b * io_km + c * in_jm) * invDet;

		float const gp_ho = g * p - h * o;
		float const fp_hn = f * p - h * n;
		float const fo_gn = f * o - g * n;
		float const ep_hm = e * p - h * m;
		float const eo_gm = e * o - g * m;
		float const en_fm = e * n - f * m;

		result->m13 = +(b * gp_ho - c * fp_hn + d * fo_gn) * invDet;
		result->m23 = -(a * gp_ho - c * ep_hm + d * eo_gm) * invDet;
		result->m33 = +(a * fp_hn - b * ep_hm + d * en_fm) * invDet;
		result->m43 = -(a * fo_gn - b * eo_gm + c * en_fm) * invDet;

		float const gl_hk = g * l - h * k;
		float const fl_hj = f * l - h * j;
		float const fk_gj = f * k - g * j;
		float const el_hi = e * l - h * i;
		float const ek_gi = e * k - g * i;
		float const ej_fi = e * j - f * i;

		result->m14 = -(b * gl_hk - c * fl_hj + d * fk_gj) * invDet;
		result->m24 = +(a * gl_hk - c * el_hi + d * ek_gi) * invDet;
		result->m34 = -(a * fl_hj - b * el_hi + d * ej_fi) * invDet;
		result->m44 = +(a * fk_gj - b * ek_gi + c * ej_fi) * invDet;

		return true;
	}

	inline bool decompose(float4x4 const& matrix, float3* const scale, quaternion* rotation, float3* const translation) noexcept
	{
		constexpr static float4 pvCanonicalBasis[4] = { float4::unit_x(), float4::unit_y(), float4::unit_z(), float4::unit_w() };
		constexpr static float decomp_epsilon = 0.0001f;

		_HICXX_ASSERT(scale != nullptr, L"decompose scale is nullptr");
		_HICXX_ASSERT(rotation != nullptr, L"decompose rotation is nullptr");
		_HICXX_ASSERT(translation != nullptr, L"decompose translation is nullptr");

		float4x4 matTemp = { matrix.data[0], matrix.data[1], matrix.data[2], pvCanonicalBasis[3] };
		float3* const ppvBasis[3] = { reinterpret_cast<float3*>(&matTemp.data[0]), reinterpret_cast<float3*>(&matTemp.data[1]),
			reinterpret_cast<float3*>(&matTemp.data[2]) };

		float4 pfScales = { length(*ppvBasis[0]), length(*ppvBasis[1]), length(*ppvBasis[2]), 0 };

		unsigned int a, b, c;

		if (pfScales[0] < pfScales[1])
		{
			if (pfScales[1] < pfScales[2])
			{
				a = 2;
				b = 1;
				c = 0;
			}
			else
			{
				a = 1;

				if (pfScales[0] < pfScales[2])
				{
					b = 2;
					c = 0;
				}
				else
				{
					b = 0;
					c = 2;
				}
			}
		}
		else
		{
			if (pfScales[0] < pfScales[2])
			{
				a = 2;
				b = 0;
				c = 1;
			}
			else
			{
				a = 0;

				if (pfScales[1] < pfScales[2])
				{
					b = 2;
					c = 1;
				}
				else
				{
					b = 1;
					c = 2;
				}
			}
		}

		if (pfScales[a] < decomp_epsilon)
			*ppvBasis[a] = (float3 const&)pvCanonicalBasis[a];

		*ppvBasis[a] = normalize(*ppvBasis[a]);

		if (pfScales[b] < decomp_epsilon)
		{
			unsigned int aa, bb, cc;

			float const fAbsX = fabsf(ppvBasis[a]->x);
			float const fAbsY = fabsf(ppvBasis[a]->y);
			float const fAbsZ = fabsf(ppvBasis[a]->z);

			if (fAbsX < fAbsY)
			{
				if (fAbsY < fAbsZ)
				{
					aa = 2;
					bb = 1;
					cc = 0;
				}
				else
				{
					aa = 1;

					if (fAbsX < fAbsZ)
					{
						bb = 2;
						cc = 0;
					}
					else
					{
						bb = 0;
						cc = 2;
					}
				}
			}
			else
			{
				if (fAbsX < fAbsZ)
				{
					aa = 2;
					bb = 0;
					cc = 1;
				}
				else
				{
					aa = 0;

					if (fAbsY < fAbsZ)
					{
						bb = 2;
						cc = 1;
					}
					else
					{
						bb = 1;
						cc = 2;
					}
				}
			}

			*ppvBasis[b] = cross(*ppvBasis[a], (float3 const&)pvCanonicalBasis[cc]);
		}

		*ppvBasis[b] = normalize(*ppvBasis[b]);

		if (pfScales[c] < decomp_epsilon)
			*ppvBasis[c] = cross(*ppvBasis[a], *ppvBasis[b]);

		*ppvBasis[c] = normalize(*ppvBasis[c]);

		float fDet = determinant(matTemp);

		if (fDet < 0)
		{
			pfScales[a] = -pfScales[a];
			*ppvBasis[a] = -*ppvBasis[a];
			fDet = -fDet;
		}

		fDet -= 1;
		fDet *= fDet;

		if (decomp_epsilon < fDet)
			return false;

		*translation = float3{ matrix.data[3].x, matrix.data[3].y, matrix.data[3].z };
		*rotation = make_quaternion_from_rotation_matrix(matTemp);
		return true;
	}

	inline float4x4 transform(float4x4 const& value, quaternion const& rotation) noexcept
	{
		float const x2 = rotation.x + rotation.x;
		float const y2 = rotation.y + rotation.y;
		float const z2 = rotation.z + rotation.z;

		float const wx2 = rotation.w * x2;
		float const wy2 = rotation.w * y2;
		float const wz2 = rotation.w * z2;
		float const xx2 = rotation.x * x2;
		float const xy2 = rotation.x * y2;
		float const xz2 = rotation.x * z2;
		float const yy2 = rotation.y * y2;
		float const yz2 = rotation.y * z2;
		float const zz2 = rotation.z * z2;

		float const q11 = 1 - yy2 - zz2;
		float const q21 = xy2 - wz2;
		float const q31 = xz2 + wy2;

		float const q12 = xy2 + wz2;
		float const q22 = 1 - xx2 - zz2;
		float const q32 = yz2 - wx2;

		float const q13 = xz2 - wy2;
		float const q23 = yz2 + wx2;
		float const q33 = 1 - xx2 - yy2;

		return { value.m11 * q11 + value.m12 * q21 + value.m13 * q31,
				 value.m11 * q12 + value.m12 * q22 + value.m13 * q32,
				 value.m11 * q13 + value.m12 * q23 + value.m13 * q33,
				 value.m14,

				 value.m21 * q11 + value.m22 * q21 + value.m23 * q31,
				 value.m21 * q12 + value.m22 * q22 + value.m23 * q32,
				 value.m21 * q13 + value.m22 * q23 + value.m23 * q33,
				 value.m24,

				 value.m31 * q11 + value.m32 * q21 + value.m33 * q31,
				 value.m31 * q12 + value.m32 * q22 + value.m33 * q32,
				 value.m31 * q13 + value.m32 * q23 + value.m33 * q33,
				 value.m34,

				 value.m41 * q11 + value.m42 * q21 + value.m43 * q31,
				 value.m41 * q12 + value.m42 * q22 + value.m43 * q32,
				 value.m41 * q13 + value.m42 * q23 + value.m43 * q33,
				 value.m44 };
	}

	inline float4x4 transpose(float4x4 const& matrix) noexcept
	{
		return { matrix.m11, matrix.m21, matrix.m31, matrix.m41,
				 matrix.m12, matrix.m22, matrix.m32, matrix.m42,
				 matrix.m13, matrix.m23, matrix.m33, matrix.m43,
				 matrix.m14, matrix.m24, matrix.m34, matrix.m44 };
	}

	inline float4x4 lerp(float4x4 const& matrix1, float4x4 const& matrix2, float const amount) noexcept
	{
		return matrix1 + (matrix2 - matrix1) * amount;
	}

	inline float4x4 make_float4x4_billboard(float3 const& objectPosition, float3 const& cameraPosition, float3 const& cameraUpVector, float3 const& cameraForwardVector) noexcept
	{
		constexpr static float epsilon = 1e-4f;

		float3 zaxis = objectPosition - cameraPosition;
		float const norm = length_squared(zaxis);
		zaxis = (norm < epsilon) ? (-cameraForwardVector) : (zaxis / sqrtf(norm));

		float3 const xaxis = normalize(cross(cameraUpVector, zaxis));
		float3 const yaxis = cross(zaxis, xaxis);

		return { xaxis.x, xaxis.y, xaxis.z, 0,
				 yaxis.x, yaxis.y, yaxis.z, 0,
				 zaxis.x, zaxis.y, zaxis.z, 0,
				 objectPosition.x, objectPosition.y, objectPosition.z, 1 };
	}

	inline float4x4 make_float4x4_constrained_billboard(float3 const& objectPosition, float3 const& cameraPosition, float3 const& rotateAxis, float3 const& cameraForwardVector, float3 const& objectForwardVector) noexcept
	{
		constexpr static float epsilon = 1e-4f;
		constexpr static float const minAngle = 1 - (0.1f * (MF_PI / 180));

		float3 faceDir = objectPosition - cameraPosition;

		float const norm = length_squared(faceDir);

		faceDir = (norm < epsilon) ? (-cameraForwardVector) : (faceDir / sqrtf(norm));

		float3 const yaxis = rotateAxis;
		float3 xaxis;
		float3 zaxis;

		if (::fabs(dot(rotateAxis, faceDir)) > minAngle)
		{
			zaxis = objectForwardVector;

			if (::fabs(dot(rotateAxis, zaxis)) > minAngle)
				zaxis = (::fabs(rotateAxis.z) > minAngle) ? float3{ 1, 0, 0 } : float3{ 0, 0, -1 };

			xaxis = normalize(cross(rotateAxis, zaxis));
			zaxis = normalize(cross(xaxis, rotateAxis));
		}
		else
		{
			xaxis = normalize(cross(rotateAxis, faceDir));
			zaxis = normalize(cross(xaxis, yaxis));
		}

		return { xaxis.x, xaxis.y, xaxis.z, 0,
				 yaxis.x, yaxis.y, yaxis.z, 0,
				 zaxis.x, zaxis.y, zaxis.z, 0,
				 objectPosition.x, objectPosition.y, objectPosition.z, 1 };
	}

	inline float4x4 make_float4x4_translation(float3 const& position) noexcept
	{
		return { 1, 0, 0, 0,
				 0, 1, 0, 0,
				 0, 0, 1, 0,
				 position.x, position.y, position.z, 1 };
	}

	inline float4x4 make_float4x4_translation(float const xPosition, float const yPosition, float const zPosition) noexcept
	{
		return { 1, 0, 0, 0,
				 0, 1, 0, 0,
				 0, 0, 1, 0,
				 xPosition, yPosition, zPosition, 1 };
	}

	inline float4x4 make_float4x4_scale(float const xScale, float const yScale, float const zScale) noexcept
	{
		return { xScale, 0, 0, 0,
				 0, yScale, 0, 0,
				 0, 0, zScale, 0,
				 0, 0, 0, 1 };
	}

	inline float4x4 make_float4x4_scale(float const xScale, float const yScale, float const zScale, float3 const& centerPoint) noexcept
	{
		float const tx = centerPoint.x * (1 - xScale);
		float const ty = centerPoint.y * (1 - yScale);
		float const tz = centerPoint.z * (1 - zScale);
		return { xScale, 0, 0, 0,
				 0, yScale, 0, 0,
				 0, 0, zScale, 0,
				 tx, ty, tz, 1 };
	}

	inline float4x4 make_float4x4_scale(float3 const& scales) noexcept
	{
		return { scales.x, 0, 0, 0,
				 0, scales.y, 0, 0,
				 0, 0, scales.z, 0,
				 0, 0, 0, 1 };
	}

	inline float4x4 make_float4x4_scale(float3 const& scales, float3 const& centerPoint) noexcept
	{
		float3 const t = centerPoint * (float3::one() - scales);
		return { scales.x, 0, 0, 0,
				 0, scales.y, 0, 0,
				 0, 0, scales.z, 0,
				 t.x, t.y, t.z, 1 };
	}

	inline float4x4 make_float4x4_scale(float const scale) noexcept
	{
		return { scale, 0, 0, 0,
				 0, scale, 0, 0,
				 0, 0, scale, 0,
				 0, 0, 0, 1 };
	}

	inline float4x4 make_float4x4_scale(float const scale, float3 const& centerPoint) noexcept
	{
		float3 const t = centerPoint * (1 - scale);
		return { scale, 0, 0, 0,
				 0, scale, 0, 0,
				 0, 0, scale, 0,
				 t.x, t.y, t.z, 1 };
	}

	inline float4x4 make_float4x4_rotation_x(float const radians) noexcept
	{
		float const c = cosf(radians);
		float const s = sinf(radians);
		return { 1, 0, 0, 0,
				 0, c, s, 0,
				 0, -s, c, 0,
				 0, 0, 0, 1 };
	}

	inline float4x4 make_float4x4_rotation_x(float const radians, float3 const& centerPoint) noexcept
	{
		float const c = cosf(radians);
		float const s = sinf(radians);
		float const y = centerPoint.y * (1 - c) + centerPoint.z * s;
		float const z = centerPoint.z * (1 - c) - centerPoint.y * s;
		return { 1, 0, 0, 0,
				 0, c, s, 0,
				 0, -s, c, 0,
				 0, y, z, 1 };
	}

	inline float4x4 make_float4x4_rotation_y(float const radians) noexcept
	{
		float const c = cosf(radians);
		float const s = sinf(radians);
		return { c, 0, -s, 0,
				 0, 1, 0, 0,
				 s, 0, c, 0,
				 0, 0, 0, 1 };
	}

	inline float4x4 make_float4x4_rotation_y(float const radians, float3 const& centerPoint) noexcept
	{
		float const c = cosf(radians);
		float const s = sinf(radians);
		float const x = centerPoint.x * (1 - c) - centerPoint.z * s;
		float const z = centerPoint.z * (1 - c) + centerPoint.x * s;
		return { c, 0, -s, 0,
				 0, 1, 0, 0,
				 s, 0, c, 0,
				 x, 0, z, 1 };
	}

	inline float4x4 make_float4x4_rotation_z(float const radians) noexcept
	{
		float const c = cosf(radians);
		float const s = sinf(radians);
		return { c, s, 0, 0,
				 -s, c, 0, 0,
				 0, 0, 1, 0,
				 0, 0, 0, 1 };
	}

	inline float4x4 make_float4x4_rotation_z(float const radians, float3 const& centerPoint) noexcept
	{
		float const c = cosf(radians);
		float const s = sinf(radians);
		float const x = centerPoint.x * (1 - c) + centerPoint.y * s;
		float const y = centerPoint.y * (1 - c) - centerPoint.x * s;
		return { c, s, 0, 0,
				 -s, c, 0, 0,
				 0, 0, 1, 0,
				 x, y, 0, 1 };
	}

	inline float4x4 make_float4x4_from_axis_angle(float3 const& axis, float const acos) noexcept
	{
		float const x = axis.x, y = axis.y, z = axis.z;
		float const sa = sinf(acos), ca = cosf(acos);
		float const x2 = x * x, y2 = y * y, z2 = z * z;
		float const xy = x * y, xz = x * z, yz = y * z;
		return { x2 + ca * (1 - x2), xy - ca * xy + sa * z, xz - ca * xz - sa * y, 0,
				 xy - ca * xy - sa * z, y2 + ca * (1 - y2), yz - ca * yz + sa * x, 0,
				 xz - ca * xz + sa * y, yz - ca * yz - sa * x, z2 + ca * (1 - z2), 0,
				 0, 0, 0, 1 };
	}

	inline float4x4 make_float4x4_perspective_field_of_view(float const fieldOfView, float const aspectRatio, float const nearplaneDistance, float const farplaneDistance)
	{
		if (fieldOfView <= 0 || fieldOfView >= MF_PI)
			throw std::invalid_argument(std::invalid_argument("fieldOfView"));

		if (nearplaneDistance <= 0)
			throw std::invalid_argument(std::invalid_argument("nearplaneDistance"));

		if (farplaneDistance <= 0)
			throw std::invalid_argument(std::invalid_argument("farplaneDistance"));

		if (nearplaneDistance >= farplaneDistance)
			throw std::invalid_argument(std::invalid_argument("nearplaneDistance"));

		float const yScale = 1 / tanf(fieldOfView * 0.5f);
		float const xScale = yScale / aspectRatio;
		float const clipDist = nearplaneDistance - farplaneDistance;
		return { xScale, 0, 0, 0,
				 0, yScale, 0, 0,
				 0, 0, farplaneDistance / clipDist, -1,
				 0, 0, nearplaneDistance * farplaneDistance / clipDist, 0 };
	}

	inline float4x4 make_float4x4_perspective(float const width, float const height, float const nearplaneDistance, float const farplaneDistance)
	{
		if (nearplaneDistance <= 0)
			throw std::invalid_argument(std::invalid_argument("nearplaneDistance"));

		if (farplaneDistance <= 0)
			throw std::invalid_argument(std::invalid_argument("farplaneDistance"));

		if (nearplaneDistance >= farplaneDistance)
			throw std::invalid_argument(std::invalid_argument("nearplaneDistance"));

		float const clipDist = nearplaneDistance - farplaneDistance;
		return { 2 * nearplaneDistance / width, 0, 0, 0,
				 0, 2 * nearplaneDistance / height, 0, 0,
				 0, 0, farplaneDistance / clipDist, -1,
				 0, 0, nearplaneDistance * farplaneDistance / clipDist, 0 };
	}

	inline float4x4 make_float4x4_perspective_off_center(float const left, float const right, float const bottom, float const top, float const nearplaneDistance, float const farplaneDistance)
	{
		if (nearplaneDistance <= 0)
			throw std::invalid_argument(std::invalid_argument("nearplaneDistance"));

		if (farplaneDistance <= 0)
			throw std::invalid_argument(std::invalid_argument("farplaneDistance"));

		if (nearplaneDistance >= farplaneDistance)
			throw std::invalid_argument(std::invalid_argument("nearplaneDistance"));

		float const clipDist = nearplaneDistance - farplaneDistance;
		return { 2 * nearplaneDistance / (right - left), 0, 0, 0,
				 0, 2 * nearplaneDistance / (top - bottom), 0, 0,
				 (left + right) / (right - left), (top + bottom) / (top - bottom), farplaneDistance / clipDist, -1,
				 0, 0, nearplaneDistance * farplaneDistance / clipDist, 0 };
	}

	inline float4x4 make_float4x4_orthographic(float const width, float const height, float const zNearplane, float const zFarplane) noexcept
	{
		float const clipDist = zNearplane - zFarplane;
		return { 2 / width, 0, 0, 0,
				 0, 2 / height, 0, 0,
				 0, 0, 1 / clipDist, 0,
				 0, 0, zNearplane / clipDist, 1 };
	}

	inline float4x4 make_float4x4_orthographic_off_center(float const left, float const right, float const bottom, float const top, float const zNearplane, float const zFarplane) noexcept
	{
		float const clipDist = zNearplane - zFarplane;
		return { 2 / (right - left), 0, 0, 0,
				 0, 2 / (top - bottom), 0, 0,
				 0, 0, 1 / clipDist, 0,
				 (left + right) / (left - right), (top + bottom) / (bottom - top), zNearplane / clipDist, 1 };
	}

	inline float4x4 make_float4x4_look_at(float3 const& cameraPosition, float3 const& cameraTarget, float3 const& cameraUpVector) noexcept
	{
		float3 const zaxis = normalize(cameraPosition - cameraTarget);
		float3 const xaxis = normalize(cross(cameraUpVector, zaxis));
		float3 const yaxis = cross(zaxis, xaxis);

		return { xaxis.x, yaxis.x, zaxis.x, 0,
				 xaxis.y, yaxis.y, zaxis.y, 0,
				 xaxis.z, yaxis.z, zaxis.z, 0,
				 -dot(xaxis, cameraPosition), -dot(yaxis, cameraPosition), -dot(zaxis, cameraPosition), 1 };
	}

	inline float4x4 make_float4x4_world(float3 const& position, float3 const& forward, float3 const& up) noexcept
	{
		float3 const zaxis = normalize(-forward);
		float3 const xaxis = normalize(cross(up, zaxis));
		float3 const yaxis = cross(zaxis, xaxis);

		return { xaxis.x, xaxis.y, xaxis.z, 0,
				 yaxis.x, yaxis.y, yaxis.z, 0,
				 zaxis.x, zaxis.y, zaxis.z, 0,
				 position.x, position.y, position.z, 1 };
	}

	inline float4x4 make_float4x4_from_quaternion(quaternion const& quaternion) noexcept
	{
		float const x2 = quaternion.x * quaternion.x;
		float const y2 = quaternion.y * quaternion.y;
		float const z2 = quaternion.z * quaternion.z;

		float const xy = quaternion.x * quaternion.y;
		float const wz = quaternion.z * quaternion.w;
		float const xz = quaternion.z * quaternion.x;
		float const wy = quaternion.y * quaternion.w;
		float const yz = quaternion.y * quaternion.z;
		float const wx = quaternion.x * quaternion.w;

		return { 1 - 2 * (y2 + z2), 2 * (xy + wz), 2 * (xz - wy), 0,
				 2 * (xy - wz), 1 - 2 * (z2 + x2), 2 * (yz + wx), 0,
				 2 * (xz + wy), 2 * (yz - wx), 1 - 2 * (y2 + x2), 0,
				 0, 0, 0, 1 };
	}

	inline float4x4 make_float4x4_from_yaw_pitch_roll(float const yaw, float const pitch, float const roll) noexcept
	{
		return make_float4x4_from_quaternion(make_quaternion_from_yaw_pitch_roll(yaw, pitch, roll));
	}

	inline float4x4 make_float4x4_shadow(float3 const& lightDirection, plane const& plane) noexcept
	{
		auto const p = normalize(plane);

		float const dot = dot_normal(p, lightDirection);

		float const a = -p.a;
		float const b = -p.b;
		float const c = -p.c;
		float const d = -p.d;

		return { a * lightDirection.x + dot, a * lightDirection.y, a * lightDirection.z, 0,
				 b * lightDirection.x, b * lightDirection.y + dot, b * lightDirection.z, 0,
				 c * lightDirection.x, c * lightDirection.y, c * lightDirection.z + dot, 0,
				 d * lightDirection.x, d * lightDirection.y, d * lightDirection.z, dot };
	}

	inline float4x4 make_float4x4_reflection(plane const& value) noexcept
	{
		plane const v = normalize(value);

		float const fa = -2 * value.a;
		float const fb = -2 * value.b;
		float const fc = -2 * value.c;

		return { fa * value.a + 1, fb * value.a,		   fc * value.a,		0,
				 fa * value.b,		  fb * value.b + 1, fc * value.b,		0,
				 fa * value.c,		  fb * value.c,		   fc * value.c + 1, 0,
				 fa * v.d,			  fb * v.d,			   fc * v.d,			1 };
	}

	constexpr float4x4 float4x4::identity() noexcept
	{
		return { 1, 0, 0, 0,
				 0, 1, 0, 0,
				 0, 0, 1, 0,
				 0, 0, 0, 1 };
	}

	constexpr float4x4::float4x4(float const m11, float const m12, float const m13, float const m14, float const m21, float const m22, float const m23, float const m24, float const m31, float const m32, float const m33, float const m34, float const m41, float const m42, float const m43, float const m44) noexcept
		: value{ m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44 } {}

	constexpr float4x4::float4x4(float4 const& r1, float4 const& r2, float4 const& r3, float4 const& r4) noexcept
		: data{ r1, r2, r3, r4 } {}

	constexpr float4x4::float4x4(float3x2 const& value) noexcept
		: value{ value.m11, value.m12, 0, 0,
				 value.m21, value.m22, 0, 0,
				 0,	0,		   1, 0,
				 value.m31, value.m32, 0, 1 } {}

	inline bool float4x4::is_identity() const noexcept
	{
		return HiCxx::is_identity(*this);
	}

	float float4x4::determinant() const noexcept
	{
		return HiCxx::determinant(*this);
	}

	inline float3 float4x4::translation() const noexcept
	{
		return HiCxx::translation(*this);
	}

	inline bool float4x4::invert(float4x4* const result) noexcept
	{
		return HiCxx::invert(*this, result);
	}

	inline bool float4x4::decompose(float3* const scale, quaternion* rotation, float3* const translation) const noexcept
	{
		return HiCxx::decompose(*this, scale, rotation, translation);
	}

	inline float4x4 float4x4::transform(quaternion const& rotation) const noexcept
	{
		return HiCxx::transform(*this, rotation);
	}

	inline float4x4 float4x4::transpose() const noexcept
	{
		return HiCxx::transpose(*this);
	}

	inline float4x4 float4x4::lerp(float4x4 const& matrix2, float const amount) const noexcept
	{
		return HiCxx::lerp(*this, matrix2, amount);
	}

	inline float4& float4x4::operator[](unsigned int const i) noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 4, L"float4x4 subscript out of range");
		return this->data[i];
	}

	inline float4 const& float4x4::operator[](unsigned int const i) const noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 4, L"float4x4 subscript out of range");
		return this->data[i];
	}

	constexpr plane operator+(plane const& value) noexcept
	{
		return value;
	}

	constexpr plane operator-(plane const& value) noexcept
	{
		return plane(-value.normal, -value.d);
	}

	constexpr bool operator==(plane const& value1, plane const& value2) noexcept
	{
		return value1.a == value2.a &&
			   value1.b == value2.b &&
			   value1.c == value2.c &&
			   value1.d == value2.d;
	}

	constexpr bool operator!=(plane const& value1, plane const& value2) noexcept
	{
		return value1.a != value2.a ||
			   value1.b != value2.b ||
			   value1.c != value2.c ||
			   value1.d != value2.d;
	}

	inline plane normalize(plane const& value) noexcept
	{
		float const f = length_squared(value.normal);

		if (::fabs(f - 1) < FLT_EPSILON)
			return value;

		float const fInv = 1 / sqrtf(f);

		return plane(value.normal * fInv, value.d * fInv);
	}

	inline plane transform(plane const& value, float4x4 const& matrix) noexcept
	{
		float4x4 inverseMatrix;
		invert(matrix, &inverseMatrix);
		return plane(transform(float4(value.normal, value.d), transpose(inverseMatrix)));
	}

	inline plane transform(plane const& value, quaternion const& rotation) noexcept
	{
		return plane(transform(float4(value.normal, value.d), rotation));
	}

	inline float3 one_point_on(plane const& value) noexcept
	{
		return value.a ? float3(value.d / value.a, 0, 0) : value.b ? float3(0, value.d / value.b, 0) : float3(0, 0, value.d / value.c);
	}

	inline float dot(plane const& plane, float4 const& value) noexcept
	{
		return plane.a * value.x +
			   plane.b * value.y +
			   plane.c * value.z +
			   plane.d * value.w;
	}

	inline float dot_coordinate(plane const& plane, float3 const& value) noexcept
	{
		return plane.a * value.x +
			   plane.b * value.y +
			   plane.c * value.z +
			   plane.d;
	}

	inline float dot_normal(plane const& plane, float3 const& value) noexcept
	{
		return dot(plane.normal, value);
	}

	inline bool is_antarafacial(plane const& value1, float3 const& value2) noexcept
	{
		return dot(value1.normal, value2) + value1.d == 0;
	}

	inline plane make_plane_from_vertices(float3 const& point1, float3 const& point2, float3 const& point3) noexcept
	{
		float3 const normal = normalize(cross(point2 - point1, point3 - point1));
		return plane(normal, -dot(normal, point1));
	}

	constexpr plane::plane(float const x, float const y, float const z, float const d) noexcept : value{ x, y, z, d } {}

	constexpr plane::plane(float3 const& normal, float const d) noexcept : value{ normal.x, normal.y, normal.z, d } {}

	constexpr plane::plane(float4 const& value) noexcept : value{ value.x,value.y,value.z, value.w } {}

	constexpr plane::plane(quaternion const& value) noexcept : value{ value.x,value.y,value.z, value.w } {}

	inline plane plane::normalize() const noexcept
	{
		return HiCxx::normalize(*this);
	}

	inline plane plane::transform(float4x4 const& matrix) const noexcept
	{
		return HiCxx::transform(*this, matrix);
	}

	inline plane plane::transform(quaternion const& rotation) const noexcept
	{
		return HiCxx::transform(*this, rotation);
	}

	inline float3 plane::one_point_on() const noexcept
	{
		return HiCxx::one_point_on(*this);
	}

	inline float plane::dot(float4 const& value) const noexcept
	{
		return HiCxx::dot(*this, value);
	}

	inline float plane::dot_coordinate(float3 const& value) const noexcept
	{
		return HiCxx::dot_coordinate(*this, value);
	}

	inline float plane::dot_normal(float3 const& value) const noexcept
	{
		return HiCxx::dot_normal(*this, value);
	}

	inline float& plane::operator[](unsigned int const i) noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 4, L"plane subscript out of range");
		return this->data[i];
	}

	inline float const& plane::operator[](unsigned int const i) const noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 4, L"plane subscript out of range");
		return this->data[i];
	}

	constexpr quaternion operator+(quaternion const& value1, quaternion const& value2) noexcept
	{
		return { value1.x + value2.x, value1.y + value2.y, value1.z + value2.z, value1.w + value2.w };
	}

	constexpr quaternion operator-(quaternion const& value1, quaternion const& value2) noexcept
	{
		return { value1.x - value2.x, value1.y - value2.y, value1.z - value2.z, value1.w - value2.w };
	}

	constexpr quaternion operator*(quaternion const& value1, quaternion const& value2) noexcept
	{
		return { value1.x * value2.x, value1.y * value2.y, value1.z * value2.z, value1.w * value2.w };
	}

	constexpr quaternion operator*(quaternion const& value1, float const value2) noexcept
	{
		return { value1.x * value2, value1.y * value2, value1.z * value2, value1.w * value2 };
	}

	constexpr quaternion operator*(float const value1, quaternion const& value2) noexcept
	{
		return value2 * value1;
	}

	constexpr quaternion operator/(quaternion const& value1, quaternion const& value2) noexcept
	{
		return { value1.x / value2.x, value1.y / value2.y, value1.z / value2.z, value1.w / value2.w };
	}

	constexpr quaternion operator/(quaternion const& value1, float const value2) noexcept
	{
		return value1 * (1 / value2);
	}

	constexpr quaternion operator+(quaternion const& value1) noexcept
	{
		return value1;
	}

	constexpr quaternion operator-(quaternion const& value1) noexcept
	{
		return { -value1.x, -value1.y, -value1.z, -value1.w };
	}

	constexpr quaternion& operator+=(quaternion& value1, quaternion const& value2) noexcept
	{
		return value1 = value1 + value2;
	}

	constexpr quaternion& operator-=(quaternion& value1, quaternion const& value2) noexcept
	{
		return value1 = value1 - value2;
	}

	constexpr quaternion& operator*=(quaternion& value1, quaternion const& value2) noexcept
	{
		return value1 = value1 * value2;
	}

	constexpr quaternion& operator*=(quaternion& value1, float const value2) noexcept
	{
		return value1 = value1 * value2;
	}

	constexpr quaternion& operator/=(quaternion& value1, quaternion const& value2) noexcept
	{
		return value1 = value1 / value2;
	}

	constexpr quaternion& operator/=(quaternion& value1, float const value2) noexcept
	{
		return value1 = value1 / value2;
	}

	constexpr bool operator==(quaternion const& value1, quaternion const& value2) noexcept
	{
		return value1.x == value2.x && value1.y == value2.y && value1.z == value2.z && value1.w == value2.w;
	}

	constexpr bool operator!=(quaternion const& value1, quaternion const& value2) noexcept
	{
		return value1.x != value2.x || value1.y != value2.y || value1.z != value2.z || value1.w != value2.w;
	}

	inline bool is_identity(quaternion const& value) noexcept
	{
		return value == quaternion::identity();
	}

	inline float length(quaternion const& value) noexcept
	{
		return sqrtf(length_squared(value));
	}

	inline float length_squared(quaternion const& value) noexcept
	{
		return dot(value, value);
	}

	inline float dot(quaternion const& quaternion1, quaternion const& quaternion2) noexcept
	{
		return quaternion1.x * quaternion2.x +
			quaternion1.y * quaternion2.y +
			quaternion1.z * quaternion2.z +
			quaternion1.w * quaternion2.w;
	}

	inline quaternion normalize(quaternion const& value) noexcept
	{
		return value * (1 / length(value));
	}

	inline quaternion conjugate(quaternion const& value) noexcept
	{
		return { -value.x, -value.y, -value.z, value.w };
	}

	inline quaternion inverse(quaternion const& value) noexcept
	{
		return conjugate(value * (1 / length_squared(value)));
	}

	inline quaternion slerp(quaternion const& quaternion1, quaternion const& quaternion2, float const amount) noexcept
	{
		float const epsilon = 1e-6f;

		float const t = amount;
		float cosOmega = dot(quaternion1, quaternion2);
		bool flip = false;

		if (cosOmega < 0)
		{
			flip = true;
			cosOmega = -cosOmega;
		}

		float s1, s2;

		if (cosOmega > (1 - epsilon))
		{
			s1 = 1 - t;
			s2 = flip ? -t : t;
		}
		else
		{
			float const omega = acosf(cosOmega);
			float const invSinOmega = 1 / sinf(omega);

			s1 = sinf((1 - t) * omega) * invSinOmega;
			s2 = flip ? -::sinf(t * omega) * invSinOmega
				: sinf(t * omega) * invSinOmega;
		}

		return { s1 * quaternion1.x + s2 * quaternion2.x,
				 s1 * quaternion1.y + s2 * quaternion2.y,
				 s1 * quaternion1.z + s2 * quaternion2.z,
				 s1 * quaternion1.w + s2 * quaternion2.w };
	}

	inline quaternion lerp(quaternion const& quaternion1, quaternion const& quaternion2, float const amount) noexcept
	{
		float t2 = amount;
		float const t1 = 1 - amount;

		if (dot(quaternion1, quaternion2) < 0)
			t2 = -t2;
		return normalize(quaternion{ t1 * quaternion1.x + t2 * quaternion2.x,
							 t1 * quaternion1.y + t2 * quaternion2.y,
							 t1 * quaternion1.z + t2 * quaternion2.z,
							 t1 * quaternion1.w + t2 * quaternion2.w });
	}

	inline quaternion concatenate(quaternion const& value1, quaternion const& value2) noexcept
	{
		return value2 * value1;
	}

	inline quaternion make_quaternion_from_axis_angle(float3 const& axis, float const acos) noexcept
	{
		float const halfAngle = acos * 0.5f;
		return quaternion(axis * sinf(halfAngle), cosf(halfAngle));
	}

	inline quaternion make_quaternion_from_yaw_pitch_roll(float const yaw, float const pitch, float const roll) noexcept
	{
		float const halfRoll = roll * 0.5f;
		float const sr = sinf(halfRoll), cr = cosf(halfRoll);

		float const halfPitch = pitch * 0.5f;
		float const sp = sinf(halfPitch), cp = cosf(halfPitch);

		float const halfYaw = yaw * 0.5f;
		float const sy = sinf(halfYaw), cy = cosf(halfYaw);

		return { cy * sp * cr + sy * cp * sr,
				 sy * cp * cr - cy * sp * sr,
				 cy * cp * sr - sy * sp * cr,
				 cy * cp * cr + sy * sp * sr };
	}

	inline quaternion make_quaternion_from_rotation_matrix(float4x4 const& matrix) noexcept
	{
		if (matrix.m11 + matrix.m22 + matrix.m33 > 0)
		{
			float const s = sqrtf(1 + matrix.m11 + matrix.m22 + matrix.m33);
			float const invS = 0.5f / s;

			return { (matrix.m23 - matrix.m32) * invS,
					 (matrix.m31 - matrix.m13) * invS,
					 (matrix.m12 - matrix.m21) * invS,
					 s * 0.5f };
		}
		else if (matrix.m11 >= matrix.m22 && matrix.m11 >= matrix.m33)
		{
			float const s = sqrtf(1 + matrix.m11 - matrix.m22 - matrix.m33);
			float const invS = 0.5f / s;

			return { 0.5f * s,
					 (matrix.m12 + matrix.m21) * invS,
					 (matrix.m13 + matrix.m31) * invS,
					 (matrix.m23 - matrix.m32) * invS };
		}
		else if (matrix.m22 > matrix.m33)
		{
			float const s = sqrtf(1 + matrix.m22 - matrix.m11 - matrix.m33);
			float const invS = 0.5f / s;

			return { (matrix.m21 + matrix.m12) * invS,
					 0.5f * s,
					 (matrix.m32 + matrix.m23) * invS,
					 (matrix.m31 - matrix.m13) * invS };
		}
		else
		{
			float const s = sqrtf(1 + matrix.m33 - matrix.m11 - matrix.m22);
			float const invS = 0.5f / s;

			return { (matrix.m31 + matrix.m13) * invS,
					 (matrix.m32 + matrix.m23) * invS,
					 0.5f * s,
					 (matrix.m12 - matrix.m21) * invS };
		}
	}

	constexpr quaternion quaternion::identity() noexcept
	{
		return { 0, 0, 0, 1 };
	}

	constexpr quaternion::quaternion(float const x, float const y, float const z, float const w) noexcept : value{ x, y, z, w } {}

	constexpr quaternion::quaternion(float2 const& value, float const z, float const w) noexcept : value{ value.x, value.y, z, w } {}

	constexpr quaternion::quaternion(float3 const& value, float const w) noexcept : value{ value.x, value.y, value.z, w } {}

	constexpr quaternion::quaternion(float4 const& value) noexcept : value{ value.x, value.y, value.z, value.w } {}

	constexpr quaternion::quaternion(plane const& value) noexcept : value{ value.a, value.b, value.c, value.d } {}

	constexpr quaternion::quaternion(float const value) noexcept : value{ value, value, value, value } {}

	inline bool quaternion::is_identity() const noexcept
	{
		return HiCxx::is_identity(*this);
	}

	inline float quaternion::length() const noexcept
	{
		return HiCxx::length(*this);
	}

	inline float quaternion::length_squared() const noexcept
	{
		return HiCxx::length_squared(*this);
	}

	inline float quaternion::dot(quaternion const& quaternion2) const noexcept
	{
		return HiCxx::dot(*this, quaternion2);
	}

	inline quaternion quaternion::normalize() const noexcept
	{
		return HiCxx::normalize(*this);
	}

	inline quaternion quaternion::conjugate() const noexcept
	{
		return HiCxx::conjugate(*this);
	}

	inline quaternion quaternion::inverse() const noexcept
	{
		return HiCxx::inverse(*this);
	}

	inline quaternion quaternion::slerp(quaternion const& quaternion2, float const amount) const noexcept
	{
		return HiCxx::slerp(*this, quaternion2, amount);
	}

	inline quaternion quaternion::lerp(quaternion const& quaternion2, float const amount) const noexcept
	{
		return HiCxx::lerp(*this, quaternion2, amount);
	}

	inline quaternion quaternion::concatenate(quaternion const& value2) const noexcept
	{
		return HiCxx::concatenate(*this, value2);
	}

	inline float& quaternion::operator[](unsigned int const i) noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 4, L"quaternion subscript out of range");
		return this->data[i];
	}

	inline float const& quaternion::operator[](unsigned int const i) const noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 4, L"quaternion subscript out of range");
		return this->data[i];
	}

	inline bool is_parallel(float2x2 const& value1, float2x2 const& value2) noexcept
	{
		return is_parallel(value1.v, value2.v);
	}

	inline bool is_intersecting(float2x2 const& value1, float2x2 const& value2) noexcept
	{
		return is_intersecting(value1.v, value2.v);
	}

	inline float2 intersection(float2x2 const& value1, float2x2 const& value2) noexcept
	{
		_HICXX_ASSERT(is_intersecting(value1, value2), L"float2x2 are not intersecting");
		return value1.p + value1.v * (cross(value2.v, value1.p - value2.p) / cross(value1.v, value2.v));
	}

	constexpr float2x2::float2x2(float const x1, float const y1, float const x2, float const y2) noexcept
		: value{ x1, y1, x2, y2 } {}
	constexpr float2x2::float2x2(float2 const& value1, float2 const& value2) noexcept
		: data{ value1, value2 } {}
	constexpr float2x2::float2x2(float4 const& value) noexcept
		: value{ value.x, value.y, value.z, value.w } {}

	constexpr float2x2 float2x2::zero() noexcept
	{
		return { float2::zero(), float2::zero() };
	}

	constexpr float2x2 float2x2::one() noexcept
	{
		return { float2::zero(), float2::one() };
	}

	constexpr float2x2 float2x2::unit_x() noexcept
	{
		return { float2::zero(), float2::unit_x() };
	}

	constexpr float2x2 float2x2::unit_y() noexcept
	{
		return { float2::zero(), float2::unit_y() };
	}

	inline bool float2x2::is_parallel(float2x2 const& value2) const noexcept
	{
		return HiCxx::is_parallel(*this, value2);
	}

	inline bool float2x2::is_intersecting(float2x2 const& value2) const noexcept
	{
		return HiCxx::is_intersecting(*this, value2);
	}

	inline float2 float2x2::intersection(float2x2 const& value2) const noexcept
	{
		return HiCxx::intersection(*this, value2);
	}

	inline float2& float2x2::operator[](unsigned int const i) noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 2, L"float2x2 subscript out of range");
		return this->data[i];
	}

	inline const float2& float2x2::operator[](unsigned int const i) const noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 2, L"float2x2 subscript out of range");
		return this->data[i];
	}

	inline bool is_parallel(float2x3 const& value1, float2x3 const& value2) noexcept
	{
		return is_parallel(value1.v, value2.v);
	}

	inline bool is_antarafacial(float2x3 const& value1, float2x3 const& value2) noexcept
	{
		return dot(cross(value1.v, value2.p - value1.p), value2.v) != 0;
	}

	inline bool is_intersecting(float2x3 const& value1, float2x3 const& value2) noexcept
	{
		return !is_parallel(value1, value2) && !is_antarafacial(value1, value2);
	}

	inline float3 intersection(float2x3 const& value1, float2x3 const& value2) noexcept
	{
		_HICXX_ASSERT(is_intersecting(value1, value2), L"float2x3 are not intersecting");
		return value1.p + value1.v * sqrtf(length_squared(cross(value2.v, value1.p - value2.p)) / length_squared(cross(value1.v, value2.v)));
	}

	constexpr float2x3::float2x3(float const x1, float const y1, float const z1, float const x2, float const y2, float const z2) noexcept
		: value{ x1, y1, z1, x2, y2, z2 } {}
	constexpr float2x3::float2x3(float3 const& value1, float3 const& value2) noexcept
		: data{ value1, value2 } {}

	constexpr float2x3 float2x3::zero() noexcept
	{
		return { float3::zero(), float3::zero() };
	}

	constexpr float2x3 float2x3::one() noexcept
	{
		return { float3::zero(), float3::one() };
	}

	constexpr float2x3 float2x3::unit_x() noexcept
	{
		return { float3::zero(), float3::unit_x() };
	}

	constexpr float2x3 float2x3::unit_y() noexcept
	{
		return { float3::zero(), float3::unit_y() };
	}

	constexpr float2x3 float2x3::unit_z() noexcept
	{
		return { float3::zero(), float3::unit_z() };
	}

	inline bool float2x3::is_parallel(float2x3 const& value2) const noexcept
	{
		return HiCxx::is_parallel(*this, value2);
	}

	inline bool float2x3::is_antarafacial(float2x3 const& value2) const noexcept
	{
		return HiCxx::is_antarafacial(*this, value2);
	}

	inline bool float2x3::is_intersecting(float2x3 const& value2) const noexcept
	{
		return HiCxx::is_intersecting(*this, value2);
	}

	inline float3 float2x3::intersection(float2x3 const& value2) const noexcept
	{
		return HiCxx::intersection(*this, value2);
	}

	inline float3& float2x3::operator[](unsigned int const i) noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 2, L"float2x3 subscript out of range");
		return this->data[i];
	}

	inline const float3& float2x3::operator[](unsigned int const i) const noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 2, L"float2x3 subscript out of range");
		return this->data[i];
	}

	inline std::ostream& operator<<(::std::ostream& os, float2 const& value) noexcept
	{
		return os << '(' << value.x << ", " << value.y << ')';
	}

	inline std::ostream& operator<<(::std::ostream& os, float3 const& value) noexcept
	{
		return os << '(' << value.x << ", " << value.y << ", " << value.z << ')';
	}

	inline std::ostream& operator<<(::std::ostream& os, float4 const& value) noexcept
	{
		return os << '(' << value.x << ", " << value.y << ", " << value.z << ", " << value.w << ')';
	}

	inline std::ostream& operator<<(::std::ostream& os, float3x2 const& value) noexcept
	{
		return os << '(' << value.r1 << ", " << value.r2 << ", " << value.r3 << ')';
	}

	inline std::ostream& operator<<(::std::ostream& os, float4x4 const& value) noexcept
	{
		return os << '(' << value.r1 << ", " << value.r2 << ", " << value.r3 << ", " << value.r4 << ')';
	}

	inline std::ostream& operator<<(::std::ostream& os, plane const& value) noexcept
	{
		return os << '(' << value.normal << ", " << value.d << ')';
	}

	inline std::ostream& operator<<(::std::ostream& os, quaternion const& value) noexcept
	{
		return os << '(' << value.x << ", " << value.y << ", " << value.z << ", " << value.w << ')';
	}

	inline std::ostream& operator<<(::std::ostream& os, float2x2 const& value) noexcept
	{
		return os << '(' << value.p << ", " << value.v << ')';
	}

	inline std::ostream& operator<<(::std::ostream& os, float2x3 const& value) noexcept
	{
		return os << '(' << value.p << ", " << value.v << ')';
	}
}