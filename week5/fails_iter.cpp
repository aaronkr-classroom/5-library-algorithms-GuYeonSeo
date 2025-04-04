//fails_iter.cpp
#include <vector>
#include "Student_info.h"
#include "grade.h"

using std::vector;

//3��° ���� �л��� �����ϴ� �л� ������
//�ε��� ��� �ݺ��� ����ϱ�(������ ����)
vector<Student_info> extract_fails(vector<Student_info>& students) {
	vector<Student_info> fial;
	vector<Student_info>::iterator iter = students.begin();

	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fial.push_back(*iter);
			//���� ���� i �ε����� �ִ� �л� ����
			iter = students.erase(iter);
		}
		else {
			++iter;
		}
	}
	return fial;
}