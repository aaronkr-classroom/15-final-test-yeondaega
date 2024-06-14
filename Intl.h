#pragma once
#ifndef GUARD_INTL_H
#define GUARD_INTL_H

#include "Core.h"

class Intl : public Core {
public:
    // 기본 생성자와 istream을 매개변수로 받는 생성자
    Intl() : toeic(0) {};
    Intl(std::istream& is) { read(is); };

    double grade() const override;
    std::istream& read(std::istream&) override;

protected:
    Intl* clone() const override { return new Intl(*this); }

private:
    double toeic; // 토익 점수
};

#endif // GUARD_INTL_H