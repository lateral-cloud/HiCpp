#pragma once

#include <ctime>

namespace HiCxx
{
	namespace Main
	{
		static clock_t clock_begin;

		void begin() noexcept
		{
			clock_begin = clock();
		}

		void wait() noexcept
		{
			(void)getchar();
		}

		clock_t time() noexcept
		{
			return clock() - clock_begin;
		}

		void end() noexcept
		{
			printf("main end, time %dms\n", time());
			wait();
		}
	}
}