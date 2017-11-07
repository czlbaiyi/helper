/*********************************************************************
 * Created:       2017/11/03
 * File name:     zllist.h
 * Author:        ChenZhonglin
 * Revision:      1.0.0
 *
 * Copyright (C)  2017 - 2020 , All Rights Reserved.
 *
 * Purpose: 
 *********************************************************************/

#ifndef __ZLLIST_H_2017_11_03__
#define __ZLLIST_H_2017_11_03__


#include <list>

template<class _Ty>
class ZLList
{
public:
	typedef typename std::list<_Ty>::iterator iterator;
	typedef typename std::list<_Ty>::const_iterator const_iterator;
	typedef typename std::list<_Ty>::reverse_iterator reverse_iterator;
	typedef typename std::list<_Ty>::const_reference const_reference;
	typedef typename std::list<_Ty>::reference reference;

public:
	ZLList()
		: mysize(0)
	{
	}

public:
	iterator insert(const_iterator _Where, _Ty _Val)
	{
		++mysize;
		return  mylist.insert(_Where, _Val);
	}

	iterator insert(iterator _Where, _Ty _Val)
	{
		++mysize;
		return  mylist.insert(_Where, _Val);
	}

	iterator erase(const_iterator _Where)
	{
		--mysize;
		return mylist.erase(_Where);
	}

	iterator erase(iterator _Where)
	{
		--mysize;
		return mylist.erase(_Where);
	}

	void push_front(_Ty _Val)
	{	// insert element at beginning
		++mysize;
		return  mylist.push_front(_Val);
	}

	void pop_front()
	{	// erase element at beginning
		--mysize;
		return  mylist.pop_front();
	}

	void push_back(_Ty _Val)
	{
		++mysize;
		return  mylist.push_back(_Val);
	}

	void pop_back()
	{	// erase element at end
		--mysize;
		return  mylist.pop_back();
	}

	reference front()
	{	// return first element of mutable sequence
		return mylist.front();
	}

	const_reference front() const
	{	// return first element of nonmutable sequence
		return mylist.front();
	}

	reference back()
	{	// return last element of mutable sequence
		return mylist.back();
	}

	const_reference back() const
	{	// return last element of nonmutable sequence
		return  mylist.back();
	}

	iterator begin()
	{
		return mylist.begin();
	}

	iterator end()
	{
		return mylist.end();
	}

	reverse_iterator rbegin()
	{
		return mylist.rbegin();
	}

	reverse_iterator rend()
	{
		return mylist.rend();
	}

	void clear()
	{
		mysize = 0;
		return mylist.clear();
	}

	size_t size()
	{
		return mysize;
	}


	template<class _Pr2>
	void sort(_Pr2 _Pred)
	{
		return mylist.sort(_Pred);
	}

	void sort()
	{
		return mylist.sort();
	}


private:
	std::list<_Ty> mylist;
	size_t mysize;
};


#endif
