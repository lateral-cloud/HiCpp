/**
 * @file	fps.h
 * @brief	HiCxx µÄÖ¡ÂÊÄ£¿é
 * @author	²àÔÆ
*/

#include "fps.h"

namespace HiCxx
{
	void fps_manager::set_fps(FpsT fps) noexcept
	{
		new(&this->m_duration) DurationT{ (intmax_t)(den / fps) };
	}

	void fps_manager::start() noexcept
	{
		this->m_time_point = ClockT::now();
	}

	fps_manager::StateT fps_manager::is_over_time() const noexcept
	{
		return ClockT::now() >= (this->m_time_point + 2 * this->m_duration);
	}

	fps_manager::StateT fps_manager::sleep() noexcept
	{
		this->m_time_point += this->m_duration;
		if (ClockT::now() >= this->m_time_point + this->m_duration)
			return false;

		::std::this_thread::sleep_until(this->m_time_point);
		return true;
	}

	void fps_supervisor::start() noexcept
	{
		this->m_count = 0;
		this->m_stop_time_point = {};
		this->m_start_time_point = ClockT::now();
	}

	void fps_supervisor::stop() noexcept
	{
		this->m_stop_time_point = ClockT::now();
	}

	const fps_supervisor::TimePointT& fps_supervisor::get_start_time_point() const noexcept
	{
		return this->m_start_time_point;
	}

	const fps_supervisor::TimePointT& fps_supervisor::get_stop_time_point() const noexcept
	{
		return this->m_stop_time_point;
	}

	void fps_supervisor::check() noexcept
	{
		++this->m_count;
	}

	intmax_t fps_supervisor::get_count() const noexcept
	{
		return this->m_count;
	}

	fps_supervisor::FpsT fps_supervisor::get_fps() const noexcept
	{
		if (this->m_stop_time_point == TimePointT{})
			return ((FpsT)(den * this->m_count)) / (ClockT::now() - this->m_start_time_point).count();
		
		return (FpsT)(den * this->m_count) / (this->m_stop_time_point - this->m_start_time_point).count();
	}
}