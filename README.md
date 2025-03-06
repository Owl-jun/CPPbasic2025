## C++ 문법 및 자료구조 알고리즘 공부 기록용

### vscode 에서 c++ 빌드 및 컴파일, 디버깅 세팅 [블로그](https://basiclike.tistory.com/360)

### 기초문법

- 자료형
    - int + float = ? , 정수와 실수의 표현방식  :  [[자료형공부](./basic/data/data/data.cpp)]
    - bit/byte, signed/unsigned, 2의보수법  :  [[학습정리](https://blog.naver.com/beatspermymind/223571398078)]
    - 부동소수점방식, 연산자  :  [[학습정리](https://blog.naver.com/beatspermymind/223572581021)]

- 조건문 등
    - 기초문법2 (함수,전처리기,지역변수,비트연산...) : [[조건문공부](./basic/data/data/data2.cpp)]
    - 조건문 (if else , switch , ? : 삼항연산자) : [[학습정리]](https://blog.naver.com/beatspermymind/223575681487)
    - 비트쉬프트, 비트연산 관련 : [[학습정리]](https://blog.naver.com/beatspermymind/223577067236)
    - 지역&전역변수 , 반복문 관련 : [[학습정리]](https://blog.naver.com/beatspermymind/223577067236)

- 재귀함수 등
    - 유용한 단축키 , 디버깅 단축키 , 함수&재귀함수 , 배열 : [[CPP]](./basic/data/data/func.cpp)
    - 함수동작원리 : [학습정리](https://blog.naver.com/beatspermymind/223580587199)
    - 재귀함수 : [학습정리](https://blog.naver.com/beatspermymind/223581910252)
    
- 구조체
    - 커스터마이징 자료형 : [[구조체](./basic/data/data/struct_etc.cpp)]

- 지역변수 외 다양한 변수들과 메모리영역 , 분할 구현
    - 학습내용 : [[지역변수](./basic/data/data/main.cpp)]
    - 정적변수(static) : 생성된 위치에서만 생존하는 정적인 변수, 생성된 위치에 계속 상주하며, 초기화는 최초 한번만 이루어진다. 그러나 스택에 머무는 것이 아닌, 데이터 영역에 생성됨.
    - 외부변수(extern) : 코드관리를 위해 여러 파일들을 분할 구현할 때, 모든 파일에서 접근하여 사용하는 변수. 한 파일에서만 접근가능한 전역 변수와 구분된다. 
        - 사용법 : 모두가 참조하는 공용 헤더파일에 **선언** 만 한다, 초기화 하면 안됨. 그리고 어차피 나중에 컴파일 시 하나로 합쳐지기 때문에, 아무 cpp 파일에서 전역으로 초기화해준다. (지역 내에서 초기화하면 외부에서 접근 불가)
        ```Cpp
        // common.h
        extern int g_iExtern;
        // main.cpp
        int main()
        {
            #include "common.h"
            printf("%d", g_iExtern); // 결과 : 300
            return 0
        }
        // etc.cpp
        #include "common.h"
        int g_iExtern = 300;
        ```
        - 왜 이렇게 동작할까? , 헤더 파일을 include 하게 되면, include 한 곳에 h파일을 코드 복사 붙여넣기 한다. 라고 생각하면 되는데 그렇게 되면 동일한 변수가 include 횟수만큼 초기화 될 것이다.
        - cpp 에서 허용하지 않는 문법이지 않은가? 에러가 발생하게 된다. 동일한 이름의 변수가 많아 어느 변수를 참조해야할지 모르기 때문이다.
        - 함수도 위와 같은 이유로, h파일에서 선언만 하고, 구현하지 않는 이유이다. (굳이 헤더에서 구현까지 하는 경우는, inline 혹은 템플릿 함수일 경우이다.)
- **템플릿 함수를 헤더에서 구현해야하는 이유**
    - 컴파일 시 자료형에 맞춰서 함수를 인스턴스화(구현) 시켜야하는데, 헤더에 구현이 없다면 링킹 단계까지 가서 cpp 파일을 뒤져봐야하는데, 컴파일이 완료가 되지 않아 에러발생.

- 포인터와 배열 , const
    - 학습내용 : [포인터와배열](./basic/data/data/pointer.cpp)
    - 까먹을 것 같은 const 포인터 변수의 위치
    ```cpp
    // * 을 기준으로 앞에 있으면 역참조키워드니까, const가 위치한 곳이 상수화된다.
    const int* ConstpInt; // 역참조된 값 변경 불가, 즉 원본데이터 변경X
    int* const pConstInt; // 주소변경 불가, 포인터 변수 자체 상수화
    ```

- 함수 오버로딩
    - 함수의 이름은 같지만, 매개인자 타입은 다른, 여러가지 버전의 함수
    
### 자료구조

- [[연결리스트구현](./data_algo/CLinkedList.h)]

