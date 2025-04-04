#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string::size_type width(const vector<string>& v) {
	string::size_type maxlen = 0;

	for (vector<string>::size_type i = 0; i != v.size(); i++) {
		maxlen = max(maxlen, v[i].size()); //제일 긴 문장 찾기
	}
	return maxlen;
}

vector<string> frame(const vector<string>& v) {
	vector<string> ret;
	string::size_type maxlen = width(v);
	string border(maxlen + 4, '*');

	//상단 테두리 추가
	ret.push_back(border);

	//양 끝이 별표와 공백으로 둘러싸인 문자열들을 각각 추가
	for (vector<string>::size_type i = 0; i != v.size(); i++) {
		ret.push_back("* " + v[i] +
			string(maxlen - v[i].size(), ' ') + " *");
	}

	//하단 테두리 추가
	ret.push_back(border);
	return ret;
}

//수직결합 - vector concat
vector<string>vcat(const vector<string>& top,
	const vector<string>& down) {
	//위쪽 문자 그림을 복사
	vector<string> ret = top;

	//아래쪽 문자 그림을 복사
	for (vector<string>::const_iterator it = down.begin();
		it != down.end(); ++it) {
		ret.push_back(*it); //반복자가 가르키는 값 추가
	}
	return ret;
}

//수평결합 - horizontal concat
vector<string>hcat(const vector<string>& left,
	const vector<string>& right) {
	vector<string> ret;

	//두 문자 그림 사이에 공백 하나를 남김
	string::size_type width1 = width(left) + 1;

	//왼쪽 문자 그림과 오른쪽 문자 그림의 요소를 살펴보는 인덱스
	vector<string>::size_type i = 0, j = 0;

	//두 문자 그림의 모든 행을 살펴봄
	while (1 != left.size() || j != right.size()) {
		//두 문자 그림의 문자들을 저장할 새로운 문자열을 생성
		string s;

		//왼쪽 문자 그림에서 행 하나를 복사
		if (i != left.size()) {
			s = left[i++];
		}
		//공백을 포함하여 문자열을 적절한 너비까지 채움
		s += string(width1 - s.size(), ' ');

		//오른쪽 문자 그림에서 행 하나를 복사
		if (j != right.size()) {
			s += right[j++];
		}
		//새로운 문자 그림에 문자열 s를 추가
		ret.push_back(s);
	}
	return ret;
}