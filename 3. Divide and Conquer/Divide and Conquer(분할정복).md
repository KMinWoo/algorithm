# Divide and Conquer(분할정복)

분할 정복은 말 그대로 문제를 두 단계, **①분할**과 **②정복**으로 나눠서 해결하는 것을 말합니다. 분할하는 단계에서는 말 그대로 주어진 문제를 여러 개의 부분 문제들로 나누는데, 문제가 작아지면 작아질수록 풀기 쉬워지는 성질을 이용한 합니다. 

또한 문제의 크기가 엄청나게 줄어든다면(n = 1) 그야말로 바로 답을 구할 수 있는 수준이 되고, 이게 재귀호출로 문제를 풀 때의 base case와 같습니다. 그래서 분할정복은 재귀로 문제를 풀 수 있습니다.

![img](http://postfiles6.naver.net/20160731_101/kks227_1469954317370naiaW_PNG/divide_conquer_3_steps.png?type=w3)

가장 큰 문제를 반으로 나누어서 가장 작은 문제가 될 때까지 반복하는 것입니다. 아주 대표적인 예시로는 병합정렬, 이분탐색, 거듭제곱연상이 있습니다.

![img](http://postfiles8.naver.net/20160731_119/kks227_1469954954786CDXJ4_GIF/0721tree.gif?type=w3)

그래서 분할정복은 O(n log n )의 시간 복잡도를 가집니다.



- C++ STL 

  - lower_bound()

    ~~~c++
    #include <iostream>
    #include <algorithm>
    #include <vector>
    using namespace std;
    int main(){
        vector<int> test = {0,1,2,3,4,5,5,7,8,9,10};
        vector<int> :: iterator it;
        it = lower_bound(test.begin(), test.end(), 3);
        (*it); // 3 value
        lower_bound(test.begin(), test.end(), 3) - test.begin();// 3(index)       
        lower_bound(test.begin(), test.end(), 5) - test.begin();// 5(index)       
        
        return 0;
    }
    ~~~

  - upper_bound()

    ~~~c++
    #include <iostream>
    #include <algorithm>
    #include <vector>
    using namespace std;
    int main(){
        vector<int> test = {0,1,2,3,4,5,5,7,8,9,10};
        vector<int> :: iterator it;
        it = upper_bound(test.begin(), test.end(), 3);
        (*it); // 4 value
        upper_bound(test.begin(), test.end(), 3) - test.begin();// 4(index)       
        upper_bound(test.begin(), test.end(), 5) - test.begin();// 7(index)       
        
        return 0;
    }
    ~~~

  - binary_search()

    ~~~c++
    #include <iostream>
    #include <algorithm>
    #include <vector>
    using namespace std;
    int main() {
    	vector<int> test = { 0,1,2,3,4,5,5,7,8,9,10 };
    	bool check;
    	
    	check = binary_search(test.begin(), test.end(), 3);// true       
    	check = binary_search(test.begin(), test.end(), 6);// false 
    
    	return 0;
    }
    ~~~

  >**※ 모두 정렬된 데이터에 사용해야지 유효하다(오름차순으로 정렬된 데이터)**
