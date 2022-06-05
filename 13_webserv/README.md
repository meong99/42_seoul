## 소켓을 이용해 웹서버를 만드는 과제입니다.
Nginx를 모방하는 웹서버를 만드는게 목표이며 HTTP/1.1 사양에 맞게 웹서버를 만들어야 합니다.<br/>
클라이언트의 Request를 받아서 파싱, 분석하여 Response를 만들어 클라이언트에게 전송합니다.

### 인원
- 3인

### 실행
```
git clone git@github.com:meong99/42_seoul.git webserv
cd webserv/13_webserv
make
./webserv
```

### 구현목록
- GET
- POST
- DELETE

### 협업 방법
- 페어프로그래밍
- Github
- Vscode Live share
- Drawio
- Notion
- Slack

### 기여도
- 70%
- 프로그램 로직 구상
- Config file 파싱
- client request 받기 및 파싱
- php파일 호출 시 파이썬 환경변수 Response 생성 및 송신
- 기타 CGI 호출 시 Request body에 있는 텍스트 중 소문자를 대문자로 변경해서 전송

### 학습 내용
- http란 무엇인가?
- request message
- response message
- CGI란?
- HTTP 1.1
- 소켓과 TCP 커넥션
- IO-Multiplexing
- kqueue
- C++ 코딩 컨벤션
- 협업
