/**
 * @file	numerics.1.h
 * @brief	HiCxx 的数学模块
 * @author	侧云
*/

#pragma once

#include <cmath>
#include <iostream>

namespace HiCxx
{
	constexpr double M_PI = 3.141592653589793;
	constexpr double M_PIDIV2 = M_PI / 2;
	constexpr double M_TAO = M_PI * 2;

	struct double2;
	struct double3;
	struct double4;
	struct double3x2;
	struct double4x4;
	struct planed;
	struct quaterniond;
	struct double2x2;
	struct double2x3;

	constexpr double2 operator+(double2 const& value1, double2 const& value2) noexcept;
	constexpr double2 operator-(double2 const& value1, double2 const& value2) noexcept;
	constexpr double2 operator*(double2 const& value1, double2 const& value2) noexcept;
	constexpr double2 operator*(double2 const& value1, double const value2) noexcept;
	constexpr double2 operator*(double const value1, double2 const& value2) noexcept;
	constexpr double2 operator/(double2 const& value1, double2 const& value2) noexcept;
	constexpr double2 operator/(double2 const& value1, double const value2) noexcept;
	constexpr double2 operator+(double2 const& value1) noexcept;
	constexpr double2 operator-(double2 const& value1) noexcept;
	constexpr double2& operator+=(double2& value1, double2 const& value2) noexcept;
	constexpr double2& operator-=(double2& value1, double2 const& value2) noexcept;
	constexpr double2& operator*=(double2& value1, double2 const& value2) noexcept;
	constexpr double2& operator*=(double2& value1, double const value2) noexcept;
	constexpr double2& operator/=(double2& value1, double2 const& value2) noexcept;
	constexpr double2& operator/=(double2& value1, double const value2) noexcept;
	constexpr bool operator==(double2 const& value1, double2 const& value2) noexcept;
	constexpr bool operator!=(double2 const& value1, double2 const& value2) noexcept;

	double length(double2 const& value1) noexcept;
	double length_squared(double2 const& value1) noexcept;
	double distance(double2 const& value1, double2 const& value2) noexcept;
	double distance_squared(double2 const& value1, double2 const& value2) noexcept;
	double distance(double2 const& value1, double2x2 const& value2) noexcept;
	double distance_directed(double2 const& value1, double2x2 const& value2) noexcept;
	double cos(double2 const& value1, double2 const& value2) noexcept;
	double acos(double2 const& value1, double2 const& value2) noexcept;
	double dot(double2 const& vector1, double2 const& vector2) noexcept;
	double cross(double2 const& vector1, double2 const& vector2) noexcept;
	double2 abs(double2 const& value1) noexcept;
	double2 sqrt(double2 const& value1) noexcept;
	double2 squared(double2 const& value1) noexcept;
	double2 rotate(double2 const& value1, double const rad) noexcept;
	double2 rotate90(double2 const& value1) noexcept;
	double2 normalize(double2 const& value1) noexcept;
	double2 reflect(double2 const& value, double2 const& normal) noexcept;
	double2 min(double2 const& value1, double2 const& value2) noexcept;
	double2 max(double2 const& value1, double2 const& value2) noexcept;
	double2 projection(double2 const& value1, double2 const& value2) noexcept;
	double2 projection(double2 const& value1, double2x2 const& value2) noexcept;
	double2 clamp(double2 const& value1, double2 const& min, double2 const& max) noexcept;
	double2 lerp(double2 const& value1, double2 const& value2, double const amount) noexcept;
	double2 transform(double2 const& position, double3x2 const& matrix) noexcept;
	double2 transform(double2 const& position, double4x4 const& matrix) noexcept;
	double2 transform_normal(double2 const& normal, double3x2 const& matrix) noexcept;
	double2 transform_normal(double2 const& normal, double4x4 const& matrix) noexcept;
	double2 transform(double2 const& value, quaterniond const& rotation) noexcept;
	bool is_parallel(double2 const& value1, double2 const& value2) noexcept;
	bool is_intersecting(double2 const& value1, double2 const& value2) noexcept;

	struct double2
	{
		constexpr double2(double const x, double const y) noexcept;
		constexpr explicit double2(double3 const& value) noexcept;
		constexpr explicit double2(double4 const& value) noexcept;
		constexpr explicit double2(double const value = 0.0f) noexcept;

		constexpr static double2 zero() noexcept;
		constexpr static double2 one() noexcept;
		constexpr static double2 unit_x() noexcept;
		constexpr static double2 unit_y() noexcept;

		double length() const noexcept;
		double length_squared() const noexcept;
		double distance(double2 const& value2) const noexcept;
		double distance_squared(double2 const& value2) const noexcept;
		double distance(double2x2 const& value2) const noexcept;
		double distance_directed(double2x2 const& value2) const noexcept;
		double cos(double2 const& value2) const noexcept;
		double acos(double2 const& value2) const noexcept;
		double dot(double2 const& vector2) const noexcept;
		double cross(double2 const& vector2) const noexcept;
		double2 abs() const noexcept;
		double2 sqrt() const noexcept;
		double2 squared() const noexcept;
		double2 rotate(double const rad) const noexcept;
		double2 rotate90() const noexcept;
		double2 normalize() const noexcept;
		double2 reflect(double2 const& normal) const noexcept;
		double2 min(double2 const& value2) const noexcept;
		double2 max(double2 const& value2) const noexcept;
		double2 projection(double2 const& value2) const noexcept;
		double2 projection(double2x2 const& value2) const noexcept;
		double2 clamp(double2 const& minValue, double2 const& maxValue) const noexcept;
		double2 lerp(double2 const& value2, double const amount) const noexcept;
		double2 transform(double3x2 const& matrix) const noexcept;
		double2 transform(double4x4 const& matrix) const noexcept;
		double2 transform_normal(double3x2 const& matrix) const noexcept;
		double2 transform_normal(double4x4 const& matrix) const noexcept;
		double2 transform(quaterniond const& rotation) const noexcept;
		bool is_parallel(double2 const& value2) const noexcept;
		bool is_intersecting(double2 const& value2) const noexcept;

		double& operator[](unsigned int const i) noexcept;
		const double& operator[](unsigned int const i) const noexcept;

		union
		{
			struct { double x; double y; };
			double value[2];
			double data[2];
		};
	};

	constexpr double3 operator+(double3 const& value1, double3 const& value2) noexcept;
	constexpr double3 operator-(double3 const& value1, double3 const& value2) noexcept;
	constexpr double3 operator*(double3 const& value1, double3 const& value2) noexcept;
	constexpr double3 operator*(double3 const& value1, double const value2) noexcept;
	constexpr double3 operator*(double const value1, double3 const& value2) noexcept;
	constexpr double3 operator/(double3 const& value1, double3 const& value2) noexcept;
	constexpr double3 operator/(double3 const& value1, double const value2) noexcept;
	constexpr double3 operator+(double3 const& value1) noexcept;
	constexpr double3 operator-(double3 const& value1) noexcept;
	constexpr double3& operator+=(double3& value1, double3 const& value2) noexcept;
	constexpr double3& operator-=(double3& value1, double3 const& value2) noexcept;
	constexpr double3& operator*=(double3& value1, double3 const& value2) noexcept;
	constexpr double3& operator*=(double3& value1, double const value2) noexcept;
	constexpr double3& operator/=(double3& value1, double3 const& value2) noexcept;
	constexpr double3& operator/=(double3& value1, double const value2) noexcept;
	constexpr bool operator==(double3 const& value1, double3 const& value2) noexcept;
	constexpr bool operator!=(double3 const& value1, double3 const& value2) noexcept;

	double length(double3 const& value1) noexcept;
	double length_squared(double3 const& value1) noexcept;
	double distance(double3 const& value1, double3 const& value2) noexcept;
	double distance_squared(double3 const& value1, double3 const& value2) noexcept;
	double distance(double3 const& value1, double2x3 const& value2) noexcept;
	double distance_directed(double3 const& value1, double2x3 const& value2) noexcept;
	double cos(double3 const& value1, double3 const& value2) noexcept;
	double acos(double3 const& value1, double3 const& value2) noexcept;
	double dot(double3 const& value1, double3 const& value2) noexcept;
	double3 cross(double3 const& value1, double3 const& value2) noexcept;
	double3 abs(double3 const& value1) noexcept;
	double3 sqrt(double3 const& value1) noexcept;
	double3 squared(double3 const& value1) noexcept;
	double3 rotate(double3 const& value1, double const radX, double const radY, double const radZ) noexcept;
	double3 rotate_x(double3 const& value1, double const rad) noexcept;
	double3 rotate_y(double3 const& value1, double const rad) noexcept;
	double3 rotate_z(double3 const& value1, double const rad) noexcept;
	double3 rotate90_x(double3 const& value1) noexcept;
	double3 rotate90_y(double3 const& value1) noexcept;
	double3 rotate90_z(double3 const& value1) noexcept;
	double3 normalize(double3 const& value1) noexcept;
	double3 reflect(double3 const& value, double3 const& normal) noexcept;
	double3 min(double3 const& value1, double3 const& value2) noexcept;
	double3 max(double3 const& value1, double3 const& value2) noexcept;
	double3 projection(double3 const& value1, double3 const& value2) noexcept;
	double3 projection(double3 const& value1, planed const& value2) noexcept;
	double3 clamp(double3 const& value1, double3 const& min, double3 const& max) noexcept;
	double3 lerp(double3 const& value1, double3 const& value2, double const amount) noexcept;
	double3 transform(double3 const& position, double4x4 const& matrix);
	double3 transform_normal(double3 const& normal, double4x4 const& matrix);
	double3 transform(double3 const& value, quaterniond const& rotation);
	bool is_parallel(double3 const& value1, double3 const& value2) noexcept;

	struct double3
	{
		constexpr double3(double const x, double const y, double const z) noexcept;
		constexpr explicit double3(double2 const& value, double const z = 0.0f) noexcept;
		constexpr explicit double3(double4 const& value) noexcept;
		constexpr explicit double3(double const value = 0.0f) noexcept;

		constexpr static double3 zero() noexcept;
		constexpr static double3 one() noexcept;
		constexpr static double3 unit_x() noexcept;
		constexpr static double3 unit_y() noexcept;
		constexpr static double3 unit_z() noexcept;

		double length() const noexcept;
		double length_squared() const noexcept;
		double distance(double3 const& value2) const noexcept;
		double distance_squared(double3 const& value2) const noexcept;
		double distance(double2x3 const& value2) const noexcept;
		double distance_directed(double2x3 const& value2) const noexcept;
		double cos(double3 const& value2) const noexcept;
		double acos(double3 const& value2) const noexcept;
		double dot(double3 const& value2) const noexcept;
		double3 cross(double3 const& value2) const noexcept;
		double3 abs() const noexcept;
		double3 sqrt() const noexcept;
		double3 squared() const noexcept;
		double3 rotate(double const radX, double const radY, double const radZ) const noexcept;
		double3 rotate_x(double const rad) const noexcept;
		double3 rotate_y(double const rad) const noexcept;
		double3 rotate_z(double const rad) const noexcept;
		double3 rotate90_x() const noexcept;
		double3 rotate90_y() const noexcept;
		double3 rotate90_z() const noexcept;
		double3 normalize() const noexcept;
		double3 reflect(double3 const& normal) const noexcept;
		double3 min(double3 const& value2) const noexcept;
		double3 max(double3 const& value2) const noexcept;
		double3 projection(double3 const& value2) const noexcept;
		double3 projection(planed const& value2) const noexcept;
		double3 clamp(double3 const& minValue, double3 const& maxValue) const noexcept;
		double3 lerp(double3 const& value2, double const amount) const noexcept;
		double3 transform(double4x4 const& matrix) const noexcept;
		double3 transform_normal(double4x4 const& matrix) const noexcept;
		double3 transform(quaterniond const& rotation) const noexcept;
		bool is_parallel(double3 const& value2) const noexcept;

		double& operator[](unsigned int const i) noexcept;
		const double& operator[](unsigned int const i) const noexcept;

		union
		{
			struct { double x; double y; double z; };
			double value[3];
			double data[3];
		};
	};

	constexpr double4 operator+(double4 const& value1, double4 const& value2) noexcept;
	constexpr double4 operator-(double4 const& value1, double4 const& value2) noexcept;
	constexpr double4 operator*(double4 const& value1, double4 const& value2) noexcept;
	constexpr double4 operator*(double4 const& value1, double const value2) noexcept;
	constexpr double4 operator*(double const value1, double4 const& value2) noexcept;
	constexpr double4 operator/(double4 const& value1, double4 const& value2) noexcept;
	constexpr double4 operator/(double4 const& value1, double const value2) noexcept;
	constexpr double4 operator+(double4 const& value1) noexcept;
	constexpr double4 operator-(double4 const& value1) noexcept;
	constexpr double4& operator+=(double4& value1, double4 const& value2) noexcept;
	constexpr double4& operator-=(double4& value1, double4 const& value2) noexcept;
	constexpr double4& operator*=(double4& value1, double4 const& value2) noexcept;
	constexpr double4& operator*=(double4& value1, double const value2) noexcept;
	constexpr double4& operator/=(double4& value1, double4 const& value2) noexcept;
	constexpr double4& operator/=(double4& value1, double const value2) noexcept;
	constexpr bool operator==(double4 const& value1, double4 const& value2) noexcept;
	constexpr bool operator!=(double4 const& value1, double4 const& value2) noexcept;

	double length(double4 const& value1) noexcept;
	double length_squared(double4 const& value1) noexcept;
	double distance(double4 const& value1, double4 const& value2) noexcept;
	double distance_squared(double4 const& value1, double4 const& value2) noexcept;
	double dot(double4 const& value1, double4 const& value2) noexcept;
	double4 abs(double4 const& value1) noexcept;
	double4 sqrt(double4 const& value1) noexcept;
	double4 squared(double4 const& value1) noexcept;
	double4 normalize(double4 const& value1) noexcept;
	double4 reflect(double4 const& value, double4 const& normal) noexcept;
	double4 min(double4 const& value1, double4 const& value2) noexcept;
	double4 max(double4 const& value1, double4 const& value2) noexcept;
	double4 clamp(double4 const& value1, double4 const& min, double4 const& max) noexcept;
	double4 lerp(double4 const& value1, double4 const& value2, double const amount) noexcept;
	double4 transform(double4 const& vector, double4x4 const& matrix) noexcept;
	double4 transform4(double3 const& position, double4x4 const& matrix) noexcept;
	double4 transform4(double2 const& position, double4x4 const& matrix) noexcept;
	double4 transform(double4 const& value, quaterniond const& rotation) noexcept;
	double4 transform4(double3 const& value, quaterniond const& rotation) noexcept;
	double4 transform4(double2 const& value, quaterniond const& rotation) noexcept;

	struct double4
	{
		constexpr double4(double const x, double const y, double const z, double const w) noexcept;
		constexpr explicit double4(double2 const& value, double const z = 0.0f, double const w = 0.0f) noexcept;
		constexpr explicit double4(double3 const& value, double const w = 0.0f) noexcept;
		constexpr explicit double4(planed const& value) noexcept;
		constexpr explicit double4(quaterniond const& value) noexcept;
		constexpr explicit double4(double const value = 0.0f) noexcept;

		constexpr static double4 zero() noexcept;
		constexpr static double4 one() noexcept;
		constexpr static double4 unit_x() noexcept;
		constexpr static double4 unit_y() noexcept;
		constexpr static double4 unit_z() noexcept;
		constexpr static double4 unit_w() noexcept;

		double length() const noexcept;
		double length_squared() const noexcept;
		double distance(double4 const& value2) const noexcept;
		double distance_squared(double4 const& value2) const noexcept;
		double dot(double4 const& value2) const noexcept;
		double4 abs() const noexcept;
		double4 sqrt() const noexcept;
		double4 squared() const noexcept;
		double4 normalize() const noexcept;
		double4 reflect(double4 const& normal) const noexcept;
		double4 min(double4 const& value2) const noexcept;
		double4 max(double4 const& value2) const noexcept;
		double4 clamp(double4 const& minValue, double4 const& maxValue) const noexcept;
		double4 lerp(double4 const& value2, double const amount) const noexcept;
		double4 transform(double4x4 const& matrix) const noexcept;
		double4 transform(quaterniond const& rotation) const noexcept;

		double& operator[](unsigned int const i) noexcept;
		const double& operator[](unsigned int const i) const noexcept;

		union
		{
			struct { double x; double y; double z; double w; };
			double value[4];
			double data[4];
		};
	};

	constexpr double3x2 operator+(double3x2 const& value1, double3x2 const& value2) noexcept;
	constexpr double3x2 operator-(double3x2 const& value1, double3x2 const& value2) noexcept;
	constexpr double3x2 operator*(double3x2 const& value1, double3x2 const& value2) noexcept;
	constexpr double3x2 operator*(double3x2 const& value1, double const value2) noexcept;
	constexpr double3x2 operator*(double const value1, double3x2 const& value2) noexcept;
	constexpr double3x2 operator/(double3x2 const& value1, double const value2) noexcept;
	constexpr double3x2 operator+(double3x2 const& value) noexcept;
	constexpr double3x2 operator-(double3x2 const& value) noexcept;
	constexpr double3x2& operator+=(double3x2& value1, double3x2 const& value2) noexcept;
	constexpr double3x2& operator-=(double3x2& value1, double3x2 const& value2) noexcept;
	constexpr double3x2& operator*=(double3x2& value1, double3x2 const& value2) noexcept;
	constexpr double3x2& operator*=(double3x2& value1, double const value2) noexcept;
	constexpr double3x2& operator/=(double3x2& value1, double const value2) noexcept;
	constexpr bool operator==(double3x2 const& value1, double3x2 const& value2) noexcept;
	constexpr bool operator!=(double3x2 const& value1, double3x2 const& value2) noexcept;

	bool is_identity(double3x2 const& value) noexcept;
	double determinant(double3x2 const& value) noexcept;
	double2 translation(double3x2 const& value) noexcept;
	bool invert(double3x2 const& matrix, double3x2* const result) noexcept;
	double3x2 lerp(double3x2 const& matrix1, double3x2 const& matrix2, double const amount) noexcept;

	double3x2 make_double3x2_translation(double2 const& position) noexcept;
	double3x2 make_double3x2_translation(double const xPosition, double const yPosition) noexcept;
	double3x2 make_double3x2_scale(double const xScale, double const yScale) noexcept;
	double3x2 make_double3x2_scale(double const xScale, double const yScale, double2 const& centerPoint) noexcept;
	double3x2 make_double3x2_scale(double2 const& scales) noexcept;
	double3x2 make_double3x2_scale(double2 const& scales, double2 const& centerPoint) noexcept;
	double3x2 make_double3x2_scale(double const scale) noexcept;
	double3x2 make_double3x2_scale(double const scale, double2 const& centerPoint) noexcept;
	double3x2 make_double3x2_skew(double const radiansX, double const radiansY) noexcept;
	double3x2 make_double3x2_skew(double const radiansX, double const radiansY, double2 const& centerPoint) noexcept;
	double3x2 make_double3x2_rotation(double const radians) noexcept;
	double3x2 make_double3x2_rotation(double radians, double2 const& centerPoint) noexcept;

	struct double3x2
	{
		constexpr static double3x2 identity() noexcept;

		constexpr double3x2(double const m11 = 0.0f, double const m12 = 0.0f,
						   double const m21 = 0.0f, double const m22 = 0.0f,
						   double const m31 = 0.0f, double const m32 = 0.0f) noexcept;
		constexpr double3x2(double2 const& r1, double2 const& r2 = double2::zero(), double2 const& r3 = double2::zero()) noexcept;

		bool is_identity() const noexcept;
		double determinant() const noexcept;
		double2 translation() const noexcept;
		bool invert(double3x2* const result) const noexcept;
		double3x2 lerp(double3x2 const& matrix2, double const amount) const noexcept;

		double2& operator[](unsigned int const i) noexcept;
		const double2& operator[](unsigned int const i) const noexcept;

		union
		{
			struct
			{
				double m11, m12;
				double m21, m22;
				double m31, m32;
			};
			struct
			{
				double2 r1;
				double2 r2;
				double2 r3;
			};
			double m[3][2];
			double value[6];
			double2 data[3];
			double2 row[3];
		};
	};

	constexpr double4x4 operator+(double4x4 const& value1, double4x4 const& value2) noexcept;
	constexpr double4x4 operator-(double4x4 const& value1, double4x4 const& value2) noexcept;
	constexpr double4x4 operator*(double4x4 const& value1, double4x4 const& value2) noexcept;
	constexpr double4x4 operator*(double4x4 const& value1, double const value2) noexcept;
	constexpr double4x4 operator*(double const value1, double4x4 const& value2) noexcept;
	constexpr double4x4 operator+(double4x4 const& value) noexcept;
	constexpr double4x4 operator-(double4x4 const& value) noexcept;
	constexpr double4x4& operator+=(double4x4& value1, double4x4 const& value2) noexcept;
	constexpr double4x4& operator-=(double4x4& value1, double4x4 const& value2) noexcept;
	constexpr double4x4& operator*=(double4x4& value1, double4x4 const& value2) noexcept;
	constexpr double4x4& operator*=(double4x4& value1, double const value2) noexcept;
	constexpr bool operator==(double4x4 const& value1, double4x4 const& value2) noexcept;
	constexpr bool operator!=(double4x4 const& value1, double4x4 const& value2) noexcept;

	bool is_identity(double4x4 const& value) noexcept;
	double determinant(double4x4 const& value) noexcept;
	double3 translation(double4x4 const& value) noexcept;
	bool invert(double4x4 const& matrix, double4x4* const result) noexcept;
	bool decompose(double4x4 const& matrix, double3* const scale, quaterniond* rotation, double3* const translation) noexcept;
	double4x4 transform(double4x4 const& value, quaterniond const& rotation) noexcept;
	double4x4 transpose(double4x4 const& matrix) noexcept;
	double4x4 lerp(double4x4 const& matrix1, double4x4 const& matrix2, double const amount) noexcept;

	double4x4 make_double4x4_billboard(double3 const& objectPosition, double3 const& cameraPosition, double3 const& cameraUpVector, double3 const& cameraForwardVector) noexcept;
	double4x4 make_double4x4_constrained_billboard(double3 const& objectPosition, double3 const& cameraPosition, double3 const& rotateAxis, double3 const& cameraForwardVector, double3 const& objectForwardVector) noexcept;
	double4x4 make_double4x4_translation(double3 const& position) noexcept;
	double4x4 make_double4x4_translation(double const xPosition, double const yPosition, double const zPosition) noexcept;
	double4x4 make_double4x4_scale(double const xScale, double const yScale, double const zScale) noexcept;
	double4x4 make_double4x4_scale(double const xScale, double const yScale, double const zScale, double3 const& centerPoint) noexcept;
	double4x4 make_double4x4_scale(double3 const& scales) noexcept;
	double4x4 make_double4x4_scale(double3 const& scales, double3 const& centerPoint) noexcept;
	double4x4 make_double4x4_scale(double const scale) noexcept;
	double4x4 make_double4x4_scale(double const scale, double3 const& centerPoint) noexcept;
	double4x4 make_double4x4_rotation_x(double const radians) noexcept;
	double4x4 make_double4x4_rotation_x(double const radians, double3 const& centerPoint) noexcept;
	double4x4 make_double4x4_rotation_y(double const radians) noexcept;
	double4x4 make_double4x4_rotation_y(double const radians, double3 const& centerPoint) noexcept;
	double4x4 make_double4x4_rotation_z(double const radians) noexcept;
	double4x4 make_double4x4_rotation_z(double const radians, double3 const& centerPoint) noexcept;
	double4x4 make_double4x4_from_axis_angle(double3 const& axis, double const acos) noexcept;
	double4x4 make_double4x4_perspective_field_of_view(double const fieldOfView, double const aspectRatio, double const nearplaneDistance, double const farplaneDistance);
	double4x4 make_double4x4_perspective(double const width, double const height, double const nearplaneDistance, double const farplaneDistance);
	double4x4 make_double4x4_perspective_off_center(double const left, double const right, double const bottom, double const top, double const nearplaneDistance, double const farplaneDistance);
	double4x4 make_double4x4_orthographic(double const width, double const height, double const zNearplane, double const zFarplane) noexcept;
	double4x4 make_double4x4_orthographic_off_center(double const left, double const right, double const bottom, double const top, double const zNearplane, double const zFarplane) noexcept;
	double4x4 make_double4x4_look_at(double3 const& cameraPosition, double3 const& cameraTarget, double3 const& cameraUpVector) noexcept;
	double4x4 make_double4x4_world(double3 const& position, double3 const& forward, double3 const& up) noexcept;
	double4x4 make_double4x4_from_quaternion(quaterniond const& quaterniond) noexcept;
	double4x4 make_double4x4_from_yaw_pitch_roll(double const yaw, double const pitch, double const roll) noexcept;
	double4x4 make_double4x4_shadow(double3 const& lightDirection, planed const& planed) noexcept;
	double4x4 make_double4x4_reflection(planed const& value) noexcept;

	struct double4x4
	{
		constexpr static double4x4 identity() noexcept;

		constexpr double4x4(double const m11 = 0.0f, double const m12 = 0.0f, double const m13 = 0.0f, double const m14 = 0.0f,
						   double const m21 = 0.0f, double const m22 = 0.0f, double const m23 = 0.0f, double const m24 = 0.0f, 
						   double const m31 = 0.0f, double const m32 = 0.0f, double const m33 = 0.0f, double const m34 = 0.0f,
						   double const m41 = 0.0f, double const m42 = 0.0f, double const m43 = 0.0f, double const m44 = 0.0f) noexcept;
		constexpr double4x4(double4 const& r1, double4 const& r2 = double4::zero(), double4 const& r3 = double4::zero(), double4 const& r4 = double4::zero()) noexcept;
		constexpr explicit double4x4(double3x2 const& value) noexcept;

		bool is_identity() const noexcept;
		double determinant() const noexcept;
		double3 translation() const noexcept;
		bool invert(double4x4* const result) noexcept;
		bool decompose(double3* const scale, quaterniond* rotation, double3* const translation) const noexcept;
		double4x4 transform(quaterniond const& rotation) const noexcept;
		double4x4 transpose() const noexcept;
		double4x4 lerp(double4x4 const& matrix2, double const amount) const noexcept;

		double4& operator[](unsigned int const i) noexcept;
		const double4& operator[](unsigned int const i) const noexcept;

		union
		{
			struct
			{
				double m11, m12, m13, m14;
				double m21, m22, m23, m24;
				double m31, m32, m33, m34;
				double m41, m42, m43, m44;
			};
			struct
			{
				double4 r1;
				double4 r2;
				double4 r3;
				double4 r4;
			};
			double m[4][4];
			double value[16];
			double4 data[4];
			double4 row[4];
		};
	};

	constexpr planed operator+(planed const& value) noexcept;
	constexpr planed operator-(planed const& value) noexcept;
	constexpr bool operator==(planed const& value1, planed const& value2) noexcept;
	constexpr bool operator!=(planed const& value1, planed const& value2) noexcept;

	planed normalize(planed const& value) noexcept;
	planed transform(planed const& planed, double4x4 const& matrix) noexcept;
	planed transform(planed const& planed, quaterniond const& rotation) noexcept;
	double3 one_point_on(planed const& planed) noexcept;
	double dot(planed const& planed, double4 const& value) noexcept;
	double dot_coordinate(planed const& planed, double3 const& value) noexcept;
	double dot_normal(planed const& planed, double3 const& value) noexcept;
	bool is_antarafacial(planed const& value1, double3 const& value2) noexcept;

	planed make_plane_from_vertices(double3 const& point1, double3 const& point2, double3 const& point3) noexcept;

	struct planed
	{
		constexpr planed(double const x = 0.0f, double const y = 0.0f, double const z = 0.0f, double const d = 0.0f) noexcept;
		constexpr explicit planed(double3 const& normal, double const d) noexcept;
		constexpr explicit planed(double4 const& value) noexcept;
		constexpr explicit planed(quaterniond const& value) noexcept;

		planed normalize() const noexcept;
		planed transform(double4x4 const& matrix) const noexcept;
		planed transform(quaterniond const& rotation) const noexcept;
		double3 one_point_on() const noexcept;
		double dot(double4 const& value) const noexcept;
		double dot_coordinate(double3 const& value) const noexcept;
		double dot_normal(double3 const& value) const noexcept;

		double& operator[](unsigned int const i) noexcept;
		const double& operator[](unsigned int const i) const noexcept;

		union
		{
			struct { double a; double b; double c; double d; };
			double3 normal;
			double value[4];
			double data[4];
		};
	};

	constexpr quaterniond operator+(quaterniond const& value1, quaterniond const& value2) noexcept;
	constexpr quaterniond operator-(quaterniond const& value1, quaterniond const& value2) noexcept;
	constexpr quaterniond operator*(quaterniond const& value1, quaterniond const& value2) noexcept;
	constexpr quaterniond operator*(quaterniond const& value1, double const value2) noexcept;
	constexpr quaterniond operator*(double const value1, quaterniond const& value2) noexcept;
	constexpr quaterniond operator/(quaterniond const& value1, quaterniond const& value2) noexcept;
	constexpr quaterniond operator/(quaterniond const& value1, double const value2) noexcept;
	constexpr quaterniond operator+(quaterniond const& value) noexcept;
	constexpr quaterniond operator-(quaterniond const& value) noexcept;
	constexpr quaterniond& operator+=(quaterniond& value1, quaterniond const& value2) noexcept;
	constexpr quaterniond& operator-=(quaterniond& value1, quaterniond const& value2) noexcept;
	constexpr quaterniond& operator*=(quaterniond& value1, quaterniond const& value2) noexcept;
	constexpr quaterniond& operator*=(quaterniond& value1, double const value2) noexcept;
	constexpr quaterniond& operator/=(quaterniond& value1, quaterniond const& value2) noexcept;
	constexpr quaterniond& operator/=(quaterniond& value1, double const value2) noexcept;
	constexpr bool operator==(quaterniond const& value1, quaterniond const& value2) noexcept;
	constexpr bool operator!=(quaterniond const& value1, quaterniond const& value2) noexcept;

	bool is_identity(quaterniond const& value) noexcept;
	double length(quaterniond const& value) noexcept;
	double length_squared(quaterniond const& value) noexcept;
	double dot(quaterniond const& quaternion1, quaterniond const& quaternion2) noexcept;
	quaterniond normalize(quaterniond const& value) noexcept;
	quaterniond conjugate(quaterniond const& value) noexcept;
	quaterniond inverse(quaterniond const& value) noexcept;
	quaterniond slerp(quaterniond const& quaternion1, quaterniond const& quaternion2, double const amount) noexcept;
	quaterniond lerp(quaterniond const& quaternion1, quaterniond const& quaternion2, double const amount) noexcept;
	quaterniond concatenate(quaterniond const& value1, quaterniond const& value2) noexcept;

	quaterniond make_quaternion_from_axis_angle(double3 const& axis, double const acos) noexcept;
	quaterniond make_quaternion_from_yaw_pitch_roll(double const yaw, double const pitch, double const roll) noexcept;
	quaterniond make_quaternion_from_rotation_matrix(double4x4 const& matrix) noexcept;

	struct quaterniond
	{
		constexpr static quaterniond identity() noexcept;

		constexpr quaterniond(double const x = 0.0f, double const y = 0.0f, double const z = 0.0f, double const w = 0.0f) noexcept;
		constexpr explicit quaterniond(double2 const& value, double const z = 0.0f, double const w = 0.0f) noexcept;
		constexpr explicit quaterniond(double3 const& value, double const w = 0.0f) noexcept;
		constexpr explicit quaterniond(double4 const& value) noexcept;
		constexpr explicit quaterniond(planed const& value) noexcept;
		constexpr explicit quaterniond(double const value = 0.0f) noexcept;

		bool is_identity() const noexcept;
		double length() const noexcept;
		double length_squared() const noexcept;
		double dot(quaterniond const& quaternion2) const noexcept;
		quaterniond normalize() const noexcept;
		quaterniond conjugate() const noexcept;
		quaterniond inverse() const noexcept;
		quaterniond slerp(quaterniond const& quaternion2, double const amount) const noexcept;
		quaterniond lerp(quaterniond const& quaternion2, double const amount) const noexcept;
		quaterniond concatenate(quaterniond const& value2) const noexcept;

		double& operator[](unsigned int const i) noexcept;
		const double& operator[](unsigned int const i) const noexcept;

		union
		{
			struct { double x; double y; double z; double w; };
			struct { double X; double Y; double Z; double W; };
			double value[4];
			double data[4];
		};
	};

	bool is_parallel(double2x2 const& value1, double2x2 const& value2) noexcept;
	bool is_intersecting(double2x2 const& value1, double2x2 const& value2) noexcept;
	double2 intersection(double2x2 const& value1, double2x2 const& value2) noexcept;

	struct double2x2
	{
		constexpr double2x2(double const x1 = 0.0f, double const y1 = 0.0f, double const x2 = 0.0f, double const y2 = 0.0f) noexcept;
		constexpr double2x2(double2 const& value1, double2 const& value2) noexcept;
		constexpr explicit double2x2(double4 const& value) noexcept;

		constexpr static double2x2 zero() noexcept;
		constexpr static double2x2 one() noexcept;
		constexpr static double2x2 unit_x() noexcept;
		constexpr static double2x2 unit_y() noexcept;

		bool is_parallel(double2x2 const& value2) const noexcept;
		bool is_intersecting(double2x2 const& value2) const noexcept;
		double2 intersection(double2x2 const& value2) const noexcept;

		double2& operator[](unsigned int const i) noexcept;
		const double2& operator[](unsigned int const i) const noexcept;

		union
		{
			struct { double x1; double y1; double x2; double y2; };
			struct { double2 p; double2 v; };
			double value[4];
			double2 data[2];
		};
	};

	bool is_parallel(double2x3 const& value1, double2x3 const& value2) noexcept;
	bool is_antarafacial(double2x3 const& value1, double2x3 const& value2) noexcept;
	bool is_intersecting(double2x3 const& value1, double2x3 const& value2) noexcept;
	double3 intersection(double2x3 const& value1, double2x3 const& value2) noexcept;

	struct double2x3
	{
		constexpr double2x3(double const x1 = 0.0f, double const y1 = 0.0f, double const z1 = 0.0f,
						double const x2 = 0.0f, double const y2 = 0.0f, double const z2 = 0.0f) noexcept;
		constexpr double2x3(double3 const& value1, double3 const& value2) noexcept;

		constexpr static double2x3 zero() noexcept;
		constexpr static double2x3 one() noexcept;
		constexpr static double2x3 unit_x() noexcept;
		constexpr static double2x3 unit_y() noexcept;
		constexpr static double2x3 unit_z() noexcept;

		bool is_parallel(double2x3 const& value2) const noexcept;
		bool is_antarafacial(double2x3 const& value2) const noexcept;
		bool is_intersecting(double2x3 const& value2) const noexcept;
		double3 intersection(double2x3 const& value2) const noexcept;

		double3& operator[](unsigned int const i) noexcept;
		const double3& operator[](unsigned int const i) const noexcept;

		union
		{
			struct { double x1; double y1;; double z1; double x2; double y2; ; double z2; };
			struct { double3 p; double3 v; };
			double value[6];
			double3 data[2];
		};
	};

	::std::ostream& operator<<(::std::ostream& os, double2 const& value) noexcept;
	::std::ostream& operator<<(::std::ostream& os, double3 const& value) noexcept;
	::std::ostream& operator<<(::std::ostream& os, double4 const& value) noexcept;
	::std::ostream& operator<<(::std::ostream& os, double3x2 const& value) noexcept;
	::std::ostream& operator<<(::std::ostream& os, double4x4 const& value) noexcept;
	::std::ostream& operator<<(::std::ostream& os, planed const& value) noexcept;
	::std::ostream& operator<<(::std::ostream& os, quaterniond const& value) noexcept;
	::std::ostream& operator<<(::std::ostream& os, double2x2 const& value) noexcept;
	::std::ostream& operator<<(::std::ostream& os, double2x3 const& value) noexcept;
}