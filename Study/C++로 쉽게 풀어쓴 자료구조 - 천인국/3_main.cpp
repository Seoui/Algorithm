#include "Stack.h"

bool checkMatching(const char* filename)
{
	FILE* fp; 
	fopen_s(&fp, filename, "r");
	if (fp == nullptr)
		error("Error: ������ �������� �ʽ��ϴ�.\n");
	
	int nLine = 1;
	int nChar = 0;
	ArrayStack stack;
	char ch;
	bool squot = false;
	bool bquot = false;
	bool OLineCmt = false;
	bool SLineCmt = false;
	char prev = 0;

	while ((ch = getc(fp)) != EOF) {
		// ���� ����ǥ
		if (ch == '\'')
			squot = !squot;
		// ū ����ǥ
		if (ch == '\"')
			bquot = !bquot;
		// �� �� �ּ�
		if (ch == '/' && prev == '/')
			OLineCmt = true;
		// ���� �� �ּ�
		if (ch == '*' && prev == '/')
			SLineCmt = true;
		if (ch == '/' && prev == '*')
			SLineCmt = false;

		if (ch == '\n') {
			if (OLineCmt == true) OLineCmt = false;
			nLine++;
		}
		nChar++;

		if (squot == false && bquot == false && OLineCmt == false && SLineCmt == false) {
			if (ch == '[' || ch == '(' || ch == '{')
				stack.push(ch);
			else if (ch == ']' || ch == ')' || ch == '}') {
				prev = stack.pop();
				if ((ch == ']' && prev != '[') ||
					(ch == ')' && prev != '(') ||
					(ch == '}' && prev != '{')) break;
			}
		}

		prev = ch;
	}

	fclose(fp);
	printf("[%s] ���� �˻���:\n", filename);
	if (!stack.isEmpty())
		printf("Error: �����߰�!(���μ�=%d, ���ڼ�=%d)\n\n", nLine, nChar);
	else
		printf(" O K : ��ȣ�ݱ�����(���μ�=%d, ���ڼ�=%d)\n(�ѱ� ���ڴ� �� ���ڴ� 2���� ����.)\n", nLine, nChar);

	return stack.isEmpty();
}

double calcPostfixExpr(FILE* fp = stdin)
{
	char c;
	OperandStack st;

	while ((c = getc(fp)) != EOF) {
		if (c == '+' || c == '-' || c == '*' || c == '/') {
			double val2 = st.pop();
			double val1 = st.pop();
			switch (c) {
				case '+': st.push(val1 + val2); break;
				case '-': st.push(val1 - val2); break;
				case '*': st.push(val1 * val2); break;
				case '/': st.push(val1 / val2); break;
			}
		}
		else if (c >= '0' && c <= '9') {
			ungetc(c, fp);
			double val;
			fscanf_s(fp, "%lf", &val);
			st.push(val);
		}
	}
	return st.pop();
}

inline int precedence(char op)
{
	switch (op) {
		case '(': case ')': return 0;
		case '+': case '-': return 1;
		case '*': case '/': return 2;
	}
	return -1;
}

void infix2Postfix(FILE* fp = stdin)
{
	char c, op;
	double val;
	ArrayStack st;

	while ((c = getc(fp)) != EOF) {
		if ((c >= '0' && c <= '9')) {
			ungetc(c, fp);
			fscanf_s(fp, "%lf", &val);
			printf("%4.1f ", val);
		}
		else if (c == '(') st.push(c);
		else if (c == ')') {
			while (!st.isEmpty()) {
				op = st.pop();
				if (op == '(') break;
				else printf("%c ", op);
			}
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			while (!st.isEmpty()) {
				op = st.peek();
				if (precedence(c) <= precedence(op)) {
					printf("%c ", op);
					st.pop();
				}
				else break;
			}
			st.push(c);
		}
	}
	while (!st.isEmpty())
		printf("%c ", st.pop());
	printf("\n");
}

#include <stack>
using namespace std;
const int MAZE_SIZE = 6;

struct Location2D 
{
	int row;
	int col;
	Location2D(int r = 0, int c = 0) { row = r; col = c; }
	bool isNeighbor(Location2D& p){
		return ((row == p.row && (col == p.col - 1 || col == p.col + 1)) ||
			(col == p.col && (row == p.row - 1 || row == p.row + 1)));
	}
	bool operator==(Location2D& p) { return row == p.row && col == p.col; }
};

char map[MAZE_SIZE][MAZE_SIZE] = 
{
	{'1','1','1','1','1','1'},
	{'e','0','1','0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','x'},
	{'1','1','1','1','1','1'},
};

bool isValidLoc(int r, int c)
{
	if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE) return false;
	else return map[r][c] == '0' || map[r][c] == 'x';
}

int main()
{
	ArrayStack arrStack;
	for (int i = 1; i < 10; ++i)
		arrStack.push(i);
	arrStack.display();
	arrStack.pop();
	arrStack.pop();
	arrStack.pop();
	arrStack.display();

	printf("=============================================\n");

	checkMatching("TestMatching.txt");

	printf("=============================================\n");
	printf("���� �Է� (Postfix) = 8 2 / 3 - 3 2 * +\n");
	FILE* fp;
	fopen_s(&fp, "TestExpr.txt", "r");
	if (fp == nullptr)
		error("Error: ������ �������� �ʽ��ϴ�.\n");
	double res = calcPostfixExpr(fp);
	fclose(fp);
	printf("��� ��� => %f\n", res);

	printf("=============================================\n");
	printf("���� �Է� (Infix) = (3.1 + 4.2) * 5\n");
	FILE* fp2;
	fopen_s(&fp2, "TestInfix.txt", "r");
	if (fp2 == nullptr)
		error("Error: ������ �������� �ʽ��ϴ�.\n");
	printf("���������� �ٲ� ���: ");
	infix2Postfix(fp2);
	fclose(fp2);

	printf("=============================================\n");
	stack<Location2D> locStack;
	Location2D entry(1, 0);
	locStack.push(entry);

	// ������ �� ������ while�� ����. DFS�� ���� ����
	while (locStack.empty() == false) {
		Location2D here = locStack.top();
		locStack.pop();

		int r = here.row;
		int c = here.col;
		printf("(%d, %d) ", r, c);
		if (map[r][c] == 'x') {
			printf(" �̷� Ž�� ����\n");
			return 0;
		}
		else {
			// �湮�� ���� . ���� �ٲ�
			map[r][c] = '.';
			// �¿���� �ϳ��� ���캸�鼭 ��ȿ�� ���� ���ÿ� �������.
			if (isValidLoc(r - 1, c)) locStack.push(Location2D(r - 1, c));
			if (isValidLoc(r + 1, c)) locStack.push(Location2D(r + 1, c));
			if (isValidLoc(r, c - 1)) locStack.push(Location2D(r, c - 1));
			if (isValidLoc(r, c + 1)) locStack.push(Location2D(r, c + 1));
		}
	}
	printf("�̷� Ž�� ����\n");

	return 0;
}