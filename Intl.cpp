#include "Intl.h"
#include "grade.h"


// Core.cpp ���Ͽ��� ������ read_hw �Լ��� ����
istream& read_hw(istream& in, vector<double>& hw);


double Intl::grade() const {
    return std::min(Core::grade(), toeic);
}

std::istream& Intl::read(std::istream& in) {
    Core::read_common(in);
    in >> toeic;
    read_hw(in, Core::homework);
    return in;
}