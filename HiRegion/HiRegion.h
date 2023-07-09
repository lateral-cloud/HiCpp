#pragma once

#include <HiNumerics.h>

namespace HiRegion
{
	template<class _Ty> struct HiSingleRegion;
	template<class _Ty> struct HiRectangularRegion;

	template<class _Ty> struct HiBasicRegion
	{
		using ValueType			= _Ty;
		using BasicRegion		= HiBasicRegion<_Ty>;
		using SingleRegion		= HiSingleRegion<_Ty>;
		using Point2			= ::HiNumerics::HiPoint2<_Ty>;
		using Size				= ::HiNumerics::HiSize<_Ty>;
		using RectangularRegion = HiRectangularRegion<_Ty>;

		virtual ValueType		  GetCenterX() const = 0;
		virtual ValueType		  GetCenterY() const = 0;
		virtual Point2			  GetCenterPos() const { return Point2{ this->GetCenterX(),this->GetCenterY() }; }
		virtual RectangularRegion GetRectangularRegion() const = 0;

		virtual void SetCenterX(ValueType x) = 0;
		virtual void SetCenterY(ValueType y) = 0;
		virtual void SetCenterPos(ValueType x, ValueType y) { this->SetCenterX(x); this->SetCenterY(y); }
		virtual void SetCenterPos(const Point2& pt) { this->SetCenterPos(pt.x, pt.y); }
		virtual void MoveXRel(ValueType dx) = 0;
		virtual void MoveYRel(ValueType dy) = 0;
		virtual void MoveRel(ValueType dx, ValueType dy) { this->MoveXRel(dx); this->MoveYRel(dy); }
		virtual void MoveRel(const Point2& diff) { this->MoveRel(diff.x, diff.y); }
		virtual bool PtInRectangularRegion(ValueType x, ValueType y) const { return this->GetRectangularRegion().PtInRectangularRegion(x, y); }
		virtual bool PtInRectangularRegion(const Point2& pt) const { return this->PtInRectangularRegion(pt.x, pt.y); }
		virtual bool PtInRegion(ValueType x, ValueType y) const = 0;
		virtual bool PtInRegion(const Point2& pt) const { return this->PtInRegion(pt.x, pt.y); }
	};
	template<class _Ty> struct HiSingleRegion : public HiBasicRegion<_Ty>
	{
		using ValueType			= _Ty;
		using BasicRegion		= HiBasicRegion<_Ty>;
		using SingleRegion		= HiSingleRegion<_Ty>;
		using Point2			= typename BasicRegion::Point2;
		using Size				= typename BasicRegion::Size;
		using RectangularRegion = typename BasicRegion::RectangularRegion;

		using BasicRegion::GetCenterX;
		using BasicRegion::GetCenterY;
		using BasicRegion::GetCenterPos;
		using BasicRegion::GetRectangularRegion;
		using BasicRegion::SetCenterX;
		using BasicRegion::SetCenterY;
		using BasicRegion::SetCenterPos;
		using BasicRegion::MoveXRel;
		using BasicRegion::MoveYRel;
		using BasicRegion::MoveRel;
		using BasicRegion::PtInRectangularRegion;
		using BasicRegion::PtInRegion;
		virtual SingleRegion& GetRegion() { return *this; }
		virtual const SingleRegion& GetRegion() const { return *this; }
		virtual bool PtInRegion(ValueType x, ValueType y) const { return this->GetRegion().PtInRegion(x, y); }
	};
	template<class _Ty> struct HiRectangularRegion : public HiSingleRegion<_Ty>
	{
		using ValueType			= _Ty;
		using BasicRegion		= HiBasicRegion<_Ty>;
		using SingleRegion		= HiSingleRegion<_Ty>;
		using Point2			= typename BasicRegion::Point2;
		using Size				= typename BasicRegion::Size;
		using RectangularRegion = typename BasicRegion::RectangularRegion;

		ValueType left;
		ValueType top;
		ValueType right;
		ValueType bottom;
		HiRectangularRegion(ValueType left = 0, ValueType top = 0, ValueType right = 0, ValueType bottom = 0) : left(left), top(top), right(right), bottom(bottom) {}
		void SetLeft(ValueType left) { this->left = left; }
		void SetTop(ValueType top) { this->top = top; }
		void SetRight(ValueType right) { this->right = right; }
		void SetBottom(ValueType bottom) { this->bottom = bottom; }
		void SetLR(ValueType left, ValueType top) { this->left = left; this->top = top; }
		void SetLR(const Point2& LR) { this->SetLR(LR.x, LR.y); }
		void SetRB(ValueType right, ValueType bottom) { this->right = right; this->bottom = bottom; }
		void SetRB(const Point2& RB) { this->SetRB(RB.x, RB.y); }
		void SetRectangle(ValueType left, ValueType top, ValueType right, ValueType bottom) { this->SetLeft(left); this->SetTop(top); this->SetRight(right); this->SetBottom(bottom); }
		void SetRectangle(const RectangularRegion& rct) { this->SetRectangle(rct.left, rct.top, rct.right, rct.bottom); }
		void SetSize(ValueType cx, ValueType cy) { this->right = this->left + cx; this->bottom = this->top + cy; }
		void SetSize(const Size& size) { this->SetSize(size.x, size.y); }

		ValueType		    GetX() const { return this->left; }
		ValueType		    GetY() const { return this->top; }
		Point2			    GetPos() const { return Point2{ this->GetX(),this->GetY() }; }
		ValueType		    GetCenterX() const { return (this->left + this->right) / 2; }
		ValueType		    GetCenterY() const { return (this->top + this->bottom) / 2; }
		SingleRegion&	    GetRegion() { return *this; }
		const SingleRegion& GetRegion() const { return *this; }
		RectangularRegion   GetRectangularRegion() const { return *this; }
		void SetX(ValueType x) { this->right = this->right - this->left + x; this->left = x; }
		void SetY(ValueType y) { this->bottom = this->bottom - this->top + y; this->top = y; }
		void SetPos(ValueType x, ValueType y) { this->SetX(x); this->SetY(y); }
		void SetPos(const Point2& pt) { this->SetPos(pt.x, pt.y); }
		void SetCenterX(ValueType x) { ValueType xRadius = (this->left + this->right) / 2; this->left = x - xRadius; this->right = x + xRadius; }
		void SetCenterY(ValueType y) { ValueType yRadius = (this->top + this->bottom) / 2; this->top = y - yRadius; this->bottom = y + yRadius; }
		void SetCenterPos(ValueType x, ValueType y) { this->SetCenterX(x); this->SetCenterY(y); }
		void SetCenterPos(const Point2& pt) { this->SetCenterPos(pt.x, pt.y); }
		void MoveX(ValueType x) { this->SetX(x); }
		void MoveY(ValueType y) { this->SetY(y); }
		void Move(ValueType x, ValueType y) { this->MoveX(x); this->MoveY(y); }
		void Move(const Point2& pt) { this->Move(pt.x, pt.y); }
		void MoveXRel(ValueType dx) { this->left += dx; this->right += dx; }
		void MoveYRel(ValueType dy) { this->top += dy; this->bottom += dy; }
		bool PtInRectangularRegion(ValueType x, ValueType y) const { return x >= this->left && x <= this->right && y >= this->top && y <= this->bottom; }
		bool PtInRegion(ValueType x, ValueType y) const { return this->PtInRectangularRegion(x, y); }
		using SingleRegion::GetCenterPos;
		using SingleRegion::MoveRel;
		using SingleRegion::PtInRectangularRegion;
		using SingleRegion::PtInRegion;
	};
	template<class _Ty> struct HiEllipticalRegion : public HiSingleRegion<_Ty>
	{
		using ValueType			= _Ty;
		using BasicRegion		= HiBasicRegion<_Ty>;
		using SingleRegion		= HiSingleRegion<_Ty>;
		using Point2			= typename BasicRegion::Point2;
		using Size				= typename BasicRegion::Size;
		using RectangularRegion = typename BasicRegion::RectangularRegion;

		ValueType x;
		ValueType y;
		ValueType xRadius;
		ValueType yRadius;
		HiEllipticalRegion(ValueType x = 0, ValueType y = 0, ValueType xRadius = 0, ValueType yRadius = 0) : x(x), y(y), xRadius(xRadius), yRadius(yRadius) {}
		void SetRectangle(ValueType left, ValueType top, ValueType right, ValueType bottom) { this->x = (left + right) / 2; this->y = (top + bottom) / 2; this->xRadius = this->x - left; this->yRadius = this->y - top; }
		void SetRectangle(const RectangularRegion& rct) { this->SetRectangle(rct.left, rct.top, rct.right, rct.bottom); }
		void SetXRadius(ValueType xRadius) { this->xRadius = xRadius; }
		void SetYRadius(ValueType yRadius) { this->yRadius = yRadius; }
		void SetRadius(ValueType xRadius, ValueType yRadius) { this->xRadius = xRadius; this->yRadius = yRadius; }
		void SetRadius(const Size& radius) { this->SetRadius(radius.cx, radius.cy); }

		ValueType		    GetX() const { return this->x - this->xRadius; }
		ValueType		    GetY() const { return this->y - this->yRadius; }
		Point2			    GetPos() const { return Point2{ this->GetX(),this->GetY() }; }
		ValueType		    GetCenterX() const { return this->x; }
		ValueType		    GetCenterY() const { return this->y; }
		SingleRegion&	    GetRegion() { return *this; }
		const SingleRegion& GetRegion() const { return *this; }
		RectangularRegion   GetRectangularRegion() const { return { this->x - this->xRadius,this->y - this->yRadius,this->x + this->xRadius,this->y + this->yRadius }; }
		void SetX(ValueType x) { this->x = x + this->xRadius; }
		void SetY(ValueType y) { this->y = y + this->yRadius; }
		void SetPos(ValueType x, ValueType y) { this->SetX(x); this->SetY(y); }
		void SetPos(const Point2& pt) { this->SetPos(pt.x, pt.y); }
		void SetCenterX(ValueType x) { this->x = x; }
		void SetCenterY(ValueType y) { this->y = y; }
		void MoveX(ValueType x) { this->SetX(x); }
		void MoveY(ValueType y) { this->SetY(y); }
		void Move(ValueType x, ValueType y) { this->MoveX(x); this->MoveY(y); }
		void Move(const Point2& pt) { this->Move(pt.x, pt.y); }
		void MoveXRel(ValueType dx) { this->x += dx; }
		void MoveYRel(ValueType dy) { this->y += dy; }
		bool PtInRectangularRegion(ValueType x, ValueType y) const { return x >= this->x - this->xRadius && x <= this->x + this->xRadius && y >= this->y - this->yRadius && y <= this->y + this->yRadius; }
		bool PtInRegion(ValueType x, ValueType y) const { Size diff{ (x - this->x) * this->yRadius,(y - this->y) * this->xRadius }; return diff.x * diff.x + diff.y * diff.y <= this->xRadius * this->xRadius * this->yRadius * this->yRadius; }
		using SingleRegion::GetCenterPos;
		using SingleRegion::MoveRel;
		using SingleRegion::PtInRectangularRegion;
		using SingleRegion::PtInRegion;
	};
	template<class _Ty> struct HiCompositeRegion : public HiSingleRegion<_Ty>
	{

	};

	template<class _Ty, class _RECT, class _RECT_Ty = long> _RECT RectangularRegionToRECT(const HiRectangularRegion<_Ty>& region)
	{
		return _RECT{ (_RECT_Ty)region.left,(_RECT_Ty)region.top,(_RECT_Ty)region.right,(_RECT_Ty)region.bottom };
	}
	template<class _Ty, class _RECT, class _RECT_Ty = long> _RECT RectangularRegionToRECT(const HiRectangularRegion<_Ty>* region)
	{
		return RectangularRegionToRECT<_Ty, _RECT, _RECT_Ty>(*region);
	}
}