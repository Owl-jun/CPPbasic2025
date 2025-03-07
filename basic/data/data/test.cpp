#include <iostream>
#include <wchar.h>


// 瘤开 , 傈开 , 沥利(static) , 寇何(extern)




int leng(const wchar_t* data)
{
	static int sInt = 0;
	int Int = 0;
	++sInt;
	++Int;
	int i = 0;
	while (true)
	{
		if (data[i] != 0) { ++i; }
		else { break; }
	}
	return i;
}

int my_cmp(const wchar_t* left, const wchar_t* right)
{
	int a = 5;
	int l = leng(left);
	int r = leng(right);
	int min = l >= r ? r : l;
	int result = 0;
	for (int i = 0; i < min; ++i)
	{
		if (left[i] == right[i]) { continue; }
		
		if (left[i] < right[i]) { return -1; }
		else if (left[i] > right[i]) { return 1; }
	}
	return result;
}


int main() {

	int a = 3;
	my_cmp(L"abc", L"abc");
	my_cmp(L"abc", L"ab");
	my_cmp(L"bc", L"abc");
	leng(L"ab");
	leng(L"ab");
	leng(L"ab");
	leng(L"ab");
	leng(L"ab");
	leng(L"ab");
	leng(L"ab");
	return 0;
}