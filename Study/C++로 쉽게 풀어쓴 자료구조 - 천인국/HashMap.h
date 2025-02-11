#pragma once
#include <cstdio>
#include <cstring>
#define KEY_SIZE 64
#define VALUE_SIZE 64
#define TABLE_SIZE 13

// ���ڿ��� �� Ž��Ű�� ���ڷ� ��ȯ
// ���ڿ��� �� ������ �ƽ�Ű�ڵ��� �������� ��ȯ�Ѵ�.
inline int transform(const char* key)
{
	int number = 0;
	while (*key)
		number += (*key++);
	return number;
}

// ������ ���� ���� ���̺� ������� ���� �������� ��ȯ�Ѵ�.
// �׷� ������ [0, ���̺������-1)�� �ȴ�.
inline int hashFunction(const char* key)
{
	return transform(key) % TABLE_SIZE;
}

// �ؽ� ���� ���� Keyed Record Ŭ����
// key�� value. �� ���� ���� ����.
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

// �ؽ� �� Ŭ����
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

	// ���� ������� �̿��� ����
	void addLinearProb(const char* key, const char* value)
	{
		int i, hashValue;
		// key�� �ؽ� ���� ���Ѵ�.
		hashValue = i = hashFunction(key);
		// table�� �ؽ� ���� �ش��ϴ� ��Ŷ�� ������� �ʴٸ� ����
		while (table[i].isEmpty() == false) {
			// �ش� ��Ŷ�� �̹� ���� (Ű, ��)�� �ִٸ�
			if (table[i].equal(key)) {
				printf("[%s] Ž��Ű�� �ߺ��Ǿ����ϴ�.\n", key);
				return;
			}
			// �ش� ��Ŷ�� ���� ä���� �ֱ� ������ ���� ��Ŷ���� �Ѿ��
			// ������ ���ٸ� ���⼭ ���� while�� �������� �Ѿ��
			// while���� ������ ��
			i = (i + 1) % TABLE_SIZE;
			// �׷����� �ؽ� ���� ���� ��Ŷ���� �Ѿ ���� ���ٸ� �� ������
			if (i == hashValue) {
				printf("[%s] ���̺��� ����á���ϴ�.\n", key);
				return;
			}
		}
		// while�� ������ ����� ���� �� ��Ŷ�� ���� �־��ָ� ��
		table[i].set(key, value);
	}

	// ���� ������� �̿��� Ž��
	Record* searchLinearProb(const char* key)
	{
		int i, hashValue;
		hashValue = i = hashFunction(key);
		// table�� �ؽ� ���� �ش��ϴ� ��Ŷ�� ������� �ʴٸ� ����
		while (table[i].isEmpty() == false) {
			// ã���� ���
			if (table[i].equal(key)) {
				printf("[%s] Ž������[%d]", key, i);
				table[i].display();
				return table + i;
			}
			// ��ã�Ҵ�. �׷� �������� �Ѿ
			// �������� �Ѿ�Դµ� ���� ��Ŷ�� ��������� while�� �����
			i = (i + 1) % TABLE_SIZE;
			// �������� �Ѿ�Դµ� �ؽ� ���̶� ����. ���� ����������.
			if (i == hashValue) break;
		}
		// ������ �߰��� ����ִ� ��쵵 ��ã�� ��찡 �߻���..
		printf("[%s] Ž�� ����: ã�� ���� ���̺� ����\n", key);
		return nullptr;
	}
};

// ���� ����Ʈ�� ���� ��� Ŭ����. Record�� ��ӹ޴´�
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

// �ؽ� ü�̴����� ������ �ؽ� ��
class HashChainMap
{
	// ���� ����Ʈ�� table�� �����ȴ�.
	Node* table[TABLE_SIZE];
public:
	HashChainMap()
	{
		// �ʱ�ȭ
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
	// ü�ι��� �̿��Ͽ� ���̺� ����
	void addRecord(Node* n)
	{
		// �ؽ� ���� ���Ѵ�
		int hashValue = hashFunction(n->getKey());
		// �ش� �ؽð��� ��Ŷ�� ���� ��ȸ�Ѵ�.
		for (Node* p = table[hashValue]; p != nullptr; p = p->getLink()) {
			// ���� �Ȱ��� ���� ã���� �ߺ�
			if (p->equal(n->getKey())) {
				printf("�̹� Ž��Ű�� ����Ǿ� ����\n");
				delete n;
				return;
			}
		}
		// for���� ������ �ߺ� Ű�� ���� ����.
		// ���Ӱ� �߰��� ��� �ڷ� ���� ��Ŷ�� �ٿ�������.
		n->setLink(table[hashValue]);
		// �׷� ���� ó�� ���� ���� ��� �߰��� �����. 
		// �� ���Ӱ� �߰��� ��带 ��Ŷ�� ��ǥ���� ����.
		table[hashValue] = n;
	}

	// ü�ι��� �̿��Ͽ� ���̺� ����� Ű�� Ž��
	void searchRecord(const char* key)
	{
		int hashValue = hashFunction(key);
		// �ش� �ؽð��� ��Ŷ�� ���� ��ȸ
		for (Node* p = table[hashValue]; p != nullptr; p = p->getLink()) {
			// ã���� ��ȯ
			if (p->equal(key)) {
				printf("Ž�� ���� ");
				p->display();
				return;
			}
		}
		// ��ã��
		printf("Ž�� ����: %s\n", key);
	}
};