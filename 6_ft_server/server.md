도커가 도대체 뭐지??

우선은 도커를 알기 전에 컨테이너가 무엇인지, 가상머신이 무엇인지를 알아둘 필요가 있을 것 같다.

우선은 가상머신이라는 녀석은 무엇일까??

- 가상머신(Virtual Machine, VM)

    가상머신은 간단하게 내 컴퓨터 내의 일정 공간을 사용해서 별도의 컴퓨터처럼 작동하는 작은 컴퓨터라고 생각했다.

    그렇다면 이 가상머신으로 어떤 일을 할 수 있을까???

- 가상머신의 장 단점.
    - 장점
        - 사이버 공격이나 기타 문제가 발생했을때 복구를 하거나 [프로비저닝](https://blog.naver.com/gojump0713/140110601767) 옵션을 제공한다.
        - 가상 머신은 유지 및 관리가 간편하며 범용성이 뛰어나다.
        - 하나의 물리적 컴퓨터에서 여러 운영 체제 환경을 실행할 수 있다.
    - 단점
        - 하나의 물리적 시스템에서 여러 가상 머신을 실행하면 성능이 불안정해질 수 있다.
        - 가상 머신은 물리적 컴퓨터보다 효율성이 떨어지며 실행 속도도 느리다.

이렇듯 가상머신으로 여러개의 운영체제를 사용할 수 있고, 내 컴퓨터공간에서 별개의 공간을 만들어 사용하기에 위험한 작업을 할 때 내 컴퓨터에 영향을 주지 않도록 할 수 있는 등 다양한 이유때문에 가상머신을 사용한다.

그렇다면 컨테이너는 무엇일까??

- 컨테이너

[도커란?](https://www.redhat.com/ko/topics/containers/what-is-docker)

[리눅스 컨테이너](https://www.redhat.com/ko/topics/containers/whats-a-linux-container)란? [22222](https://goofcode.github.io/container-101)

[컨테이너와 VM차이](https://medium.com/@lhs6395/container%EC%99%80-vm%EC%9D%98-%EB%B9%84%EA%B5%90-84f6a8b7cd4c)

[가상화란?](https://www.redhat.com/ko/topics/virtualization)

[하이퍼바이저란](https://www.redhat.com/ko/topics/virtualization/what-is-a-hypervisor)?

[가상머신이란?](https://www.redhat.com/ko/topics/virtualization/what-is-a-virtual-machine) [가상머신이란?222](https://www.vmware.com/kr/topics/glossary/content/virtual-machine.html)

[개발자가 처음 Docker 접할때 오는 멘붕 몇가지 | Popit](https://www.popit.kr/%EA%B0%9C%EB%B0%9C%EC%9E%90%EA%B0%80-%EC%B2%98%EC%9D%8C-docker-%EC%A0%91%ED%95%A0%EB%95%8C-%EC%98%A4%EB%8A%94-%EB%A9%98%EB%B6%95-%EB%AA%87%EA%B0%80%EC%A7%80/)

[도커 기본 사용방법](http://pyrasis.com/Docker/Docker-HOWTO)

[컨테이너 기술과 가상화 기술 비교](http://www.opennaru.com/cloud/virtualization-vs-container/)

[컨테이너의 역사](http://www.opennaru.com/openshift/container/history-of-the-container/)

[컨테이너 기술 소개](http://www.opennaru.com/openshift/container/container-introduction/)

[컨테이너 시리즈](https://tech.osci.kr/2020/03/03/91690167/)
