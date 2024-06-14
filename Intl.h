#pragma once
#ifndef GUARD_INTL_H
#define GUARD_INTL_H

#include "Core.h"

class Intl : public Core {
public:
    // �⺻ �����ڿ� istream�� �Ű������� �޴� ������
    Intl() : toeic(0) {};
    Intl(std::istream& is) { read(is); };

    double grade() const override;
    std::istream& read(std::istream&) override;

protected:
    Intl* clone() const override { return new Intl(*this); }

private:
    double toeic; // ���� ����
};

#endif // GUARD_INTL_H