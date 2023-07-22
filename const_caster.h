#pragma once

namespace HiCxx
{
	template<class U> U&& const_caster(U&& v) { return static_cast<U>(v); };
	template<class U> U& const_caster(U const& v) { return *static_cast<U*>(&v); };
	template<class U> U&& const_caster(U const&& v) { return *static_cast<U*>(&v); };
	template<class U> U*& const_caster(U const*& v) { return *static_cast<U**>(&v); };
	template<class U> U*&& const_caster(U const*&& v) { return *static_cast<U**>(&v); };
	template<class U> volatile U& const_caster(U const volatile& v) { return *static_cast<volatile U*>(&v); };
	template<class U> volatile U&& const_caster(U const volatile&& v) { return *static_cast<volatile U*>(&v); };
	template<class U> volatile U*& const_caster(U const volatile*& v) { return *static_cast<volatile U**>(&v); };
	template<class U> volatile U*&& const_caster(U const volatile*&& v) { return *static_cast<volatile U**>(&v); };
}