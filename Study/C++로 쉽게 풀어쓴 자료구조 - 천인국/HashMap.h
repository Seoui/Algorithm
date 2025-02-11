#pragma once
#include <cstdio>
#include <cstring>
#define KEY_SIZE 64
#define VALUE_SIZE 64
#define TABLE_SIZE 13

// 문자열로 된 탐색키를 숫자로 변환
// 문자열의 각 문자의 아스키코드의 누적합을 반환한다.
inline int transform(const char* key)
{
	int number = 0;
	while (*key)
		number += (*key++);
	return number;
}

// 위에서 구한 합을 테이블 사이즈로 나눈 나머지를 반환한다.
// 그럼 범위는 [0, 테이블사이즈-1)이 된다.
inline int hashFunction(const char* key)
{
	return transform(key) % TABLE_SIZE;
}

// 해시 맵을 위한 Keyed Record 클래스
// key와 value. 두 개의 값을 가짐.
class Record
{
protected:
	char key[KEY_SIZE];
	char value[KEY_SIZE];
public:
	Record(const char* k = "", const char* v = "") { set(k, v); }
	void set(const char* k, const char* v = "")
	{
		strcpy_s(key, k);
		strcpy_s(value, v);
	}
	void reset() { set("", ""); }
	bool isEmpty() { return key[0] == '\0'; }
	bool equal(const char* k) { return strcmp(k, key) == 0; }
	void display() { printf("%20s = %s\n", key, value); }
};

// 해시 맵 클래스
class HashMap
{
	Record table[TABLE_SIZE];

public:
	HashMap() { reset(); }
	void reset()
	{
		for (int i = 0; i < TABLE_SIZE; ++i)
			table[i].reset();
	}

	void display() 
	{
		for (int i = 0; i < TABLE_SIZE; ++i) {
			printf("[%2d] ", i);
			table[i].display();
		}
	}

	// 선형 조사법을 이용한 삽입
	void addLinearProb(const char* key, const char* value)
	{
		int i, hashValue;
		// key의 해시 값을 구한다.
		hashValue = i = hashFunction(key);
		// table의 해시 값에 해당하는 버킷이 비어있지 않다면 실행
		while (table[i].isEmpty() == false) {
			// 해당 버킷에 이미 같은 (키, 값)이 있다면
			if (table[i].equal(key)) {
				printf("[%s] 탐색키가 중복되었습니다.\n", key);
				return;
			}
			// 해당 버킷에 값이 채워져 있기 때문에 다음 버킷으로 넘어간다
			// 문제가 없다면 여기서 다음 while문 조건으로 넘어가고
			// while문이 끝나게 됨
			i = (i + 1) % TABLE_SIZE;
			// 그럼에도 해시 값이 다음 버킷으로 넘어간 값이 같다면 꽉 찬거임
			if (i == hashValue) {
				printf("[%s] 테이블이 가득찼습니다.\n", key);
				return;
			}
		}
		// while문 끝나서 여기로 오면 그 버킷에 값을 넣어주면 됨
		table[i].set(key, value);
	}

	// 선형 조사법을 이용한 탐색
	Record* searchLinearProb(const char* key)
	{
		int i, hashValue;
		hashValue = i = hashFunction(key);
		// table의 해시 값에 해당하는 버킷이 비어있지 않다면 실행
		while (table[i].isEmpty() == false) {
			// 찾으면 출력
			if (table[i].equal(key)) {
				printf("[%s] 탐색성공[%d]", key, i);
				table[i].display();
				return table + i;
			}
			// 못찾았다. 그럼 다음으로 넘어감
			// 다음으로 넘어왔는데 다음 버킷이 비어있으면 while문 종료됨
			i = (i + 1) % TABLE_SIZE;
			// 다음으로 넘어왔는데 해시 값이랑 같다. 전부 뒤져본거임.
			if (i == hashValue) break;
		}
		// 문제는 중간에 비어있는 경우도 못찾는 경우가 발생함..
		printf("[%s] 탐색 실패: 찾는 값이 테이블에 없음\n", key);
		return nullptr;
	}
};

// 연결 리스트를 위한 노드 클래스. Record를 상속받는다
class Node : public Record
{
	Node* link;
public:
	Node(const char* key, const char* val)
		: Record(key, val), link(nullptr) {}
	Node* getLink() { return link; }
	char* getKey() { return key; }
	void setLink(Node* next) { link = next; }
};

// 해시 체이닝으로 구현된 해시 맵
class HashChainMap
{
	// 연결 리스트로 table이 구현된다.
	Node* table[TABLE_SIZE];
public:
	HashChainMap()
	{
		// 초기화
		for (int i = 0; i < TABLE_SIZE; ++i)
			table[i] = nullptr;
	}
	void display()
	{
		for (int i = 0; i < TABLE_SIZE; ++i) {
			printf("[%2d] ", i);
			for (Node* p = table[i]; p != nullptr; p = p->getLink())
				printf("%10s", p->getKey());
			printf("\n");
		}
	}
	// 체인법을 이용하여 테이블에 삽입
	void addRecord(Node* n)
	{
		// 해시 값을 구한다
		int hashValue = hashFunction(n->getKey());
		// 해당 해시값의 버킷을 전부 순회한다.
		for (Node* p = table[hashValue]; p != nullptr; p = p->getLink()) {
			// 만약 똑같은 값을 찾으면 중복
			if (p->equal(n->getKey())) {
				printf("이미 탐색키가 저장되어 있음\n");
				delete n;
				return;
			}
		}
		// for문이 끝나면 중복 키가 없는 거임.
		// 새롭게 추가된 노드 뒤로 기존 버킷을 붙여버린다.
		n->setLink(table[hashValue]);
		// 그럼 가장 처음 노드는 지금 방금 추가한 노드임. 
		// 이 새롭게 추가된 노드를 버킷의 대표노드로 갱신.
		table[hashValue] = n;
	}

	// 체인법을 이용하여 테이블에 저장된 키를 탐색
	void searchRecord(const char* key)
	{
		int hashValue = hashFunction(key);
		// 해당 해시값의 버킷을 전부 순회
		for (Node* p = table[hashValue]; p != nullptr; p = p->getLink()) {
			// 찾으면 반환
			if (p->equal(key)) {
				printf("탐색 성공 ");
				p->display();
				return;
			}
		}
		// 못찾음
		printf("탐색 실패: %s\n", key);
	}
};