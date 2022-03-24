3649번 로봇 프로젝트
---
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);
    int x, n, lego[1000000];
    // 길이 x / 레고조각 갯수 n / lego[] 레고조각의 배열

    while(cin >> x){
        // 여러 테스트 케이스을 입력 받기위해 조건으로 입력 받음(cin)
        x *= 10000000;

        cin >> n;
        for(int i=0;i<n;i++) cin >> lego[i];

        sort(lego,lego+n);
        // two pointer을 사용하여 탐색하기 위해 정렬 
        
        int sum=0, left=0, right=n-1;
        bool flag = true;

        while(left<right){
            // lego[left] 는 2개의 레고 중 작은 블럭, lego[right]는 큰 블럭이라고 볼 수 있다.

            sum = lego[left] + lego[right];

            if(sum < x) left++;
            else if(sum > x) right--;
            else {
                flag = false;
                break;
            }
            // sum 과 구멍의 너비 x와 비교하여 작을 경우, 큰 경우, 같을 경우를 생각하여 탐색한다.
        }

        if(flag) cout << "danger\n";
        else cout << "yes " << lego[left] << ' ' << lego[right] << "\n";
        // 위 while 문이 한번도 돌 지 않았을 때에는 flag에 의해 danger 가 출력
    }
    return 0;
}
```

