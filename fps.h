/**
 * @file	fps.h
 * @brief	HiCxx 的帧率模块
 * @author	侧云
*/

#pragma once

#include <thread>

namespace HiCxx
{
	class fps_manager
	{
	public:
		using ClockT					= ::std::chrono::steady_clock;
		using DurationT					= ClockT::duration;
		using TimePointT				= ClockT::time_point;
		using PeriodT					= ClockT::period;
		using FpsT						= double;
		using StateT					= bool;
		static constexpr intmax_t den	= PeriodT::den;

		void set_fps(FpsT fps) noexcept;
		void start() noexcept;
		StateT is_over_time() const noexcept;
		StateT sleep() noexcept;

	protected:
		TimePointT	m_time_point;
		DurationT	m_duration;
	};

	/**
	* @note
	*		检查次数与真实帧率比值		检查帧率与真实帧率比值
	*		1:100						0.818
	*		1:50						0.873
	*		1:20						0.924
	*		1:10						0.961
	*		1:5							0.984
	*		1:2							0.993
	*		1:1							0.996
	*		2:1							0.999
	*/
	class fps_supervisor
	{
	public:
		using ClockT					= ::std::chrono::steady_clock;
		using DurationT					= ClockT::duration;
		using TimePointT				= ClockT::time_point;
		using PeriodT					= ClockT::period;
		using FpsT						= double;
		using StateT					= bool;
		static constexpr intmax_t den	= PeriodT::den;

		void start() noexcept;
		void stop() noexcept;
		const TimePointT& get_start_time_point() const noexcept;
		const TimePointT& get_stop_time_point() const noexcept;
		void check() noexcept;
		intmax_t get_count() const noexcept;
		FpsT get_fps() const noexcept;

	protected:
		TimePointT	m_start_time_point;
		TimePointT	m_stop_time_point;
		intmax_t	m_count;
	};
}