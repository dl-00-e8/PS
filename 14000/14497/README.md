# 주난의 난(難)

## 풀이 방법

문제의 파동의 정의가 굉장히 어려웠기에, 파동의 정의부터 생각해보아야 한다.
파동의 정확한 동작원리는 질문게시판의 [글](https://www.acmicpc.net/board/view/147270)을 참고했다.

즉, 파동이 한 번 있을 때 1이 없어 계속 파동이 퍼져나가게 된다. 파동은 퍼지면서도 계속 상하좌우로 움직일 수 있다.

처음에는 파동이 계속 갈 수 있다는 점에 집중하여 해당 방향으로 `while(graph[nx][ny] == 0)`으로 1을 마주치기 전까지 움직이도록 하려 했으나, 해당 방식이 잘못되었음을 위의 파동 설명을 통해 알 수 있었다.

결국 파동이 마주치기 전까지는 0인 좌표를 지나기에, 다익스트라로 이동거리가 0인 것과 마찬가지로 간주하는 것이 효과적이다고 판단했다.
기본적인 다익스트라 알고리즘을 그대로 적용하여 구현해서 "맞았습니다!!"를 받았다.

## 결과

- 메모리: 182096KB
- 시간: 772ms