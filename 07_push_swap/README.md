## 두 개의 스택에 랜덤한 숫자가 들어왔을 때 특정 명령어로만 정렬하는 과제입니다.

### 인원
- 1인

### 구현 목록
다음과 같은 명령어 구현
- sa: A의 가장 위에 있는 두 원소(혹은 첫 번째 원소와 두 번째 원소)의 위치를 서로 바꾼다.
- sb: B의 가장 위에 있는 두 원소(혹은 첫 번째 원소와 두 번째 원소)의 위치를 서로 바꾼다.
- ss: sa와 sb를 동시에 실행한다.
- pa: B에서 가장 위(탑)에 있는 원소를 가져와서 A의 맨 위(탑)에 넣는다. B가 비어 있으면 아무 것도 하지 않는다.
- pb: A에서 가장 위(탑)에 있는 원소를 가져와서 B의 맨 위(탑)에 넣는다. A가 비어 있으면 아무 것도 하지 않는다.
- ra: A의 모든 원소들을 위로 1 인덱스만큼 올린다. 첫 번째 원소(탑)는 마지막 원소(바텀)가 된다.
- rb: B의 모든 원소들을 위로 1 인덱스만큼 올린다. 첫 번째 원소(탑)는 마지막 원소(바텀)가 된다.
- rr: ra와 rb를 동시에 실행한다.
- rra: A의 모든 원소들을 아래로 1 인덱스만큼 내린다. 마지막 원소(바텀)는 첫 번째 원소(탑)가 된다.
- rrb: B의 모든 원소들을 아래로 1 인덱스만큼 내린다. 마지막 원소(바텀)는 첫 번째 원소(탑)가 된다.
- rrr: rra와 rrb를 동시에 실행한다.

### 실행
```
git clone git@github.com:meong99/42_seoul.git Push_Swap
cd Push_Swap
make
./push_swap {원하는 숫자를 스페이스로 구분지어서 입력}
ex ) ./push_swap 4 6 3 7
```
### 학습내용
- 시간복잡도
- 퀵소트
- 자료구조

https://user-images.githubusercontent.com/57436863/170276586-808717f2-6945-4f71-9fc3-187aaaac74ea.mp4