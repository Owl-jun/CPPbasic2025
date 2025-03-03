#include <stdlib.h>
#include <stdio.h>

int main() {

	// 포인터 변수
	// 주소를 저장하는 변수
	// 포인터 변수의 크기 64bit = 8byte , 32bit = 4byte
	// why? 레지스터가 한번에 수행할 수 있는 크기의 차이
	// 자료형 * 변수명
	// 여기서 자료형은 해당 포인터에게 전달된 주소를 해석하는 단위
	int i = 100;
	float f = 3.f;

	int* pInt = (int*) &f;	// 부동소수점으로 표현되있는 실수 3.f 를 int 자료형처럼 읽는순간 값이 이상한게나온다;
	printf("%d\n", *pInt);

	// 주소로 접근
	*pInt = 300;
	printf("%d\n", *pInt);

	// 주소의 단위
	// BYTE

	// 포인터 변수의 증감 
	// 자료형의 크기에 맞춰 주소가 증가한다
	// ex) pInt 의 시작주소가 100일 때, int타입이기때문에 ++ 을 하면 104가 된다.
	pInt = pInt + 1;


	// 포인터와 배열
	// 배열의 특징
	// 1. 메모리가 연속적인 구조이다.
	// 2. 배열의 이름은 배열의 시작 주소이다.
	
	int iArr[10] = {};
	*(iArr + 0) = 10; // iArr[0] = 10;
	*(iArr + 1) = 20; // iArr[1] = 20;

	// 포인터 이해 확인 문제 , 디버그없이 손코딩으로 풀어볼 것.
	// 문제 1.
	short sArr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* pI = (int*)sArr;
	int iData = *((short*)(pI + 2));
	printf("1번 문제 정답 : %d\n", iData);

	// 문제 2.
	char cArr[2] = { 1, 1 };
	short* pS = (short*)cArr;
	iData = *pS;
	printf("2번 문제 정답 : %d\n", iData);

	// l-value : 변수 , r-value : 상수
	// const , 상수화
	// 무조건 값이 변경 되지 않는 건 아님.
	// volatile : 레지스터 사용하지말고, 제대로 확인하거라.
	volatile const int cint = 100;
	int* cpInt = (int*)&cint;
	*cpInt = 300;
	printf("%d", cint);

	// 1. const
	const int i = 100;

	// const 와 포인터
	int a = 0;
	int* pInt = &a;
	*pInt = 1;

	// 역 참조를 막겠다. 즉, 주소의 원본값을 수정할 수 없다.
	const int* pConstInt = &a;
	pConstInt = &i; // 주소 변경만 가능

	// 포인터 주소변경을 막겠다. 즉, 원본값은 수정가능하지만 주소변경은 불가능하다.
	int* const ConstPInt = &a;
	*ConstPInt = i; // 원본값 변경만 가능

	// 둘다 막아보자.
	const int* const ConstpConstInt = &a;

	// 사용예시
	// 함수에서 큰 자료 등을 매개변수로 필요로 할 때, 매번 복사하기 오버헤드가 부담됨
	// 포인터 타입변수로 주소를 읽어옴
	// 허나, 원본 값 변경을 하지 않겠다 라는 표식으로 앞에 const int* pI 등으로 매개변수를 설정

	return 0;
}