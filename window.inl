/**
 * @file	window.h
 * @brief	HiCxx µÄ´°¿ÚÄ£¿é
 * @author	²àÔÆ
*/

#pragma once

#include "window.h"

namespace HiCxx
{
	inline window::window(int cx, int cy, LPCTSTR name) noexcept
	{
		this->SetSize(cx, cy);
		this->SetWindowName(name);
	}

	inline HWND window::Create() noexcept
	{
		return this->hwnd = ::CreateWindowEx(this->createStruct.dwExStyle, this->createStruct.lpszClass, this->createStruct.lpszName, 
			this->createStruct.style, this->createStruct.x, this->createStruct.y, this->createStruct.cx, this->createStruct.cy, 
			this->createStruct.hwndParent, this->createStruct.hMenu, this->createStruct.hInstance, this->createStruct.lpCreateParams);
	}

	inline bool window::Show(int nCmdShow) noexcept
	{
		return ::ShowWindow(this->hwnd, nCmdShow);
	}

	inline bool window::SetWindowName(LPCTSTR name) noexcept
	{
		if (this->hwnd)
			return false;
		this->createStruct.lpszName = name;
		return true;
	}

	inline bool window::SetPos(int x, int y) noexcept
	{
		this->createStruct.x = x;
		this->createStruct.y = y;
		if (this->hwnd)
			return ::SetWindowPos(this->hwnd, nullptr, x, y, 0, 0, SWP_NOSIZE);
		return true;
	}

	inline bool window::SetSize(int cx, int cy) noexcept
	{
		this->createStruct.cx = cx;
		this->createStruct.cy = cy;
		if (this->hwnd)
			return ::SetWindowPos(this->hwnd, nullptr, 0, 0, cx, cy, SWP_NOMOVE);
		return true;
	}

	inline WNDPROC window::SetClassWndProc(WNDPROC wndProc) noexcept
	{
		WNDPROC const wndProcOld = this->wndClassEx.lpfnWndProc;
		this->wndClassEx.lpfnWndProc = wndProc;
		return wndProcOld;
	}

	inline HINSTANCE window::SetClassInstance(HINSTANCE hInstance) noexcept
	{
		HINSTANCE const hInstanceOld = this->createStruct.hInstance;
		this->createStruct.hInstance = hInstance;
		return hInstanceOld;
	}

	inline DWORD window::SetClassStyle(DWORD style) noexcept
	{
		DWORD const styleOld = this->createStruct.style;
		this->createStruct.style = style;
		return styleOld;
	}

	inline WNDPROC window::SetWindowWndProc(WNDPROC wndProc) noexcept
	{
		if (!this->hwnd)
			return 0;
		WNDPROC const wndProcOld = (WNDPROC)::GetWindowLongPtr(this->hwnd, GWLP_WNDPROC);
		this->wndClassEx.lpfnWndProc = wndProc;
		return (WNDPROC)::SetWindowLongPtr(this->hwnd, GWLP_WNDPROC, (LONG_PTR)wndProc);
	}

	inline HINSTANCE window::SetWindowInstance(HINSTANCE hInstance) noexcept
	{
		HINSTANCE const hInstanceOld = this->createStruct.hInstance;
		this->createStruct.hInstance = hInstance;
		if (this->hwnd)
			return (HINSTANCE)::SetWindowLongPtr(this->hwnd, GWLP_HINSTANCE, (LONG_PTR)hInstance);
		return hInstanceOld;
	}

	inline HWND window::SetWindowHwndParent(HWND hwndParent) noexcept
	{
		HWND const hwndParentOld = this->createStruct.hwndParent;
		this->createStruct.hwndParent = hwndParent;
		if (this->hwnd)
			return (HWND)::SetWindowLongPtr(this->hwnd, GWLP_HINSTANCE, (LONG_PTR)hwndParent);
		return hwndParentOld;
	}

	inline DWORD window::SetWindowStyle(DWORD style) noexcept
	{
		DWORD const styleOld = this->createStruct.style;
		this->createStruct.style = style;
		if (this->hwnd)
			return (DWORD)::SetWindowLongPtr(this->hwnd, GWL_STYLE, (LONG_PTR)style);
		return styleOld;
	}

	inline DWORD window::SetWindowExStyle(DWORD exStyle) noexcept
	{
		DWORD const exStyleOld = this->createStruct.dwExStyle;
		this->createStruct.dwExStyle = exStyle;
		if (this->hwnd)
			return (DWORD)::SetWindowLongPtr(this->hwnd, GWL_EXSTYLE, (LONG_PTR)exStyle);
		return exStyleOld;
	}

	inline LPVOID window::SetWindowUserData(LPVOID userData) noexcept
	{
		if (this->hwnd)
			return (LPVOID)::SetWindowLongPtr(this->hwnd, GWL_EXSTYLE, (LONG_PTR)userData);
		return 0;
	}

	inline LONG_PTR window::SetWindowID(LONG_PTR id) noexcept
	{
		if (this->hwnd)
			return ::SetWindowLongPtr(this->hwnd, GWLP_ID, (LONG_PTR)id);
		return 0;
	}

	inline LPCTSTR window::GetWindowName() const noexcept
	{
		return this->createStruct.lpszName;
	}

	inline POINT window::GetPos() const noexcept
	{
		return { this->createStruct.x, this->createStruct.y };
	}

	inline SIZE window::GetSize() const noexcept
	{
		return { this->createStruct.cx, this->createStruct.cy };
	}

	inline WNDPROC window::GetClassWndProc() const noexcept
	{
		return this->wndClassEx.lpfnWndProc;
	}

	inline HINSTANCE window::GetClassInstance() const noexcept
	{
		return this->createStruct.hInstance;
	}

	inline DWORD window::GetClassStyle() const noexcept
	{
		return this->createStruct.style;
	}

	inline WNDPROC window::GetWindowWndProc() const noexcept
	{
		if (this->hwnd)
			return (WNDPROC)::GetWindowLongPtr(this->hwnd, GWLP_WNDPROC);
		return this->wndClassEx.lpfnWndProc;
	}

	inline HINSTANCE window::GetWindowInstance() const noexcept
	{
		if (this->hwnd)
			return (HINSTANCE)::GetWindowLongPtr(this->hwnd, GWLP_HINSTANCE);
		return this->createStruct.hInstance;
	}

	inline HWND window::GetWindowHwndParent() const noexcept
	{
		if (this->hwnd)
			return (HWND)::GetWindowLongPtr(this->hwnd, GWLP_HINSTANCE);
		return this->createStruct.hwndParent;
	}

	inline DWORD window::GetWindowStyle() const noexcept
	{
		if (this->hwnd)
			return (DWORD)::GetWindowLongPtr(this->hwnd, GWL_STYLE);
		return this->createStruct.style;
	}

	inline DWORD window::GetWindowExStyle() const noexcept
	{
		if (this->hwnd)
			return (DWORD)::GetWindowLongPtr(this->hwnd, GWL_EXSTYLE);
		return this->createStruct.dwExStyle;
	}

	inline LPVOID window::GetWindowUserData() const noexcept
	{
		if (this->hwnd)
			return (LPVOID)::GetWindowLongPtr(this->hwnd, GWL_EXSTYLE);
		return 0;
	}

	inline LONG_PTR window::GetWindowID() const noexcept
	{
		if (this->hwnd)
			return ::GetWindowLongPtr(this->hwnd, GWLP_ID);
		return 0;
	}

	inline void window::GetMessage(LPMSG lpMsg, UINT wMsgFilterMin, UINT wMsgFilterMax) noexcept
	{
		::GetMessage(lpMsg, this->hwnd, wMsgFilterMin, wMsgFilterMax);
	}

	inline bool window::PeekMessage(LPMSG lpMsg, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg) noexcept
	{
		return ::PeekMessage(lpMsg, this->hwnd, wMsgFilterMin, wMsgFilterMax, wRemoveMsg);
	}

	constexpr window::operator HWND() const noexcept
	{
		return this->hwnd;
	}

	inline ATOM window::func_prepare_default() noexcept
	{
		return ::RegisterClassEx(&window::wndClassExDefault);
	}
}
