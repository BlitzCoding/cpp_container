/*-----------------------------------------------------------------
|	std::array는 메모리를 자동으로 할당, 해제하며, 타입과 배열 크기를 매개변수로 사용한다.
|	[]연산자는 빠른 동작을 위해 전달된 인덱스 값이 배열의 크기보다 작은지 검사하진 않는다.
|	-> at함수는 인자로 전달된 인덱스 값이 유효하지 않으면 std::out_of_range 발생
|		-> 그러므로 느리지만 예외를 적절하게 활용할 수 있다.
|	* 
|	-단 array의 크기는 컴파일 시간에 결정되는 상우이어햐 한다. 즉 프로그램 실행중 변경 x
|	-크기가 고정되어 있어서 원소를 추가하거나 삭제할 수 없다.
|	-메모리 할당 방법을 변경할 수 없으므라 항상 스택 메모리를 사용한다. 
-----------------------------------------------------------------*/

#include <string>
#include <algorithm>
#include <iostream>

#include <array>
#include <type_traits>

template <typename T>
class dynamic_array
{
	private :
		T* data;
		size_t n;
	public :
		dynamic_array(int n)
		{
			this->n = n;
			data = new T[n];
		}

		dynamic_array(const dynamic_array<T>& other)
		{
			n = other.n;
			data = new T[n];

			for (int i = 0; i < n; i++)
				data[i] = other[i];
		}

		// [], at() 함수
		T& operator[](int index)
		{
			return data[index];
		}

		const T& operator[](int index) const
		{
			return data[index];
		}

		T& at(int index)
		{
			if (index < n)
				return data[index];
			throw "Index out of range";
		}

		//소멸자
		size_t size() const
		{
			return n;
		}

		~dynamic_array()
		{
			delete[] data;
		}

		T* begin()
		{
			return data;
		}

		const T* begin()
		{
			return data;
		}

		T* end()
		{
			return data + n;
		}

		const T* end()
		{
			return data + n;
		}

		friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, dynamic_array<T>& arr2)
		{
			dynamic_array<T> result(arr1.size() + arr2.size());
			std::copy(arr1.begin(), arr1.end(), result.begin());
			std::copy(arr2.begin(), arr2.end(), result.begin());

			return result;
		}
};