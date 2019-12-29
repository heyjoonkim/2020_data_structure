#### 6장

## 연결 리스트 (linked list)

- 항목들은 연속으로 배치하지 않음, 일크로면 안결
  - 단일 연결 리스트, 이중 연결 리스트, 원형 연결 리스트
- 새로운 항목을 추가, 삭제하기 편리함
- 포인터 : 메모리의 주소값을 저장하는 병수  = 저장되는 값이 변수
  - <code>*</code> : 간접 참조 연산자 (indirection operator)	
    - 주소가 가리키는 내용을 접근하려고 할 때 사용
    - 포인터 변수는 동일한 타입의 변수만 가리킬 수 있음
      - 정수형 포인터는 정수만 가리킬 수 있음
    - 32비트 운영체제 = 모든 주소가 32비트(4byte) = 포인터 변수의 크기 = 4byte
      - 64비트 운영체제 = 포인터 변수의 크기 = 8byte
    - 포인터 변수는 꼭 초기화 해야 함.
      - <code>int * p = NULL;</code>
    - 배열명은 배열의 시작 주소값을 저장함
    - 포인터 변수끼리의 연산
      - 뺄셈 (두 주소 사이의 항목 개수 리턴), 증감 연산자(--, ++), 상수값을 더하거나 빼기 가능함
      - 포인터 변수 사이의 덧셈은 불가능함
- 배열과의 비교
  - 배열 
    - 한번에 전체 공간 할당, 연속적인 공간에 할당
      - 낭비되는 메모리 존재할 수 있음
    - 랜덤 접근(인덱스 사용)
    - 순회, 탐색이 빠르다
    - 삽입, 삭제가 느리다
  - 연결 리스트
    - 프로그램 실행 시점에 노드를 동적으로 할당
    - 순차접근
      - 순회, 탐색이 느리다
    - 삽입, 삭제가 빠르다
    - 포인터를 위한 저장공간이 별도로 필요하다

- 이중 연결 리스트 (doubly linked list) : 앞 뒤로의 링크를 가지를 리스트
  - 양방향의 탐색이 가능함
  - 링크를 위한 메모리 낭비가 크다 (앞, 뒤에 대한 포인터를 유지해야 함)