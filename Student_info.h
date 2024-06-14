#pragma once
// Student_info.h
#ifndef GUARD_STDINFO_H
#define GUARD_STDINFO_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Core.h" // private ���� cp ����

using namespace std;

class Student_info {
public:
	// ������ �� ���� ����
	Student_info() : cp(0) { }
	Student_info(istream& is) : cp(0) { read(is); }
	Student_info(const Student_info&);
	Student_info& operator=(const Student_info&);
	// ~Student_info() { delete cp; }

	// ��� �Լ�
	istream& read(istream&);

	string getName() const {
		if (cp) return cp->getName();
		else throw runtime_error("Unitialized Student!");
	}
	double grade() const {
		if (cp) return cp->grade();
		else throw runtime_error("Unitialized Student!");
	}
	static bool compare(const Student_info& s1, Student_info& s2) {
		return s1.getName() < s2.getName();
	}
private:
	Core* cp;
};

#endif