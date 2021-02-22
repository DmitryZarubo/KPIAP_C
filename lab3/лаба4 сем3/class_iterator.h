#pragma once
#define CLASS_ITERATOR_H
#include <iostream>
#include"class_Node.h"
//#ifndef CLASS_ITERATOR_H
namespace LIST_ITERATOR {


	/****  const_Iterator ****/
	template <class T>
	class const_Iterator {
	public:
		using tNode = typename NODE::Node<T>;
	protected:
		tNode* node;
	public:
		tNode*& _node() { return node; }
		const_Iterator(tNode* _node = nullptr) { node = _node; };
		const_Iterator(const const_Iterator& it) { node = it.node; };
		const T& operator*() const { return node->Item(); };
		const_Iterator& operator=(const const_Iterator& it) { node = it.node; return *this; };
		const_Iterator& operator=(tNode* _node) { node = _node; return *this; };
		const virtual const_Iterator& operator++() ;
		const virtual const_Iterator operator++(int);
	};//superclass const_Iterator<T>
	template<class T> const const_Iterator<T>& const_Iterator<T>::operator++()  
	{
		node = node->Next();
		return *this;
	}
	template<class T> const const_Iterator<T> const_Iterator<T>::operator++(int)
	{
		const_Iterator<T> result(*this);
		++(*this);
		return result;
	}// const_Iterator's methods



	/****  _Iterator ****/
	template <class T>
	class _Iterator : public const_Iterator<T> {
	public:
		_Iterator( const_Iterator<T>::tNode* _node = nullptr) :const_Iterator<T>(_node) {};
		_Iterator(const _Iterator<T>& it) { this->node = it.node; };
		T& operator*() { return const_Iterator<T>::node->Item(); };
		const_Iterator<T>::tNode* operator->() { return const_Iterator<T>::node; };
		bool operator==(const _Iterator& it) const { return (const_Iterator<T>::node == it.const_Iterator<T>::node); };
		bool operator!=(const _Iterator& it)const { return (const_Iterator<T>::node != it.const_Iterator<T>::node); };
		~_Iterator() {};
	};//class _Iterator<T>
	



	/****  const_reverse_Iterator ****/
	template <class T>
	class const_reverse_Iterator : public const_Iterator<T>
	{
	public:
		const_reverse_Iterator( const_Iterator<T>::tNode* _node = nullptr) : const_Iterator<T>(_node) {};
		const_reverse_Iterator(const const_reverse_Iterator& it) : const_Iterator<T>((const_Iterator<T>&)it) {};
		const const_Iterator<T>& operator++() override;
		const const_Iterator<T>& operator++(int) override;
		~const_reverse_Iterator() {};
	};//class const_reverse_Iterator<T>
	template <class T> const const_Iterator<T>& const_reverse_Iterator<T>::operator++() 
	{
		const_Iterator<T>::node = const_Iterator<T>::node->Prev();
		return *this;
	}
	template <class T> const const_Iterator<T>& const_reverse_Iterator<T>::operator++(int)
	{
		const_Iterator<T> result(*this);
		++(*this);
		return result;
	}//const_reverse_Iterator's methods 
	



	/****  reverse_Iterator ****/
	template <class T>
	class reverse_Iterator : public const_reverse_Iterator<T> {
	public:
		reverse_Iterator( const_Iterator<T>::tNode* _node = nullptr) : const_reverse_Iterator<T>(_node) {};
		reverse_Iterator(const reverse_Iterator& it) : const_reverse_Iterator<T>((const_Iterator<T>&)it) {};
		T& operator*() { return const_Iterator<T>::node->Item(); };
		reverse_Iterator* operator->() { return this; };
		bool operator==(const reverse_Iterator& it) const { return (const_Iterator<T>::node == it.const_Iterator<T>::node); };
		bool operator!=(const reverse_Iterator& it)const { return (const_Iterator<T>::node != it.const_Iterator<T>::node); };
	};//class reverse_Iterator<T>
	
}//namespace ITERATOR
//#endif //CLASS_ITERATOR_H