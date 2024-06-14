#include "Intl.h"
#include "grade.h"


// Core.cpp 파일에서 가져온 read_hw 함수의 정의
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