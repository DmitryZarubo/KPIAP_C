#pragma once
#define CLASS_LIST_H
#include <iostream>
#include "class_iterator.h"
#include "class_Node.h"
namespace LIST {
	using std::allocator;
	using namespace NODE;
	using namespace std;
	//#ifndef CLASS_LIST_H
	template <class T, class Allocator = allocator<Node<T>>>
	class List {
	public:
		using size_type = typename size_t;
		using value_type = typename T;
		using reference = typename T&;
		using const_reference = typename const T&;
		using iterator = typename LIST_ITERATOR::_Iterator<T>;
		using const_iterator = typename LIST_ITERATOR::const_Iterator<T>;
		using node = typename Node<T>;
		using AllocatorPointer = typename Node<T>*;
	protected:
		Allocator ListAlloc;  //allocates memory for nodes<T>
		typename Allocator::pointer BeginListPtr; // points on the first node<T> of the list
		typename Allocator::pointer EndListPtr;   //points on the last node<T> of the list
		size_type ListSize;  // number contained nodes<T>
	private:
		void EndListPtrMove(iterator new_end) { EndListPtr = new_end._node(); };
		void EndListPtrMove(typename Allocator::pointer new_end) { EndListPtr = new_end; };
		void BeginListPtrMove(iterator new_begin) { BeginListPtr = new_begin._node(); };
		void BeginListPtrMove(typename Allocator::pointer new_begin) { BeginListPtr = new_begin; };
	public:
		List() : BeginListPtr(nullptr),EndListPtr(nullptr),  ListAlloc(), ListSize(0) {};
		List( List& _list);
		bool empty()const { return (bool)(ListSize == 0); };
		size_type size()const { return ListSize; };
		iterator begin();
		iterator end();
		iterator erase(iterator node_it);
		iterator erase(iterator start, iterator end);
		iterator insert(iterator next_node_it, const T& val);
		iterator operator[](int index);
		const_iterator begin() const;
		const_iterator end() const;
		void pop_front();
		void pop_back();
		void push_back(const T& val);
		void push_front(const T& val);
		void showList();
		void clear();
		reference front();
		reference back();
		const_reference front() const;
		const_reference back() const;
		~List();
	};//class List<T>;
	


	template <class T, class Allocator> List<T, Allocator>::List( List<T,Allocator>& _list)
	{
		EndListPtr = nullptr;
		BeginListPtr = nullptr;
		ListSize = 0;
		iterator it(_list.begin());
		while (it != _list.end())
		{
			push_back(*it);
			++it;
		}
	}//List(const List<T>&);
	
	template <class T, class Allocator> void List<T, Allocator>::showList()
	{
		iterator it(begin());
		while (it != end())
		{
			cout << *it << " ";
			++it;
		}
	}// showList();


	template <class T, class Allocator> void List<T, Allocator>::push_front(const T& val)
	{
		AllocatorPointer temp = ListAlloc.allocate(1);
		temp->setItem(val);
		if (empty())
		{
			BeginListPtrMove(temp);
			EndListPtrMove(temp);
			ListSize++;
		}
		else
		{
			temp->Next() = BeginListPtr;
			BeginListPtrMove(temp);
			ListSize++;
		}
	}// push_front(const T& bal)
	template <class T, class Allocator> void List<T, Allocator>::push_back(const T& val)
	{
		AllocatorPointer temp = ListAlloc.allocate(1);
		temp->setItem(val);
		if (empty())
		{
			BeginListPtrMove(temp);
			EndListPtrMove(temp);
			ListSize++;
		}
		else
		{
			EndListPtr->Next() = temp;
			EndListPtrMove(temp);
			ListSize++;
		}
	}//push_back(const T& val);


	template <class T, class Allocator> void List<T, Allocator>::pop_front()
	{
		if (!empty())
		{
			iterator it(BeginListPtr);
			BeginListPtrMove (BeginListPtr->Next());
			ListAlloc.deallocate(it._node(), 1);
			it._node() = nullptr;
			ListSize-=1;
		}
		else
			return;
	}//pop_front();
	template <class T, class Allocator> void List<T, Allocator>::pop_back()
	{
		if (!empty())
		{
			iterator it1(BeginListPtr), it2(EndListPtr);
			while (it1->Next() != it2._node())
				++it1;
			EndListPtrMove(it1);
			EndListPtr->Next() = nullptr;
			ListAlloc.deallocate(it2._node(), 1);
			it2._node() = nullptr;
			ListSize-=1;
		}
		else
			return;
	}//pop_back();


	template <class T, class Allocator> typename List<T, Allocator>::iterator List<T, Allocator>::erase(typename iterator obj_it)
	{
		if (!empty()) 
		{
			if ((obj_it == EndListPtr || obj_it == end()) && obj_it != BeginListPtr)
			{
				pop_back();
				return iterator(EndListPtr->Next());
			}
			else if (obj_it == begin())
			{
				pop_front();
				return iterator(BeginListPtr);
			}
			else {
				iterator itBeforeDelited(BeginListPtr), itAfterDelited(obj_it->Next());
				while (itBeforeDelited->Next() != obj_it._node())
					++itBeforeDelited;
				itBeforeDelited->Next() = itAfterDelited._node();
				ListAlloc.deallocate(obj_it._node(), 1);
				ListSize -= 1;
				return itAfterDelited;
			}
		}// if(ListSize!=0)
		else
			return  iterator(nullptr);
	}//erase(iterator node_it)
	template <class T, class Allocator> typename List<T, Allocator>::iterator List<T, Allocator>::erase(iterator _start, iterator _end)
	{
		if (!empty())
		{
			iterator itStart(_start), itEnd(_end);
			if (itStart == itEnd)
				return erase(itStart);
			else if (itStart == begin() && itEnd == end())
			{
				clear();
				return iterator(nullptr);
			}//itStart == begin() && itEnd == end()
			else if(itStart == begin() && itEnd != end())
			{
				iterator returnIt(itEnd->Next());
				while (begin() != returnIt)
					pop_front();
				return returnIt;
			}//itStart == begin() && itEnd != end()
			else if (itStart != begin() && (itEnd == EndListPtr|| itEnd ==end()))
			{
				while (itStart->Next() != end()._node())
					pop_back();
				pop_back();
				return iterator(nullptr);
			}//itStart != begin() && itEnd == end()
			else
			{
				iterator EraseEnd(itEnd->Next());
				while (itStart != EraseEnd)
					itStart = erase(itStart);
				return EraseEnd;
			}//itStart != begin() && itEnd != end()
		}//if (ListSize != 0)
		else
			return iterator(nullptr);
	}//erase(iterator start, iterator end)5

	/* insert */
	template <class T, class Allocator> typename List<T, Allocator>::iterator List<T, Allocator>::insert(iterator next_obj_it, const T& val)
	{
		typename Allocator::pointer insertObj = ListAlloc.allocate(1);
		insertObj->setItem(val);
		iterator it(BeginListPtr);
		if (BeginListPtr == next_obj_it._node())
		{
			insertObj->Next() = BeginListPtr;
			BeginListPtr = insertObj;
		}
		else if(end() == next_obj_it._node())
		{
			while (it->Next() != next_obj_it._node())
				++it;
			it->Next() = insertObj;
			EndListPtr = insertObj;
		}
		else
		{
			while (it->Next() != next_obj_it._node())
				++it;
			it->Next() = insertObj;
			insertObj->Next() = next_obj_it._node();
			++it;
		}
		ListSize += 1;
		return it;
	}//insert(iterator next_obj_it, const node& val)

	/* end//back */
	template <class T, class Allocator> typename List<T, Allocator>::iterator List<T, Allocator>::begin()
	{
		iterator result(BeginListPtr);
		return result;
	}//begin();
	template <class T, class Allocator> typename List<T, Allocator>::const_iterator List<T, Allocator>::begin() const
	{
		const_iterator result(BeginListPtr);
		return result;
	}//begin()const;
	template <class T, class Allocator> typename List<T, Allocator>::iterator List<T, Allocator>::end()
	{
		iterator result(EndListPtr->Next());
		return result;
	}//end();
	template <class T, class Allocator> typename List<T, Allocator>::const_iterator List<T, Allocator>::end() const
	{
		const_iterator result(EndListPtr->Next());
		return result;
	}//end()const ;


	template <class T, class Allocator> typename List<T, Allocator>::reference List<T, Allocator>::front()
	{
		if(BeginListPtr)
		return reference(*BeginListPtr);
	}// front()
	template <class T, class Allocator> typename List<T, Allocator>::reference List<T, Allocator>::back()
	{
		if (BeginListPtr)
		return reference(*EndListPtr);
	}// back ()
	template <class T, class Allocator> typename List<T, Allocator>::const_reference List<T, Allocator>::front() const
	{
		if (BeginListPtr)
		return const_reference(*BeginListPtr);
	}// front()const
	template <class T, class Allocator> typename List<T, Allocator>::const_reference List<T, Allocator>::back() const
	{
		if (BeginListPtr)
		return const_reference(*EndListPtr);
	}// back()const

	template <class T, class Allocator> typename List<T, Allocator>::iterator List<T, Allocator>::operator[](int index)
	{
		if (!empty())
		{
			iterator result(nullptr);
			if (index <= ListSize)
			{
				result = BeginListPtr;
				for (int i = 0; i < index; i++)
					++result;
			}
			return result;
		}
		else
			return iterator(nullptr);
	}// operator[](int index);


	template <class T, class Allocator> void List<T, Allocator>::clear()
	{
		while (!empty())
			pop_front();
	}// clear()
	template <class T, class Allocator> List<T, Allocator>::~List()
	{
		while (!empty())
			pop_front();
	}// ~List()



}//namespace LIST
//#endif //CLASS_LIST_H