#pragma once

/*
	7.2 문제: 쿼드 트리 뒤집기 (문제 ID: QUADTREE, 난이도: 하) - p189
*/
struct 뭉치
{
	string str[4];
	string wholeStr;
};

class QUADTREE
{
public:
	QUADTREE();
	~QUADTREE();

	void solution();
	string reverse(string::iterator& it);
	

private:
	int testCase = 0;	// 최댓값 50인 자연수
	int edge = 0;		// 한 변의 길이, 최댓값 20인 음이 아닌 정수
	vector<string> inputString;
	vector<string> retString;
};

