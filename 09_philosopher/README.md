## 철학자 식사문제를 멀티스레드로 구현한 뒤 뮤텍스로 해결하는 과제입니다.<br/>
이 프로그램은 뮤텍스를 이용해서 데드락과 기아상태를 피해 철학자가 모든 식사를 마치거나, 죽지 않고 끝없이 식사를 하게 만드는게 목표입니다.<br/>

### 사용 언어
- C

### 프로그램 실행
```
git clone git@github.com:meong99/42_seoul.git philosopher
cd philosopher/09_philosopher
make
./philo {철학자 수} {다음 식사까지 기다릴 수 있는 시간(죽음까지의 시간)} {식사하는 데 걸리는 시간} {잠자는 데 걸리는 시간}
```

### 학습내용
- 스레드 및 멀티 스레드
- 뮤텍스
- Context switching

![](https://images.velog.io/images/meong9090/post/d6627852-726f-4841-845b-6e67580081d3/ezgif.com-gif-maker%20(2).gif)
