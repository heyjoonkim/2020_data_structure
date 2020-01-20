#### 4장

## 1차원 배열

- 1차원 배열 : 정해진 개수의 셀이 물리적으로 연속적으로 배치된 구조

  - 특정 위치의 데이터 접근이 빠르다 = 배열의 인덱스 만드로 접근이 가능하다
  - 주기억장치 (main memory) : 주소값만으로 랜덤한 정소들을 동일한 시간에 접근할 수 있다.
    - RAM (Random Access Memory)

- 구조체 (struct)

  - 항목(field)들을 하나의 이름으로 묶어서 사용. 새로운 자료형을 정의

  ~~~c
  struct Point {
  	int x;
  	int y
  };
  struct Point x1, x2;
  ~~~

  ~~~c
  struct Point {
  	int x;
  	int y;
  } x1, x2;
  ~~~

  - 직접 참조와 간접 참조

    ~~~c
    struct Point p1;
    sturct Point *p2;
    p1.x1;	// 직접 참조
    p2->x1;	// 간접 참조
    ~~~

    - 구조체 변수가 포인터인 경우 간접참조(->)

  - 함수의 파라미터로 전달 가능함

  - 배열로 생성 가능함

  - 비교 연산자, 사칙 연산 불가능. 멤버 변수를 각각 비교해야 함.

- Call-by-reference

  - 파라미터의 전달 속도 향상
  - 메모리 절약 가능
  - 값을 직접 변경할 수 있음
    - <code>const</code> 로 선언하면 호출한 함수 내에서 값을 변경할 수 없다.
  - Call-by-value로 값을 복사하려면 시간, 공간적 낭비가 크다

- Typedef : 기존의 데이터형에서 새로운 이름 부여

  ~~~c
  typedef struct point {
  	int x;
  	int y;
  } Point;
  ~~~

  - memset

    ~~~c
    #include <stdlib.h>
    void* memset(void * str, int e, size_t n);
    ~~~

    - str : 메모리 시작 주소
    - e : 초기화할 값
    - n : 초기화할 사이즈

- 희소행렬 (sparse matrix)

  - 행렬 대부분의 값이 0인 경우
  - 값이 0이 아닌 경우, 각 항목의 행 번호, 열 번호, 값을 기록

- 파일 입출력

  - C언어 에서는 스트림 (stream) 사용

    - 장치의 종류에 상관없이 동일한 방법으로 입출력 가능
    - 표준 입출력 스트림 : 프로그램이 시작될 때 자동으로 만들어지고 종료될 때 자동으로 소멸됨

    1. 입력
       - <code>int getchar();</code>
       - <code>char* gets(char *buf);</code>
       - <code>int scanf( ... );</code>
    2. 출력
       - <code>int putchar('A');</code>
       - <code>int* puts(const char *buf);</code>
       - <code>int printf( ... );</code>

  - 파일 종류

    1. 텍스트 파일 (text file) : 인쇄가 가능한 문자. <code>'\n'</code>로 줄바꿈 표시
    2. 이진파일 (binary file) : 파일의 처음부터 끝까지 데이터가 연속적으로 연결.
       - 실행파일, 이미지, 동영상 등

  - 텍스트 파일의 I/O

    1. 입력 
       - 문자 단위 : <code>int fgetc(FILE *fp);</code>
       - 문자열 : <code>char* fgets(char* buf, int n, FILE *fp);</code>
       - 포멧 : <code>fscanf( ... );</code>
    2. 출력 
       - 문자 단위 : <code>int fputc(int ch, FILE *fp);</code>
       - 문자열 : <code>char* fputs(const char* buf, int n, FILE *fp);</code>
       - 포멧 : <code>fprintf( ... );</code>

  - 문자 쓰기 과정

    1. 스트림을 열고 (fopen)

       ~~~c
       FILE* fopen(const char* name, const char* mode);
       ~~~

       - "r" : 읽기
       - "w" : 쓰기/생성
       - "a" : append/생성
       - "r+" : 읽기/쓰기
       - "w+" : 읽기/쓰기/생성
       - "a+" : 읽기/추가/생성

    2. 파일에 I/O 작성

    3. 파일을 닫음 (fclose)

    ~~~c
    FILE* fp = NULL;
    fp = fopen("...", "r");
    ...
    fclose(fp);
    ~~~

    