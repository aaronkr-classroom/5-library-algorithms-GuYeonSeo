//fails_vec1.cpp
#include <vector>
#include "Student_info.h"
#include "grade.h"

using std::vector;

//1번째 과락 학생과 성공하는 학생 나누기(메모리 사용량이 큼)
vector<Student_info> extract_fails(vector<Student_info>& students) {
	vector<Student_info> pass, fial;

	for (vector<Student_info>::size_type i = 0;
		i != students.size(); ++i) {
		if (fgrade(students[i])) {
			fial.push_back(students[i]);
		}
		else {
			pass.push_back(students[i]);
		}
	}
	students = pass; //원래 있는 students 벡터에서 pass학생만 유지
	return fial;
}