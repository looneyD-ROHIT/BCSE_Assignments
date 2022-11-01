#include "C:\Users\rohit\Desktop\Assignments\30Sept21SKS\headers.h"

template <size_t N>
void fun(int (&arr)[N])
{
    cout << "dimension = " << N << endl;
}

int main()
{
    int arr[10];
    fun(arr);
    return 0;
}