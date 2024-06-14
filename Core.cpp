// Core.cpp

#include "Core.h"
#include "grade.h"

using namespace std;

// Core Ŭ������ ��� �Լ� ����
istream& read_hw(istream& in, vector<double>& hw);

string Core::getName() const { return name; }
double Core::grade() const {
	return ::grade(midterm, final, homework);
}

/**
 * @brief �������� ����ϴ� �����͸� �о���̴� �Լ�
 *
 * @param in
 * @return istream&
 *
 * @see Core::read
 *
 * @note Core Ŭ������ read_common �Լ��� �л� name, midterm, final ������ �о���̴� �Լ��̴�.
 */
istream& Core::read_common(istream& in) {
	// �л� �̸��� ���� ������ �Է¹޾� ����
	in >> name >> midterm >> final;
	return in;
}
istream& Core::read(istream& in) {
	read_common(in);
	read_hw(in, homework); // Student_info.h�� �ִ�.
	return in;
}

// ���� �Լ� ����
bool compare(const Core& c1, const Core& c2) {
	return c1.getName() < c2.getName();
}

bool compare_grades(const Core& c1, const Core& c2) {
	return c1.grade() < c2.grade(); // ���� �Լ� ����ؾߵ�
}