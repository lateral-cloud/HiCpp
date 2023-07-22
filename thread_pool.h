/**
 * @file	thread_pool.h
 * @brief	HiCxx 的线程队列模块
 * @author	侧云
*/

#pragma once

#include <future>
#include <vector>
#include <set>
#include <unordered_map>

namespace HiCxx
{
	class thread_pool_public
	{
	public:
		using ThreadPoolT			= thread_pool_public;
		using ThreadNumT			= ::int32_t;
		using AtomicThreadNumT		= ::std::atomic<ThreadNumT>;
		using TaskNumT				= ::uint32_t;
		using ClockT				= ::std::chrono::steady_clock;
		using TimePointT			= ClockT::time_point;
		using DurationT				= ClockT::duration;
		using PriorityT				= int;
		using FuncionT				= ::std::function<void()>;
		using MutexT				= ::std::mutex;
		using ConditionVariableT	= ::std::condition_variable;
		template<class _Ret> using PackagedTaskT	= ::std::packaged_task<_Ret()>;
		template<class _Ret> using FutureT			= ::std::future<_Ret>;
		using UniqueLockT			= ::std::unique_lock<MutexT>;
		using LockGuardT			= ::std::lock_guard<MutexT>;

		struct TaskT;
		using TaskSetT				= ::std::multiset<TaskT, ::std::greater<TaskT>>;

		using ThreadT				= ::std::thread;
		struct ThreadPackT;
		using ThreadPtrT			= ThreadPackT*;
		using ThreadMapT			= ::std::unordered_map<ThreadT::id, ThreadPtrT>;
		
		struct ThreadPackT
		{
			ThreadT m_thread;
			bool m_enable;
		};
		struct TaskT
		{
			FuncionT	m_function{};
			TimePointT	m_expiration_time{};
			PriorityT	m_priority = 0;
			bool		m_submit_on_expiration = false;

			constexpr bool operator<(const TaskT& task) const noexcept;
			constexpr bool operator>(const TaskT& task) const noexcept;
		};
		
		struct MutexManagerT
		{
			MutexT				m_mutex;
			ConditionVariableT	m_task_condition;
			ConditionVariableT	m_wait_condition;
			ConditionVariableT	m_pause_condition;
		};
		struct DatasManagerT
		{
			ThreadMapT			m_threads;
			TaskSetT			m_tasks;
			AtomicThreadNumT	m_running_num = 0;
			ThreadNumT			m_threads_num = 0;
			AtomicThreadNumT	m_delete_num;
		};
		struct StateManagerT
		{
			bool				m_multi = false;
			bool				m_try_mode = true;
			bool				m_stopped = true;
			bool				m_pausing = false;
		};

		thread_pool_public() noexcept = default;
		thread_pool_public(ThreadNumT threads_num) noexcept;
		thread_pool_public(const ThreadPoolT& thread_pool) = delete;
		thread_pool_public(ThreadPoolT&& thread_pool) = delete;
		~thread_pool_public() noexcept;

		void resume_unchecked() noexcept;
		void pause_no_wait_unchecked() noexcept;
		void pause_unchecked() noexcept;
		void start_unchecked(ThreadNumT threads_num) noexcept;
		void stop_no_wait_unchecked() noexcept;
		void stop_unchecked() noexcept;
		void clear_unchecked() noexcept;

		void set_threads_num_no_wait_unchecked(ThreadNumT threads_num) noexcept;
		void set_threads_num_unchecked(ThreadNumT threads_num) noexcept;
		void set_multi_unchecked(bool multi) noexcept;
		void set_try_mode_unchecked(bool try_mode) noexcept;

		bool resume() noexcept;
		bool pause_no_wait() noexcept;
		bool pause() noexcept;
		bool start(ThreadNumT threads_num) noexcept;
		bool stop_no_wait() noexcept;
		bool stop() noexcept;

		bool set_threads_num_no_wait(ThreadNumT threads_num) noexcept;
		bool set_threads_num(ThreadNumT threads_num) noexcept;
		void set_multi(bool multi) noexcept;
		void set_try_mode(bool try_mode) noexcept;

		MutexManagerT& get_mutex_manager_unchecked() noexcept;
		DatasManagerT& get_datas_manager_unchecked() noexcept;
		StateManagerT& get_state_manager_unchecked() noexcept;
		const MutexManagerT& get_mutex_manager_unchecked() const noexcept;
		const DatasManagerT& get_datas_manager_unchecked() const noexcept;
		const StateManagerT& get_state_manager_unchecked() const noexcept;

		MutexManagerT& get_mutex_manager() noexcept;
		DatasManagerT& get_datas_manager() noexcept;
		StateManagerT& get_state_manager() noexcept;
		const MutexManagerT& get_mutex_manager() const noexcept;
		const DatasManagerT& get_datas_manager() const noexcept;
		const StateManagerT& get_state_manager() const noexcept;

		ThreadNumT get_tasks_num_unchecked() const noexcept;
		ThreadNumT get_tasks_num() noexcept;
		bool is_all_done_unchecked() const noexcept;
		bool is_all_done() noexcept;

		void wait_all_done_unchecked(bool wait_when_stop = false) noexcept;
		template<class _TTimePoint>
		bool wait_until_all_done_unchecked(const _TTimePoint& time_point, bool wait_when_stop = false) noexcept;
		template<class _TDuration>
		bool wait_for_all_done_unchecked(const _TDuration& duration, bool wait_when_stop = false) noexcept;

		void wait_all_done(bool wait_when_stop = false) noexcept;
		template<class _TTimePoint>
		bool wait_until_all_done(const _TTimePoint& time_point, bool wait_when_stop = false) noexcept;
		template<class _TDuration>
		bool wait_for_all_done(const _TDuration& duration, bool wait_when_stop = false) noexcept;

		template<class _TFunc, class..._TArgs>
		auto submit_unchecked(const TimePointT& expiration_time, PriorityT priority, bool submit_on_expiration, _TFunc&& function, _TArgs&&... args) noexcept
			-> FutureT<decltype(::std::forward<_TFunc>(function)(::std::forward<_TArgs>(args)...))>;
		template<class _TFunc, class..._TArgs>
		auto submit_unchecked(const DurationT& expiration_time_length, PriorityT priority, bool submit_on_expiration, _TFunc&& function, _TArgs&&... args) noexcept
			-> FutureT<decltype(::std::forward<_TFunc>(function)(::std::forward<_TArgs>(args)...))>;

		template<class _TFunc, class..._TArgs>
		auto submit(const TimePointT& expiration_time, PriorityT priority, bool submit_on_expiration, _TFunc&& function, _TArgs&&... args) noexcept
			-> FutureT<decltype(::std::forward<_TFunc>(function)(::std::forward<_TArgs>(args)...))>;
		template<class _TFunc, class..._TArgs>
		auto submit(const DurationT& expiration_time_length, PriorityT priority, bool submit_on_expiration, _TFunc&& function, _TArgs&&... args) noexcept
			-> FutureT<decltype(::std::forward<_TFunc>(function)(::std::forward<_TArgs>(args)...))>;

		template<class _TFunc, class..._TArgs>
		auto submit(const TimePointT& expiration_time, PriorityT priority, _TFunc&& function, _TArgs&&... args) noexcept
			-> FutureT<decltype(::std::forward<_TFunc>(function)(::std::forward<_TArgs>(args)...))>;
		template<class _TFunc, class..._TArgs>
		auto submit(const DurationT& expiration_time_length, PriorityT priority, _TFunc&& function, _TArgs&&... args) noexcept
			-> FutureT<decltype(::std::forward<_TFunc>(function)(::std::forward<_TArgs>(args)...))>;
		template<class _TFunc, class..._TArgs>
		auto submit(PriorityT priority, _TFunc&& function, _TArgs&&... args) noexcept
			-> FutureT<decltype(::std::forward<_TFunc>(function)(::std::forward<_TArgs>(args)...))>;
		template<class _TFunc, class..._TArgs>
		auto submit(_TFunc&& function, _TArgs&&... args) noexcept
			-> FutureT<decltype(::std::forward<_TFunc>(function)(::std::forward<_TArgs>(args)...))>;
		template<class..._TArgs>
		auto execute(_TArgs&&... args) noexcept
			->decltype(this->submit(::std::forward<_TArgs>(args)...));

		bool get_task(TaskT& task) noexcept;
		void mission(ThreadPtrT ptr) noexcept;

		MutexManagerT m_mutex_manager;
		DatasManagerT m_datas_manager;
		StateManagerT m_state_manager;
	};

	template<int UserLevel = 1> class thread_pool : public thread_pool_public
	{
	public:
		static constexpr int user_level = UserLevel;
		using BasicThreadPoolT = thread_pool_public;
		using ThreadPoolT = thread_pool;
	};
	template<> class thread_pool<0> : public thread_pool_public
	{
	public:
		static constexpr int user_level = 0;
		using BasicThreadPoolT = thread_pool_public;
		using ThreadPoolT = thread_pool;

	protected:
		thread_pool() noexcept = default;
		thread_pool(ThreadNumT threads_num) noexcept : BasicThreadPoolT(threads_num) {}
		using BasicThreadPoolT::thread_pool_public;
		using BasicThreadPoolT::resume_unchecked;
		using BasicThreadPoolT::pause_no_wait_unchecked;
		using BasicThreadPoolT::pause_unchecked;
		using BasicThreadPoolT::start_unchecked;
		using BasicThreadPoolT::stop_no_wait_unchecked;
		using BasicThreadPoolT::stop_unchecked;
		using BasicThreadPoolT::set_threads_num_no_wait_unchecked;
		using BasicThreadPoolT::set_threads_num_unchecked;
		using BasicThreadPoolT::set_multi_unchecked;
		using BasicThreadPoolT::set_try_mode_unchecked;
		using BasicThreadPoolT::resume;
		using BasicThreadPoolT::pause_no_wait;
		using BasicThreadPoolT::pause;
		using BasicThreadPoolT::start;
		using BasicThreadPoolT::stop_no_wait;
		using BasicThreadPoolT::stop;
		using BasicThreadPoolT::set_threads_num_no_wait;
		using BasicThreadPoolT::set_threads_num;
		using BasicThreadPoolT::set_multi;
		using BasicThreadPoolT::set_try_mode;

		using BasicThreadPoolT::get_mutex_manager_unchecked;
		using BasicThreadPoolT::get_datas_manager_unchecked;
		using BasicThreadPoolT::get_state_manager_unchecked;
		using BasicThreadPoolT::get_tasks_num_unchecked;
		using BasicThreadPoolT::is_all_done_unchecked;
		using BasicThreadPoolT::wait_all_done_unchecked;
		using BasicThreadPoolT::wait_until_all_done_unchecked;
		using BasicThreadPoolT::wait_for_all_done_unchecked;
		using BasicThreadPoolT::submit_unchecked;
		using BasicThreadPoolT::get_mutex_manager;
		using BasicThreadPoolT::get_datas_manager;
		using BasicThreadPoolT::get_state_manager;
		using BasicThreadPoolT::get_tasks_num;
		using BasicThreadPoolT::is_all_done;
		using BasicThreadPoolT::wait_all_done;
		using BasicThreadPoolT::wait_until_all_done;
		using BasicThreadPoolT::wait_for_all_done;
		using BasicThreadPoolT::submit;
		using BasicThreadPoolT::execute;
		using BasicThreadPoolT::m_mutex_manager;
		using BasicThreadPoolT::m_datas_manager;
		using BasicThreadPoolT::m_state_manager;
	};
	template<> class thread_pool<1> : public thread_pool_public
	{
	public:
		static constexpr int user_level = 1;
		using BasicThreadPoolT	= thread_pool_public;
		using ThreadPoolT		= thread_pool;

	protected:
		using BasicThreadPoolT::resume_unchecked;
		using BasicThreadPoolT::pause_no_wait_unchecked;
		using BasicThreadPoolT::pause_unchecked;
		using BasicThreadPoolT::start_unchecked;
		using BasicThreadPoolT::stop_no_wait_unchecked;
		using BasicThreadPoolT::stop_unchecked;
		using BasicThreadPoolT::set_threads_num_no_wait_unchecked;
		using BasicThreadPoolT::set_threads_num_unchecked;
		using BasicThreadPoolT::set_multi_unchecked;
		using BasicThreadPoolT::set_try_mode_unchecked;

		using BasicThreadPoolT::get_mutex_manager_unchecked;
		using BasicThreadPoolT::get_datas_manager_unchecked;
		using BasicThreadPoolT::get_state_manager_unchecked;
		using BasicThreadPoolT::get_tasks_num_unchecked;
		using BasicThreadPoolT::is_all_done_unchecked;
		using BasicThreadPoolT::wait_all_done_unchecked;
		using BasicThreadPoolT::wait_until_all_done_unchecked;
		using BasicThreadPoolT::wait_for_all_done_unchecked;
		using BasicThreadPoolT::submit_unchecked;
		using BasicThreadPoolT::m_mutex_manager;
		using BasicThreadPoolT::m_datas_manager;
		using BasicThreadPoolT::m_state_manager;
	};
}