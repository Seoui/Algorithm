#pragma once

/*
	8.2 문제: 와일드카드 (문제 ID: WILDCARD, 난이도: 중) - p218
	메모이제이션을 활용한 matchMemoized 함수를 봐라
*/

class WILDCARD
{
public:
	WILDCARD();
	~WILDCARD();

	void solution();
	vector<string> MatchPattern(vector<vector<string>>& strs);
	bool CompareString(const string& str1, const string& str2);
	bool matchMemoized(size_t w, size_t s, const string & str1, const string & str2);

private:
	int testCase = 0;				// 테스트 케이스, 최댓값 10이하인 자연수
	int numFile;					// 파일 개수, 최댓값 50이하인 자연수
	string wildcardPattern;			// 와일드 카드 패턴 W
	string fileName;				// 파일명
	vector<vector<string>> strs;
	int cache[101][101];			// 메모이제이션을 위한 캐시

};

