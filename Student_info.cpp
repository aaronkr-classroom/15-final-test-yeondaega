// Student_info.cpp
#include <iostream>

#include "Core.h"
#include "Grad.h"
#include "Student_info.h"
#include "Intl.h"

using std::istream;

istream& Student_info::read(istream& is) {
    delete cp; // 이전 객체가 있으면 삭제

    char ch;
    is >> ch; // 학생 정보의 유형 파악

    if (ch == 'U') {
        // 학부 학생 생성
        cp = new Core(is);
    }
    else if (ch == 'G') {
        // 대학원 학생 생성
        cp = new Grad(is);
    }
    else if (ch == 'I') {
        // 국제 학생 생성
        cp = new Intl(is);
    }


    return is;
}
    

Student_info::Student_info(const Student_info & s) : cp(0) {
    if (s.cp) cp = s.cp->clone();
}
Student_info& Student_info::operator=(const Student_info & s) {
    if (&s != this) {
        delete cp;

        if (s.cp) cp = s.cp->clone();
        else cp = 0;
    }
    return *this;
}


