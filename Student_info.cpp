// Student_info.cpp
#include <iostream>

#include "Core.h"
#include "Grad.h"
#include "Student_info.h"
#include "Intl.h"

using std::istream;

istream& Student_info::read(istream& is) {
    delete cp; // ���� ��ü�� ������ ����

    char ch;
    is >> ch; // �л� ������ ���� �ľ�

    if (ch == 'U') {
        // �к� �л� ����
        cp = new Core(is);
    }
    else if (ch == 'G') {
        // ���п� �л� ����
        cp = new Grad(is);
    }
    else if (ch == 'I') {
        // ���� �л� ����
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


