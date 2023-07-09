#pragma once

#include <HiRegion.h>

namespace HiContainer
{
	template<class _Ty> struct HiBasicContainer
	{
		using ValueType			= _Ty;
		using BasicRegion		= ::HiRegion::HiBasicRegion<_Ty>;
		using RectangularRegion = ::HiRegion::HiRectangularRegion<_Ty>;
		using BasicPointer		= BasicRegion*;
		using ConstBasicPointer = BasicRegion const*;
		using Point2			= ::HiNumerics::HiPoint2<ValueType>;

		bool bEnable;

		virtual ~HiBasicContainer() { this->bEnable = false; }
		void Enable(bool bEnable) { this->bEnable = bEnable; }
		void Enable() { this->bEnable = true; }
		void Disable() { this->bEnable = false; }
		bool IsEnabled() { return this->bEnable == true; }
		bool IsDisabled() { return this->bEnable == false; }
		virtual RectangularRegion GetRectangularRegion() const = 0;
		virtual bool PtInRectangularRegion(ValueType x, ValueType y) const { return this->GetRectangularRegion().PtInRectangularRegion(x, y); }
		virtual bool PtInRectangularRegion(const Point2& pt) const { return this->PtInRectangularRegion(pt.x, pt.y); }
		virtual bool PtInRegion(ValueType x, ValueType y) const { return this->GetRectangularRegion().PtInRegion(x, y); }
		virtual bool PtInRegion(const Point2& pt) const { return this->PtInRegion(pt.x, pt.y); }
	};
	template<class _Ty> struct HiUnknowSingleContainer : public HiBasicContainer<_Ty>
	{
		using ValueType				= _Ty;
		using BasicRegion			= HiBasicContainer<_Ty>::BasicRegion;
		using RectangularRegion		= HiBasicContainer<_Ty>::RectangularRegion;
		using BasicPointer			= HiBasicContainer<_Ty>::BasicPointer;
		using ConstBasicPointer		= HiBasicContainer<_Ty>::ConstBasicPointer;
		using Point2				= HiBasicContainer<_Ty>::Point2;
		using SingleRegion			= ::HiRegion::HiSingleRegion<_Ty>;
		using SinglePointer			= SingleRegion*;
		using ConstSinglePointer	= SingleRegion const*;

		SinglePointer region;

		RectangularRegion  GetRectangularRegion() const { return region->GetRectangularRegion(); }
		SinglePointer	   SetRegion(SinglePointer newRegion) { SinglePointer oldRegion = this->region; this->region = newRegion; return oldRegion; }
		SinglePointer	   GetRegion() { return this->region; }
		ConstSinglePointer GetRegion() const { return this->region; }
		SinglePointer	   SetSingleRegion(SinglePointer newRegion) { SinglePointer oldRegion = this->region; this->region = newRegion; return oldRegion; }
		SinglePointer	   GetSingleRegion() { return this->region; }
		ConstSinglePointer GetSingleRegion() const { return this->region; }
		bool PtInRectangularRegion(ValueType x, ValueType y) const { return this->region->PtInRectangularRegion(x, y); }
		bool PtInRegion(ValueType x, ValueType y) const { return this->region->PtInRegion(x, y); }
		operator BasicPointer () { return this->region; }
		operator ConstBasicPointer () const { return this->region; }
		operator SinglePointer () { return this->region; }
		operator ConstSinglePointer () const { return this->region; }
	};
	template<class _Ty> struct HiSingleContainer : public HiUnknowSingleContainer<typename _Ty::ValueType>
	{
		using ValueType				= typename _Ty::ValueType;
		using BasicRegion			= typename HiUnknowSingleContainer<ValueType>::BasicRegion;
		using BasicPointer			= typename HiUnknowSingleContainer<ValueType>::BasicPointer;
		using ConstBasicPointer		= typename HiUnknowSingleContainer<ValueType>::ConstBasicPointer;
		using Point2				= typename HiUnknowSingleContainer<ValueType>::Point2;
		using SingleRegion			= _Ty;
		using SinglePointer			= SingleRegion*;
		using ConstSinglePointer	= SingleRegion const*;

		SinglePointer	   SetSingleRegion(SinglePointer newRegion) { SinglePointer oldRegion = static_cast<SinglePointer>(this->region); this->region = newRegion; return oldRegion; }
		SinglePointer	   GetSingleRegion() { return static_cast<SinglePointer>(this->region); }
		ConstSinglePointer GetSingleRegion() const { return static_cast<ConstSinglePointer>(this->region); }
		operator SinglePointer () { return static_cast<SinglePointer>(this->region); }
		operator ConstSinglePointer () const { return static_cast<ConstSinglePointer>(this->region); }
	};
	template<class _Ty> struct HiCompositeContainer
	{

	};
}