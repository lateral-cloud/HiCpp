#pragma once

namespace HiCxx
{
	template<class U1, class U2> struct same_read_modifier { using type = U1; };
	template<class U1, class U2> struct same_read_modifier<U1, U2&> { using type = U1&; };
	template<class U1, class U2> struct same_read_modifier<U1, U2&&> { using type = U1&&; };
	template<class U1, class U2> struct same_read_modifier<U1, U2 const> { using type = U1 const; };
	template<class U1, class U2> struct same_read_modifier<U1, U2 const&> { using type = U1 const&; };
	template<class U1, class U2> struct same_read_modifier<U1, U2 const&&> { using type = U1 const&&; };
	template<class U1, class U2> struct same_read_modifier<U1, U2 volatile> { using type = U1 volatile; };
	template<class U1, class U2> struct same_read_modifier<U1, U2 volatile&> { using type = U1 volatile&; };
	template<class U1, class U2> struct same_read_modifier<U1, U2 volatile&&> { using type = U1 volatile&&; };
	template<class U1, class U2> struct same_read_modifier<U1, U2 const volatile> { using type = U1 const volatile; };
	template<class U1, class U2> struct same_read_modifier<U1, U2 const volatile&> { using type = U1 const volatile&; };
	template<class U1, class U2> struct same_read_modifier<U1, U2 const volatile&&> { using type = U1 const volatile&&; };

	template<class U1, class U2>
	typename same_read_modifier<U1, U2>::type same_read_modifier_from(U2&& v) noexcept
	{
		return reinterpret_cast<same_read_modifier<U1, U2>::type>(v);
	}
	template<class U1, class U2>
	typename same_read_modifier<U1, U2>::type must_same_read_modifier_from(U2&& v) noexcept
	{
		return *reinterpret_cast<same_read_modifier<U1, U2>::type*>(&v);
	}

	template<class U1, class U2> struct same_type_modifier { using type = U1; };
	template<class U1, class U2> struct same_type_modifier<U1, U2&> { using type = U1&; };
	template<class U1, class U2> struct same_type_modifier<U1, U2&&> { using type = U1&&; };
	template<class U1, class U2> struct same_type_modifier<U1, U2 const> { using type = U1 const; };
	template<class U1, class U2> struct same_type_modifier<U1, U2 const&> { using type = U1 const&; };
	template<class U1, class U2> struct same_type_modifier<U1, U2 const&&> { using type = U1 const&&; };
	template<class U1, class U2> struct same_type_modifier<U1, U2 volatile> { using type = U1 volatile; };
	template<class U1, class U2> struct same_type_modifier<U1, U2 volatile&> { using type = U1 volatile&; };
	template<class U1, class U2> struct same_type_modifier<U1, U2 volatile&&> { using type = U1 volatile&&; };
	template<class U1, class U2> struct same_type_modifier<U1, U2 const volatile> { using type = U1 const volatile; };
	template<class U1, class U2> struct same_type_modifier<U1, U2 const volatile&> { using type = U1 const volatile&; };
	template<class U1, class U2> struct same_type_modifier<U1, U2 const volatile&&> { using type = U1 const volatile&&; };
	template<class U1, class U2> struct same_type_modifier<U1, U2*> { using type = U1*; };
	template<class U1, class U2> struct same_type_modifier<U1, U2*&> { using type = U1*&; };
	template<class U1, class U2> struct same_type_modifier<U1, U2*&&> { using type = U1*&&; };
	template<class U1, class U2> struct same_type_modifier<U1, U2 const*> { using type = U1 const*; };
	template<class U1, class U2> struct same_type_modifier<U1, U2 const*&> { using type = U1 const*&; };
	template<class U1, class U2> struct same_type_modifier<U1, U2 const*&&> { using type = U1 const*&&; };
	template<class U1, class U2> struct same_type_modifier<U1, U2 volatile*> { using type = U1 volatile*; };
	template<class U1, class U2> struct same_type_modifier<U1, U2 volatile*&> { using type = U1 volatile*&; };
	template<class U1, class U2> struct same_type_modifier<U1, U2 volatile*&&> { using type = U1 volatile*&&; };
	template<class U1, class U2> struct same_type_modifier<U1, U2 const volatile*> { using type = U1 const volatile*; };
	template<class U1, class U2> struct same_type_modifier<U1, U2 const volatile*&> { using type = U1 const volatile*&; };
	template<class U1, class U2> struct same_type_modifier<U1, U2 const volatile*&&> { using type = U1 const volatile*&&; };

	template<class U1, class U2>
	typename same_type_modifier<U1, U2>::type same_type_modifier_from(U2&& v) noexcept
	{
		return reinterpret_cast<same_type_modifier<U1, U2>::type>(v);
	}
	template<class U1, class U2>
	typename same_type_modifier<U1, U2>::type must_same_type_modifier_from(U2&& v) noexcept
	{
		return *reinterpret_cast<same_type_modifier<U1, U2>::type*>(&v);
	}
}