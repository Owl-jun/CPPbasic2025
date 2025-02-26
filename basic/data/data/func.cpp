#include <stdio.h>
#include <iostream>

// 단축키
// ctrl + k , c 지정범위 주석
// ctrl + k , u 지정범위 주석해제
// Alt + Drag

// 디버깅
// 디버깅 시작& 다음 중단점까지 실행	 : F5
// 중단점 설정/해제						 : F9
// 프로시저 단위 실행					 : F10
// 함수 진입							 : F11
// 디버깅 종료							 : SHIFT + F5

// 함수
// Factorial
int Factorial(int n)
{
	int value = 1;
	for (int i = 1; i < n; ++i)
	{
		value *= i+1;
	}
	return value;
}
// 재귀함수
// 가독성, 구현의 용이
// 단점 : 속도가 느리다.
int Factorial_Re(int n)
{
	if (n < 2) { return 1; }
	return n * Factorial(n - 1);
}

// 피보나치 수열
// 1 1 2 3 5 8 13 21 34 55 ...
int Fibo(int n)
{
	int prev = 1;
	int next = 1;
	int temp;
	if (n <= 2) { return 1; }
	else 
	{
		for (int i = 0; i < n - 2; ++i)
		{
			temp = prev + next;
			prev = next;
			next = temp;
		}
	}
	return temp;
}
// 피보나치 수열
int Fibo_Re(int n)
{	
	if (n <= 2) { return 1; }
	return Fibo_Re(n - 2) + Fibo_Re(n - 1);
}

int main() {
	int num = Factorial(4);
	printf("%d \n", num);
	int fibo = Fibo(7);
	printf("%d \n", fibo);
	// 콘솔
	// printf
	printf("abcdef %d \n", 10);
	printf("abcdef %f \n", 10.14f);

	for (int i = 0; i < 10; ++i)
	{
		printf("Output i : %d \n", i);
	}

	// 배열
	// 메모리가 연속적임.
	int iArray[10] = { };

	// 의도치 않은 변수에 10이 대입될 수 있는 치명적인 상황
	iArray[12] = 10;


	// scanf
	int iInput = 0;
	scanf_s("%d", &iInput);


	// 함수가 사용하는 메모리 영역
	// 스택 메모리 영역


	return 0;
}