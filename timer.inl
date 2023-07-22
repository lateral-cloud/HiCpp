/**
 * @file	timer.inl
 * @brief	HiCxx 的计时器模块
 * @author	侧云
*/

#include "timer.h"

namespace HiCxx
{
	timer::DurationT timer::get_duration_unchecked() const noexcept
	{
		return this->m_records.back() - this->m_records.front();
	}

	timer::DurationT timer::get_last_duration_unchecked() const noexcept
	{
		return this->m_records.back() - *(this->m_records.end() - 2);
	}

	timer::DurationT timer::get_average_duration_unchecked() const noexcept
	{
		return this->get_duration_unchecked() / this->get_records_num();
	}

	void timer::record() noexcept
	{
		this->m_records.push_back(ClockT::now());
	}

	void timer::reset() noexcept
	{
		this->m_records.clear();
	}

	size_t timer::get_records_num() const noexcept
	{
		return this->m_records.size();
	}

	timer::DurationT timer::get_duration() const noexcept
	{
		if (this->m_records.empty())
			return {};

		return this->get_duration_unchecked();
	}

	timer::DurationT timer::get_last_duration() const noexcept
	{
		if (this->m_records.size() < 2)
			return {};
		
		return this->get_last_duration_unchecked();
	}

	timer::DurationT timer::get_average_duration() const noexcept
	{
		if (this->m_records.empty())
			return {};

		return this->get_average_duration_unchecked();
	}

	const timer::RecordVectorT& timer::get_records() const noexcept
	{
		return this->m_records;
	}
}