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

// Compare �Լ���ü�� default�� less�̴�.
template <class Compare, class BidirectionalIterator>
bool __next_permutation(BidirectionalIterator first, BidirectionalIterator last, Compare comp)
{
	BidirectionalIterator i = last;

	// first == last�� �ش� �����̳ʰ� ����ִٴ� ��.
	// first == --i�� �����̳��� ���Ұ� 1����� ��.
	if (first == last || first == --i)
		return false;
	
	// ���� i�� ������ ���Ҹ� ����Ų��.

	while (true)
	{
		BidirectionalIterator ip1 = i;
		// ���� ���ҿ� ���� ���ҿ� ��. ���Լ��� ���� ���ϰ��� �����ȴ�.
		// Compare�Լ��� default�� less�̹Ƿ� <�� �����ؾ� true�̴�.
		// ����, ������ �����̱� ������ ���� �� ���Ҽ����� ã�ƾ� �Ѵ�.
		// �Ʒ� if�� ������ true�� �Ƿ��� (���� ���� < ������ ����), �� ���������� �� true�̴�.
		// ���� ���� �� ���Ҽ����� ã�� ������ �� while�� �ݺ� �� ���̴�.
		if (comp(*--i, *ip1))
		{
			// ���� �� ���Ҽ����� ã�Ҵ�. i�� �� ���� �ٷ� �� ��ġ�̴�.
			
			BidirectionalIterator j = last;

			// ������ ���Һ��� �����ؼ� ó������ ������ *i���� ū ���� ã�´�.
			// ��, *i���� ū �������� �ּڰ�.
			while (!comp(*i, *--j))
				;
			swap(*i, *j);
			// ���� �� ���Ҽ����� ���� ��ġ�������� ������ ��ġ���� reverse
			reverse(ip1, last);
			return true;
		}
		// �� if���� �����̰�(���� �� ���Ҽ����� ã�� ��)
		// i == first�̸�, ���� �� ���Ҽ����� ��ü �����̴�. ������������ ���ĵ� ������ �����̴�.
		// �ٽ� ó�� ������ ���� �� ����.(������ ������ ���� ������ ���� ������ false)
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
