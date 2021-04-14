// PR2-Üben.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<stdexcept>
#include<functional>
#include<algorithm>
#include<numeric>
#include<memory>
#include<iterator>
#include "vector.h"
using namespace std;

size_t amount_more_than(const string werte, size_t n) {
	set<char> test2;
	vector<char> test;

	for_each(werte.begin(), werte.end(), [&](char x) {
        if (count(werte.begin(), werte.end(), x) > n)
            test.push_back(x);

		});

	std::sort(test.begin(), test.end());
	auto last = std::unique(test.begin(), test.end());
	test.erase(last, test.end());
	return test.size();
}

bool pruf(string eins) {
	string zwei = eins;

	copy_backward(eins.begin(), eins.end(), zwei.end());
	return eins == zwei;



}
void test_set() {
	set<int> set1;
	for (size_t i{ 0 }; i < 100; i++) {
		set1.insert(i);
	}
	
	vector<int> vec1;
	vec1.insert(vec1.begin(), set1.begin(), set1.end());
	for (auto v : set1) {
		vec1.push_back(v);
	}
	auto max = max_element(vec1.begin() + 14, vec1.begin() + 24);
	cout << *max;
	set<int> set2;
	set2.insert(vec1.begin(), vec1.end());
	cout << *set2.find(23);
}

void test_r() {
	vector<int> test{ 1,2,3,4,5,2,9,10,2,50 };
	auto max = find(test.begin(), test.end(),2);
	cout << *max << "\n";
	cout << *(++max) << "\n";
	auto max2 = find(test.rbegin(), test.rend(),2);
	cout << *max2 << "\n";
	cout << *(++max2) << "\n";
}

void setorder() {
	struct Compare {
		bool operator()(int a, int b) const {
			return (a > b);
		}
	};
	using myset = std::set<int, Compare>;

	myset test{ 1,2,3,4,5,6,7,8,1,2,1,2,3 };
	for (auto v : test) std::cout << v;
}

void maptest() {
	map<int, set<string>> test;
	set<string> ins{ "hello" };
	test.insert({ 10,ins });
	std::cout << test.size();

	map<int, string> test2;
	test2.insert({ 10,"testi" });
	test2.insert_or_assign( 10,"was" );
	std::cout << test2[10];
	for (auto v : test2) std::cout << v.first;


	auto it = test2.begin();
	(*it).first;             // the key value (of type Key)
	(*it).second;            // the mapped value (of type T)
	(*it);                   // the "element value" (of type pair<const Key,T>)
	std::cout << (*it).first;
}
template<typename T>
void template_test(T value) {
	std::cout << value;

}


void error_test() {
	throw runtime_error("");




}

void error_test2() {
	try {
		error_test();
	}
	catch(runtime_error x) {
		std::cout << "tester";
	}
}

void vectest() {
	Vector<int> test{ 1,2,3,4,5,6 };
	auto it = test.beginX();
	int i = 0;
	while (i<10) {
		std::cout << *it << "\n";
		++it;
		std::cout << *it << "\n";
		++it;
		std::cout << *it << "\n";
		++it;
		std::cout << *it << "\n";
		++it;
		std::cout << *it << "\n";
		++it;
		std::cout << *it << "\n";
		i++;
		if (it == test.endX()) std::cout << "ENDENDEND";
	}



}

void transformer() {

	string tester{ "HelloWorld" };
	auto plan = transform(tester.begin(), tester.end(), tester.begin(), [&](char a) { // oder alternativ statt lamda nur ::tolower
		return toupper(a); // return wichtig
		});
	cout << tester;

}

void transformer2() {

	vector<string> tester{ "hello","world","What","IS","Goint","ON" };
	auto plan = transform(tester.begin(), tester.end(), tester.begin(), [&](string a) { // oder alternativ statt lamda nur ::tolower
		return a + "add";
		});
	for (auto v : tester)
		cout << v;

}

void transformer3() {

	vector<string> tester{ "hello","world","What","IS","Goint","ON","ON" };
	auto plan = transform(tester.begin(), tester.end(), tester.begin(), [&](string a) { // oder alternativ statt lamda nur ::tolower
		transform(a.begin(), a.end(),a.begin(), ::tolower);
		return a;
		});

	set<string> test;
	test.insert(tester.begin(), tester.end());
	vector<string> ins;
	ins.insert(ins.begin(), test.begin(), test.end());
	reverse(ins.begin(), ins.end());
	for (auto v : ins)
		cout << v;
}
void rumspielen() {

	vector<string> test{ "hello","world" };
	if (find(test.begin(), test.end(), "hello") != test.end())
		std::cout << "hahaha";


}

void copy_back() {
	vector<int> test{ 1,2,3,4,5,6,7,8,9 };
	reverse(test.begin(), test.end());
	for (auto v : test)
		cout << v;
	vector<int> tester;
	copy(test.rbegin(), test.rend(), back_inserter(tester));
	for (auto v : tester)
		cout << v;

}
int main(){
	
	string test{ "Haben wir den Umweltschutz den WIR BRAUCHEN UND BRAUCHEN WIR DEN UMWELTSCHUTZ DEN WIR HABEN ?" };
	transform(test.begin(), test.end(), ::tolower);
	transform
		(

		


}

/*
 IteratorC beginC() {
		return IteratorC(values + sz - 1, values - 1);
	}
	IteratorC endC() {
		return IteratorC(values-1, values - 1);
	}

	class IteratorC {
	public:
		using value_type = Vector::value_type;
		using reference = Vector::reference;
		using pointer = Vector::pointer;
		using difference_type = Vector::difference_type;
		using iterator_category = std::forward_iterator_tag;
	private:
		pointer ptr;
		pointer endptr;
	public:
		IteratorC() : ptr{ nullptr } {}
		IteratorC(pointer pt,pointer endptr) : ptr{ pt },endptr{ endptr } {}
		reference operator*() { // Retourniert den Wert des von ptr referenzierten Wertes.
			return *ptr;
		}
		pointer operator->() { // return pointer auf referenzierten Wert
			return ptr;
		}
		bool operator==(const const_iterator& x)const {
			ConstIterator neu(ptr);
			return(x.operator==(neu));
		}
		bool operator!=(const const_iterator& x)const {
			// return (ptr!=x.getPointer());
			return !(this->operator==(x));
		}
		IteratorC& operator++() { // Prefix
				if (ptr!=endptr) {
					ptr--;
			}
				if (ptr!=endptr) {
					ptr--;
			}
			return *this;
		}


		iterator operator++(int x) { // Postfix
			Iterator neu(ptr);
			ptr++;
			return neu;
		}

		operator const_iterator()const {
			return ConstIterator(ptr);
		}





	};

*/