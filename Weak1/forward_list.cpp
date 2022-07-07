/*-----------------------------------------------------------------
|	forward_list : 데이터 중간에 자료를 추가하거나 삭제하는 작업이 용이한 링크드 리스트
	push_front() : 연결 리스트 맨 앞에 새로운 원소를 삽입
	insert_after() : 특정 원소에 원소 삽입
-----------------------------------------------------------------*/

#include <list>
#include <iostream>
#include <forward_list>

int main()
{
	std::forward_list<int> fwd = {1, 2, 3, 4,  5};
	fwd.pop_front(); // => {2, 3, 4, 5};
	
	auto it = fwd.begin();
	
	fwd.erase_after(it);  // => {2, 4, 5}

	fwd.erase_after(it, fwd.end()); // => {2}
}