## 정적 변수에 대해서 공부하기 위해서 만들어진 과제입니다.<br/>
```c
int		get_next_line(int fd, char **line)
```
이 라이브러리는 fd에서 한 줄을 읽어들여 line에 입력해줍니다.<br/>
이 과정에서 정적변수를 이용해서 읽고 남은 문자열의 정보를 보관하여 다음에 호출할 때 그 다음 줄을 반환할 수 있도록 합니다.<br/>
[관련 지식을 정리한 블로그](https://velog.io/@meong9090/series/getnextline)