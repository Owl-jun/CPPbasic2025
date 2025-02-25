#include <iostream>
// # , 전처리기 : 컴파일 시 제일 먼저 읽음
#define HUNGRY	0x1
#define THIRSTY 0x2
#define TIRED	0x4
#define COLD	0x8

#define FIRE	0x10
#define COOL	0x20
#define COOL	0x40
#define COOL	0x80

#define COOL	0x100
#define COOL	0x200
#define COOL	0x400
#define COOL	0x800 
// ... 16진수를 활용하여 비트 별 자리 배치

// 가독성 , 유지보수에 도움

// 전역변수
int global = 0;

// 함수
int Add(int a, int b)
{
	return a + b;
}

int data2() {
	int num = 3;

	if (num > 3)
	{
		
	}
	else
	{

	}


	// 정확하게 일치하는지만 체크가능 , 범위를 쓰려면 if else 문 사용
	// break 를 안걸어주면 멈추지않는다.. 다 실행됨
	switch (num)
	{
		case 10 :
		case 20 :
			break;
		default:
			break;
	}

	// 삼항 연산자
	// :?
	// 변수 = 조건 ? 참 : 거짓;
	int iTest = 20 ? iTest = 100 : iTest = 200;

	// 비트 연산자
	// 쉬프트 <<, >>
	unsigned char byte = 1;
	byte = byte << 3; // 전체적으로 왼쪽으로 한칸 , 즉 한칸 당 2^n 배가 됨
	byte = byte >> 2; // 전체적으로 오른쪽으로 한칸 , 나누기 2^n 이고, 몫만 표기 됨
	
	// 비트 곱(&), 합(|), xor(^), 반전(~)
	// 각 비트 자리에 상태 등을 넣어 조합할 수 있다.
	unsigned int iState = 0;
	iState |= HUNGRY;
	iState |= THIRSTY;

	if (iState & HUNGRY) // 배고픔이 활성화 되있니?
	{

	}

	// 특정 자리 비트 제거
	iState &= ~THIRSTY;

	// 변수
	// 1. 지역변수
	// 2. 전역변수
	// 3. 정적변수
	// 4. 외부변수

	// 함수
	int temp = Add(2, 3);

	// 지역변수
	int iName = 0;
	// 괄호 안에 선언된 변수(함수, 지역)
	{
		int iName = 3;
	}
	
	return 0;
}