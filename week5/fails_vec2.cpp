//fails_vec2.cpp
#include <vector>
#include "Student_info.h"
#include "grade.h"

using std::vector;

//2번째 과락 학생과 성공하는 학생 나누기(느림)
vector<Student_info> extract_fails(vector<Student_info>& students) {
	vector<Student_info> fail;
	vector<Student_info>::size_type i = 0;

	while (i != students.size()) {
		if (fgrade(students[i])) {
			fail.push_back(students[i]);
		//원본 벡터 i 인덱스에 있는 학생 삭제하기
		students.erase(students.begin() + i);
		}
		else {
			++i;
		}
	}
	return fail;
}