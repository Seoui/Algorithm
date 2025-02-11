template<typename ForwardIterator, typename BinaryPredicate>
ForwardIterator __unique(ForwardIterator first, ForwardIterator last,
	BinaryPredicate binary_pred)
{
	// Skip the beginning, if already unique.
	first = adjacent_find(first, last, binary_pred);
	if (first == last)
		return last;

	// Do the real copy work.
	ForwardIterator dest = first;
	++first;
	while (++first != last)
		if (!binary_pred(dest, first))
			*++dest = move(*first);
	return ++dest;
}

template<typename ForwardIterator, typename BinaryPredicate>
inline ForwardIterator unique(ForwardIterator first, ForwardIterator last)
{
	return __unique(first, last, __iter_equal_to_iter());
}

template<typename ForwardIterator, typename BinaryPredicate>
inline ForwardIterator unique(ForwardIterator first, ForwardIterator last,
	BinaryPredicate binary_pred)
{
	return __unique(first, last, __iter_comp_iter(binary_pred);
}

// Compare 함수객체는 default가 less이다.
template <class Compare, class BidirectionalIterator>
bool __next_permutation(BidirectionalIterator first, BidirectionalIterator last, Compare comp)
{
	BidirectionalIterator i = last;

	// first == last는 해당 컨테이너가 비어있다는 뜻.
	// first == --i는 컨테이너의 원소가 1개라는 뜻.
	if (first == last || first == --i)
		return false;
	
	// 현재 i는 마지막 원소를 가리킨다.

	while (true)
	{
		BidirectionalIterator ip1 = i;
		// 현재 원소와 직전 원소와 비교. 비교함수에 따라 리턴값이 결정된다.
		// Compare함수는 default가 less이므로 <를 만족해야 true이다.
		// 또한, 사전순 기준이기 때문에 가장 긴 감소수열을 찾아야 한다.
		// 아래 if문 조건이 true가 되려면 (직전 원소 < 마지막 원소), 즉 증가수열일 때 true이다.
		// 따라서 가장 긴 감소수열을 찾을 때까지 위 while이 반복 될 것이다.
		if (comp(*--i, *ip1))
		{
			// 가장 긴 감소수열을 찾았다. i가 그 수열 바로 앞 위치이다.
			
			BidirectionalIterator j = last;

			// 마지막 원소부터 시작해서 처음으로 만나는 *i보다 큰 값을 찾는다.
			// 즉, *i보다 큰 숫자중의 최솟값.
			while (!comp(*i, *--j))
				;
			swap(*i, *j);
			// 가장 긴 감소수열의 시작 위치에서부터 마지막 위치까지 reverse
			reverse(ip1, last);
			return true;
		}
		// 위 if문이 거짓이고(가장 긴 감소수열을 찾는 중)
		// i == first이면, 가장 긴 감소수열은 전체 수열이다. 오름차순으로 정렬된 마지막 순열이다.
		// 다시 처음 순열로 만든 후 리턴.(마지막 순열의 다음 순열은 없기 때문에 false)
		if (i == first)
		{
			reverse(first, last);
			return false;
		}
	}
}

template <class Compare, class BidirectionalIterator>
bool __prev_permutation(BidirectionalIterator first, BidirectionalIterator last, Compare comp)
{
	BidirectionalIterator i = last;
	if (first == last || first == --i)
		return false;
	while (true)
	{
		BidirectionalIterator ip1 = i;
		if (comp(*ip1, *--i))
		{
			BidirectionalIterator j = last;
			while (!comp(*--j, *i))
				;
			swap(*i, *j);
			reverse(ip1, last);
			return true;
		}
		if (i == first)
		{
			reverse(first, last);
			return false;
		}
	}
}
