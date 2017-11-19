/*********************************************************************
* Created:       2017/11/19
* File name:     unsort_fast_map.h
* Author:        ChenZhonglin
* Revision:      1.0.0
*
* Copyright (C)  2017 - 2020 , All Rights Reserved.
*
* Purpose:
*********************************************************************/

#ifndef __UNSORT_FAST_MAP_H_2017_11_19__
#define __UNSORT_FAST_MAP_H_2017_11_19__

#include <map>
#include <vector>
#include "assert.h"

/************************************************************************/
/* 必须是无序的															*/
/* Value必须实现GetKey方法，用于作为Key，并且这个Key不会被改变			*/
/* 第二位只支持指针（1.实现原因，2.避免Vecter申请的空间太大）           */
/************************************************************************/
template<class _Kty, class _Ty>
class UnsortFastMap
{
public:
	typedef typename std::map<_Kty, size_t>::iterator iterator;

public:
	UnsortFastMap()
	{
	}

public:

	void insert(_Ty _Val)
	{
		_Kty _key = _Val->GetKey();
		iterator it = mymap.find(_key);
		if (it != mymap.end())
		{
			assert(false);
		}
		else
		{
			myvector.push_back(_Val);
			mymap[_key] = myvector.size() - 1;
		}
	}

	_Ty find(_Kty _key)
	{
		iterator it = mymap.find(_key);
		if (it != mymap.end())
		{
			return myvector[it->second];
		}
		return NULL;
	}

	void erase(_Ty _Val, bool _delete = false)
	{
		erase(_Val->GetKey(), _delete);
	}

	void erase(_Kty _key, bool _delete = false)
	{
		iterator it = mymap.find(_key);
		if (it != mymap.end())
		{
			_Ty lastData = myvector[myvector.size() - 1];
			iterator swapIt = mymap.find(lastData->GetKey());
			if (swapIt != mymap.end())
			{
				if (_delete)
				{
					delete myvector[it->second];
				}
				myvector[it->second] = lastData;
				swapIt->second = it->second;
				myvector.pop_back();
				mymap.erase(it);
			}
			else
			{
				assert(false);
			}
		}
		else
		{
			assert(false);
		}
	}

	void clear(bool _delete = false)
	{
		if (_delete)
		{
			for (int i = 0; i < (int)myvector.size(); ++i)
			{
				delete myvector[i];
			}
		}
		mymap.clear();
		myvector.clear();
	}

	size_t size()
	{
		return myvector.size();
	}

	bool empty() const
	{
		return myvector.empty();
	}

	void resetIdxBegin() {
		m_nIdx = 0;
	}

	void resetIdxEnd() {
		m_nIdx = myvector.size() - 1;
	}

	_Ty getByIdx(size_t idx) {
		return myvector[idx];
	}

	_Ty next() {
		if (m_nIdx >= 0 && m_nIdx < myvector.size())
		{
			return myvector[m_nIdx++];
		}
		return NULL;
	}

	_Ty pre() {
		if (m_nIdx >= 0 && m_nIdx < myvector.size())
		{
			return myvector[m_nIdx--];
		}
		return NULL;
	}

private:
	std::map<_Kty, size_t> mymap;
	std::vector<_Ty> myvector;
	int m_nIdx;
};

class TestClass {
public:
	int a;
public:
	int GetKey() {
		return a;
	}
};

#endif