/**
 * @file	hicxx_defines.h
 * @brief	HiCxx 的宏定义模块
 * @author	侧云
*/

#pragma once

#include <cassert>

#ifdef _DEBUG
#define _HICXX_ASSERT(expr,msg) _ASSERT_EXPR(expr,msg)
#else
#define _HICXX_ASSERT(expr,msg) _ASSERT_EXPR(expr,msg)
#endif