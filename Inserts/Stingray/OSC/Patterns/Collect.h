/////////////////////////////////////////////////////////////////////////////
// Collect.h : Declaration of base collection classes
//
// Stingray Software Extension Classes
// Copyright (C) 1997 Stingray Software Inc,
// All rights reserved.
//
// This source code is only intended as a supplement to
// the Objective Toolkit Class Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding
// the Objective Toolkit product.
//
// Author:       Dean Hallman
// Description:  Declaration of base collection classes.
//
// $Header: $
// $NoKeywords: $


#ifndef __SECCOLLECT_H__
#define __SECCOLLECT_H__

// Includes

#ifndef __AFXTEMPL_H__
#include <afxtempl.h>
#endif

//
// CMN Extension DLL
// Initialize declaration context
//
#ifdef _CMNDLL
	#undef AFXAPP_DATA
	#define AFXAPP_DATA AFXApp_DATA
	#undef AFX_DATA
	#define AFX_DATA    CMN_DATAEXT
#endif //_CMNDLL


// define our own min/max macros. The min/max macros defined in Windef.h will
// be undefined if the preprocessor NOMINMAX is defined. NOMINMAX is required
// by Rogue Wave DBTools.
#ifndef mvcmax
#define mvcmax(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef mvcmin
#define mvcmin(a,b)            (((a) < (b)) ? (a) : (b))
#endif

// Position Specification Class
// The way inwhich position is specified varies between integers
// and linked lists.  For this reason, we have a collection type
// independent way of specifying the position of an item in a
// collection.
class CCIterPos
{
public:
	CCIterPos() {
	};
	
	virtual ~CCIterPos() {
	};
};

template <class pos_t> class CCIterPos_T : public CCIterPos
{
public:
	pos_t m_value;

	CCIterPos_T<pos_t>() {
	}

	CCIterPos_T<pos_t>( pos_t pos ) {
		m_value = pos;
	}

	CCIterPos_T<pos_t>( const CCIterPos_T<pos_t> &src )
	{
		*this = src.m_value;
	}

	operator pos_t(void) const {
			return m_value;
	}

	CCIterPos_T<pos_t>& operator=( pos_t pos ) {
		m_value = pos;
		return *this;
	}

	CCIterPos_T<pos_t>& operator=( const CCIterPos_T<pos_t> &src ) {
		return( *this = src.m_value );
	}

	BOOL operator==( const CCIterPos_T<pos_t> &src )
	{
		return ( m_value == src.m_value );
	}

	BOOL operator==( pos_t pos )
	{
		return ( m_value == pos );
	}

	BOOL operator!=( const CCIterPos_T<pos_t> &src )
	{
		return ( m_value != src.m_value );
	}

	BOOL operator!=( pos_t pos )
	{
		return ( m_value != pos );
	}
};

//@doc ICollection_T
//@class A collection interface.  When this interface is mixed in and implemented
// within any type of collection class, iteration via Iterator_T is enabled.
//@tcarg class | element_t | The class of the element to access in the collection.
template <class element_t> class ICollection_T
{
public:

	// Iteration Support
	virtual CCIterPos* iCreateIteratorPosition() const = 0;
	virtual void iFirst(CCIterPos* pbp) const = 0;
	virtual void iNext(CCIterPos* pbp) const = 0;
	virtual void iPrev(CCIterPos* pbp) const = 0;
	virtual void iLast(CCIterPos* pbp) const = 0;
	virtual void iRemoveAt(CCIterPos* pbp) = 0;
	virtual element_t iGet(CCIterPos* pbp) const = 0;
	virtual void iSet(CCIterPos* pbp, element_t elem) = 0;
	virtual void iInsert(CCIterPos* pbp, element_t elem) = 0;
	virtual BOOL iFindNext(CCIterPos* pbp, element_t elem) const = 0;
	virtual BOOL iFindPrev(CCIterPos* pbp, element_t elem) const = 0;

	// Queries
	virtual int GetSize() const = 0;
	virtual void RemoveAll() = 0;
};

//@doc IComposite_T
//@mfunc int | IComposite_T | GetChildCount | Return number of children in composite
//@xref <c IComposite_T>

//@doc IComposite_T
//@mfunc element_t | IComposite_T | GetChild | Return a pointer to a child given the collection index
//@xref <c IComposite_T>

//@doc IComposite_T
//@mfunc BOOL | IComposite_T | AddChild | Add a child to the end of the collection
//@xref <c IComposite_T>

//@doc IComposite_T
//@mfunc BOOL | IComposite_T | InsertChildAt | Insert a child into the composite at a given position
//@xref <c IComposite_T>

//@doc IComposite_T
//@mfunc BOOL | IComposite_T | RemoveChildAt | Remove a child at the specified position from the composite
//@xref <c IComposite_T>

//@doc IComposite_T
//@mfunc BOOL | IComposite_T | FindChild | Return the index of a given child in the composite
//@xref <c IComposite_T>

//@doc IComposite_T
//@class Template interface for classes that support composition.  For example, if you require
// a composite visual component, you can simply mix this interface into to your MvcVisualComponent
// derived class.
//@tcarg class | element_t | The class of the element to store in the collection.
//@tcarg class | pos_t | The class used for the iterator.
template <class element_t, class pos_t = int> class IComposite_T
{
public:
	//@cmember
	/* Return number of children in composite*/
	virtual int GetChildCount(BOOL bRecursive) = 0;

	//@cmember
	/* Return a pointer to a child given the collection index*/
	virtual element_t GetChild(const pos_t pos) const = 0;

	//@cmember
	/* Add a child to the end of the collection*/
	virtual BOOL AddChild(element_t child) = 0;

	//@cmember
	/* Insert a child into the composite at a given position*/
	virtual BOOL InsertChildAt(element_t child, const pos_t pos) = 0;

	//@cmember
	/* Remove specfied child*/
	virtual BOOL RemoveChild(const element_t child) = 0;

	//@cmember
	/* Remove a child at the specified position from the composite*/
	virtual BOOL RemoveChildAt(const pos_t pos) = 0;

	//@cmember
	/* Return the index of a given child in the composite*/
	virtual BOOL FindChild(element_t child, pos_t& pos) const = 0;

	//@cmember
	/* Return the head position in sequence*/
	virtual pos_t GetHeadChildPos() const = 0;

	//@cmember
	/* Return the head position in sequence*/
	virtual pos_t GetTailChildPos() const = 0;

	//@cmember
	/* Return the next position in sequence*/
	virtual pos_t GetNextChildPos(pos_t posOld) const = 0;

	//@cmember
	/* Return the previous position in sequence*/
	virtual pos_t GetPrevChildPos(pos_t posOld) const = 0;

	//@cmember
	/* Set (or reset) this node's parent*/
	virtual void SetParent(element_t parent,BOOL bRemoveFromOldParent=TRUE) = 0;

	//@cmember
	/* Get this node's parent*/
	virtual element_t GetParent() = 0;
};

template <class element_t> class IStack_T
{
public:
	virtual element_t Push(element_t elem) = 0;
	virtual element_t Peek() = 0;
	virtual element_t Pop() = 0;
	virtual void SetMaxSize(int nSize) = 0;
};

//@doc Iterator_T
//@mfunc void | Iterator_T | First | Moves the iterator to the first element in the collection
//@xref <c Iterator_T>

//@doc Iterator_T
//@mfunc void | Iterator_T | Next | Moves the iterator to the next element in the collection
//@xref <c Iterator_T>

//@doc Iterator_T
//@mfunc void | Iterator_T | Last | Moves the iterator to the last element in the collection
//@xref <c Iterator_T>

//@doc Iterator_T
//@mfunc void | Iterator_T | Prev | Moves the iterator to the previous element in the collection
//@xref <c Iterator_T>

//@doc Iterator_T
//@mfunc element_t | Iterator_T | Get | Retrieves the element at the current iterator position
//@xref <c Iterator_T>

//@doc Iterator_T
//@mfunc element_t | Iterator_T | GetFirst | Moves the iterator to and retrieves the first element in the collection
//@xref <c Iterator_T>

//@doc Iterator_T
//@mfunc element_t | Iterator_T | GetNext | Moves the iterator to and retrieves the next element in the collection
//@xref <c Iterator_T>

//@doc Iterator_T
//@mfunc element_t | Iterator_T | GetLast | Moves the iterator to and retrieves the last element in the collection
//@xref <c Iterator_T>

//@doc Iterator_T
//@mfunc element_t | Iterator_T | GetPrev | Moves the iterator to and retrieves the previous element in the collection
//@xref <c Iterator_T>

//@doc Iterator_T
//@mfunc BOOL | Iterator_T | FindNext | Finds the next element equal to the specified after the current iterator position.  If found, TRUE is returned and the iterator is moved.
//@parm element_t | elem | The element to search for
//@xref <c Iterator_T>

//@doc Iterator_T
//@mfunc BOOL | Iterator_T | FindPrev | Finds the previous element equal to the specified before the current iterator position.  If found, TRUE is returned and the iterator is moved.
//@parm element_t | elem | The element to search for
//@xref <c Iterator_T>

//@doc Iterator_T
//@mfunc void | Iterator_T | Set | Sets the element within the collection at the current iterator position
//@parm element_t | elem | The element to jam into the collection
//@xref <c Iterator_T>

//@doc Iterator_T
//@mfunc void | Iterator_T | Remove | Removes the element within the collection at the current iterator position
//@xref <c Iterator_T>

//@doc Iterator_T
//@mfunc void | Iterator_T | Insert | Inserts the specified element into the collection at the current iterator position
//@parm element_t | elem | The element to jam into the collection
//@xref <c Iterator_T>

//@doc Iterator_T
//@class Template interface for an iterator.  The iterator class supports iteration
// over any collection that supports the ICollection_T interface.
//@tcarg class | element_t | The class of the element to retrieve as the iterator advances.
template <class element_t> class Iterator_T
{
protected:
	CCIterPos* m_pPos;
	ICollection_T<element_t>* m_pCollection;

public:
	Iterator_T<element_t>() {
	};

	Iterator_T<element_t>(ICollection_T<element_t>* pCollection) {
		Init(pCollection);
	};

	virtual ~Iterator_T() {
		delete m_pPos;
	};

	virtual void Init(ICollection_T<element_t>* pCollection) {
		m_pCollection = pCollection;
		ASSERT(m_pCollection);		// You must supply a collection!

		m_pPos = m_pCollection->iCreateIteratorPosition();
	};

	//@cmember
	/* Moves the iterator to the first element in the collection*/
	virtual void First() {
		m_pCollection->iFirst(m_pPos);
	};

	//@cmember
	/* Moves the iterator to the next element in the collection*/
	virtual void Next() {
		m_pCollection->iNext(m_pPos);
	};

	//@cmember
	/* Finds the next element equal to the specified after the current iterator position.  If found, TRUE is returned and the iterator is moved.*/
	virtual BOOL FindNext(element_t elem) {
		return m_pCollection->iFindNext(m_pPos, elem);
	};

	//@cmember
	/* Moves the iterator to the previous element in the collection*/
	virtual void Prev() {
		m_pCollection->iPrev(m_pPos);
	};

	//@cmember
	/* Finds the previous element equal to the specified before the current iterator position.  If found, TRUE is returned and the iterator is moved.*/
	virtual BOOL FindPrev(element_t elem) {
		return m_pCollection->iFindPrev(m_pPos, elem);
	};

	//@cmember
	/* Moves the iterator to the last element in the collection*/
	virtual void Last() {
		m_pCollection->iLast(m_pPos);
	};

	//@cmember
	/* Retrieves the element at the current iterator position*/
	virtual element_t Get() {
		return m_pCollection->iGet(m_pPos);
	};

	//@cmember
	/* Moves the iterator to and retrieves the first element in the collection*/
	inline element_t GetFirst() {
		First();
		return Get();
	};

	//@cmember
	/* Moves the iterator to and retrieves the next element in the collection*/
	virtual element_t GetNext() {
		Next();
		return Get();
	};

	//@cmember
	/* Moves the iterator to and retrieves the previous element in the collection*/
	virtual element_t GetPrev() {
		Prev();
		return Get();
	};

	//@cmember
	/* Moves the iterator to and retrieves the last element in the collection*/
	virtual element_t GetLast() {
		Last();
		return Get();
	};

	//@cmember
	/* Sets the element within the collection at the current iterator position*/
	virtual void Set(element_t elem) {
		m_pCollection->iSet(m_pPos, elem);
	};

	//@cmember
	/* Removes the element within the collection at the current iterator position*/
	virtual void Remove() {
		m_pCollection->iRemoveAt(m_pPos);
	};

	//@cmember
	/* Inserts the specified element into the collection at the current iterator position*/
	virtual void Insert(element_t elem) {
		m_pCollection->iInsert(m_pPos, elem);
	};
};


//@doc CCArray_T
//@class A Collection Classes array that supports the ICollection_T interface
// a therefore iteration with Iterator_T.  This class doesn't define a new
// interface, other than that inherited from MFC's CArray class.  The interface
// you should use is the Iterator_T class to access the elements stored in
// a CCArray_T.
//@tcarg class | element_t | The class of the element to store.
//@tcarg class | arg_t | The class of the arguments to certain CArray functions.
template < class element_t,	class arg_t	> class CCArray_T : 
	public CArray<element_t, arg_t>, public ICollection_T<element_t>
{
public:
	virtual element_t iGet(CCIterPos* pbp) const {
		CCIterPos_T<int>* pp = (CCIterPos_T<int>*)pbp;
		if (pp->m_value >= 0 && pp->m_value < GetSize())
			return GetAt(pp->m_value);
		else
			return NULL;
	};

	virtual void iFirst(CCIterPos* pbp) const {
		CCIterPos_T<int>* pp = (CCIterPos_T<int>*)pbp;
		pp->m_value = 0;
	};

	virtual void iNext(CCIterPos* pbp) const {
		CCIterPos_T<int>* pp = (CCIterPos_T<int>*)pbp;
		pp->m_value++;
	};

	virtual void iPrev(CCIterPos* pbp) const {
		CCIterPos_T<int>* pp = (CCIterPos_T<int>*)pbp;
		pp->m_value--;
	};

	virtual void iLast(CCIterPos* pbp) const {
		CCIterPos_T<int>* pp = (CCIterPos_T<int>*)pbp;
		pp->m_value = GetUpperBound();
	};

	virtual int GetSize() const {
		return CArray<element_t, arg_t>::GetSize();
	};

	virtual void iSet(CCIterPos* pbp, element_t elem) {
		CCIterPos_T<int>* pp = (CCIterPos_T<int>*)pbp;
		SetAt(pp->m_value, elem);
	};

	virtual void iRemoveAt(CCIterPos* pbp) {
		CCIterPos_T<int>* pp = (CCIterPos_T<int>*)pbp;
		RemoveAt(pp->m_value);
	};

	virtual void Remove(element_t elem) {
		int i;
		for (i = GetUpperBound(); i >= 0; i--) {
			if (elem == GetAt(i))
				RemoveAt(i);
		}
	};

// WNL: Fix for CArray::Append() for VC++ 4.2
#if _MFC_VER == 0x0420
	virtual int Append(const CCArray_T<element_t,arg_t>& src) {
		int nAppendIndex = GetSize();
		for(int i=0; i<src.GetSize(); i++)
			Add(src[i]);
		return nAppendIndex;
	};
#endif

	virtual void iInsert(CCIterPos* pbp, element_t elem) {
		CCIterPos_T<int>* pp = (CCIterPos_T<int>*)pbp;
		InsertAt(pp->m_value, elem);
	};

	virtual BOOL iFindNext(CCIterPos* pbp, element_t elem) const {
		CCIterPos_T<int>* pp = (CCIterPos_T<int>*)pbp;
		return FindNext(pp->m_value, elem);
	};

	virtual BOOL iFindPrev(CCIterPos* pbp, element_t elem) const {
		CCIterPos_T<int>* pp = (CCIterPos_T<int>*)pbp;
		return FindPrev(pp->m_value, elem);
	};

	virtual BOOL FindNext(int& pos, element_t elem) const {
		BOOL bFound = FALSE;
		int seek = pos;
		while (!bFound && ++seek < GetSize()) {
			if (elem == GetAt(seek))
				bFound = TRUE;
		}
		seek = -1;
		while (!bFound && ++seek < GetSize()) {
			if (elem == GetAt(seek))
				bFound = TRUE;
		}
		if (bFound)
			pos = seek;
		return bFound;
	};

	virtual BOOL FindPrev(int& pos, element_t elem) const {
		BOOL bFound = FALSE;
		int seek = pos;
		while (!bFound && --seek >= 0) {
			if (elem == GetAt(seek))
				bFound = TRUE;
		}
		seek = GetSize();
		while (!bFound && --seek >= 0) {
			if (elem == GetAt(seek))
				bFound = TRUE;
		}
		if (bFound)
			pos = seek;
		return bFound;
	};

	virtual void RemoveAll() {
		while (GetSize() > 0)
		{
			RemoveAt(0);
		}
	};

	virtual int FindIndex(element_t elem) const {
		int nIdx = -1;
		for (int nCurIdx = 0; nCurIdx < GetSize() && nIdx == -1; nCurIdx++)
		{
			if (elem == GetAt(nCurIdx))
				nIdx = nCurIdx;
		}
		return nIdx;
	};

	virtual CCIterPos* iCreateIteratorPosition() const {
		return new CCIterPos_T<int>;
	};
};

//@doc MvcSet_T
//@class A Collection Classes set that supports the ICollection_T interface
// a therefore iteration with Iterator_T.  This class is equivalent to
// the CCArray_T class.
//@tcarg class | element_t | The class of the element to store in the set.
template <class element_t>
class MvcSet_T : public CCArray_T<element_t, element_t>
{
};

//@doc CCStack_T
//@mfunc void | CCStack_T | CCStack_T | This constructor creates a CCStack_T object initialized with the specified maximum depth
//@parm int | nMaxSize | The maximum depth of the stack
//@xref <c CCStack_T>

//@doc CCStack_T
//@mfunc void | CCStack_T | SetMaxSize | Sets the maximum depth of the stack.  Once this depth is reached, the stack "rolls"
//@parm int | nMaxSize | The maximum depth of the stack
//@xref <c CCStack_T>

//@doc CCStack_T
//@mfunc void | CCStack_T | Push | Pushes a new element onto the stack
//@parm element_t | elem | The element to push onto the stack
//@xref <c CCStack_T>

//@doc CCStack_T
//@mfunc void | CCStack_T | Pop | Retrieves and deletes to newest element off the top of the stack
//@xref <c CCStack_T>

//@doc CCStack_T
//@mfunc void | CCStack_T | Peek | Retrieves but does not delete the newest element off the top of the stack
//@xref <c CCStack_T>

//@doc CCStack_T
//@mfunc void | CCStack_T | GetElementCount | Returns the number of elements that currently exist in the stack
//@xref <c CCStack_T>

//@doc CCStack_T
//@class A Collection Classes Stack that implements the First-In, First-Out
// method of storage.  In addition, this stack can function as a circular
// buffer.  Basically, when the stack reaches its maximum depth, the oldest
// element at the bottom of the stack is expired to make room for a new
// element.  Use the SetMaxSize to setup the maximum depth.
//@tcarg class | element_t | The class of the element to store in the stack.
//@tcarg class | arg_t | The class of the arguments to certain CArray functions.
template <class element_t, class arg_t> class CCStack_T : 
	public CArray<element_t, arg_t>, public IStack_T<element_t>
{
protected:
	int m_nIndex;
	int m_nMaxSize;
	int m_cElems;

public:
	CCStack_T<element_t, arg_t>() {
		m_nIndex = -1;
		m_cElems = 0;
		m_nMaxSize = -1;
	}

	//@cmember
	/* This constructor creates a CCStack_T object initialized with the specified maximum depth*/
	CCStack_T<element_t, arg_t>(int nMaxSize) {
		m_nIndex = -1;
		m_cElems = 0;
		SetMaxSize(nMaxSize);
	}

	//@cmember
	/* Sets the maximum depth of the stack.  Once this depth is reached, the stack "rolls"*/
	void SetMaxSize(int nMaxSize) {
		m_nMaxSize = nMaxSize;
		SetSize(m_nMaxSize);
	}

	//@cmember
	/* Returns the number of elements that currently exist in the stack*/
	int GetElementCount() const {
		return m_cElems;
	}

	//@cmember
	/* Pushes a new element onto the stack*/
	element_t Push(element_t elem) {
		element_t oldElem;
		m_nIndex = ( (m_nIndex+1) % m_nMaxSize );
		oldElem = GetAt(m_nIndex);
		SetAt(m_nIndex, elem);
		m_cElems++;
		m_cElems = mvcmin(m_cElems, m_nMaxSize);
		return oldElem;
	}

	//@cmember
	/* Retrieves but does not delete the newest element off the top of the stack*/
	element_t Peek() {
		return (m_nIndex >= 0 && m_nIndex < m_nMaxSize) ? GetAt(m_nIndex) : NULL;
	}

	//@cmember
	/* Retrieves and deletes to newest element off the top of the stack*/
	element_t Pop() {
		element_t elem;
		if (m_cElems > 0) {
			elem = GetAt(m_nIndex);
			SetAt(m_nIndex, NULL);
			m_nIndex = ( (m_nIndex-1) % m_nMaxSize );
			if (m_nIndex < 0)
				m_nIndex = m_nMaxSize-1;
			m_cElems--;
			m_cElems = mvcmax(m_cElems, 0);
		}
		else
			elem = NULL;
		return elem;
	}
};

//
// CMN Extension DLL
// Reset declaration context
//

#undef AFX_DATA
#define AFX_DATA
#undef AFXAPP_DATA
#define AFXAPP_DATA NEAR

#endif // __SECCOLLECT_H__

