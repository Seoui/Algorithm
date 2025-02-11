#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

namespace Combination
{
	// 1 2 12 1
	// (1, 2) (1, 1) (1, 12) (2, 12) (2, 1)
	// (1, 2) (1, 12) (1, 1) (2, 12) (2, 1) (12, 1)
	// 6가지
	// C: (1, 2) (1, 3) (1, 4) (2, 3) (2, 4) (3, 4)
	// 파스칼의 삼각형 nCk = n-1Ck-1 + n-1Ck
	// subset은 임시 저장 벡터이다.
	void CombinationKu(vector<int>& data, int n, int k)
	{
		if (k == 0) { 
			cout << "(";
			for (auto& d : data)
				cout << d << " ";
			cout << ")\n";
			return; 
		}
		// smallest는 subset에 들어갈 숫자이다(인덱스가 아니다)
		int smallest = data.empty() ? 0 : data.back() + 1;
		for (int next = smallest; next < n; ++next) {
			data.push_back(next);
			CombinationKu(data, n, k - 1);
			data.pop_back();
		}
	}

	// https://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/
	int Compare(const void* a, const void* b)
	{
		return (*(int*)a - *(int*)b);
	}

	namespace Method1{

	void CombinationUtil(vector<int>& arr, vector<int>& data, int start, int end, int index, int r);
	// The main function that prints all combinations of size of r in arr of size n.
	// This function mainly uses combinationUtil()
	void PrintCombination(vector<int>& arr, int n, int r)
	{
		// A temporary array to store all combination one by one
		vector<int> data(r);

		// Print all combination using temporary array 'data[]'
		CombinationUtil(arr, data, 0, n - 1, 0, r);
	}

	/*
		 arr: input array
		 data: temporary array to store current combination
		 start & end: starting and ending indexes in arr
		 index:	current index in data
		 r: size of a combination to be printed
	*/
	void CombinationUtil(vector<int>& arr, vector<int>& data, int start, int end, int index, int r)
	{
		// Current combination is ready to be printed, print it
		if (index == r) {
			for (int j = 0; j < r; ++j)
				cout << data[j] << " ";
			cout << '\n';
			return;
		}

		// replace index with all possible elements. The condition "end-i+1 >= r-index"
		// makes sure that including one element at index will make a combination with
		// remaining elements at remaining positions
		// end - i + 1 >= r - index;
		// 그러니까 index는 절대로 start의 위치보다 뒤에 있을 수 없다.
		// end - i + 1은 마지막 index에서 부터 i번째 index까지 몇 개의 원소가 있는지 (닫힌 구간, 마지막index와 i번째 index까지 포함하여) 여기는 이제 들어가야 할 원소의 개수임.
		// r - index는 index의 최대는 2이고 현재 data(temporary인)배열에 자리가 몇개 남아 있는가

		for (int i = start; i <= end && end - i + 1 >= r - index; ++i) {
			data[index] = arr[i];
			CombinationUtil(arr, data, i + 1, end, index + 1, r);
		}
	}

	// Mathod 1: Duplicate version
	void CombinationUtilDupl(vector<int>& arr, vector<int>& data, int start, int end, int index, int r);

	void PrintCombinationDupl(vector<int>& arr, int n, int r) 
	{
		vector<int> data(r);

		qsort(&arr[0], n, sizeof(int), Compare);

		CombinationUtilDupl(arr, data, 0, n - 1, 0, r);
	}

	void CombinationUtilDupl(vector<int>& arr, vector<int>& data, int start, int end, int index, int r)
	{
		if (index == r) {
			for (int i = 0; i < r; ++i)
				cout << data[i] << " ";
			cout << '\n';
			return;
		}

		for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
			data[index] = arr[i];
			CombinationUtilDupl(arr, data, i + 1, end, index + 1, r);

			if(i != end)
				while (arr[i] == arr[i + 1]) ++i;
		}
	}
	}

	// Method 2:

	namespace Method2{
	void CombinationUtil(vector<int>& arr, int n, int r, int index, vector<int>& data, int i);

	void PrintCombination(vector<int>& arr, int n, int r) 
	{
		vector<int> data(r);

		CombinationUtil(arr, n, r, 0, data, 0);
	}

	// index: Current index in data[]
	// i: index of current element in arr[]
	void CombinationUtil(vector<int>& arr, int n, int r, int index, vector<int>& data, int i)
	{
		if (index == r) {
			for (int j = 0; j < r; ++j)
				cout << data[j] << " ";
			cout << '\n';
			return;
		}

		// When no more elements are there to put in data[]
		if (i >= n) return;

		// current is included, put next at next location
		data[index] = arr[i];
		CombinationUtil(arr, n, r, index + 1, data, i + 1);

		// current is excluded, replace it with next (Note that
		// i+1 is passed, but index is not changed)
		CombinationUtil(arr, n, r, index, data, i + 1);
	}

	void CombinationUtilDupl(vector<int>& arr, int n, int r, int index, vector<int>& data, int i);
	
	void PrintCombinationDupl(vector<int>& arr, int n, int r)
	{
		vector<int> data(r);

		qsort(&arr[0], n, sizeof(int), Compare);

		CombinationUtilDupl(arr, n, r, 0, data, 0);
	}

	void CombinationUtilDupl(vector<int>& arr, int n, int r, int index, vector<int>& data, int i)
	{
		if (index == r) {
			for (int j = 0; j < r; ++j)
				cout << data[j] << " ";
			cout << '\n';
			return;
		}

		if (i >= n) return;

		data[index] = arr[i];
		CombinationUtilDupl(arr, n, r, index + 1, data, i + 1);

		if(i != n-1)
			while (arr[i] == arr[i + 1]) ++i;

		CombinationUtilDupl(arr, n, r, index, data, i + 1);
	}
	}
}

namespace Permutation {
	// 순열 알고리즘만이 미리 초기화한 배열을 사용한다.
	// 12가지
	// P: (1, 2) (2, 1) (1, 3) (3, 1) (1, 4) (4, 1) (2, 3) (3, 2) (2, 4) (4, 2) (3, 4) (4, 3)

	// Method 1:
	// Function to print permutations of arr
	// This function takes three paramters:
	// 1. arr
	// 2. Starting index of the arr
	// 3. Ending index of the arr
	void Permutation(vector<int>& arr, int start, int end)
	{
		// Base case
		if (start == end) {
			static int k = 1;
			cout << k++ << ": ";
			for (auto& a : arr)
				cout <<  a << " ";
			cout << '\n';
		}
		else {
			// Permutations made
			for (int i = start; i <= end; ++i) {
				// Swapping done
				swap(arr[start], arr[i]);

				// Recursion called
				Permutation(arr, start + 1, end);

				// backtrack
				swap(arr[start], arr[i]);
			}
		}
	}
	// Method 2: permutations of a string
	int Compare(const void* a, const void* b)
	{
		return (*(char*)a - *(char*)b);
	}

	// A utility function two swap two characters a and b
	void Swap(char* a, char* b)
	{
		char t = *a;
		*a = *b;
		*b = t;
	}

	// This function finds the index of the smallest character which is greater
	// than 'first' and is present in arr[l..h]
	int findCeil(string& str, char first, int l, int h)
	{
		// initialize index of ceiling element
		int ceilIndex = l;

		// Noew iterate through rest of the elements and find the
		// smallest character greater than 'first'
		for (int i = l + 1; i <= h; ++i)
			if (str[i] > first && str[i] < str[ceilIndex])
				ceilIndex = i;

		return ceilIndex;
	}

	// Print all permutations of arr in sorted order
	void sortedPermutation(string& str)
	{
		// Get size of string
		int size = (int)str.size();

		// Sort the string in increasing order
		qsort(&str[0], size, sizeof(str[0]), Compare);

		// Print permutations one by one
		bool isFinished = false;
		while (!isFinished) {
			// print this permutation
			cout << str << '\n';

			// Find the rightmost character which is smaller than its next character.
			// Let us call it 'first char'
			int i;
			for (i = size - 2; i >= 0; --i)
				if (str[i] < str[i + 1]) break;

			// If there is no such character, all are sorted in decreasing order,
			// means we just printed the last permutation and we are done.
			if (i == -1)
				isFinished = true;
			else {
				// Find the ceil of 'first char' in right of first character.
				// Ceil of a character is the smallest character greater than it
				int ceilIndex = findCeil(str, str[0], i + 1, size - 1);

				// Swap first and second numbers
				Swap(&str[i], &str[ceilIndex]);

				// Sort the arr on right of 'first number'
				qsort(&str[0] + i + 1, size - i - 1, sizeof(str[0]), Compare);
			}
		}
	}

	void PrintArr(vector<int>& arr, int n)
	{
		static int k = 1;
		cout << k++ << ": ";
		for (auto& a : arr)
			cout << a << " ";
		cout << '\n';
	}

	// Generating permutation using heap algorithm
	void heapPermutation(vector<int>& arr, int size, int n)
	{
		// if size becomes 1 then prints the obtained permutation
		if (size == 1) {
			PrintArr(arr, n);
			return;
		}

		for (int i = 0; i < size; ++i) {
			heapPermutation(arr, size - 1, n);

			if(i < size -1) {
				// if size is odd, swap 0th i.e (first) and
				// (size -1)th i.e (last) element
				if (size % 2 == 1)
					swap(arr[0], arr[size - 1]);
				// If size is even, swap ith and
				// (size -1)th i.e (last) element
				else
					swap(arr[i], arr[size - 1]);
			}
		}
	}
	// 의사코드
	/*	k 는 크기
		procedure generate(k : integer, A : array of any):
		if k = 1 then
		    output(A)
		else
		    // Recursively call once for each k
		    for i := 0; i < k; i += 1 do
		        generate(k - 1, A)
		        // avoid swap when i==k-1
		        if (i < k - 1)
		            // swap choice dependent on parity of k
		            if k is even then
		                swap(A[i], A[k-1])
		            else
		                swap(A[0], A[k-1])
		            end if
		        end if
		    end for
		end if
	*/
}


// nHk = k+(n-1)Ck이다.  4H2 = 5C2 = 10가지
// H:  (1, 2) (1, 3) (1, 4) (2, 3) (2, 4) (3, 4) (1, 1) (2, 2) (3, 3) (4, 4)
void CombinationR(vector<int>& cards, int k)
{

}

// nΠk = n^k, 4^2 = 16가지
// Π: (1, 2) (2, 1) (1, 3) (3, 1) (1, 4) (4, 1) (2, 3) (3, 2) (2, 4) (4, 2) 
//	  (3, 4) (4, 3) (1, 1) (2, 2) (3, 3) (4, 4)
void PermutationR(vector<int>& cards, int k)
{

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// test combinationUtil
	cout << "/////////COMBINATION//////////\n";
	cout << "/////////Method 1//////////\n";
	cout << "/////////Combination//////////\n";
	vector<int> arr = { 1, 2, 3, 4 };
	int r = 2;
	Combination::Method1::PrintCombination(arr, (int)arr.size(), r);
	cout << "/////////Duplicates//////////\n";
	vector<int> arr2 = { 1, 2, 1, 3, 1 };
	int r2 = 3;
	Combination::Method1::PrintCombinationDupl(arr2, (int)arr2.size(), r2);
	cout << "\n/////////Method 2//////////\n";
	cout << "/////////Combination//////////\n";
	vector<int> arr3 = { 1, 2, 3, 4 };
	Combination::Method2::PrintCombination(arr3, (int)arr3.size(), 3);
	cout << "/////////Duplicates//////////\n";
	vector<int> arr4 = { 1, 2, 1, 3, 1 };
	Combination::Method2::PrintCombinationDupl(arr4, (int)arr4.size(), 3);

	cout << "/////////PERMUTATION//////////\n";
	cout << "/////////Method 1//////////\n";
	vector<int> arr5 = { 1, 2, 12, 1 };
	int size5 = (int)arr5.size();
	Permutation::Permutation(arr5, 0, 2);
	cout << "/////////Method 2//////////\n";
	string str = "ACBC";
	Permutation::sortedPermutation(str);
	cout << "/////////Method 3 : heap algorithm//////////\n";
	vector<int> arr6 = { 1, 2, 12, 1 };
	int size6 = (int)arr6.size();
	Permutation::heapPermutation(arr6, size6, 2);
	cout << "//////////////////////////////////////////////////////////////\n";
	cout << "//////////////////////////////////////////////////////////////\n";

	vector<int> data;
	Combination::CombinationKu(data, 5, 3);
	/*
	Combination(subset, n, k);
	Permutation(subset, n, k);
	*/
	system("pause");
	return 0;
}