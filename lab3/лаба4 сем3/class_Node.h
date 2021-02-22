#pragma once

namespace NODE {
template <class T>
	class Node {
	protected:
		T item;
		Node* next;
		Node* previous;
	public:
		Node() : item(), next(nullptr), previous(nullptr) {};
		Node(const T _item, Node* _next= nullptr , Node* _prev= nullptr) : item(_item), next(_next), previous(_prev) {};
		Node(Node& node) { item = node.item; next = node.next; previous = node.previous; };
		void setItem(const T& _item) { item = _item; };
		/*void setNext(Node* _next) { next = _next; };
		void setPrevious(Node* _prev) { previous = _prev; };*/
		Node& operator=(Node& node) { item = node.item; next = node.next; previous = node.previous; return *this; };
		T& Item() { return item; };
		Node*& Next() { return next; };
		Node*& Prev() { return previous; };
		~Node() {};
	};
}