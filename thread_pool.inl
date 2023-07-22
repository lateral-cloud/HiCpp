/**
 * @file	thread_pool.inl
 * @brief	HiCxx 的线程队列模块
 * @author	侧云
*/

#include "thread_pool.h"

namespace HiCxx
{
	constexpr bool thread_pool_public::TaskT::operator<(const TaskT& task) const noexcept
	{
		return this->m_priority < task.m_priority;
	}

	constexpr bool thread_pool_public::TaskT::operator>(const TaskT& task) const noexcept
	{
		return this->m_priority > task.m_priority;
	}

	inline thread_pool_public::thread_pool_public(ThreadNumT threads_num) noexcept
	{
		this->start_unchecked(threads_num);
	}

	inline thread_pool_public::~thread_pool_public() noexcept
	{
		this->stop();
	}

	inline void thread_pool_public::resume_unchecked() noexcept
	{
		this->m_state_manager.m_pausing = false;
		this->m_mutex_manager.m_pause_condition.notify_all();
	}

	inline void thread_pool_public::pause_no_wait_unchecked() noexcept
	{
		this->m_state_manager.m_pausing = true;
		this->m_mutex_manager.m_task_condition.notify_all();
	}

	inline void thread_pool_public::pause_unchecked() noexcept
	{
		this->pause_no_wait_unchecked();
		while (this->m_datas_manager.m_running_num)
		{
			std::this_thread::yield();
		}
	}

	inline void thread_pool_public::start_unchecked(ThreadNumT threads_num) noexcept
	{
		this->m_state_manager.m_stopped = false;
		this->resume_unchecked();
		this->set_threads_num_no_wait_unchecked(threads_num);
	}

	inline void thread_pool_public::stop_no_wait_unchecked() noexcept
	{
		this->m_state_manager.m_stopped = true;
		this->m_mutex_manager.m_task_condition.notify_all();
		this->m_mutex_manager.m_pause_condition.notify_all();
		this->m_mutex_manager.m_wait_condition.notify_all();
		this->clear_unchecked();
	}

	inline void thread_pool_public::stop_unchecked() noexcept
	{
		this->m_state_manager.m_stopped = true;
		this->m_mutex_manager.m_task_condition.notify_all();
		this->m_mutex_manager.m_pause_condition.notify_all();
		this->m_mutex_manager.m_wait_condition.notify_all();
		while (this->m_datas_manager.m_running_num)
		{
			std::this_thread::yield();
		}
		this->clear_unchecked();
	}

	inline void thread_pool_public::clear_unchecked() noexcept
	{
		this->m_datas_manager.m_threads.clear();
		this->m_datas_manager.m_tasks.clear();
	}

	inline void thread_pool_public::set_threads_num_no_wait_unchecked(ThreadNumT threads_num) noexcept
	{
		if (threads_num < this->m_datas_manager.m_threads_num)
		{
			const ThreadNumT delta = this->m_datas_manager.m_threads_num - threads_num;
			this->m_datas_manager.m_threads_num = threads_num;
			this->m_datas_manager.m_delete_num = delta;
			this->m_mutex_manager.m_task_condition.notify_all();
			this->m_mutex_manager.m_pause_condition.notify_all();
		}
		else if (threads_num > this->m_datas_manager.m_threads_num)
		{
			ThreadNumT i = this->m_datas_manager.m_threads_num;
			this->m_datas_manager.m_threads_num = threads_num;
			for (; i < threads_num; ++i)
			{
				ThreadPtrT ptr = new ThreadPackT{};
				ptr->m_thread = ThreadT{ &thread_pool_public::mission, this, ptr };
				ptr->m_enable = true;
				this->m_datas_manager.m_threads[ptr->m_thread.get_id()] = ptr;
			}
		}
	}

	inline void thread_pool_public::set_threads_num_unchecked(ThreadNumT threads_num) noexcept
	{
		bool wait = threads_num < this->m_datas_manager.m_threads_num;
		this->set_threads_num_no_wait_unchecked(threads_num);
		if(wait)
			while (this->m_datas_manager.m_delete_num)
				std::this_thread::yield();
	}

	inline void thread_pool_public::set_multi_unchecked(bool multi) noexcept
	{
		this->m_state_manager.m_multi = multi;
	}

	inline void thread_pool_public::set_try_mode_unchecked(bool try_mode) noexcept
	{
		this->m_state_manager.m_try_mode = try_mode;
	}

	inline bool thread_pool_public::resume() noexcept
	{
		if (this->m_state_manager.m_stopped || !this->m_state_manager.m_pausing)
			return false;

		if (this->m_state_manager.m_multi)
		{
			LockGuardT lock(this->m_mutex_manager.m_mutex);
			this->resume_unchecked();
		}
		else
		{
			this->resume_unchecked();
		}
		return true;
	}

	inline bool thread_pool_public::pause_no_wait() noexcept
	{
		if (this->m_state_manager.m_stopped || this->m_state_manager.m_pausing)
			return false;

		if (this->m_state_manager.m_multi)
		{
			LockGuardT lock(this->m_mutex_manager.m_mutex);
			this->pause_no_wait_unchecked();
		}
		else
		{
			this->pause_no_wait_unchecked();
		}
		return true;
	}

	inline bool thread_pool_public::pause() noexcept
	{
		if (this->m_state_manager.m_stopped || this->m_state_manager.m_pausing)
			return false;

		if (this->m_state_manager.m_multi)
		{
			LockGuardT lock(this->m_mutex_manager.m_mutex);
			this->pause_unchecked();
		}
		else
		{
			this->pause_unchecked();
		}
		return true;
	}

	inline bool thread_pool_public::start(ThreadNumT threads_num) noexcept
	{
		if (!this->m_state_manager.m_stopped)
			return false;

		if (this->m_state_manager.m_multi)
		{
			LockGuardT lock(this->m_mutex_manager.m_mutex);
			this->start_unchecked(threads_num);
		}
		else
		{
			this->start_unchecked(threads_num);
		}
		return true;
	}

	inline bool thread_pool_public::stop_no_wait() noexcept
	{
		if (this->m_state_manager.m_stopped)
			return false;

		if (this->m_state_manager.m_multi)
		{
			LockGuardT lock(this->m_mutex_manager.m_mutex);
			this->stop_no_wait_unchecked();
		}
		else
		{
			this->stop_no_wait_unchecked();
		}
		return true;
	}

	inline bool thread_pool_public::stop() noexcept
	{
		if (this->m_state_manager.m_stopped)
			return false;

		if (this->m_state_manager.m_multi)
		{
			LockGuardT lock(this->m_mutex_manager.m_mutex);
			this->stop_unchecked();
		}
		else
		{
			this->stop_unchecked();
		}
		return true;
	}

	inline bool thread_pool_public::set_threads_num_no_wait(ThreadNumT threads_num) noexcept
	{
		if (this->m_state_manager.m_stopped)
			return false;

		if (this->m_state_manager.m_multi)
		{
			LockGuardT lock(this->m_mutex_manager.m_mutex);
			this->set_threads_num_no_wait_unchecked(threads_num);
		}
		else
		{
			this->set_threads_num_no_wait_unchecked(threads_num);
		}
		return true;
	}

	inline bool thread_pool_public::set_threads_num(ThreadNumT threads_num) noexcept
	{
		if (this->m_state_manager.m_stopped)
			return false;
		
		if (this->m_state_manager.m_multi)
		{
			LockGuardT lock(this->m_mutex_manager.m_mutex);
			this->set_threads_num_unchecked(threads_num);
		}
		else
		{
			this->set_threads_num_unchecked(threads_num);
		}

		return true;
	}

	inline void thread_pool_public::set_multi(bool multi) noexcept
	{
		if (this->m_state_manager.m_multi)
		{
			LockGuardT lock(this->m_mutex_manager.m_mutex);
			this->set_multi_unchecked(multi);
		}
		else
		{
			this->set_multi_unchecked(multi);
		}
	}

	inline void thread_pool_public::set_try_mode(bool try_mode) noexcept
	{
		if (this->m_state_manager.m_multi)
		{
			LockGuardT lock(this->m_mutex_manager.m_mutex);
			this->set_try_mode_unchecked(try_mode);
		}
		else
		{
			this->set_try_mode_unchecked(try_mode);
		}
	}

	inline thread_pool_public::MutexManagerT& thread_pool_public::get_mutex_manager_unchecked() noexcept
	{
		return this->m_mutex_manager;
	}

	inline thread_pool_public::DatasManagerT& thread_pool_public::get_datas_manager_unchecked() noexcept
	{
		return this->m_datas_manager;
	}

	inline thread_pool_public::StateManagerT& thread_pool_public::get_state_manager_unchecked() noexcept
	{
		return this->m_state_manager;
	}

	inline const thread_pool_public::MutexManagerT& thread_pool_public::get_mutex_manager_unchecked() const noexcept
	{
		return this->m_mutex_manager;
	}

	inline const thread_pool_public::DatasManagerT& thread_pool_public::get_datas_manager_unchecked() const noexcept
	{
		return this->m_datas_manager;
	}

	inline const thread_pool_public::StateManagerT& thread_pool_public::get_state_manager_unchecked() const noexcept
	{
		return this->m_state_manager;
	}

	inline thread_pool_public::MutexManagerT& thread_pool_public::get_mutex_manager() noexcept
	{
		return this->m_mutex_manager;
	}

	inline thread_pool_public::DatasManagerT& thread_pool_public::get_datas_manager() noexcept
	{
		return this->get_datas_manager_unchecked();
	}

	inline thread_pool_public::StateManagerT& thread_pool_public::get_state_manager() noexcept
	{
		return this->get_state_manager_unchecked();
	}

	inline const thread_pool_public::MutexManagerT& thread_pool_public::get_mutex_manager() const noexcept
	{
		return this->get_mutex_manager_unchecked();
	}

	inline const thread_pool_public::DatasManagerT& thread_pool_public::get_datas_manager() const noexcept
	{
		return this->get_datas_manager_unchecked();
	}

	inline const thread_pool_public::StateManagerT& thread_pool_public::get_state_manager() const noexcept
	{
		return this->get_state_manager_unchecked();
	}

	inline thread_pool_public::ThreadNumT thread_pool_public::get_tasks_num_unchecked() const noexcept
	{
		return (ThreadNumT)this->m_datas_manager.m_tasks.size();
	}

	inline thread_pool_public::ThreadNumT thread_pool_public::get_tasks_num() noexcept
	{
		if (this->m_state_manager.m_multi)
		{
			LockGuardT lock(this->m_mutex_manager.m_mutex);
			return this->get_tasks_num_unchecked();
		}
		else
		{
			return this->get_tasks_num_unchecked();
		}
	}

	inline bool thread_pool_public::is_all_done_unchecked() const noexcept
	{
		return (this->m_datas_manager.m_running_num == 0) && (this->m_datas_manager.m_tasks.empty());
	}

	inline bool thread_pool_public::is_all_done() noexcept
	{
		if (this->m_state_manager.m_multi)
		{
			LockGuardT lock(this->m_mutex_manager.m_mutex);
			return this->is_all_done_unchecked();
		}
		else
		{
			return this->is_all_done_unchecked();
		}
	}

	inline void thread_pool_public::wait_all_done_unchecked(bool wait_when_stop) noexcept
	{
		UniqueLockT lock(this->m_mutex_manager.m_mutex);
		this->m_mutex_manager.m_wait_condition.wait(lock,
			[this, wait_when_stop]() { return (wait_when_stop && this->m_state_manager.m_stopped) || this->is_all_done_unchecked(); });
	}

	template<class _TTimePoint>
	inline bool thread_pool_public::wait_until_all_done_unchecked(const _TTimePoint& time_point, bool wait_when_stop) noexcept
	{
		UniqueLockT lock(this->m_mutex_manager.m_mutex);
		return (bool)this->m_mutex_manager.m_wait_condition.wait_until(lock, time_point,
			[this, wait_when_stop]() { return (wait_when_stop && this->m_state_manager.m_stopped) || this->is_all_done_unchecked(); });
	}

	template<class _TDuration>
	inline bool thread_pool_public::wait_for_all_done_unchecked(const _TDuration& duration, bool wait_when_stop) noexcept
	{
		UniqueLockT lock(this->m_mutex_manager.m_mutex);
		return (bool)this->m_mutex_manager.m_wait_condition.wait_for(lock, duration,
			[this, wait_when_stop]() { return (wait_when_stop && this->m_state_manager.m_stopped) || this->is_all_done_unchecked(); });
	}

	inline void thread_pool_public::wait_all_done(bool wait_when_stop) noexcept
	{
		if (wait_when_stop && this->m_state_manager.m_stopped)
			return;

		this->wait_all_done_unchecked();
	}

	template<class _TTimePoint>
	inline bool thread_pool_public::wait_until_all_done(const _TTimePoint& time_point, bool wait_when_stop) noexcept
	{
		if (wait_when_stop && this->m_state_manager.m_stopped)
			return true;

		return this->wait_until_all_done_unchecked(time_point, wait_when_stop);
	}

	template<class _TDuration>
	inline bool thread_pool_public::wait_for_all_done(const _TDuration& duration, bool wait_when_stop) noexcept
	{
		if (wait_when_stop && this->m_state_manager.m_stopped)
			return true;

		return this->wait_for_all_done_unchecked(duration, wait_when_stop);
	}

	template<class _TFunc, class..._TArgs>
	inline auto thread_pool_public::submit_unchecked(const TimePointT& expiration_time, PriorityT priority, bool submit_on_expiration, _TFunc&& function, _TArgs&&... args) noexcept
		-> FutureT<decltype(::std::forward<_TFunc>(function)(::std::forward<_TArgs>(args)...))>
	{
		using ReturnT = decltype(::std::forward<_TFunc>(function)(::std::forward<_TArgs>(args)...));
		auto task = ::std::make_shared<PackagedTaskT<ReturnT>>(::std::bind(::std::forward<_TFunc>(function), ::std::forward<_TArgs>(args)...));
		this->m_datas_manager.m_tasks.insert({ expiration_time, priority, submit_on_expiration, [task]() { (*task)(); } });
		this->m_mutex_manager.m_task_condition.notify_one();
		return task->get_future();
	}

	template<class _TFunc, class..._TArgs>
	inline auto thread_pool_public::submit_unchecked(const DurationT& expiration_time_length, PriorityT priority, bool submit_on_expiration, _TFunc&& function, _TArgs&&... args) noexcept
		-> FutureT<decltype(::std::forward<_TFunc>(function)(::std::forward<_TArgs>(args)...))>
	{
		using ReturnT = decltype(::std::forward<_TFunc>(function)(::std::forward<_TArgs>(args)...));
		auto task = ::std::make_shared<PackagedTaskT<ReturnT>>(::std::bind(::std::forward<_TFunc>(function), ::std::forward<_TArgs>(args)...));
		this->m_datas_manager.m_tasks.insert({ (submit_on_expiration ? TimePointT{} : (::std::chrono::steady_clock::now() + expiration_time_length)), priority,
			submit_on_expiration, [task]() { (*task)(); } });
		this->m_mutex_manager.m_task_condition.notify_one();
		return task->get_future();
	}

	template<class _TFunc, class..._TArgs>
	inline auto thread_pool_public::submit(const TimePointT& expiration_time, PriorityT priority, bool submit_on_expiration, _TFunc&& function, _TArgs&&... args) noexcept
		-> FutureT<decltype(::std::forward<_TFunc>(function)(::std::forward<_TArgs>(args)...))>
	{
		if (this->m_state_manager.m_multi)
		{
			LockGuardT lock(m_mutex_manager.m_mutex);
			return this->submit_unchecked(expiration_time, priority, submit_on_expiration, ::std::forward<_TFunc>(function), ::std::forward<_TArgs>(args)...);
		}
		else
		{
			return this->submit_unchecked(expiration_time, priority, submit_on_expiration, ::std::forward<_TFunc>(function), ::std::forward<_TArgs>(args)...);
		}
	}

	template<class _TFunc, class..._TArgs>
	inline auto thread_pool_public::submit(const DurationT& expiration_time_length, PriorityT priority, bool submit_on_expiration, _TFunc&& function, _TArgs&&... args) noexcept
		-> FutureT<decltype(::std::forward<_TFunc>(function)(::std::forward<_TArgs>(args)...))>
	{
		if (this->m_state_manager.m_multi)
		{
			LockGuardT lock(m_mutex_manager.m_mutex);
			return this->submit_unchecked(expiration_time_length, priority, submit_on_expiration, ::std::forward<_TFunc>(function), ::std::forward<_TArgs>(args)...);
		}
		else
		{
			return this->submit_unchecked(expiration_time_length, priority, submit_on_expiration, ::std::forward<_TFunc>(function), ::std::forward<_TArgs>(args)...);
		}
	}

	template<class _TFunc, class..._TArgs>
	inline auto thread_pool_public::submit(const TimePointT& expiration_time, PriorityT priority, _TFunc&& function, _TArgs&&... args) noexcept
		-> FutureT<decltype(::std::forward<_TFunc>(function)(::std::forward<_TArgs>(args)...))>
	{
		return this->submit(expiration_time, priority, false, ::std::forward<_TFunc>(function), ::std::forward<_TArgs>(args)...);
	}

	template<class _TFunc, class..._TArgs>
	inline auto thread_pool_public::submit(const DurationT& expiration_time_length, PriorityT priority, _TFunc&& function, _TArgs&&... args) noexcept
		-> FutureT<decltype(::std::forward<_TFunc>(function)(::std::forward<_TArgs>(args)...))>
	{
		return this->submit(expiration_time_length, priority, false, ::std::forward<_TFunc>(function), ::std::forward<_TArgs>(args)...);
	}

	template<class _TFunc, class..._TArgs>
	inline auto thread_pool_public::submit(PriorityT priority, _TFunc&& function, _TArgs&&... args) noexcept
		-> FutureT<decltype(::std::forward<_TFunc>(function)(::std::forward<_TArgs>(args)...))>
	{
		return this->submit(TimePointT{}, priority, true, ::std::forward<_TFunc>(function), ::std::forward<_TArgs>(args)...);
	}

	template<class _TFunc, class..._TArgs>
	inline auto thread_pool_public::submit(_TFunc&& function, _TArgs&&... args) noexcept
		-> FutureT<decltype(::std::forward<_TFunc>(function)(::std::forward<_TArgs>(args)...))>
	{
		return this->submit(TimePointT{}, (PriorityT)0, true, ::std::forward<_TFunc>(function), ::std::forward<_TArgs>(args)...);
	}

	template<class..._TArgs>
	inline auto thread_pool_public::execute(_TArgs&&... args) noexcept
		->decltype(this->submit(::std::forward<_TArgs>(args)...))
	{
		return this->submit(::std::forward<_TArgs>(args)...);
	}

	inline bool thread_pool_public::get_task(TaskT& task) noexcept
	{
		if (this->m_state_manager.m_stopped || this->m_state_manager.m_pausing)
			return false;

		UniqueLockT lock(this->m_mutex_manager.m_mutex);
		if (this->m_datas_manager.m_tasks.empty())
			this->m_mutex_manager.m_task_condition.wait(lock, [this]() { return this->m_state_manager.m_stopped || this->m_state_manager.m_pausing || !this->m_datas_manager.m_tasks.empty(); });

		if (this->m_state_manager.m_stopped || this->m_state_manager.m_pausing)
			return false;

		auto ptr = this->m_datas_manager.m_tasks.begin();
		task = ::std::move(const_cast<TaskT&>(*ptr));
		this->m_datas_manager.m_tasks.erase(ptr);

		return true;
	}

	inline void thread_pool_public::mission(ThreadPtrT ptr) noexcept
	{
		TaskT task;
		while (!this->m_state_manager.m_stopped)
		{
			{
				if (this->m_datas_manager.m_delete_num)
				{
					LockGuardT lock(this->m_mutex_manager.m_mutex);
					this->m_datas_manager.m_threads.erase(ptr->m_thread.get_id());
					--this->m_datas_manager.m_delete_num;
				}
				if (this->m_state_manager.m_pausing)
				{
					UniqueLockT lock(this->m_mutex_manager.m_mutex);
					m_mutex_manager.m_pause_condition.wait(lock);
				}
			}
			if (this->get_task(task))
			{
				++this->m_datas_manager.m_running_num;
				if (this->m_state_manager.m_try_mode)
				{
					try
					{
						if (task.m_submit_on_expiration || ::std::chrono::steady_clock::now() <= task.m_expiration_time)
						{
							task.m_function();
						}
					}
					catch (const ::std::exception& exception)
					{
						const auto id = ptr->m_thread.get_id();
						::fprintf(stderr, "HiCxx: thread_pool_public[%d] caught exception\nwhat():%s\n", *(int*)(&id), exception.what());
					}
				}
				else
				{
					if (task.m_submit_on_expiration || ::std::chrono::steady_clock::now() <= task.m_expiration_time)
					{
						task.m_function();
					}
				}
				--this->m_datas_manager.m_running_num;
				if ((this->m_datas_manager.m_running_num == 0) && (this->m_datas_manager.m_tasks.empty()) || this->m_state_manager.m_pausing)
					this->m_mutex_manager.m_wait_condition.notify_all();
			}
			else if (!this->m_state_manager.m_stopped && !this->m_state_manager.m_pausing)
			{
				UniqueLockT lock(this->m_mutex_manager.m_mutex);
				this->m_mutex_manager.m_task_condition.wait(lock);
			}
		}
	}
}