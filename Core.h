#pragma once
# ifndef GUARD_CORE_H
# define GUARD_CORE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Core {
public:
	// Core Ŭ������ �⺻ �����ڿ� �⺻ ��
	Core() : midterm(0), final(0) {};

	// istream���� Core ��ü ����
	Core(istream& is) { read(is); };

	string getName() const;
	virtual double grade() const; // ���� �Լ�
	virtual istream& read(istream&); // ���� �Լ�

	virtual ~Core() {} // ���� �Ҹ���
protected:
	istream& read_common(istream&); // �̸�, ����, ����
	double midterm, final;
	vector<double> homework;

	virtual Core* clone() const { return new Core(*this); }
private:
	string name;
	friend class Student_info;
};

bool compare(const Core&, const Core&);
bool compare_grades(const Core&, const Core&);

# endif
