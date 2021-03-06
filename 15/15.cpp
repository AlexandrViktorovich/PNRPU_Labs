#include <iostream>
using namespace std;
int n;
struct Aeroflot{ 
    int m;
    int d;
};

void Hoar(Aeroflot* a, int left, int right)
{
    int buf;
    int buf2;
    int i=left;
    int j=right;
    while (i<=j)
    {
        while (a[i].d < a[(left+right)/2].d && i < right)
        i++;
        while (a[j].d > a[(left+right)/2].d && j > left)
        j--;
        if (i <= j)
        {
            buf = a[i].d;
            a[i].d = a[j].d;
            a[j].d = buf;
            buf2 = a[i].m;
            a[i].m = a[j].m;
            a[j].m = buf2;
            i++;
            j--;
        }
        if (i > right)
        {
            Hoar (a, i, right);
        }
        if (j < left)
        {
            Hoar (a, left, j);
        }
    }

}

int main()
{
    cout << "Enter number of flights: " << endl;
    cin >> n;
    Aeroflot* p = new Aeroflot[n];
    for (int i=1; i<=n; i++)
    {
        cout << "Enter Aircraft registration number: " << endl;
        cin >> p[i].m;
        cout << endl;
        cout << "Enter arrival time:" << endl;
        cin >> p[i].d;
    }
    Hoar(p, 1, n+1);
    cout << "Sorted array:" << endl;
    for (int i=1; i<=n; i++)
    {
        cout << "Aircraft " << "Number"<< " " << p[i].m << " ";
        cout << "Arrival time" << " " << p[i].d << endl;
    }
	return 0;
}
