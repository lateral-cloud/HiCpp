#include <thread>
#include <chrono>

namespace HiFPS
{
	struct HiLimitFPS
	{
		::std::chrono::steady_clock::duration time_between_frames;
		::std::chrono::time_point<::std::chrono::steady_clock> tp;
		
		void SetFPS(double newFPS) { new(&time_between_frames)::std::chrono::steady_clock::duration{(long long)(1000000000 / newFPS)}; }
		void Begin() { tp = ::std::chrono::steady_clock::now(); }
		void Sleep()
		{
			tp += time_between_frames;
			std::this_thread::sleep_until(tp);
		}
	};
	struct HiCheckFPS
	{
		::std::chrono::time_point<::std::chrono::steady_clock> tp;
		int count;

		void Begin() { tp = ::std::chrono::steady_clock::now(); count = 0; }
		void Check() { ++count; }
		double GetFPS() { return (double)1e9 * count / (::std::chrono::steady_clock::now() - tp).count(); }
	};
}