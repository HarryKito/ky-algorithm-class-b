## 2023年12月13日 Project 完
* 알고리즘 수업 / 팀플 과제 / 문제해결

# 완성본 문제점 및 개선점

팀 프로젝트.. main 브렌치로 푸시 그만!...  
*******************************************************
### 깊은 복사 코드를 굳이 이렇게 짤 필요가 있었을까?  
### 과연 이게 깊은 복사인가?
개선 전
```cpp
object copy(object in,int number)
{
    object obj;
    obj.data_num = number;
    obj.date = in.date;
    obj.Ideparture = in.Ideparture;
    obj.Iarrival = in.Iarrival;
    obj.info[0] = in.info[0];
    obj.info[1] = in.info[1];
    obj.info[2] = in.info[2];
    return obj;
}
```
개선 후

*******************************************************
> 담당하였던 date sort 개인환경에서는 문제가 없었지만,  
> 윈도우 환경에서는 함수 호출 시 오버스택 발생
>> [해결방법](#solve)  
>> [근본적 원인](#problem)
 
# problem


# solve
