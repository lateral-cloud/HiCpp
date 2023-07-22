/**
 * @file	window.h
 * @brief	HiCxx µÄ´°¿ÚÄ£¿é
 * @author	²àÔÆ
*/

#pragma once

#include <Windows.h>
#include <tchar.h>

namespace HiCxx
{
	struct window
	{
		static WNDCLASSEX const wndClassExDefault;
		static CREATESTRUCT const createStructDefault;
		static ATOM wndClassExDefaultAtom;

		window() noexcept = default;
		window(int cx, int cy, LPCTSTR name = _T("window")) noexcept;

		HWND Create() noexcept;
		bool Show(int nCmdShow = SW_NORMAL) noexcept;

		bool SetWindowName(LPCTSTR name) noexcept;
		bool SetPos(int x, int y) noexcept;
		bool SetSize(int cx, int cy) noexcept;
		WNDPROC SetClassWndProc(WNDPROC wndProc) noexcept;
		HINSTANCE SetClassInstance(HINSTANCE hInstance) noexcept;
		DWORD SetClassStyle(DWORD style) noexcept;
		WNDPROC SetWindowWndProc(WNDPROC wndProc) noexcept;
		HINSTANCE SetWindowInstance(HINSTANCE hInstance) noexcept;
		HWND SetWindowHwndParent(HWND hwndParent) noexcept;
		DWORD SetWindowStyle(DWORD style) noexcept;
		DWORD SetWindowExStyle(DWORD exStyle) noexcept;
		LPVOID SetWindowUserData(LPVOID userData) noexcept;
		LONG_PTR SetWindowID(LONG_PTR id) noexcept;

		LPCTSTR GetWindowName() const noexcept;
		POINT GetPos() const noexcept;
		SIZE GetSize() const noexcept;
		WNDPROC GetClassWndProc() const noexcept;
		HINSTANCE GetClassInstance() const noexcept;
		DWORD GetClassStyle() const noexcept;
		WNDPROC GetWindowWndProc() const noexcept;
		HINSTANCE GetWindowInstance() const noexcept;
		HWND GetWindowHwndParent() const noexcept;
		DWORD GetWindowStyle() const noexcept;
		DWORD GetWindowExStyle() const noexcept;
		LPVOID GetWindowUserData() const noexcept;
		LONG_PTR GetWindowID() const noexcept;

		void GetMessage(LPMSG lpMsg, UINT wMsgFilterMin, UINT wMsgFilterMax) noexcept;
		bool PeekMessage(LPMSG lpMsg, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg) noexcept;
		
		constexpr operator HWND() const noexcept;

		WNDCLASSEX wndClassEx = wndClassExDefault;
		CREATESTRUCT createStruct = createStructDefault;
		HWND hwnd = nullptr;
	private:
		static ATOM func_prepare_default() noexcept;
	};

	WNDCLASSEX const window::wndClassExDefault =
	{ sizeof(WNDCLASSEX), 0, ::DefWindowProc, 0, 0, ::GetModuleHandle(nullptr), nullptr, nullptr, 
		(HBRUSH)COLOR_WINDOW, nullptr, _T("HiCxxWindowClassDefault"), nullptr};
	CREATESTRUCT const window::createStructDefault =
	{ nullptr, ::GetModuleHandle(nullptr), nullptr, nullptr, 480, 640, CW_USEDEFAULT, CW_USEDEFAULT, WS_OVERLAPPEDWINDOW, 
		_T("window"), _T("HiCxxWindowClassDefault"), 0};
	ATOM window::wndClassExDefaultAtom = window::func_prepare_default();

	void GetWindowRealSize(HWND hwnd, SIZE& size2) noexcept
	{
		RECT clientSize, windowSize;
		::GetClientRect(hwnd, &clientSize);
		::GetWindowRect(hwnd, &windowSize);
		size2 = { windowSize.right - windowSize.left - clientSize.right + size2.cx,
			windowSize.bottom - windowSize.top - clientSize.bottom + size2.cy };
	}
}