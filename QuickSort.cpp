#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void QuickSort (int Array[], /* array to sort */
		unsigned int N, /* array size */
		int L, /* array left limit */
		int R) /* array right limit */
{
    int iter = L ,
        jter = R ;

    int middle = (R+L)/2 ;

    int x = Array [middle] ;
    int w ;

    do
    {
        while (Array[iter]<x)
        { iter ++ ; }

        while (x<Array[jter])
        { jter -- ; }

        if (iter<=jter)
        {
           w = Array [iter];
           Array [iter] = Array [jter] ;
           Array [jter] = w ;

           iter ++ ;
           jter -- ;
        }
    }
    while (iter<jter) ;

    if (L<jter)
    { QuickSort (Array, N, L, jter) ; }

    if (iter<R)
    { QuickSort (Array, N, iter, R) ; }
}

const int Min = -100;
const int Max = 100;
const int N = 50;

int main()
{
    srand(time(0));

    int a[N];
    for(int i = 0; i < N; i++){
        a[i] = Min + (rand() % (Max - Min + 1));
        std::cout << a[i] << ' ';
    }
    std::cout << "\n\n\t Sorting..... \n\n";

    QuickSort (a, N, 0, N-1) ;

    for(int i = 0; i < N; i++){
        std::cout << a[i] << ' ';
    }

    return 0 ;
}
