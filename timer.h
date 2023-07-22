/**
 * @file	timer.h
 * @brief	HiCxx 的计时器模块
 * @author	侧云
*/

#pragma once

#include <chrono>
#include <vector>

namespace HiCxx
{
	class timer
	{
	public:
		using ClockT			= ::std::chrono::steady_clock;
		using DurationT			= ClockT::duration;
		using TimePointT		= ClockT::time_point;
		using RecordVectorT		= ::std::vector<TimePointT>;

	protected:
		DurationT get_duration_unchecked() const noexcept;
		DurationT get_last_duration_unchecked() const noexcept;
		DurationT get_average_duration_unchecked() const noexcept;

	public:
		void record() noexcept;
		void reset() noexcept;
		size_t get_records_num() const noexcept;
		DurationT get_duration() const noexcept;
		DurationT get_last_duration() const noexcept;
		DurationT get_average_duration() const noexcept;
		const RecordVectorT& get_records() const noexcept;

	protected:
		RecordVectorT m_records;
	};
}