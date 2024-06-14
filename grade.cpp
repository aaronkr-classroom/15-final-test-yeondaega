// grade.cpp

#include <algorithm>
#include <list>
#include <vector>
#include <stdexcept>

#include "grade.h"
#include "median.h"

using namespace std;

// �߰����� ����, �⸻���� ����, ���� ���� ��������
// �л��� ���� ������ ����
double grade(double mt, double ft, double hw) {
    return 0.2 * mt + 0.4 * ft + 0.4 * hw;
}

// �߰����� ����, �⸻���� ����, ���� ������ ���ͷ�
// �л��� ���� ������ ����.
// �� �Լ��� �μ��� �����ϱ� �ʰ� median �Լ��� �ش� �۾��� ����.
double grade(double mt, double ft, const vector<double>& hw) {
    if (hw.size() == 0)
        throw domain_error("No homework!");

    return grade(mt, ft, median(hw));
}
