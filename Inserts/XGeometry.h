// XGeometry.h.h: interface for the CXGeometry.h class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XGeometry_INCLUDED_)
#define AFX_XGeometry_INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CXSize;
class CXPoint;
class CXRect;


////////////////////////////////////////////////////////////////
typedef const CXRect* LPCXRECT;    // pointer to read/only RECT
typedef CXSize* LPXSIZE;
// CXRect - A 2-D rectangle, similar to Windows RECT structure.

class CXRect
{
public:
   // Constructors
	CXRect();
	CXRect(float l, float r, float t, float b);
	CXRect(const CXRect& srcRect);
	CXRect(CXPoint point, CXSize size);
	CXRect(CXPoint topLeft, CXPoint bottomRight);

	// Destructor
	virtual ~CXRect();

	// Attributes (in addition to RECT members)

	float m_left;
	float m_top;
	float m_right;
	float m_bottom;

	float Width() const;
	float Height() const;
	CXSize Size() const;
	CXPoint& TopLeft();
	CXPoint& BottomRight();
	const CXPoint& TopLeft() const;
	const CXPoint& BottomRight() const;
	CXPoint CenterPoint() const;

	// convert between CXRect and LPXRECT/LPCXRECT (no need for &)
	//operator LPXRECT();
	//operator LPCXRECT() const;

	BOOL IsRectEmpty() const;
	BOOL IsRectNull() const;
	BOOL PtInRect(CXPoint point) const;

// Operations
	void SetRect(float x1, float y1, float x2, float y2);
	void SetRect(CXPoint topLeft, CXPoint bottomRight);
	void SetRectEmpty();
	void CopyRect(LPCXRECT lpSrcRect);
	BOOL EqualRect(LPCXRECT lpRect) const;

	void InflateRect(float x, float y);
	void InflateRect(CXSize size);
	void InflateRect(LPCXRECT lpRect);
	void InflateRect(float l, float t, float r, float b);
	void DeflateRect(float x, float y);
	void DeflateRect(CXSize size);
	void DeflateRect(LPCXRECT lpRect);
	void DeflateRect(float l, float t, float r, float b);

	void OffsetRect(float x, float y);
	void OffsetRect(CXSize size);
	void OffsetRect(CXPoint point);
	void NormalizeRect();

	// operations that fill '*this' with result
	BOOL IntersectRect(LPCXRECT lpRect1, LPCXRECT lpRect2);
	BOOL UnionRect(LPCXRECT lpRect1, LPCXRECT lpRect2);
	BOOL SubtractRect(LPCXRECT lpRectSrc1, LPCXRECT lpRectSrc2);

// Additional Operations
//  const CXRect& operator=(CXRect & srcRect);
	void operator=(const CXRect& srcRect);
	BOOL operator==(const CXRect& rect) const;
	BOOL operator!=(const CXRect& rect) const;
	void operator+=(CXPoint point);
	void operator+=(CXSize size);
	void operator+=(LPCXRECT lpRect);
	void operator-=(CXPoint point);
	void operator-=(CXSize size);
	void operator-=(LPCXRECT lpRect);
	void operator&=(const CXRect& rect);
	void operator|=(const CXRect& rect);

// Operators returning CXRect values
	CXRect operator+(CXPoint point) const;
	CXRect operator-(CXPoint point) const;
	CXRect operator+(LPCXRECT lpRect) const;
	CXRect operator+(CXSize size) const;
	CXRect operator-(CXSize size) const;
	CXRect operator-(LPCXRECT lpRect) const;
	CXRect operator&(const CXRect& rect2) const;
	CXRect operator|(const CXRect& rect2) const;
	CXRect MulDiv(float nMultiplier, float nDivisor) const;
};


/////////////////////////////////////////////////////////////////////////////
// CXPoint - A 2-D point, similar to Windows POINT structure.

class CXPoint
{
public:
// Constructors
	CXPoint();
	CXPoint(float initX, float initY);
	CXPoint(CXPoint &initPt);
	CXPoint(CXSize initSize);
	virtual ~CXPoint();
    CXPoint(const CXPoint& Loc);

	float m_x;
	float m_y;

// Operations
	void Offset(float xOffset, float yOffset);
	void Offset(CXPoint point);
	void Offset(CXSize size);
	BOOL operator==(CXPoint point) const;
	BOOL operator!=(CXPoint point) const;
	void operator+=(CXSize size);
	void operator-=(CXSize size);
	void operator+=(CXPoint point);
	void operator-=(CXPoint point);
	void operator=(const CXPoint& P);

// Operators returning CXPoint values
	CXPoint operator+(CXSize size) const;
	CXPoint operator-(CXSize size) const;
	CXPoint operator-() const;
	CXPoint operator+(CXPoint point) const;

// Operators returning CXSize values
	CXSize operator-(CXPoint point) const;

// Operators returning CXRect values
	CXRect operator+(const CXRect* lpRect) const;
	CXRect operator-(const CXRect* lpRect) const;

    int		IsLocationInRect(CXRect &Rect);

};


// CXSize
class CXSize
{
public:
   // Constructor
   CXSize();
   CXSize(float initCX, float initCY);
   CXSize(CXSize &initSize);
   CXSize(CXPoint initPt);
   virtual ~CXSize();

   float m_cx; 
   float m_cy;

// Operations
   BOOL operator==(CXSize size) const;
   BOOL operator!=(CXSize size) const;
   void operator+=(CXSize size);
   void operator-=(CXSize size);

// Operators returning CXSize values
   CXSize operator+(CXSize size) const;
   CXSize operator-(CXSize size) const;
   CXSize operator-() const;

// Operators returning CXPoint values
   CXPoint operator+(CXPoint point) const;
   CXPoint operator-(CXPoint point) const;

};



#endif // !defined(AFX_XGeometry_INCLUDED_)
