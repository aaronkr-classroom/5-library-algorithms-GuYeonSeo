//fails_list.cpp 반복자 사용(리스트 컨테이너)
#include<list>
#include "Student_info.h"
#include "grade.h"

using std::list;

//4번째 과락 학생과 성공하는 학생 나누기
//인덱스 대신 반복자 사용하기(빠름)
list<Student_info> extract_fails(list<Student_info>& students) {
	list<Student_info> fail;
	list<Student_info>::iterator iter = students.begin();

	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fail.push_back(*iter);
			//원본 벡터 i 인덱스에 있는 학생 삭제하기
			iter = students.erase(iter);
		}
		else {
			++iter;
		}
	}
	return fail;
}