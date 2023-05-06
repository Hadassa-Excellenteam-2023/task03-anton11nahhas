#pragma once

#include <iostream>
#include <list>
#include <exception>
#include "MyComparator.h"


template<typename T>
class PriorityQueue {

public:

	PriorityQueue() { };//add a constructor
	
	void push(const T&);
	T poll();

private:
	MyComparator m_comparator;// create a Mycomparator object
	std::list<T> m_list;//list which implements a queue
};

//this template function receives a val of type T, checks if the list is empty,
//if so push the val to the stack, if the stack is not empty, locate the correct
//position with the help of the comparator member. then push the val to that 
//correct position
template <typename T>
void PriorityQueue<T>::push(const T& val){
	if (m_list.empty())
		m_list.push_back(val);
	
	else{
		auto iter = m_list.begin();
		while (iter != m_list.end() && m_comparator(val, *iter) < 0)
			++iter;
		
		m_list.insert(iter, val);
	}
}


//this template function returns a value of type T, if the list is empty throw 
//an exception indicating that the queue is empty.If not, retreive the last 
//value in the stack and store it in a T variable, then pop_back the last cell.
template< typename T>
T PriorityQueue<T>::poll(){
	if (m_list.empty())
		throw std::runtime_error("PriorityQueue empty !");
	

	T pulled_val = m_list.back();
	m_list.pop_back();
	return pulled_val;
}
