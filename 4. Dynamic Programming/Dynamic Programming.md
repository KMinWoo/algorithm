# Dynamic Programming

Dynamic Programming을 흔히들 줄여서 DP라고 많이 부른다. 가장 쉬운 예로는 피보나치 수열 문제가 있다.
$$
F(n) = \begin{cases}0, &\mbox{if }n\mbox{ = 0;}\\1, &\mbox{if }n\mbox{ = 1;}\\F(n-1) + F(n-2), &\mbox{if }n\mbox{ > 1;}\end{cases}
$$
피보나치 수열은 위의 점화식을 가진다. 만약 피보나치 수열을 재귀로 문제를 풀게 된다면 

![img](https://blogfiles.pstatic.net/20160801_275/kks227_14700305083805XBuM_GIF/complexityRecursion_1.gif)

이런 구조로 함수를 호출하여서 문제를 해결 할 수 있다. 그러나 트리 구조를 잘 살펴보면 동일한 값을 연속해서 부르는 걸 확인할 수 있다. 오른쪽 트리에 f(3)이라는 값을 부르고 있는데 왼쪽에서도 동일하게 f(3)에 대해서 또 부르는 걸 확인 할 수 있다. 그래서 다음의 **문제를 해결하기 위해서 메모이제이션을 사용한다(memoization)**. dp[n]이라는 배열을 선언하여서 이미 그 전에 구한 값을 저장하는 방법이다. 이렇게 된다면 오른쪽 f(3)을 구할 때는 이미 왼쪽에서 구한 값을 이용하여 또 다시 불필요하게 호출을 할 필요가 없게 되어 시간을 단축할 수 있다.



- Top-down

  위에서 부터 아래로 가면서 문제를 푸는 방법

- Bottom-up

  아래에서 부터 시작해서 위로 올라가면서 문제를 푸는 방법



- Dynamic Programming 문제
  1. 1463 1로 만들기   <https://www.acmicpc.net/problem/1463>
  2. 1699 제곱수의 합  <https://www.acmicpc.net/problem/1699>
  3. 1904 01타일  <https://www.acmicpc.net/problem/1904>
  4. 2193 이친수 <https://www.acmicpc.net/problem/2193>
  5. 2294 동전2   <https://www.acmicpc.net/problem/2294>
  6. 9465 스티커 <https://www.acmicpc.net/problem/9465>
  7. 10844 쉬운계단수<https://www.acmicpc.net/problem/10844>
  8. 11051 오르막수 <https://www.acmicpc.net/problem/11051>
  9. 11726 2xn타일링 <https://www.acmicpc.net/problem/11726>
  10. 11727 2xn타일링2 <https://www.acmicpc.net/problem/11727> 

> 출처 백준

