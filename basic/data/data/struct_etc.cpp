#include <stdio.h>

// 구조체
// 사용자 정의 자료형
// C 스타일 선언방법
typedef struct _tagMyST
{
	int		a;
	float	f;
}MYST;

typedef struct _tagBig
{
	MYST	k;
	int		i;
	char	c;
}BIG;
typedef struct newSt {} NS; // typedef : 정의하겠다, struct newSt 를 NS 라고 부르기로. 

int main()
{
	MYST t = { 3, 0.4f };
	t.a = 30;
	t.f = 3.14f;

	return 0;
}