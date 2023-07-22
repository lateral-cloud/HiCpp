/**
 * @file	hicxx_defines.h
 * @brief	HiCxx �ĺ궨��ģ��
 * @author	����
*/

#pragma once

#include <cassert>

#ifdef _DEBUG
#define _HICXX_ASSERT(expr,msg) _ASSERT_EXPR(expr,msg)
#else
#define _HICXX_ASSERT(expr,msg) _ASSERT_EXPR(expr,msg)
#endif