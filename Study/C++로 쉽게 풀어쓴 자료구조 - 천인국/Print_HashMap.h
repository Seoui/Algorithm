#pragma once
#include <cstdio>
#include <cstring>
#define KEY_SIZE 64
#define VALUE_SIZE 64
#define TABLE_SIZE 13

inline int transform(const char* key)
{
	int number = 0;
	while (*key)
		number += (*key++);
	return number;
}

inline int hashFunction(const char* key)
{
	return transform(key) % TABLE_SIZE;
}

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

	void addLinearProb(const char* key, const char* value)
	{
		int i, hashValue;
		hashValue = i = hashFunction(key);
		while (table[i].isEmpty() == false) {
			if (table[i].equal(key)) {
				printf("[%s] Ž��Ű�� �ߺ��Ǿ����ϴ�.\n", key);
				return;
			}

			i = (i + 1) % TABLE_SIZE;
			if (i == hashValue) {
				printf("[%s] ���̺��� ����á���ϴ�.\n", key);
				return;
			}
		}
		table[i].set(key, value);
	}

	Record* searchLinearProb(const char* key)
	{
		int i, hashValue;
		hashValue = i = hashFunction(key);
		while (table[i].isEmpty() == false) {
			if (table[i].equal(key)) {
				printf("[%s] Ž������[%d]", key, i);
				table[i].display();
				return table + i;
			}
			i = (i + 1) % TABLE_SIZE;
			if (i == hashValue) break;
		}
		printf("[%s] Ž�� ����: ã�� ���� ���̺� ����\n", key);
		return nullptr;
	}
};

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

class HashChainMap
{
	Node* table[TABLE_SIZE];
public:
	HashChainMap()
	{
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

	void addRecord(Node* n)
	{
		int hashValue = hashFunction(n->getKey());
		for (Node* p = table[hashValue]; p != nullptr; p = p->getLink()) {
			if (p->equal(n->getKey())) {
				printf("�̹� Ž��Ű�� ����Ǿ� ����\n");
				delete n;
				return;
			}
		}
		n->setLink(table[hashValue]);
		table[hashValue] = n;
	}

	void searchRecord(const char* key)
	{
		int hashValue = hashFunction(key);
		for (Node* p = table[hashValue]; p != nullptr; p = p->getLink()) {
			if (p->equal(key)) {
				printf("Ž�� ���� ");
				p->display();
				return;
			}
		}
		printf("Ž�� ����: %s\n", key);
	}
};
