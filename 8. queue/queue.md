#### 8장

## 큐 (queue)

- FIFO (First In First Out) = FCFS (First Come First Served)

  - dequeue : 앞 (front)에서 삭제
  - enqueue : 뒤 (rear) 에서 삽입

- 1차원 배열 이용

  - 큐의 오른쪽 (rear)에서 십입, 큐의 왼쪽 (front)에서 삭제
  - Front, rear 변수는 각각 -1에서 시작
  - 값을 삽입하면 rear 값을 1 증가
  - 값을 삭제하면 front 값을 1 증가

  - FULL : rear 값이 배열의 오른쪽 끝인 경우
  - EMPTY : front와 rear 값이 같은 경우
    - rear의 값이 배열의 오른쪽 끝인 경우 + rear = front인 경우 큐는 비어있지만 더 이상 삽입하지 못하는 경우 발생함 = 환형 큐 (circular queue)

- 환형 큐 (circular queue)

  - 배열의 양쪽 끝이 붙어있는 경우
  - <code>(rear + 1) & MAX_SIZE == front</code>

- 생산자-소비자 문제 (producer and customer problem)

  - 두개의 병행 프로세스가 수행될 때 발생할 수 있음
  - 생산자와 소비자는 큐를 통해서 정보를 전달

  ~~~c
  /* producer */
  while(true) {
    while(isFull());
    enQueue();
  }
  /* customer */
  while(true) {
    while(isEmpty());
    deQueue();
  }
  ~~~

  - 임계영역 (critical section) 
    - 병행 프로세스 (concurrent process)
      - 두 개 이상의 프로세스가 서로 영향을 주면서 수행되는 상황
      - 상호배제 (mutual exclusion) 가 수행되어야 함
        - 한 순간에 하나의 프로세스만 사용될 수 있도록 함
        - 상호배제 하에 수행되어야 하는 프로그램 영역 = 임계 영역
          - 임계 영역은 atomic(더 이상 분할하지 못하는)하게 수행되어야 함
        - 세마포어(semaphore)라는 공유 변수를 사용함

- 덱(deque, double=ended queue)
  - 큐의 앞과 뒤에서 모두 삽입, 삭제가 가능한 경우