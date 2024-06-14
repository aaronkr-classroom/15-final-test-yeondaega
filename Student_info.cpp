// Student_info.cpp
#include <iostream>

#include "Core.h"
#include "Grad.h"
#include "Intl.h"
#include "Student_info.h"

using std::istream;

istream& Student_info::read(istream& is) {
	delete cp; // 이전 객체가 있으면 삭제

	char ch;
	is >> ch; // 학생 정보의 유형 파악

	if (ch == 'U') cp = new Core(is);
	else if (ch == 'G') cp = new Grad(is); // TODO: Grad 클래스 구현
	else if (ch == 'I') cp = new Intl(is); // TODO: Intl 클래스 구현

	return is;
}
Student_info::Student_info(const Student_info& s) : cp(0) {
	if (s.cp) cp = s.cp->clone();
}
Student_info& Student_info::operator=(const Student_info& s) {
	if (&s != this) {
		delete cp;

		if (s.cp) cp = s.cp->clone();
		else cp = 0;
	}
	return *this;
}