/**
 * @file	numerics.1.inl
 * @brief	HiCxx 的数学模块
 * @author	侧云
*/

#include "numerics.1.h"
#include "hicxx_defines.h"

namespace HiCxx
{
	constexpr double2 operator+(double2 const& value1, double2 const& value2) noexcept
	{
		return { value1.x + value2.x, value1.y + value2.y };
	}

	constexpr double2 operator-(double2 const& value1, double2 const& value2) noexcept
	{
		return { value1.x - value2.x, value1.y - value2.y };
	}

	constexpr double2 operator*(double2 const& value1, double2 const& value2) noexcept
	{
		return { value1.x * value2.x, value1.y * value2.y };
	}

	constexpr double2 operator*(double2 const& value1, double const value2) noexcept
	{
		return { value1.x * value2, value1.y * value2 };
	}

	constexpr double2 operator*(double const value1, double2 const& value2) noexcept
	{
		return value2 * value1;
	}

	constexpr double2 operator/(double2 const& value1, double2 const& value2) noexcept
	{
		return { value1.x / value2.x, value1.y / value2.y };
	}

	constexpr double2 operator/(double2 const& value1, double const value2) noexcept
	{
		return value1 * (1 / value2);
	}

	constexpr double2 operator+(double2 const& value1) noexcept
	{
		return value1;
	}

	constexpr double2 operator-(double2 const& value1) noexcept
	{
		return { -value1.x, -value1.y };
	}

	constexpr double2& operator+=(double2& value1, double2 const& value2) noexcept
	{
		return value1 = value1 + value2;
	}

	constexpr double2& operator-=(double2& value1, double2 const& value2) noexcept
	{
		return value1 = value1 - value2;
	}

	constexpr double2& operator*=(double2& value1, double2 const& value2) noexcept
	{
		return value1 = value1 * value2;
	}

	constexpr double2& operator*=(double2& value1, double const value2) noexcept
	{
		return value1 = value1 * value2;
	}

	constexpr double2& operator/=(double2& value1, double2 const& value2) noexcept
	{
		return value1 = value1 / value2;
	}

	constexpr double2& operator/=(double2& value1, double const value2) noexcept
	{
		return value1 = value1 / value2;
	}

	constexpr bool operator==(double2 const& value1, double2 const& value2) noexcept
	{
		return value1.x == value2.x && value1.y == value2.y;
	}

	constexpr bool operator!=(double2 const& value1, double2 const& value2) noexcept
	{
		return value1.x != value2.x || value1.y != value2.y;
	}

	inline double length(double2 const& value1) noexcept
	{
		return ::sqrt(length_squared(value1));
	}

	inline double length_squared(double2 const& value1) noexcept
	{
		return dot(value1, value1);
	}

	inline double distance(double2 const& value1, double2 const& value2) noexcept
	{
		return length(value1 - value2);
	}

	inline double distance_squared(double2 const& value1, double2 const& value2) noexcept
	{
		return length_squared(value1 - value2);
	}

	inline double distance(double2 const& value1, double2x2 const& value2) noexcept
	{
		return ::abs(distance_directed(value1, value2));
	}

	inline double distance_directed(double2 const& value1, double2x2 const& value2) noexcept
	{
		return cross(value2.v, value2.p - value1) / length(value1);
	}

	inline double cos(double2 const& value1, double2 const& value2) noexcept
	{
		return dot(value1, value2) / (value1.length() * value2.length());
	}

	inline double acos(double2 const& value1, double2 const& value2) noexcept
	{
		return ::acos(cos(value1, value2));
	}

	inline double dot(double2 const& vector1, double2 const& vector2) noexcept
	{
		return vector1.x * vector2.x + vector1.y * vector2.y;
	}

	inline double cross(double2 const& vector1, double2 const& vector2) noexcept
	{
		return vector1.x * vector2.y - vector1.y * vector2.x;
	}

	inline double2 abs(double2 const& value1) noexcept
	{
		return { value1.x < 0 ? -value1.x : value1.x,
				 value1.y < 0 ? -value1.y : value1.y };
	}

	inline double2 sqrt(double2 const& value1) noexcept
	{
		return { ::sqrt(value1.x), ::sqrt(value1.y) };
	}

	inline double2 squared(double2 const& value1) noexcept
	{
		return value1 * value1;
	}

	inline double2 rotate(double2 const& value1, double const value2) noexcept
	{
		double const _cos = ::cos(value2);
		double const _sin = sin(value2);
		return { value1.x * _cos - value1.y * _sin, value1.x * _sin + value1.y * _cos };
	}

	inline double2 rotate90(double2 const& value1) noexcept
	{
		return { -value1.y, value1.x };
	}

	inline double2 normalize(double2 const& value1) noexcept
	{
		return value1 / length(value1);
	}

	inline double2 reflect(double2 const& value, double2 const& normal) noexcept
	{
		return value - 2 * dot(value, normal) * normal;
	}

	inline double2 min(double2 const& value1, double2 const& value2) noexcept
	{
		return { value1.x < value2.x ? value1.x : value2.x,
				 value1.y < value2.y ? value1.y : value2.y };
	}

	inline double2 max(double2 const& value1, double2 const& value2) noexcept
	{
		return { value1.x > value2.x ? value1.x : value2.x,
				 value1.y > value2.y ? value1.y : value2.y };
	}

	inline double2 projection(double2 const& value1, double2 const& value2) noexcept
	{
		return value2 * (length(value1) * cos(value1, value2) / length(value2));
	}

	inline double2 projection(double2 const& value1, double2x2 const& value2) noexcept
	{
		return value2.p + value2.v * (dot(value2.v, value1 - value2.p) / dot(value2.v, value2.v));
	}

	inline double2 clamp(double2 const& value1, double2 const& minValue, double2 const& maxValue) noexcept
	{
		return max(min(value1, minValue), maxValue);
	}

	inline double2 lerp(double2 const& value1, double2 const& value2, double const amount) noexcept
	{
		return value1 + (value2 - value1) * amount;
	}

	inline double2 transform(double2 const& position, double3x2 const& matrix) noexcept
	{
		return { position.x * matrix.m11 + position.y * matrix.m21 + matrix.m31,
				 position.x * matrix.m12 + position.y * matrix.m22 + matrix.m32 };
	}

	inline double2 transform(double2 const& position, double4x4 const& matrix) noexcept
	{
		return { position.x * matrix.m11 + position.y * matrix.m21 + matrix.m41,
				 position.x * matrix.m12 + position.y * matrix.m22 + matrix.m42 };
	}

	inline double2 transform_normal(double2 const& normal, double3x2 const& matrix) noexcept
	{
		return { normal.x * matrix.m11 + normal.y * matrix.m21,
				 normal.x * matrix.m12 + normal.y * matrix.m22 };
	}

	inline double2 transform_normal(double2 const& normal, double4x4 const& matrix) noexcept
	{
		return { normal.x * matrix.m11 + normal.y * matrix.m21,
				 normal.x * matrix.m12 + normal.y * matrix.m22 };
	}

	inline double2 transform(double2 const& value, quaterniond const& rotation) noexcept
	{
		double const x2 = rotation.x + rotation.x;
		double const y2 = rotation.y + rotation.y;
		double const z2 = rotation.z + rotation.z;

		double const wz2 = rotation.w * z2;
		double const xx2 = rotation.x * x2;
		double const xy2 = rotation.x * y2;
		double const yy2 = rotation.y * y2;
		double const zz2 = rotation.z * z2;

		return { value.x * (1 - yy2 - zz2) + value.y * (xy2 - wz2),
				 value.x * (xy2 + wz2) + value.y * (1 - xx2 - zz2) };
	}

	inline bool is_parallel(double2 const& value1, double2 const& value2) noexcept
	{
		return cross(value1, value2) == 0;
	}

	inline bool is_intersecting(double2 const& value1, double2 const& value2) noexcept
	{
		return !is_parallel(value1, value2);
	}

	constexpr double2::double2(double const x, double const y) noexcept : value{ x, y } {}

	constexpr double2::double2(double3 const& value) noexcept : value{ value.x, value.y } {}

	constexpr double2::double2(double4 const& value) noexcept : value{ value.x, value.y } {}

	constexpr double2::double2(double const value) noexcept : value{ value, value } {}

	constexpr double2 double2::zero() noexcept
	{
		return { 0, 0 };
	}

	constexpr double2 double2::one() noexcept
	{
		return { 1, 1 };
	}

	constexpr double2 double2::unit_x() noexcept
	{
		return { 1, 0 };
	}

	constexpr double2 double2::unit_y() noexcept
	{
		return { 0, 1 };
	}

	inline double double2::length() const noexcept
	{
		return HiCxx::length(*this);
	}

	inline double double2::length_squared() const noexcept
	{
		return HiCxx::length_squared(*this);
	}

	inline double double2::distance(double2 const& value2) const noexcept
	{
		return HiCxx::distance(*this, value2);
	}

	inline double double2::distance_squared(double2 const& value2) const noexcept
	{
		return HiCxx::distance_squared(*this, value2);
	}

	inline double double2::distance(double2x2 const& value2) const noexcept
	{
		return HiCxx::distance(*this, value2);
	}

	inline double double2::distance_directed(double2x2 const& value2) const noexcept
	{
		return HiCxx::distance_directed(*this, value2);
	}

	inline double double2::cos(double2 const& value2) const noexcept
	{
		return HiCxx::cos(*this, value2);
	}

	inline double double2::acos(double2 const& value2) const noexcept
	{
		return HiCxx::acos(*this, value2);
	}

	inline double double2::dot(double2 const& vector2) const noexcept
	{
		return HiCxx::dot(*this, vector2);
	}

	inline double double2::cross(double2 const& vector2) const noexcept
	{
		return HiCxx::cross(*this, vector2);
	}

	inline double2 double2::abs() const noexcept
	{
		return HiCxx::abs(*this);
	}

	inline double2 double2::sqrt() const noexcept
	{
		return HiCxx::sqrt(*this);
	}

	inline double2 double2::squared() const noexcept
	{
		return HiCxx::squared(*this);
	}

	inline double2 double2::rotate(double const value2) const noexcept
	{
		return HiCxx::rotate(*this, value2);
	}

	inline double2 double2::rotate90() const noexcept
	{
		return HiCxx::rotate90(*this);
	}

	inline double2 double2::normalize() const noexcept
	{
		return HiCxx::normalize(*this);
	}

	inline double2 double2::reflect(double2 const& normal) const noexcept
	{
		return HiCxx::reflect(*this, normal);
	}

	inline double2 double2::min(double2 const& value2) const noexcept
	{
		return HiCxx::min(*this, value2);
	}

	inline double2 double2::max(double2 const& value2) const noexcept
	{
		return HiCxx::max(*this, value2);
	}

	inline double2 double2::projection(double2 const& value2) const noexcept
	{
		return HiCxx::projection(*this, value2);
	}

	inline double2 double2::projection(double2x2 const& value2) const noexcept
	{
		return HiCxx::projection(*this, value2);
	}

	inline double2 double2::clamp(double2 const& minValue, double2 const& maxValue) const noexcept
	{
		return HiCxx::clamp(*this, minValue, maxValue);
	}

	inline double2 double2::lerp(double2 const& value2, double const amount) const noexcept
	{
		return HiCxx::lerp(*this, value2, amount);
	}

	inline double2 double2::transform(double3x2 const& matrix) const noexcept
	{
		return HiCxx::transform(*this, matrix);
	}

	inline double2 double2::transform(double4x4 const& matrix) const noexcept
	{
		return HiCxx::transform(*this, matrix);
	}

	inline double2 double2::transform_normal(double3x2 const& matrix) const noexcept
	{
		return HiCxx::transform_normal(*this, matrix);
	}

	inline double2 double2::transform_normal(double4x4 const& matrix) const noexcept
	{
		return HiCxx::transform_normal(*this, matrix);
	}

	inline double2 double2::transform(quaterniond const& rotation) const noexcept
	{
		return HiCxx::transform(*this, rotation);
	}

	inline bool double2::is_parallel(double2 const& value2) const noexcept
	{
		return HiCxx::is_parallel(*this, value2);
	}

	inline bool double2::is_intersecting(double2 const& value2) const noexcept
	{
		return HiCxx::is_intersecting(*this, value2);
	}

	inline double& double2::operator[](unsigned int const i) noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 2, L"double2 subscript out of range");
		return this->data[i];
	}

	inline double const& double2::operator[](unsigned int const i) const noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 2, L"double2 subscript out of range");
		return this->data[i];
	}

	constexpr double3 operator+(double3 const& value1, double3 const& value2) noexcept
	{
		return { value1.x + value2.x, value1.y + value2.y, value1.z + value2.z };
	}

	constexpr double3 operator-(double3 const& value1, double3 const& value2) noexcept
	{
		return { value1.x - value2.x, value1.y - value2.y, value1.z - value2.z };
	}

	constexpr double3 operator*(double3 const& value1, double3 const& value2) noexcept
	{
		return { value1.x * value2.x, value1.y * value2.y, value1.z * value2.z };
	}

	constexpr double3 operator*(double3 const& value1, double const value2) noexcept
	{
		return { value1.x * value2, value1.y * value2, value1.z * value2 };
	}

	constexpr double3 operator*(double const value1, double3 const& value2) noexcept
	{
		return value2 * value1;
	}

	constexpr double3 operator/(double3 const& value1, double3 const& value2) noexcept
	{
		return { value1.x / value2.x, value1.y / value2.y, value1.z / value2.z };
	}

	constexpr double3 operator/(double3 const& value1, double const value2) noexcept
	{
		return value1 * (1 / value2);
	}

	constexpr double3 operator+(double3 const& value1) noexcept
	{
		return value1;
	}

	constexpr double3 operator-(double3 const& value1) noexcept
	{
		return { -value1.x, -value1.y, -value1.z };
	}

	constexpr double3& operator+=(double3& value1, double3 const& value2) noexcept
	{
		return value1 = value1 + value2;
	}

	constexpr double3& operator-=(double3& value1, double3 const& value2) noexcept
	{
		return value1 = value1 - value2;
	}

	constexpr double3& operator*=(double3& value1, double3 const& value2) noexcept
	{
		return value1 = value1 * value2;
	}

	constexpr double3& operator*=(double3& value1, double const value2) noexcept
	{
		return value1 = value1 * value2;
	}

	constexpr double3& operator/=(double3& value1, double3 const& value2) noexcept
	{
		return value1 = value1 / value2;
	}

	constexpr double3& operator/=(double3& value1, double const value2) noexcept
	{
		return value1 = value1 / value2;
	}

	constexpr bool operator==(double3 const& value1, double3 const& value2) noexcept
	{
		return value1.x == value2.x && value1.y == value2.y && value1.z == value2.z;
	}

	constexpr bool operator!=(double3 const& value1, double3 const& value2) noexcept
	{
		return value1.x != value2.x || value1.y != value2.y || value1.z != value2.z;
	}

	inline double length(double3 const& value1) noexcept
	{
		return ::sqrt(length_squared(value1));
	}

	inline double length_squared(double3 const& value1) noexcept
	{
		return dot(value1, value1);
	}

	inline double distance(double3 const& value1, double3 const& value2) noexcept
	{
		return length(value1 - value2);
	}

	inline double distance_squared(double3 const& value1, double3 const& value2) noexcept
	{
		return length_squared(value1 - value2);
	}

	inline double distance(double3 const& value1, double2x3 const& value2) noexcept
	{
		return ::abs(distance_directed(value1, value2));
	}

	inline double distance_directed(double3 const& value1, double2x3 const& value2) noexcept
	{
		return length(cross(value2.v, value2.p - value1)) / length(value1);
	}

	inline double cos(double3 const& value1, double3 const& value2) noexcept
	{
		return dot(value1, value2) / (value1.length() * value2.length());
	}

	inline double acos(double3 const& value1, double3 const& value2) noexcept
	{
		return ::acos(cos(value1, value2));
	}

	inline double dot(double3 const& vector1, double3 const& vector2) noexcept
	{
		return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z;
	}

	inline double3 cross(double3 const& vector1, double3 const& vector2) noexcept
	{
		return { vector1.y * vector2.z - vector1.z * vector2.y,
				 vector1.z * vector2.x - vector1.x * vector2.z,
				 vector1.x * vector2.y - vector1.y * vector2.x };
	}

	inline double3 abs(double3 const& value1) noexcept
	{
		return { value1.x < 0 ? -value1.x : value1.x,
				 value1.y < 0 ? -value1.y : value1.y,
				 value1.z < 0 ? -value1.z : value1.z };
	}

	inline double3 sqrt(double3 const& value1) noexcept
	{
		return { ::sqrt(value1.x), ::sqrt(value1.y), ::sqrt(value1.z) };
	}

	inline double3 squared(double3 const& value1) noexcept
	{
		return value1 * value1;
	}

	inline double3 rotate(double3 const& value1, double const radX, double const radY, double const radZ) noexcept
	{
		return rotate_z(rotate_y(rotate_x(value1, radX), radY), radZ);
	}

	inline double3 rotate_x(double3 const& value1, double const rad) noexcept
	{
		double const _sin = sin(rad);
		double const _cos = ::cos(rad);
		return { value1.x, value1.y * _cos - value1.z * _sin, value1.z * _cos + value1.y * _sin };
	}

	inline double3 rotate_y(double3 const& value1, double const rad) noexcept
	{
		double const _sin = sin(rad);
		double const _cos = ::cos(rad);
		return { value1.x * _cos - value1.z * _sin, value1.y, value1.z * _cos + value1.x * _sin };
	}

	inline double3 rotate_z(double3 const& value1, double const rad) noexcept
	{
		double const _sin = sin(rad);
		double const _cos = ::cos(rad);
		return { value1.x * _cos - value1.y * _sin, value1.y * _cos + value1.x * _sin, value1.z };
	}

	inline double3 rotate90_x(double3 const& value1) noexcept
	{
		return { value1.x, -value1.z, value1.y };
	}

	inline double3 rotate90_y(double3 const& value1) noexcept
	{
		return { -value1.z, value1.y, value1.x };
	}

	inline double3 rotate90_z(double3 const& value1) noexcept
	{
		return { -value1.y, value1.x, value1.z };
	}

	inline double3 normalize(double3 const& value1) noexcept
	{
		return value1 / length(value1);
	}

	inline double3 reflect(double3 const& value, double3 const& normal) noexcept
	{
		return value - 2 * dot(value, normal) * normal;
	}

	inline double3 min(double3 const& value1, double3 const& value2) noexcept
	{
		return { value1.x < value2.x ? value1.x : value2.x,
				 value1.y < value2.y ? value1.y : value2.y,
				 value1.z < value2.z ? value1.z : value2.z };
	}

	inline double3 max(double3 const& value1, double3 const& value2) noexcept
	{
		return { value1.x > value2.x ? value1.x : value2.x,
				 value1.y > value2.y ? value1.y : value2.y,
				 value1.z > value2.z ? value1.z : value2.z, };
	}

	inline double3 projection(double3 const& value1, double3 const& value2) noexcept
	{
		return value2 * (length(value1) * cos(value1, value2) / length(value2));
	}

	inline double3 projection(double3 const& value1, planed const& value2) noexcept
	{
		_HICXX_ASSERT(value2.normal != double3::zero(), L"normal is zero vector");
		return value1 - normalize(value2.normal) * dot(value1 - one_point_on(value2), normalize(value2.normal));
	}

	inline double3 clamp(double3 const& value1, double3 const& minValue, double3 const& maxValue) noexcept
	{
		return max(min(value1, minValue), maxValue);
	}

	inline double3 lerp(double3 const& value1, double3 const& value2, double const amount) noexcept
	{
		return value1 + (value2 - value1) * amount;
	}

	inline double3 transform(double3 const& position, double4x4 const& matrix)
	{
		return { position.x * matrix.m11 + position.y * matrix.m21 + position.z * matrix.m31 + matrix.m41,
				 position.x * matrix.m12 + position.y * matrix.m22 + position.z * matrix.m32 + matrix.m42,
				 position.x * matrix.m13 + position.y * matrix.m23 + position.z * matrix.m33 + matrix.m43 };
	}

	inline double3 transform_normal(double3 const& normal, double4x4 const& matrix)
	{
		return { normal.x * matrix.m11 + normal.y * matrix.m21 + normal.z * matrix.m31,
				 normal.x * matrix.m12 + normal.y * matrix.m22 + normal.z * matrix.m32,
				 normal.x * matrix.m13 + normal.y * matrix.m23 + normal.z * matrix.m33 };
	}

	inline double3 transform(double3 const& value, quaterniond const& rotation)
	{
		double const x2 = rotation.x + rotation.x;
		double const y2 = rotation.y + rotation.y;
		double const z2 = rotation.z + rotation.z;

		double const wx2 = rotation.w * x2;
		double const wy2 = rotation.w * y2;
		double const wz2 = rotation.w * z2;
		double const xx2 = rotation.x * x2;
		double const xy2 = rotation.x * y2;
		double const xz2 = rotation.x * z2;
		double const yy2 = rotation.y * y2;
		double const yz2 = rotation.y * z2;
		double const zz2 = rotation.z * z2;

		return { value.x * (1 - yy2 - zz2) + value.y * (xy2 - wz2) + value.z * (xz2 + wy2),
				 value.x * (xy2 + wz2) + value.y * (1 - xx2 - zz2) + value.z * (yz2 - wx2),
				 value.x * (xz2 - wy2) + value.y * (yz2 + wx2) + value.z * (1 - xx2 - yy2) };
	}

	inline bool is_parallel(double3 const& value1, double3 const& value2) noexcept
	{
		return cross(value1, value2) == double3::zero();
	}

	constexpr double3::double3(double const x, double const y, double const z) noexcept : value{ x, y, z } {}

	constexpr double3::double3(double2 const& value, double const z) noexcept : value{ value.x, value.y, z } {}

	constexpr double3::double3(double4 const& value) noexcept : value{ value.x, value.y, value.z } {}

	constexpr double3::double3(double const value) noexcept : value{ value, value, value } {}

	constexpr double3 double3::zero() noexcept
	{
		return { 0, 0, 0 };
	}

	constexpr double3 double3::one() noexcept
	{
		return { 1, 1, 1 };
	}

	constexpr double3 double3::unit_x() noexcept
	{
		return { 1, 0, 0 };
	}

	constexpr double3 double3::unit_y() noexcept
	{
		return { 0, 1, 0 };
	}

	constexpr double3 double3::unit_z() noexcept
	{
		return { 0, 0, 1 };
	}

	inline double double3::length() const noexcept
	{
		return HiCxx::length(*this);
	}

	inline double double3::length_squared() const noexcept
	{
		return HiCxx::length_squared(*this);
	}

	inline double double3::distance(double3 const& value2) const noexcept
	{
		return HiCxx::distance(*this, value2);
	}

	inline double double3::distance_squared(double3 const& value2) const noexcept
	{
		return HiCxx::distance_squared(*this, value2);
	}

	inline double double3::distance(double2x3 const& value2) const noexcept
	{
		return HiCxx::distance(*this, value2);
	}

	inline double double3::distance_directed(double2x3 const& value2) const noexcept
	{
		return HiCxx::distance_directed(*this, value2);
	}

	inline double double3::cos(double3 const& value2) const noexcept
	{
		return HiCxx::cos(*this, value2);
	}

	inline double double3::acos(double3 const& value2) const noexcept
	{
		return HiCxx::acos(*this, value2);
	}

	inline double double3::dot(double3 const& value2) const noexcept
	{
		return HiCxx::dot(*this, value2);
	}

	inline double3 double3::cross(double3 const& value2) const noexcept
	{
		return HiCxx::cross(*this, value2);
	}

	inline double3 double3::abs() const noexcept
	{
		return HiCxx::abs(*this);
	}

	inline double3 double3::sqrt() const noexcept
	{
		return HiCxx::sqrt(*this);
	}

	inline double3 double3::squared() const noexcept
	{
		return HiCxx::squared(*this);
	}

	inline double3 double3::rotate(double const radX, double const radY, double const radZ) const noexcept
	{
		return HiCxx::rotate(*this, radX, radY, radZ);
	}

	inline double3 double3::rotate_x(double const radX) const noexcept
	{
		return HiCxx::rotate_x(*this, radX);
	}

	inline double3 double3::rotate_y(double const radX) const noexcept
	{
		return HiCxx::rotate_y(*this, radX);
	}

	inline double3 double3::rotate_z(double const radX) const noexcept
	{
		return HiCxx::rotate_z(*this, radX);
	}

	inline double3 double3::rotate90_x() const noexcept
	{
		return HiCxx::rotate90_x(*this);
	}

	inline double3 double3::rotate90_y() const noexcept
	{
		return HiCxx::rotate90_y(*this);
	}

	inline double3 double3::rotate90_z() const noexcept
	{
		return HiCxx::rotate90_z(*this);
	}

	inline double3 double3::normalize() const noexcept
	{
		return HiCxx::normalize(*this);
	}

	inline double3 double3::reflect(double3 const& normal) const noexcept
	{
		return HiCxx::reflect(*this, normal);
	}

	inline double3 double3::min(double3 const& value2) const noexcept
	{
		return HiCxx::min(*this, value2);
	}

	inline double3 double3::max(double3 const& value2) const noexcept
	{
		return HiCxx::max(*this, value2);
	}

	inline double3 double3::projection(double3 const& value2) const noexcept
	{
		return HiCxx::projection(*this, value2);
	}

	inline double3 double3::projection(planed const& value2) const noexcept
	{
		return HiCxx::projection(*this, value2);
	}

	inline double3 double3::clamp(double3 const& minValue, double3 const& maxValue) const noexcept
	{
		return HiCxx::clamp(*this, minValue, maxValue);
	}

	inline double3 double3::lerp(double3 const& value2, double const amount) const noexcept
	{
		return HiCxx::lerp(*this, value2, amount);
	}

	inline double3 double3::transform(double4x4 const& matrix) const noexcept
	{
		return HiCxx::transform(*this, matrix);
	}

	inline double3 double3::transform_normal(double4x4 const& matrix) const noexcept
	{
		return HiCxx::transform_normal(*this, matrix);
	}

	inline double3 double3::transform(quaterniond const& rotation) const noexcept
	{
		return HiCxx::transform(*this, rotation);
	}

	inline bool double3::is_parallel(double3 const& value2) const noexcept
	{
		return HiCxx::is_parallel(*this, value2);
	}

	inline double& double3::operator[](unsigned int const i) noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 3, L"double3 subscript out of range");
		return this->data[i];
	}

	inline double const& double3::operator[](unsigned int const i) const noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 3, L"double3 subscript out of range");
		return this->data[i];
	}

	constexpr double4 operator+(double4 const& value1, double4 const& value2) noexcept
	{
		return { value1.x + value2.x, value1.y + value2.y, value1.z + value2.z, value1.w + value2.w };
	}

	constexpr double4 operator-(double4 const& value1, double4 const& value2) noexcept
	{
		return { value1.x - value2.x, value1.y - value2.y, value1.z - value2.z, value1.w - value2.w };
	}

	constexpr double4 operator*(double4 const& value1, double4 const& value2) noexcept
	{
		return { value1.x * value2.x, value1.y * value2.y, value1.z * value2.z, value1.w * value2.w };
	}

	constexpr double4 operator*(double4 const& value1, double const value2) noexcept
	{
		return { value1.x * value2, value1.y * value2, value1.z * value2, value1.w * value2 };
	}

	constexpr double4 operator*(double const value1, double4 const& value2) noexcept
	{
		return value2 * value1;
	}

	constexpr double4 operator/(double4 const& value1, double4 const& value2) noexcept
	{
		return { value1.x / value2.x, value1.y / value2.y, value1.z / value2.z, value1.w / value2.w };
	}

	constexpr double4 operator/(double4 const& value1, double const value2) noexcept
	{
		return value1 * (1 / value2);
	}

	constexpr double4 operator+(double4 const& value1) noexcept
	{
		return value1;
	}

	constexpr double4 operator-(double4 const& value1) noexcept
	{
		return { -value1.x, -value1.y, -value1.z, -value1.w };
	}

	constexpr double4& operator+=(double4& value1, double4 const& value2) noexcept
	{
		return value1 = value1 + value2;
	}

	constexpr double4& operator-=(double4& value1, double4 const& value2) noexcept
	{
		return value1 = value1 - value2;
	}

	constexpr double4& operator*=(double4& value1, double4 const& value2) noexcept
	{
		return value1 = value1 * value2;
	}

	constexpr double4& operator*=(double4& value1, double const value2) noexcept
	{
		return value1 = value1 * value2;
	}

	constexpr double4& operator/=(double4& value1, double4 const& value2) noexcept
	{
		return value1 = value1 / value2;
	}

	constexpr double4& operator/=(double4& value1, double const value2) noexcept
	{
		return value1 = value1 / value2;
	}

	constexpr bool operator==(double4 const& value1, double4 const& value2) noexcept
	{
		return value1.x == value2.x && value1.y == value2.y && value1.z == value2.z && value1.w == value2.w;
	}

	constexpr bool operator!=(double4 const& value1, double4 const& value2) noexcept
	{
		return value1.x != value2.x || value1.y != value2.y || value1.z != value2.z || value1.w != value2.w;
	}

	inline double length(double4 const& value1) noexcept
	{
		return ::sqrt(length_squared(value1));
	}

	inline double length_squared(double4 const& value1) noexcept
	{
		return dot(value1, value1);
	}

	inline double distance(double4 const& value1, double4 const& value2) noexcept
	{
		return length(value1 - value2);
	}

	inline double distance_squared(double4 const& value1, double4 const& value2) noexcept
	{
		return length_squared(value1 - value2);
	}

	inline double dot(double4 const& vector1, double4 const& vector2) noexcept
	{
		return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z + vector1.w * vector2.w;
	}

	inline double4 abs(double4 const& value1) noexcept
	{
		return { value1.x < 0 ? -value1.x : value1.x,
				 value1.y < 0 ? -value1.y : value1.y,
				 value1.z < 0 ? -value1.z : value1.z,
				 value1.w < 0 ? -value1.w : value1.w };
	}

	inline double4 sqrt(double4 const& value1) noexcept
	{
		return { ::sqrt(value1.x), ::sqrt(value1.y), ::sqrt(value1.z), ::sqrt(value1.w) };
	}

	inline double4 squared(double4 const& value1) noexcept
	{
		return value1 * value1;
	}

	inline double4 normalize(double4 const& value1) noexcept
	{
		return value1 / length(value1);
	}

	inline double4 reflect(double4 const& value, double4 const& normal) noexcept
	{
		return value - 2 * dot(value, normal) * normal;
	}

	inline double4 min(double4 const& value1, double4 const& value2) noexcept
	{
		return { value1.x < value2.x ? value1.x : value2.x,
				 value1.y < value2.y ? value1.y : value2.y,
				 value1.z < value2.z ? value1.z : value2.z,
				 value1.w < value2.w ? value1.w : value2.w };
	}

	inline double4 max(double4 const& value1, double4 const& value2) noexcept
	{
		return { value1.x > value2.x ? value1.x : value2.x,
				 value1.y > value2.y ? value1.y : value2.y,
				 value1.z > value2.z ? value1.z : value2.z,
				 value1.w > value2.w ? value1.w : value2.w };
	}

	inline double4 clamp(double4 const& value1, double4 const& minValue, double4 const& maxValue) noexcept
	{
		return max(min(value1, minValue), maxValue);
	}

	inline double4 lerp(double4 const& value1, double4 const& value2, double const amount) noexcept
	{
		return value1 + (value2 - value1) * amount;
	}

	inline double4 transform(double4 const& vector, double4x4 const& matrix) noexcept
	{
		return { vector.x * matrix.m11 + vector.y * matrix.m21 + vector.z * matrix.m31 + vector.w * matrix.m41,
				 vector.x * matrix.m12 + vector.y * matrix.m22 + vector.z * matrix.m32 + vector.w * matrix.m42,
				 vector.x * matrix.m13 + vector.y * matrix.m23 + vector.z * matrix.m33 + vector.w * matrix.m43,
				 vector.x * matrix.m14 + vector.y * matrix.m24 + vector.z * matrix.m34 + vector.w * matrix.m44 };
	}

	inline double4 transform4(double3 const& position, double4x4 const& matrix) noexcept
	{
		return { position.x * matrix.m11 + position.y * matrix.m21 + position.z * matrix.m31 + matrix.m41,
				 position.x * matrix.m12 + position.y * matrix.m22 + position.z * matrix.m32 + matrix.m42,
				 position.x * matrix.m13 + position.y * matrix.m23 + position.z * matrix.m33 + matrix.m43,
				 position.x * matrix.m14 + position.y * matrix.m24 + position.z * matrix.m34 + matrix.m44 };
	}

	inline double4 transform4(double2 const& position, double4x4 const& matrix) noexcept
	{
		return { position.x * matrix.m11 + position.y * matrix.m21 + matrix.m41,
				 position.x * matrix.m12 + position.y * matrix.m22 + matrix.m42,
				 position.x * matrix.m13 + position.y * matrix.m23 + matrix.m43,
				 position.x * matrix.m14 + position.y * matrix.m24 + matrix.m44 };
	}

	inline double4 transform(double4 const& value, quaterniond const& rotation) noexcept
	{
		double const xx = rotation.x + rotation.x;
		double const yy = rotation.y + rotation.y;
		double const zz = rotation.z + rotation.z;

		double const wx2 = rotation.w * xx;
		double const wy2 = rotation.w * yy;
		double const wz2 = rotation.w * zz;
		double const xx2 = rotation.x * xx;
		double const xy2 = rotation.x * yy;
		double const xz2 = rotation.x * zz;
		double const yy2 = rotation.y * yy;
		double const yz2 = rotation.y * zz;
		double const zz2 = rotation.z * zz;

		return { value.x * (1 - yy2 - zz2) + value.y * (xy2 - wz2) + value.z * (xz2 + wy2),
				 value.x * (xy2 + wz2) + value.y * (1 - xx2 - zz2) + value.z * (yz2 - wx2),
				 value.x * (xz2 - wy2) + value.y * (yz2 + wx2) + value.z * (1 - xx2 - yy2),
				 value.w };
	}

	inline double4 transform4(double3 const& value, quaterniond const& rotation) noexcept
	{
		double const xx = rotation.x + rotation.x;
		double const yy = rotation.y + rotation.y;
		double const zz = rotation.z + rotation.z;

		double const wx2 = rotation.w * xx;
		double const wy2 = rotation.w * yy;
		double const wz2 = rotation.w * zz;
		double const xx2 = rotation.x * xx;
		double const xy2 = rotation.x * yy;
		double const xz2 = rotation.x * zz;
		double const yy2 = rotation.y * yy;
		double const yz2 = rotation.y * zz;
		double const zz2 = rotation.z * zz;

		return { value.x * (1 - yy2 - zz2) + value.y * (xy2 - wz2) + value.z * (xz2 + wy2),
				 value.x * (xy2 + wz2) + value.y * (1 - xx2 - zz2) + value.z * (yz2 - wx2),
				 value.x * (xz2 - wy2) + value.y * (yz2 + wx2) + value.z * (1 - xx2 - yy2),
				 1 };
	}

	inline double4 transform4(double2 const& value, quaterniond const& rotation) noexcept
	{
		double const xx = rotation.x + rotation.x;
		double const yy = rotation.y + rotation.y;
		double const zz = rotation.z + rotation.z;

		double const wx2 = rotation.w * xx;
		double const wy2 = rotation.w * yy;
		double const wz2 = rotation.w * zz;
		double const xx2 = rotation.x * xx;
		double const xy2 = rotation.x * yy;
		double const xz2 = rotation.x * zz;
		double const yy2 = rotation.y * yy;
		double const yz2 = rotation.y * zz;
		double const zz2 = rotation.z * zz;

		return { value.x * (1 - yy2 - zz2) + value.y * (xy2 - wz2),
				 value.x * (xy2 + wz2) + value.y * (1 - xx2 - zz2),
				 value.x * (xz2 - wy2) + value.y * (yz2 + wx2),
				 1 };
	}

	constexpr double4::double4(double const x, double const y, double const z, double const w) noexcept : value{ x, y, z, w } {}

	constexpr double4::double4(double2 const& value, double const z, double const w) noexcept : value{ value.x, value.y, z, w } {}

	constexpr double4::double4(double3 const& value, double const w) noexcept : value{ value.x, value.y, value.z, w } {}

	constexpr double4::double4(planed const& value) noexcept : value{ value.a, value.b, value.c, value.d } {}

	constexpr double4::double4(quaterniond const& value) noexcept : value{ value.x, value.y, value.z, value.w } {}

	constexpr double4::double4(double const value) noexcept : value{ value, value, value, value } {}

	constexpr double4 double4::zero() noexcept
	{
		return { 0, 0, 0, 0 };
	}

	constexpr double4 double4::one() noexcept
	{
		return { 1, 1, 1, 0 };
	}

	constexpr double4 double4::unit_x() noexcept
	{
		return { 1, 0, 0, 0 };
	}

	constexpr double4 double4::unit_y() noexcept
	{
		return { 0, 1, 0, 0 };
	}

	constexpr double4 double4::unit_z() noexcept
	{
		return { 0, 0, 1, 0 };
	}

	constexpr double4 double4::unit_w() noexcept
	{
		return { 0, 0, 0, 1 };
	}

	inline double double4::length() const noexcept
	{
		return HiCxx::length(*this);
	}

	inline double double4::length_squared() const noexcept
	{
		return HiCxx::length_squared(*this);
	}

	inline double double4::distance(double4 const& value2) const noexcept
	{
		return HiCxx::distance(*this, value2);
	}

	inline double double4::distance_squared(double4 const& value2) const noexcept
	{
		return HiCxx::distance_squared(*this, value2);
	}

	inline double double4::dot(double4 const& value2) const noexcept
	{
		return HiCxx::dot(*this, value2);
	}

	inline double4 double4::abs() const noexcept
	{
		return HiCxx::abs(*this);
	}

	inline double4 double4::sqrt() const noexcept
	{
		return HiCxx::sqrt(*this);
	}

	inline double4 double4::squared() const noexcept
	{
		return HiCxx::squared(*this);
	}

	inline double4 double4::normalize() const noexcept
	{
		return HiCxx::normalize(*this);
	}

	inline double4 double4::reflect(double4 const& normal) const noexcept
	{
		return HiCxx::reflect(*this, normal);
	}

	inline double4 double4::min(double4 const& value2) const noexcept
	{
		return HiCxx::min(*this, value2);
	}

	inline double4 double4::max(double4 const& value2) const noexcept
	{
		return HiCxx::max(*this, value2);
	}

	inline double4 double4::clamp(double4 const& minValue, double4 const& maxValue) const noexcept
	{
		return HiCxx::clamp(*this, minValue, maxValue);
	}

	inline double4 double4::lerp(double4 const& value2, double const amount) const noexcept
	{
		return HiCxx::lerp(*this, value2, amount);
	}

	inline double4 double4::transform(double4x4 const& matrix) const noexcept
	{
		return HiCxx::transform(*this, matrix);
	}

	inline double4 double4::transform(quaterniond const& rotation) const noexcept
	{
		return HiCxx::transform(*this, rotation);
	}

	inline double& double4::operator[](unsigned int const i) noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 4, L"double4 subscript out of range");
		return this->data[i];
	}

	inline double const& double4::operator[](unsigned int const i) const noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 4, L"double4 subscript out of range");
		return this->data[i];
	}

	constexpr double3x2 operator+(double3x2 const& value1, double3x2 const& value2) noexcept
	{
		return { value1.m11 + value2.m11, value1.m12 + value2.m12,
				 value1.m21 + value2.m21, value1.m22 + value2.m22,
				 value1.m31 + value2.m31, value1.m32 + value2.m32 };
	}

	constexpr double3x2 operator-(double3x2 const& value1, double3x2 const& value2) noexcept
	{
		return { value1.m11 - value2.m11, value1.m12 - value2.m12,
				 value1.m21 - value2.m21, value1.m22 - value2.m22,
				 value1.m31 - value2.m31, value1.m32 - value2.m32 };
	}

	constexpr double3x2 operator*(double3x2 const& value1, double3x2 const& value2) noexcept
	{
		return { value1.m11 * value2.m11 + value1.m12 * value2.m21,
				 value1.m11 * value2.m12 + value1.m12 * value2.m22,
				 value1.m21 * value2.m11 + value1.m22 * value2.m21,
				 value1.m21 * value2.m12 + value1.m22 * value2.m22,
				 value1.m31 * value2.m11 + value1.m32 * value2.m21 + value2.m31,
				 value1.m31 * value2.m12 + value1.m32 * value2.m22 + value2.m32 };
	}

	constexpr double3x2 operator*(double3x2 const& value1, double const value2) noexcept
	{
		return { value1.m11 / value2, value1.m12 / value2,
				 value1.m21 / value2, value1.m22 / value2,
				 value1.m31 / value2, value1.m32 / value2 };
	}

	constexpr double3x2 operator*(double const value1, double3x2 const& value2) noexcept
	{
		return value2 * value1;
	}

	constexpr double3x2 operator/(double3x2 const& value1, double const value2) noexcept
	{
		return value1 * (1 / value2);
	}

	constexpr double3x2 operator+(double3x2 const& value) noexcept
	{
		return value;
	}

	constexpr double3x2 operator-(double3x2 const& value) noexcept
	{
		return { -value.m11, -value.m12,
				 -value.m21, -value.m22,
				 -value.m31, -value.m32 };
	}

	constexpr double3x2& operator+=(double3x2& value1, double3x2 const& value2) noexcept
	{
		return value1 = value1 + value2;
	}

	constexpr double3x2& operator-=(double3x2& value1, double3x2 const& value2) noexcept
	{
		return value1 = value1 - value2;
	}

	constexpr double3x2& operator*=(double3x2& value1, double3x2 const& value2) noexcept
	{
		return value1 = value1 * value2;
	}

	constexpr double3x2& operator*=(double3x2& value1, double const value2) noexcept
	{
		return value1 = value1 * value2;
	}

	constexpr double3x2& operator/=(double3x2& value1, double const value2) noexcept
	{
		return value1 = value1 / value2;
	}

	constexpr bool operator==(double3x2 const& value1, double3x2 const& value2) noexcept
	{
		return value1.m11 == value2.m11 && value1.m12 == value2.m12 &&
			   value1.m21 == value2.m21 && value1.m22 == value2.m22 &&
			   value1.m31 == value2.m31 && value1.m32 == value2.m32;
	}

	constexpr bool operator!=(double3x2 const& value1, double3x2 const& value2) noexcept
	{
		return value1.m11 != value2.m11 || value1.m12 != value2.m12 ||
			   value1.m21 != value2.m21 || value1.m22 != value2.m22 ||
			   value1.m31 != value2.m31 || value1.m32 != value2.m32;
	}

	inline bool is_identity(double3x2 const& value) noexcept
	{
		return value == double3x2::identity();
	}

	inline double determinant(double3x2 const& value) noexcept
	{
		return (value.m11 * value.m22) - (value.m21 * value.m12);
	}

	inline double2 translation(double3x2 const& value) noexcept
	{
		return { value.m31,value.m32 };
	}

	inline bool invert(double3x2 const& matrix, double3x2* const result) noexcept
	{
		constexpr static double nan = std::numeric_limits<double>::quiet_NaN();

		double const det = determinant(matrix);

		if (!(::abs(det) >= FLT_EPSILON))
		{
			*result = double3x2{ nan, nan, nan, nan, nan, nan };
			return false;
		}

		double const invDet = 1 / det;
		*result = double3x2
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

	inline double3x2 lerp(double3x2 const& matrix1, double3x2 const& matrix2, double const amount) noexcept
	{
		return matrix1 + (matrix2 - matrix1) * amount;
	}

	inline double3x2 make_double3x2_translation(double2 const& position) noexcept
	{
		return { 1, 0,
				 0, 1,
				 position.x, position.y };
	}

	inline double3x2 make_double3x2_translation(double const xPosition, double const yPosition) noexcept
	{
		return { 1, 0,
				 0, 1,
				 xPosition, yPosition };
	}

	inline double3x2 make_double3x2_scale(double const xScale, double const yScale) noexcept
	{
		return { xScale, 0,
				 0, yScale,
				 0, 0 };
	}

	inline double3x2 make_double3x2_scale(double const xScale, double const yScale, double2 const& centerPoint) noexcept
	{
		double const nxScale = 1 - xScale;
		return { xScale, 0,
				 0, yScale,
				 centerPoint.x * nxScale, centerPoint.y * nxScale };
	}

	inline double3x2 make_double3x2_scale(double2 const& scales) noexcept
	{
		return { scales.x, 0,
				 0, scales.y,
				 0, 0 };
	}

	inline double3x2 make_double3x2_scale(double2 const& scales, double2 const& centerPoint) noexcept
	{
		double2 const t = centerPoint * (double2::one() - scales);
		return { scales.x, 0,
				 0, scales.y,
				 t.x, t.y };
	}

	inline double3x2 make_double3x2_scale(double const scale) noexcept
	{
		return { scale, 0,
				 0, scale,
				 0, 0 };
	}

	inline double3x2 make_double3x2_scale(double const scale, double2 const& centerPoint) noexcept
	{
		double2 const t = centerPoint * (1 - scale);
		return { scale, 0,
				 0, scale,
				 t.x, t.y };
	}

	inline double3x2 make_double3x2_skew(double const radiansX, double const radiansY) noexcept
	{
		return { 1, ::tan(radiansX),
				 ::tan(radiansY), 1,
				 0, 0 };
	}

	inline double3x2 make_double3x2_skew(double const radiansX, double const radiansY, double2 const& centerPoint) noexcept
	{
		double const xTan = ::tan(radiansX);
		double const yTan = ::tan(radiansY);
		return { 1, yTan,
				 xTan, 1,
				 -centerPoint.y * xTan, -centerPoint.x * yTan };
	}

	inline double3x2 make_double3x2_rotation(double const radians) noexcept
	{
		return make_double3x2_rotation(radians, double2::zero());
	}

	inline double3x2 make_double3x2_rotation(double radians, double2 const& centerPoint) noexcept
	{
		constexpr double epsilon = 0.00001 * M_PI / 180;
		
		radians = ::fmod(radians, M_TAO);

		if (radians < 0)
			radians += M_TAO;

		double c, s;
		if (radians < epsilon || radians > M_TAO - epsilon)
		{
			c = 1;
			s = 0;
		}
		else if (radians > M_PIDIV2 - epsilon && radians < M_PIDIV2 + epsilon)
		{
			c = 0;
			s = 1;
		}
		else if (radians > M_PI - epsilon && radians < M_PI + epsilon)
		{
			c = -1;
			s = 0;
		}
		else if (radians > M_PI + M_PIDIV2 - epsilon && radians < M_PI + M_PIDIV2 + epsilon)
		{
			c = 0;
			s = -1;
		}
		else
		{
			c = ::cos(radians);
			s = sin(radians);
		}

		return { c, s,
				 -s, c,
				 centerPoint.x * (1 - c) + centerPoint.y * s, centerPoint.y * (1 - c) - centerPoint.x * s };
	}

	constexpr double3x2 double3x2::identity() noexcept
	{
		return { 1, 0, 0, 1, 0, 0 };
	}

	constexpr double3x2::double3x2(double const m11, double const m12, double const m21, double const m22, double const m31, double const m32) noexcept
		: value{ m11, m12, m21, m22, m31, m32 } {}

	constexpr double3x2::double3x2(double2 const& r1, double2 const& r2, double2 const& r3) noexcept
		: data{ r1, r2, r3 } {}

	inline bool double3x2::is_identity() const noexcept
	{
		return *this == this->identity();
	}

	inline double double3x2::determinant() const noexcept
	{
		return HiCxx::determinant(*this);
	}

	inline double2 double3x2::translation() const noexcept
	{
		return HiCxx::translation(*this);
	}

	inline bool double3x2::invert(double3x2* const result) const noexcept
	{
		return HiCxx::invert(*this, result);
	}

	inline double3x2 double3x2::lerp(double3x2 const& matrix2, double const amount) const noexcept
	{
		return HiCxx::lerp(*this, matrix2, amount);
	}

	inline double2& double3x2::operator[](unsigned int const i) noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 3, L"double3x2 subscript out of range");
		return this->data[i];
	}

	inline double2 const& double3x2::operator[](unsigned int const i) const noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 3, L"double3x2 subscript out of range");
		return this->data[i];
	}

	constexpr double4x4 operator+(double4x4 const& value1, double4x4 const& value2) noexcept
	{
		return { value1.m11 + value2.m11, value1.m12 + value2.m12, value1.m13 + value2.m13, value1.m14 + value2.m14,
				 value1.m21 + value2.m21, value1.m22 + value2.m22, value1.m23 + value2.m23, value1.m24 + value2.m24,
				 value1.m31 + value2.m31, value1.m32 + value2.m32, value1.m33 + value2.m33, value1.m34 + value2.m34,
				 value1.m41 + value2.m41, value1.m42 + value2.m42, value1.m43 + value2.m43, value1.m44 + value2.m44 };
	}

	constexpr double4x4 operator-(double4x4 const& value1, double4x4 const& value2) noexcept
	{
		return { value1.m11 - value2.m11, value1.m12 - value2.m12, value1.m13 - value2.m13, value1.m14 - value2.m14,
				 value1.m21 - value2.m21, value1.m22 - value2.m22, value1.m23 - value2.m23, value1.m24 - value2.m24,
				 value1.m31 - value2.m31, value1.m32 - value2.m32, value1.m33 - value2.m33, value1.m34 - value2.m34,
				 value1.m41 - value2.m41, value1.m42 - value2.m42, value1.m43 - value2.m43, value1.m44 - value2.m44 };
	}
	constexpr double4x4 operator*(double4x4 const& value1, double4x4 const& value2) noexcept
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

	constexpr double4x4 operator*(double4x4 const& value1, double const value2) noexcept
	{
		return { value1.m11 * value2, value1.m12 * value2, value1.m13 * value2, value1.m14 * value2,
				 value1.m21 * value2, value1.m22 * value2, value1.m23 * value2, value1.m24 * value2,
				 value1.m31 * value2, value1.m32 * value2, value1.m33 * value2, value1.m34 * value2,
				 value1.m41 * value2, value1.m42 * value2, value1.m43 * value2, value1.m44 * value2 };
	}

	constexpr double4x4 operator*(double const value1, double4x4 const& value2) noexcept
	{
		return value2 * value1;
	}

	constexpr double4x4 operator/(double4x4 const& value1, double const value2) noexcept
	{
		return { value1.m11 / value2, value1.m12 / value2, value1.m13 / value2, value1.m14 / value2,
				 value1.m21 / value2, value1.m22 / value2, value1.m23 / value2, value1.m24 / value2,
				 value1.m31 / value2, value1.m32 / value2, value1.m33 / value2, value1.m34 / value2,
				 value1.m41 / value2, value1.m42 / value2, value1.m43 / value2, value1.m44 / value2 };
	}

	constexpr double4x4 operator+(double4x4 const& value) noexcept
	{
		return value;
	}

	constexpr double4x4 operator-(double4x4 const& value) noexcept
	{
		return { -value.m11, -value.m12, -value.m13, -value.m14,
				 -value.m21, -value.m22, -value.m23, -value.m24,
				 -value.m31, -value.m32, -value.m33, -value.m34,
				 -value.m41, -value.m42, -value.m43, -value.m44 };
	}

	constexpr double4x4& operator+=(double4x4& value1, double4x4 const& value2) noexcept
	{
		return value1 = value1 + value2;
	}

	constexpr double4x4& operator-=(double4x4& value1, double4x4 const& value2) noexcept
	{
		return value1 = value1 - value2;
	}

	constexpr double4x4& operator*=(double4x4& value1, double4x4 const& value2) noexcept
	{
		return value1 = value1 * value2;
	}

	constexpr double4x4& operator*=(double4x4& value1, double const value2) noexcept
	{
		return value1 = value1 * value2;
	}

	constexpr double4x4& operator/=(double4x4& value1, double const value2) noexcept
	{
		return value1 = value1 / value2;
	}

	constexpr bool operator==(double4x4 const& value1, double4x4 const& value2) noexcept
	{
		return value1.m11 == value2.m11 && value1.m12 == value2.m12 && value1.m13 == value2.m31 && value1.m14 == value2.m41 &&
			value1.m21 == value2.m21 && value1.m22 == value2.m22 && value1.m23 == value2.m32 && value1.m24 == value2.m42 &&
			value1.m31 == value2.m31 && value1.m32 == value2.m32 && value1.m33 == value2.m33 && value1.m34 == value2.m43 &&
			value1.m41 == value2.m41 && value1.m42 == value2.m42 && value1.m43 == value2.m34 && value1.m44 == value2.m44;
	}

	constexpr bool operator!=(double4x4 const& value1, double4x4 const& value2) noexcept
	{
		return value1.m11 != value2.m11 || value1.m12 != value2.m12 || value1.m13 != value2.m31 || value1.m14 != value2.m41 ||
			value1.m21 != value2.m21 || value1.m22 != value2.m22 || value1.m23 != value2.m32 || value1.m24 != value2.m42 ||
			value1.m31 != value2.m31 || value1.m32 != value2.m32 || value1.m33 != value2.m33 || value1.m34 != value2.m43 ||
			value1.m41 != value2.m41 || value1.m42 != value2.m42 || value1.m43 != value2.m34 || value1.m44 != value2.m44;
	}

	inline bool is_identity(double4x4 const& value) noexcept
	{
		return value == double4x4::identity();
	}

	inline double determinant(double4x4 const& value) noexcept
	{
		double const kp_lo = value.m33 * value.m44 - value.m34 * value.m43;
		double const jp_ln = value.m32 * value.m44 - value.m34 * value.m42;
		double const jo_kn = value.m32 * value.m43 - value.m33 * value.m42;
		double const ip_lm = value.m31 * value.m44 - value.m34 * value.m41;
		double const io_km = value.m31 * value.m43 - value.m33 * value.m41;
		double const in_jm = value.m31 * value.m42 - value.m32 * value.m41;

		return value.m11 * (value.m22 * kp_lo - value.m23 * jp_ln + value.m24 * jo_kn) -
			value.m12 * (value.m21 * kp_lo - value.m23 * ip_lm + value.m24 * io_km) +
			value.m13 * (value.m21 * jp_ln - value.m22 * ip_lm + value.m24 * in_jm) -
			value.m14 * (value.m21 * jo_kn - value.m22 * io_km + value.m23 * in_jm);
	}

	inline double3 translation(double4x4 const& value) noexcept
	{
		return { value.m41, value.m42, value.m43 };
	}

	inline bool invert(double4x4 const& matrix, double4x4* const result) noexcept
	{
		double const a = matrix.m11, b = matrix.m12, c = matrix.m13, d = matrix.m14;
		double const e = matrix.m21, f = matrix.m22, g = matrix.m23, h = matrix.m24;
		double const i = matrix.m31, j = matrix.m32, k = matrix.m33, l = matrix.m34;
		double const m = matrix.m41, n = matrix.m42, o = matrix.m43, p = matrix.m44;

		double const kp_lo = k * p - l * o;
		double const jp_ln = j * p - l * n;
		double const jo_kn = j * o - k * n;
		double const ip_lm = i * p - l * m;
		double const io_km = i * o - k * m;
		double const in_jm = i * n - j * m;

		double const a11 = +(f * kp_lo - g * jp_ln + h * jo_kn);
		double const a12 = -(e * kp_lo - g * ip_lm + h * io_km);
		double const a13 = +(e * jp_ln - f * ip_lm + h * in_jm);
		double const a14 = -(e * jo_kn - f * io_km + g * in_jm);

		double const det = a * a11 + b * a12 + c * a13 + d * a14;

		if (!(::abs(det) >= FLT_EPSILON))
		{
			constexpr double nan = std::numeric_limits<double>::quiet_NaN();
			*result = { nan, nan, nan, nan,
						nan, nan, nan, nan,
						nan, nan, nan, nan,
						nan, nan, nan, nan };
			return false;
		}
		double const invDet = 1 / det;

		result->m11 = a11 * invDet;
		result->m21 = a12 * invDet;
		result->m31 = a13 * invDet;
		result->m41 = a14 * invDet;

		result->m12 = -(b * kp_lo - c * jp_ln + d * jo_kn) * invDet;
		result->m22 = +(a * kp_lo - c * ip_lm + d * io_km) * invDet;
		result->m32 = -(a * jp_ln - b * ip_lm + d * in_jm) * invDet;
		result->m42 = +(a * jo_kn - b * io_km + c * in_jm) * invDet;

		double const gp_ho = g * p - h * o;
		double const fp_hn = f * p - h * n;
		double const fo_gn = f * o - g * n;
		double const ep_hm = e * p - h * m;
		double const eo_gm = e * o - g * m;
		double const en_fm = e * n - f * m;

		result->m13 = +(b * gp_ho - c * fp_hn + d * fo_gn) * invDet;
		result->m23 = -(a * gp_ho - c * ep_hm + d * eo_gm) * invDet;
		result->m33 = +(a * fp_hn - b * ep_hm + d * en_fm) * invDet;
		result->m43 = -(a * fo_gn - b * eo_gm + c * en_fm) * invDet;

		double const gl_hk = g * l - h * k;
		double const fl_hj = f * l - h * j;
		double const fk_gj = f * k - g * j;
		double const el_hi = e * l - h * i;
		double const ek_gi = e * k - g * i;
		double const ej_fi = e * j - f * i;

		result->m14 = -(b * gl_hk - c * fl_hj + d * fk_gj) * invDet;
		result->m24 = +(a * gl_hk - c * el_hi + d * ek_gi) * invDet;
		result->m34 = -(a * fl_hj - b * el_hi + d * ej_fi) * invDet;
		result->m44 = +(a * fk_gj - b * ek_gi + c * ej_fi) * invDet;

		return true;
	}

	inline bool decompose(double4x4 const& matrix, double3* const scale, quaterniond* rotation, double3* const translation) noexcept
	{
		constexpr static double4 pvCanonicalBasis[4] = { double4::unit_x(), double4::unit_y(), double4::unit_z(), double4::unit_w() };
		constexpr static double decomp_epsilon = 0.000001;

		_HICXX_ASSERT(scale != nullptr, L"decompose scale is nullptr");
		_HICXX_ASSERT(rotation != nullptr, L"decompose rotation is nullptr");
		_HICXX_ASSERT(translation != nullptr, L"decompose translation is nullptr");

		double4x4 matTemp = { matrix.data[0], matrix.data[1], matrix.data[2], pvCanonicalBasis[3] };
		double3* const ppvBasis[3] = { reinterpret_cast<double3*>(&matTemp.data[0]), reinterpret_cast<double3*>(&matTemp.data[1]),
			reinterpret_cast<double3*>(&matTemp.data[2]) };

		double4 pfScales = { length(*ppvBasis[0]), length(*ppvBasis[1]), length(*ppvBasis[2]), 0 };

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
			*ppvBasis[a] = (double3 const&)pvCanonicalBasis[a];

		*ppvBasis[a] = normalize(*ppvBasis[a]);

		if (pfScales[b] < decomp_epsilon)
		{
			unsigned int aa, bb, cc;
			
			double const fAbsX = ::abs(ppvBasis[a]->x);
			double const fAbsY = ::abs(ppvBasis[a]->y);
			double const fAbsZ = ::abs(ppvBasis[a]->z);

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

			*ppvBasis[b] = cross(*ppvBasis[a], (double3 const&)pvCanonicalBasis[cc]);
		}

		*ppvBasis[b] = normalize(*ppvBasis[b]);

		if (pfScales[c] < decomp_epsilon)
			*ppvBasis[c] = cross(*ppvBasis[a], *ppvBasis[b]);

		*ppvBasis[c] = normalize(*ppvBasis[c]);

		double fDet = determinant(matTemp);

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

		*translation = double3{ matrix.data[3].x, matrix.data[3].y, matrix.data[3].z };
		*rotation = make_quaternion_from_rotation_matrix(matTemp);
		return true;
	}

	inline double4x4 transform(double4x4 const& value, quaterniond const& rotation) noexcept
	{
		double const x2 = rotation.x + rotation.x;
		double const y2 = rotation.y + rotation.y;
		double const z2 = rotation.z + rotation.z;

		double const wx2 = rotation.w * x2;
		double const wy2 = rotation.w * y2;
		double const wz2 = rotation.w * z2;
		double const xx2 = rotation.x * x2;
		double const xy2 = rotation.x * y2;
		double const xz2 = rotation.x * z2;
		double const yy2 = rotation.y * y2;
		double const yz2 = rotation.y * z2;
		double const zz2 = rotation.z * z2;

		double const q11 = 1 - yy2 - zz2;
		double const q21 = xy2 - wz2;
		double const q31 = xz2 + wy2;

		double const q12 = xy2 + wz2;
		double const q22 = 1 - xx2 - zz2;
		double const q32 = yz2 - wx2;

		double const q13 = xz2 - wy2;
		double const q23 = yz2 + wx2;
		double const q33 = 1 - xx2 - yy2;

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

	inline double4x4 transpose(double4x4 const& matrix) noexcept
	{
		return { matrix.m11, matrix.m21, matrix.m31, matrix.m41,
				 matrix.m12, matrix.m22, matrix.m32, matrix.m42,
				 matrix.m13, matrix.m23, matrix.m33, matrix.m43,
				 matrix.m14, matrix.m24, matrix.m34, matrix.m44 };
	}

	inline double4x4 lerp(double4x4 const& matrix1, double4x4 const& matrix2, double const amount) noexcept
	{
		return matrix1 + (matrix2 - matrix1) * amount;
	}

	inline double4x4 make_double4x4_billboard(double3 const& objectPosition, double3 const& cameraPosition, double3 const& cameraUpVector, double3 const& cameraForwardVector) noexcept
	{
		constexpr static double epsilon = 1e-4f;

		double3 zaxis = objectPosition - cameraPosition;
		double const norm = length_squared(zaxis);
		zaxis = (norm < epsilon) ? (-cameraForwardVector) : (zaxis / ::sqrt(norm));

		double3 const xaxis = normalize(cross(cameraUpVector, zaxis));
		double3 const yaxis = cross(zaxis, xaxis);

		return { xaxis.x, xaxis.y, xaxis.z, 0,
				 yaxis.x, yaxis.y, yaxis.z, 0,
				 zaxis.x, zaxis.y, zaxis.z, 0,
				 objectPosition.x, objectPosition.y, objectPosition.z, 1 };
	}

	inline double4x4 make_double4x4_constrained_billboard(double3 const& objectPosition, double3 const& cameraPosition, double3 const& rotateAxis, double3 const& cameraForwardVector, double3 const& objectForwardVector) noexcept
	{
		constexpr static double epsilon = 0.00001;
		constexpr static double const minAngle = 1 - (0.1 * (M_PI / 180));

		double3 faceDir = objectPosition - cameraPosition;

		double const norm = length_squared(faceDir);

		faceDir = (norm < epsilon) ? (-cameraForwardVector) : (faceDir / ::sqrt(norm));

		double3 const yaxis = rotateAxis;
		double3 xaxis;
		double3 zaxis;

		if (::abs(dot(rotateAxis, faceDir)) > minAngle)
		{
			zaxis = objectForwardVector;

			if (::abs(dot(rotateAxis, zaxis)) > minAngle)
				zaxis = (::abs(rotateAxis.z) > minAngle) ? double3::unit_x() : -double3::unit_z();

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

	inline double4x4 make_double4x4_translation(double3 const& position) noexcept
	{
		return { 1, 0, 0, 0,
				 0, 1, 0, 0,
				 0, 0, 1, 0,
				 position.x, position.y, position.z, 1 };
	}

	inline double4x4 make_double4x4_translation(double const xPosition, double const yPosition, double const zPosition) noexcept
	{
		return { 1, 0, 0, 0,
				 0, 1, 0, 0,
				 0, 0, 1, 0,
				 xPosition, yPosition, zPosition, 1 };
	}

	inline double4x4 make_double4x4_scale(double const xScale, double const yScale, double const zScale) noexcept
	{
		return { xScale, 0, 0, 0,
				 0, yScale, 0, 0,
				 0, 0, zScale, 0,
				 0, 0, 0, 1 };
	}

	inline double4x4 make_double4x4_scale(double const xScale, double const yScale, double const zScale, double3 const& centerPoint) noexcept
	{
		double const tx = centerPoint.x * (1 - xScale);
		double const ty = centerPoint.y * (1 - yScale);
		double const tz = centerPoint.z * (1 - zScale);
		return { xScale, 0, 0, 0,
				 0, yScale, 0, 0,
				 0, 0, zScale, 0,
				 tx, ty, tz, 1 };
	}

	inline double4x4 make_double4x4_scale(double3 const& scales) noexcept
	{
		return { scales.x, 0, 0, 0,
				 0, scales.y, 0, 0,
				 0, 0, scales.z, 0,
				 0, 0, 0, 1 };
	}

	inline double4x4 make_double4x4_scale(double3 const& scales, double3 const& centerPoint) noexcept
	{
		double3 const t = centerPoint * (double3::one() - scales);
		return { scales.x, 0, 0, 0,
				 0, scales.y, 0, 0,
				 0, 0, scales.z, 0,
				 t.x, t.y, t.z, 1 };
	}

	inline double4x4 make_double4x4_scale(double const scale) noexcept
	{
		return { scale, 0, 0, 0,
				 0, scale, 0, 0,
				 0, 0, scale, 0,
				 0, 0, 0, 1 };
	}

	inline double4x4 make_double4x4_scale(double const scale, double3 const& centerPoint) noexcept
	{
		double3 const t = centerPoint * (1 - scale);
		return { scale, 0, 0, 0,
				 0, scale, 0, 0,
				 0, 0, scale, 0,
				 t.x, t.y, t.z, 1 };
	}

	inline double4x4 make_double4x4_rotation_x(double const radians) noexcept
	{
		double const c = ::cos(radians);
		double const s = sin(radians);
		return { 1, 0, 0, 0,
				 0, c, s, 0,
				 0, -s, c, 0,
				 0, 0, 0, 1 };
	}

	inline double4x4 make_double4x4_rotation_x(double const radians, double3 const& centerPoint) noexcept
	{
		double const c = ::cos(radians);
		double const s = sin(radians);
		double const y = centerPoint.y * (1 - c) + centerPoint.z * s;
		double const z = centerPoint.z * (1 - c) - centerPoint.y * s;
		return { 1, 0, 0, 0,
				 0, c, s, 0,
				 0, -s, c, 0,
				 0, y, z, 1 };
	}

	inline double4x4 make_double4x4_rotation_y(double const radians) noexcept
	{
		double const c = ::cos(radians);
		double const s = sin(radians);
		return { c, 0, -s, 0,
				 0, 1, 0, 0,
				 s, 0, c, 0,
				 0, 0, 0, 1 };
	}

	inline double4x4 make_double4x4_rotation_y(double const radians, double3 const& centerPoint) noexcept
	{
		double const c = ::cos(radians);
		double const s = sin(radians);
		double const x = centerPoint.x * (1 - c) - centerPoint.z * s;
		double const z = centerPoint.z * (1 - c) + centerPoint.x * s;
		return { c, 0, -s, 0,
				 0, 1, 0, 0,
				 s, 0, c, 0,
				 x, 0, z, 1 };
	}

	inline double4x4 make_double4x4_rotation_z(double const radians) noexcept
	{
		double const c = ::cos(radians);
		double const s = sin(radians);
		return { c, s, 0, 0,
				 -s, c, 0, 0,
				 0, 0, 1, 0,
				 0, 0, 0, 1 };
	}

	inline double4x4 make_double4x4_rotation_z(double const radians, double3 const& centerPoint) noexcept
	{
		double const c = ::cos(radians);
		double const s = sin(radians);
		double const x = centerPoint.x * (1 - c) + centerPoint.y * s;
		double const y = centerPoint.y * (1 - c) - centerPoint.x * s;
		return { c, s, 0, 0,
				 -s, c, 0, 0,
				 0, 0, 1, 0,
				 x, y, 0, 1 };
	}

	inline double4x4 make_double4x4_from_axis_angle(double3 const& axis, double const acos) noexcept
	{
		double const x = axis.x, y = axis.y, z = axis.z;
		double const sa = sin(acos), ca = ::cos(acos);
		double const x2 = x * x, y2 = y * y, z2 = z * z;
		double const xy = x * y, xz = x * z, yz = y * z;
		return { x2 + ca * (1 - x2), xy - ca * xy + sa * z, xz - ca * xz - sa * y, 0,
				 xy - ca * xy - sa * z, y2 + ca * (1 - y2), yz - ca * yz + sa * x, 0,
				 xz - ca * xz + sa * y, yz - ca * yz - sa * x, z2 + ca * (1 - z2), 0,
				 0, 0, 0, 1 };
	}

	inline double4x4 make_double4x4_perspective_field_of_view(double const fieldOfView, double const aspectRatio, double const nearplaneDistance, double const farplaneDistance)
	{
		if (fieldOfView <= 0 || fieldOfView >= M_PI)
			throw std::invalid_argument(std::invalid_argument("fieldOfView"));

		if (nearplaneDistance <= 0)
			throw std::invalid_argument(std::invalid_argument("nearplaneDistance"));

		if (farplaneDistance <= 0)
			throw std::invalid_argument(std::invalid_argument("farplaneDistance"));

		if (nearplaneDistance >= farplaneDistance)
			throw std::invalid_argument(std::invalid_argument("nearplaneDistance"));

		double const yScale = 1 / ::tan(fieldOfView * 0.5f);
		double const xScale = yScale / aspectRatio;
		double const clipDist = nearplaneDistance - farplaneDistance;
		return { xScale, 0, 0, 0,
				 0, yScale, 0, 0,
				 0, 0, farplaneDistance / clipDist, -1,
				 0, 0, nearplaneDistance * farplaneDistance / clipDist, 0 };
	}

	inline double4x4 make_double4x4_perspective(double const width, double const height, double const nearplaneDistance, double const farplaneDistance)
	{
		if (nearplaneDistance <= 0)
			throw std::invalid_argument(std::invalid_argument("nearplaneDistance"));

		if (farplaneDistance <= 0)
			throw std::invalid_argument(std::invalid_argument("farplaneDistance"));

		if (nearplaneDistance >= farplaneDistance)
			throw std::invalid_argument(std::invalid_argument("nearplaneDistance"));

		double const clipDist = nearplaneDistance - farplaneDistance;
		return { 2 * nearplaneDistance / width, 0, 0, 0,
				 0, 2 * nearplaneDistance / height, 0, 0,
				 0, 0, farplaneDistance / clipDist, -1,
				 0, 0, nearplaneDistance * farplaneDistance / clipDist, 0 };
	}

	inline double4x4 make_double4x4_perspective_off_center(double const left, double const right, double const bottom, double const top, double const nearplaneDistance, double const farplaneDistance)
	{
		if (nearplaneDistance <= 0)
			throw std::invalid_argument(std::invalid_argument("nearplaneDistance"));

		if (farplaneDistance <= 0)
			throw std::invalid_argument(std::invalid_argument("farplaneDistance"));

		if (nearplaneDistance >= farplaneDistance)
			throw std::invalid_argument(std::invalid_argument("nearplaneDistance"));

		double const clipDist = nearplaneDistance - farplaneDistance;
		return { 2 * nearplaneDistance / (right - left), 0, 0, 0,
				 0, 2 * nearplaneDistance / (top - bottom), 0, 0,
				 (left + right) / (right - left), (top + bottom) / (top - bottom), farplaneDistance / clipDist, -1,
				 0, 0, nearplaneDistance * farplaneDistance / clipDist, 0 };
	}

	inline double4x4 make_double4x4_orthographic(double const width, double const height, double const zNearplane, double const zFarplane) noexcept
	{
		double const clipDist = zNearplane - zFarplane;
		return { 2 / width, 0, 0, 0,
				 0, 2 / height, 0, 0,
				 0, 0, 1 / clipDist, 0,
				 0, 0, zNearplane / clipDist, 1 };
	}

	inline double4x4 make_double4x4_orthographic_off_center(double const left, double const right, double const bottom, double const top, double const zNearplane, double const zFarplane) noexcept
	{
		double const clipDist = zNearplane - zFarplane;
		return { 2 / (right - left), 0, 0, 0,
				 0, 2 / (top - bottom), 0, 0,
				 0, 0, 1 / clipDist, 0,
				 (left + right) / (left - right), (top + bottom) / (bottom - top), zNearplane / clipDist, 1 };
	}

	inline double4x4 make_double4x4_look_at(double3 const& cameraPosition, double3 const& cameraTarget, double3 const& cameraUpVector) noexcept
	{
		double3 const zaxis = normalize(cameraPosition - cameraTarget);
		double3 const xaxis = normalize(cross(cameraUpVector, zaxis));
		double3 const yaxis = cross(zaxis, xaxis);

		return { xaxis.x, yaxis.x, zaxis.x, 0,
				 xaxis.y, yaxis.y, zaxis.y, 0,
				 xaxis.z, yaxis.z, zaxis.z, 0,
				 -dot(xaxis, cameraPosition), -dot(yaxis, cameraPosition), -dot(zaxis, cameraPosition), 1 };
	}

	inline double4x4 make_double4x4_world(double3 const& position, double3 const& forward, double3 const& up) noexcept
	{
		double3 const zaxis = normalize(-forward);
		double3 const xaxis = normalize(cross(up, zaxis));
		double3 const yaxis = cross(zaxis, xaxis);

		return { xaxis.x, xaxis.y, xaxis.z, 0,
				 yaxis.x, yaxis.y, yaxis.z, 0,
				 zaxis.x, zaxis.y, zaxis.z, 0,
				 position.x, position.y, position.z, 1 };
	}

	inline double4x4 make_double4x4_from_quaternion(quaterniond const& quaterniond) noexcept
	{
		double const x2 = quaterniond.x * quaterniond.x;
		double const y2 = quaterniond.y * quaterniond.y;
		double const z2 = quaterniond.z * quaterniond.z;

		double const xy = quaterniond.x * quaterniond.y;
		double const wz = quaterniond.z * quaterniond.w;
		double const xz = quaterniond.z * quaterniond.x;
		double const wy = quaterniond.y * quaterniond.w;
		double const yz = quaterniond.y * quaterniond.z;
		double const wx = quaterniond.x * quaterniond.w;

		return { 1 - 2 * (y2 + z2), 2 * (xy + wz), 2 * (xz - wy), 0,
				 2 * (xy - wz), 1 - 2 * (z2 + x2), 2 * (yz + wx), 0,
				 2 * (xz + wy), 2 * (yz - wx), 1 - 2 * (y2 + x2), 0,
				 0, 0, 0, 1 };
	}

	inline double4x4 make_double4x4_from_yaw_pitch_roll(double const yaw, double const pitch, double const roll) noexcept
	{
		return make_double4x4_from_quaternion(make_quaternion_from_yaw_pitch_roll(yaw, pitch, roll));
	}

	inline double4x4 make_double4x4_shadow(double3 const& lightDirection, planed const& planed) noexcept
	{
		auto const p = normalize(planed);

		double const dot = dot_normal(p, lightDirection);

		double const a = -p.a;
		double const b = -p.b;
		double const c = -p.c;
		double const d = -p.d;

		return { a * lightDirection.x + dot, a * lightDirection.y, a * lightDirection.z, 0,
				 b * lightDirection.x, b * lightDirection.y + dot, b * lightDirection.z, 0,
				 c * lightDirection.x, c * lightDirection.y, c * lightDirection.z + dot, 0,
				 d * lightDirection.x, d * lightDirection.y, d * lightDirection.z, dot };
	}

	inline double4x4 make_double4x4_reflection(planed const& value) noexcept
	{
		planed const v = normalize(value);

		double const fa = -2 * value.a;
		double const fb = -2 * value.b;
		double const fc = -2 * value.c;

		return { fa * value.a + 1, fb * value.a,		   fc * value.a,		0,
				 fa * value.b,		  fb * value.b + 1, fc * value.b,		0,
				 fa * value.c,		  fb * value.c,		   fc * value.c + 1, 0,
				 fa * v.d,			  fb * v.d,			   fc * v.d,			1 };
	}

	constexpr double4x4 double4x4::identity() noexcept
	{
		return { 1, 0, 0, 0,
				 0, 1, 0, 0,
				 0, 0, 1, 0,
				 0, 0, 0, 1 };
	}

	constexpr double4x4::double4x4(double const m11, double const m12, double const m13, double const m14, double const m21, double const m22, double const m23, double const m24, double const m31, double const m32, double const m33, double const m34, double const m41, double const m42, double const m43, double const m44) noexcept
		: value{ m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44 } {}

	constexpr double4x4::double4x4(double4 const& r1, double4 const& r2, double4 const& r3, double4 const& r4) noexcept
		: data{ r1, r2, r3, r4 } {}

	constexpr double4x4::double4x4(double3x2 const& value) noexcept
		: value{ value.m11, value.m12, 0, 0,
				 value.m21, value.m22, 0, 0,
				 0,	0,		   1, 0,
				 value.m31, value.m32, 0, 1 } {}

	inline bool double4x4::is_identity() const noexcept
	{
		return HiCxx::is_identity(*this);
	}

	double double4x4::determinant() const noexcept
	{
		return HiCxx::determinant(*this);
	}

	inline double3 double4x4::translation() const noexcept
	{
		return HiCxx::translation(*this);
	}

	inline bool double4x4::invert(double4x4* const result) noexcept
	{
		return HiCxx::invert(*this, result);
	}

	inline bool double4x4::decompose(double3* const scale, quaterniond* rotation, double3* const translation) const noexcept
	{
		return HiCxx::decompose(*this, scale, rotation, translation);
	}

	inline double4x4 double4x4::transform(quaterniond const& rotation) const noexcept
	{
		return HiCxx::transform(*this, rotation);
	}

	inline double4x4 double4x4::transpose() const noexcept
	{
		return HiCxx::transpose(*this);
	}

	inline double4x4 double4x4::lerp(double4x4 const& matrix2, double const amount) const noexcept
	{
		return HiCxx::lerp(*this, matrix2, amount);
	}

	inline double4& double4x4::operator[](unsigned int const i) noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 4, L"double4x4 subscript out of range");
		return this->data[i];
	}

	inline double4 const& double4x4::operator[](unsigned int const i) const noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 4, L"double4x4 subscript out of range");
		return this->data[i];
	}

	constexpr planed operator+(planed const& value) noexcept
	{
		return value;
	}

	constexpr planed operator-(planed const& value) noexcept
	{
		return planed(-value.normal, -value.d);
	}

	constexpr bool operator==(planed const& value1, planed const& value2) noexcept
	{
		return value1.a == value2.a &&
			   value1.b == value2.b &&
			   value1.c == value2.c &&
			   value1.d == value2.d;
	}

	constexpr bool operator!=(planed const& value1, planed const& value2) noexcept
	{
		return value1.a != value2.a ||
			   value1.b != value2.b ||
			   value1.c != value2.c ||
			   value1.d != value2.d;
	}

	inline planed normalize(planed const& value) noexcept
	{
		double const f = length_squared(value.normal);

		if (::abs(f - 1) < FLT_EPSILON)
			return value;

		double const fInv = 1 / ::sqrt(f);

		return planed(value.normal * fInv, value.d * fInv);
	}

	inline planed transform(planed const& value, double4x4 const& matrix) noexcept
	{
		double4x4 inverseMatrix;
		invert(matrix, &inverseMatrix);
		return planed(transform(double4(value.normal, value.d), transpose(inverseMatrix)));
	}

	inline planed transform(planed const& value, quaterniond const& rotation) noexcept
	{
		return planed(transform(double4(value.normal, value.d), rotation));
	}

	inline double3 one_point_on(planed const& value) noexcept
	{
		return value.a ? double3(value.d / value.a, 0, 0) : value.b ? double3(0, value.d / value.b, 0) : double3(0, 0, value.d / value.c);
	}

	inline double dot(planed const& planed, double4 const& value) noexcept
	{
		return planed.a * value.x +
			   planed.b * value.y +
			   planed.c * value.z +
			   planed.d * value.w;
	}

	inline double dot_coordinate(planed const& planed, double3 const& value) noexcept
	{
		return planed.a * value.x +
			   planed.b * value.y +
			   planed.c * value.z +
			   planed.d;
	}

	inline double dot_normal(planed const& planed, double3 const& value) noexcept
	{
		return dot(planed.normal, value);
	}

	inline bool is_antarafacial(planed const& value1, double3 const& value2) noexcept
	{
		return dot(value1.normal, value2) + value1.d == 0;
	}

	inline planed make_plane_from_vertices(double3 const& point1, double3 const& point2, double3 const& point3) noexcept
	{
		double3 const normal = normalize(cross(point2 - point1, point3 - point1));
		return planed(normal, -dot(normal, point1));
	}

	constexpr planed::planed(double const x, double const y, double const z, double const d) noexcept : value{ x, y, z, d } {}

	constexpr planed::planed(double3 const& normal, double const d) noexcept : value{ normal.x, normal.y, normal.z, d } {}

	constexpr planed::planed(double4 const& value) noexcept : value{ value.x,value.y,value.z, value.w } {}

	constexpr planed::planed(quaterniond const& value) noexcept : value{ value.x,value.y,value.z, value.w } {}

	inline planed planed::normalize() const noexcept
	{
		return HiCxx::normalize(*this);
	}

	inline planed planed::transform(double4x4 const& matrix) const noexcept
	{
		return HiCxx::transform(*this, matrix);
	}

	inline planed planed::transform(quaterniond const& rotation) const noexcept
	{
		return HiCxx::transform(*this, rotation);
	}

	inline double3 planed::one_point_on() const noexcept
	{
		return HiCxx::one_point_on(*this);
	}

	inline double planed::dot(double4 const& value) const noexcept
	{
		return HiCxx::dot(*this, value);
	}

	inline double planed::dot_coordinate(double3 const& value) const noexcept
	{
		return HiCxx::dot_coordinate(*this, value);
	}

	inline double planed::dot_normal(double3 const& value) const noexcept
	{
		return HiCxx::dot_normal(*this, value);
	}

	inline double& planed::operator[](unsigned int const i) noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 4, L"planed subscript out of range");
		return this->data[i];
	}

	inline double const& planed::operator[](unsigned int const i) const noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 4, L"planed subscript out of range");
		return this->data[i];
	}

	constexpr quaterniond operator+(quaterniond const& value1, quaterniond const& value2) noexcept
	{
		return { value1.x + value2.x, value1.y + value2.y, value1.z + value2.z, value1.w + value2.w };
	}

	constexpr quaterniond operator-(quaterniond const& value1, quaterniond const& value2) noexcept
	{
		return { value1.x - value2.x, value1.y - value2.y, value1.z - value2.z, value1.w - value2.w };
	}

	constexpr quaterniond operator*(quaterniond const& value1, quaterniond const& value2) noexcept
	{
		return { value1.x * value2.x, value1.y * value2.y, value1.z * value2.z, value1.w * value2.w };
	}

	constexpr quaterniond operator*(quaterniond const& value1, double const value2) noexcept
	{
		return { value1.x * value2, value1.y * value2, value1.z * value2, value1.w * value2 };
	}

	constexpr quaterniond operator*(double const value1, quaterniond const& value2) noexcept
	{
		return value2 * value1;
	}

	constexpr quaterniond operator/(quaterniond const& value1, quaterniond const& value2) noexcept
	{
		return { value1.x / value2.x, value1.y / value2.y, value1.z / value2.z, value1.w / value2.w };
	}

	constexpr quaterniond operator/(quaterniond const& value1, double const value2) noexcept
	{
		return value1 * (1 / value2);
	}

	constexpr quaterniond operator+(quaterniond const& value1) noexcept
	{
		return value1;
	}

	constexpr quaterniond operator-(quaterniond const& value1) noexcept
	{
		return { -value1.x, -value1.y, -value1.z, -value1.w };
	}

	constexpr quaterniond& operator+=(quaterniond& value1, quaterniond const& value2) noexcept
	{
		return value1 = value1 + value2;
	}

	constexpr quaterniond& operator-=(quaterniond& value1, quaterniond const& value2) noexcept
	{
		return value1 = value1 - value2;
	}

	constexpr quaterniond& operator*=(quaterniond& value1, quaterniond const& value2) noexcept
	{
		return value1 = value1 * value2;
	}

	constexpr quaterniond& operator*=(quaterniond& value1, double const value2) noexcept
	{
		return value1 = value1 * value2;
	}

	constexpr quaterniond& operator/=(quaterniond& value1, quaterniond const& value2) noexcept
	{
		return value1 = value1 / value2;
	}

	constexpr quaterniond& operator/=(quaterniond& value1, double const value2) noexcept
	{
		return value1 = value1 / value2;
	}

	constexpr bool operator==(quaterniond const& value1, quaterniond const& value2) noexcept
	{
		return value1.x == value2.x && value1.y == value2.y && value1.z == value2.z && value1.w == value2.w;
	}

	constexpr bool operator!=(quaterniond const& value1, quaterniond const& value2) noexcept
	{
		return value1.x != value2.x || value1.y != value2.y || value1.z != value2.z || value1.w != value2.w;
	}

	inline bool is_identity(quaterniond const& value) noexcept
	{
		return value == quaterniond::identity();
	}

	inline double length(quaterniond const& value) noexcept
	{
		return ::sqrt(length_squared(value));
	}

	inline double length_squared(quaterniond const& value) noexcept
	{
		return dot(value, value);
	}

	inline double dot(quaterniond const& quaternion1, quaterniond const& quaternion2) noexcept
	{
		return quaternion1.x * quaternion2.x +
			quaternion1.y * quaternion2.y +
			quaternion1.z * quaternion2.z +
			quaternion1.w * quaternion2.w;
	}

	inline quaterniond normalize(quaterniond const& value) noexcept
	{
		return value * (1 / length(value));
	}

	inline quaterniond conjugate(quaterniond const& value) noexcept
	{
		return { -value.x, -value.y, -value.z, value.w };
	}

	inline quaterniond inverse(quaterniond const& value) noexcept
	{
		return conjugate(value * (1 / length_squared(value)));
	}

	inline quaterniond slerp(quaterniond const& quaternion1, quaterniond const& quaternion2, double const amount) noexcept
	{
		double const epsilon = 1e-6f;

		double const t = amount;
		double cosOmega = dot(quaternion1, quaternion2);
		bool flip = false;

		if (cosOmega < 0)
		{
			flip = true;
			cosOmega = -cosOmega;
		}

		double s1, s2;

		if (cosOmega > (1 - epsilon))
		{
			s1 = 1 - t;
			s2 = flip ? -t : t;
		}
		else
		{
			double const omega = ::acos(cosOmega);
			double const invSinOmega = 1 / sin(omega);

			s1 = sin((1 - t) * omega) * invSinOmega;
			s2 = flip ? -::sin(t * omega) * invSinOmega
				: sin(t * omega) * invSinOmega;
		}

		return { s1 * quaternion1.x + s2 * quaternion2.x,
				 s1 * quaternion1.y + s2 * quaternion2.y,
				 s1 * quaternion1.z + s2 * quaternion2.z,
				 s1 * quaternion1.w + s2 * quaternion2.w };
	}

	inline quaterniond lerp(quaterniond const& quaternion1, quaterniond const& quaternion2, double const amount) noexcept
	{
		double t2 = amount;
		double const t1 = 1 - amount;

		if (dot(quaternion1, quaternion2) < 0)
			t2 = -t2;
		return normalize(quaterniond{ t1 * quaternion1.x + t2 * quaternion2.x,
							 t1 * quaternion1.y + t2 * quaternion2.y,
							 t1 * quaternion1.z + t2 * quaternion2.z,
							 t1 * quaternion1.w + t2 * quaternion2.w });
	}

	inline quaterniond concatenate(quaterniond const& value1, quaterniond const& value2) noexcept
	{
		return value2 * value1;
	}

	inline quaterniond make_quaternion_from_axis_angle(double3 const& axis, double const acos) noexcept
	{
		double const halfAngle = acos * 0.5f;
		return quaterniond(axis * sin(halfAngle), ::cos(halfAngle));
	}

	inline quaterniond make_quaternion_from_yaw_pitch_roll(double const yaw, double const pitch, double const roll) noexcept
	{
		double const halfRoll = roll * 0.5f;
		double const sr = sin(halfRoll), cr = ::cos(halfRoll);

		double const halfPitch = pitch * 0.5f;
		double const sp = sin(halfPitch), cp = ::cos(halfPitch);

		double const halfYaw = yaw * 0.5f;
		double const sy = sin(halfYaw), cy = ::cos(halfYaw);

		return { cy * sp * cr + sy * cp * sr,
				 sy * cp * cr - cy * sp * sr,
				 cy * cp * sr - sy * sp * cr,
				 cy * cp * cr + sy * sp * sr };
	}

	inline quaterniond make_quaternion_from_rotation_matrix(double4x4 const& matrix) noexcept
	{
		if (matrix.m11 + matrix.m22 + matrix.m33 > 0)
		{
			double const s = ::sqrt(1 + matrix.m11 + matrix.m22 + matrix.m33);
			double const invS = 0.5f / s;

			return { (matrix.m23 - matrix.m32) * invS,
					 (matrix.m31 - matrix.m13) * invS,
					 (matrix.m12 - matrix.m21) * invS,
					 s * 0.5f };
		}
		else if (matrix.m11 >= matrix.m22 && matrix.m11 >= matrix.m33)
		{
			double const s = ::sqrt(1 + matrix.m11 - matrix.m22 - matrix.m33);
			double const invS = 0.5f / s;

			return { 0.5f * s,
					 (matrix.m12 + matrix.m21) * invS,
					 (matrix.m13 + matrix.m31) * invS,
					 (matrix.m23 - matrix.m32) * invS };
		}
		else if (matrix.m22 > matrix.m33)
		{
			double const s = ::sqrt(1 + matrix.m22 - matrix.m11 - matrix.m33);
			double const invS = 0.5f / s;

			return { (matrix.m21 + matrix.m12) * invS,
					 0.5f * s,
					 (matrix.m32 + matrix.m23) * invS,
					 (matrix.m31 - matrix.m13) * invS };
		}
		else
		{
			double const s = ::sqrt(1 + matrix.m33 - matrix.m11 - matrix.m22);
			double const invS = 0.5f / s;

			return { (matrix.m31 + matrix.m13) * invS,
					 (matrix.m32 + matrix.m23) * invS,
					 0.5f * s,
					 (matrix.m12 - matrix.m21) * invS };
		}
	}

	constexpr quaterniond quaterniond::identity() noexcept
	{
		return { 0, 0, 0, 1 };
	}

	constexpr quaterniond::quaterniond(double const x, double const y, double const z, double const w) noexcept : value{ x, y, z, w } {}

	constexpr quaterniond::quaterniond(double2 const& value, double const z, double const w) noexcept : value{ value.x, value.y, z, w } {}

	constexpr quaterniond::quaterniond(double3 const& value, double const w) noexcept : value{ value.x, value.y, value.z, w } {}

	constexpr quaterniond::quaterniond(double4 const& value) noexcept : value{ value.x, value.y, value.z, value.w } {}

	constexpr quaterniond::quaterniond(planed const& value) noexcept : value{ value.a, value.b, value.c, value.d } {}

	constexpr quaterniond::quaterniond(double const value) noexcept : value{ value, value, value, value } {}

	inline bool quaterniond::is_identity() const noexcept
	{
		return HiCxx::is_identity(*this);
	}

	inline double quaterniond::length() const noexcept
	{
		return HiCxx::length(*this);
	}

	inline double quaterniond::length_squared() const noexcept
	{
		return HiCxx::length_squared(*this);
	}

	inline double quaterniond::dot(quaterniond const& quaternion2) const noexcept
	{
		return HiCxx::dot(*this, quaternion2);
	}

	inline quaterniond quaterniond::normalize() const noexcept
	{
		return HiCxx::normalize(*this);
	}

	inline quaterniond quaterniond::conjugate() const noexcept
	{
		return HiCxx::conjugate(*this);
	}

	inline quaterniond quaterniond::inverse() const noexcept
	{
		return HiCxx::inverse(*this);
	}

	inline quaterniond quaterniond::slerp(quaterniond const& quaternion2, double const amount) const noexcept
	{
		return HiCxx::slerp(*this, quaternion2, amount);
	}

	inline quaterniond quaterniond::lerp(quaterniond const& quaternion2, double const amount) const noexcept
	{
		return HiCxx::lerp(*this, quaternion2, amount);
	}

	inline quaterniond quaterniond::concatenate(quaterniond const& value2) const noexcept
	{
		return HiCxx::concatenate(*this, value2);
	}

	inline double& quaterniond::operator[](unsigned int const i) noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 4, L"quaterniond subscript out of range");
		return this->data[i];
	}

	inline double const& quaterniond::operator[](unsigned int const i) const noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 4, L"quaterniond subscript out of range");
		return this->data[i];
	}

	inline bool is_parallel(double2x2 const& value1, double2x2 const& value2) noexcept
	{
		return is_parallel(value1.v, value2.v);
	}

	inline bool is_intersecting(double2x2 const& value1, double2x2 const& value2) noexcept
	{
		return is_intersecting(value1.v, value2.v);
	}

	inline double2 intersection(double2x2 const& value1, double2x2 const& value2) noexcept
	{
		_HICXX_ASSERT(is_intersecting(value1, value2), L"double2x2 are not intersecting");
		return value1.p + value1.v * (cross(value2.v, value1.p - value2.p) / cross(value1.v, value2.v));
	}

	constexpr double2x2::double2x2(double const x1, double const y1, double const x2, double const y2) noexcept
		: value{ x1, y1, x2, y2 } {}
	constexpr double2x2::double2x2(double2 const& value1, double2 const& value2) noexcept
		: data{ value1, value2 } {}
	constexpr double2x2::double2x2(double4 const& value) noexcept
		: value{ value.x, value.y, value.z, value.w } {}

	constexpr double2x2 double2x2::zero() noexcept
	{
		return { double2::zero(), double2::zero() };
	}

	constexpr double2x2 double2x2::one() noexcept
	{
		return { double2::zero(), double2::one() };
	}

	constexpr double2x2 double2x2::unit_x() noexcept
	{
		return { double2::zero(), double2::unit_x() };
	}

	constexpr double2x2 double2x2::unit_y() noexcept
	{
		return { double2::zero(), double2::unit_y() };
	}

	inline bool double2x2::is_parallel(double2x2 const& value2) const noexcept
	{
		return HiCxx::is_parallel(*this, value2);
	}

	inline bool double2x2::is_intersecting(double2x2 const& value2) const noexcept
	{
		return HiCxx::is_intersecting(*this, value2);
	}

	inline double2 double2x2::intersection(double2x2 const& value2) const noexcept
	{
		return HiCxx::intersection(*this, value2);
	}

	inline double2& double2x2::operator[](unsigned int const i) noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 2, L"double2x2 subscript out of range");
		return this->data[i];
	}

	inline const double2& double2x2::operator[](unsigned int const i) const noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 2, L"double2x2 subscript out of range");
		return this->data[i];
	}

	inline bool is_parallel(double2x3 const& value1, double2x3 const& value2) noexcept
	{
		return is_parallel(value1.v, value2.v);
	}

	inline bool is_antarafacial(double2x3 const& value1, double2x3 const& value2) noexcept
	{
		return dot(cross(value1.v, value2.p - value1.p), value2.v) != 0;
	}

	inline bool is_intersecting(double2x3 const& value1, double2x3 const& value2) noexcept
	{
		return !is_parallel(value1, value2) && !is_antarafacial(value1, value2);
	}

	inline double3 intersection(double2x3 const& value1, double2x3 const& value2) noexcept
	{
		_HICXX_ASSERT(is_intersecting(value1, value2), L"double2x3 are not intersecting");
		return value1.p + value1.v * ::sqrt(length_squared(cross(value2.v, value1.p - value2.p)) / length_squared(cross(value1.v, value2.v)));
	}

	constexpr double2x3::double2x3(double const x1, double const y1, double const z1, double const x2, double const y2, double const z2) noexcept
		: value{ x1, y1, z1, x2, y2, z2 } {}
	constexpr double2x3::double2x3(double3 const& value1, double3 const& value2) noexcept
		: data{ value1, value2 } {}

	constexpr double2x3 double2x3::zero() noexcept
	{
		return { double3::zero(), double3::zero() };
	}

	constexpr double2x3 double2x3::one() noexcept
	{
		return { double3::zero(), double3::one() };
	}

	constexpr double2x3 double2x3::unit_x() noexcept
	{
		return { double3::zero(), double3::unit_x() };
	}

	constexpr double2x3 double2x3::unit_y() noexcept
	{
		return { double3::zero(), double3::unit_y() };
	}

	constexpr double2x3 double2x3::unit_z() noexcept
	{
		return { double3::zero(), double3::unit_z() };
	}

	inline bool double2x3::is_parallel(double2x3 const& value2) const noexcept
	{
		return HiCxx::is_parallel(*this, value2);
	}

	inline bool double2x3::is_antarafacial(double2x3 const& value2) const noexcept
	{
		return HiCxx::is_antarafacial(*this, value2);
	}

	inline bool double2x3::is_intersecting(double2x3 const& value2) const noexcept
	{
		return HiCxx::is_intersecting(*this, value2);
	}

	inline double3 double2x3::intersection(double2x3 const& value2) const noexcept
	{
		return HiCxx::intersection(*this, value2);
	}

	inline double3& double2x3::operator[](unsigned int const i) noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 2, L"double2x3 subscript out of range");
		return this->data[i];
	}

	inline const double3& double2x3::operator[](unsigned int const i) const noexcept
	{
		_HICXX_ASSERT(0 <= i && i < 2, L"double2x3 subscript out of range");
		return this->data[i];
	}

	inline std::ostream& operator<<(::std::ostream& os, double2 const& value) noexcept
	{
		return os << '(' << value.x << ", " << value.y << ')';
	}

	inline std::ostream& operator<<(::std::ostream& os, double3 const& value) noexcept
	{
		return os << '(' << value.x << ", " << value.y << ", " << value.z << ')';
	}

	inline std::ostream& operator<<(::std::ostream& os, double4 const& value) noexcept
	{
		return os << '(' << value.x << ", " << value.y << ", " << value.z << ", " << value.w << ')';
	}

	inline std::ostream& operator<<(::std::ostream& os, double3x2 const& value) noexcept
	{
		return os << '(' << value.r1 << ", " << value.r2 << ", " << value.r3 << ')';
	}

	inline std::ostream& operator<<(::std::ostream& os, double4x4 const& value) noexcept
	{
		return os << '(' << value.r1 << ", " << value.r2 << ", " << value.r3 << ", " << value.r4 << ')';
	}

	inline std::ostream& operator<<(::std::ostream& os, planed const& value) noexcept
	{
		return os << '(' << value.normal << ", " << value.d << ')';
	}

	inline std::ostream& operator<<(::std::ostream& os, quaterniond const& value) noexcept
	{
		return os << '(' << value.x << ", " << value.y << ", " << value.z << ", " << value.w << ')';
	}

	inline std::ostream& operator<<(::std::ostream& os, double2x2 const& value) noexcept
	{
		return os << '(' << value.p << ", " << value.v << ')';
	}

	inline std::ostream& operator<<(::std::ostream& os, double2x3 const& value) noexcept
	{
		return os << '(' << value.p << ", " << value.v << ')';
	}
}