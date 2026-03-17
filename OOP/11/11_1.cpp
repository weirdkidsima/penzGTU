#include <iostream>

using namespace std;

class Distance { // длина в английской системе
    private:
        int feet;
        float inches;
    public:
        void setdist(int ft, float in)
        {
            feet = ft; inches = in;
        }
        void getdist()
        {
            cout << "\nВведите число футов: ";  cin >> feet;
            cout << "\nВведите число дюймов: ";  cin >> inches;
        }
        void showdist()
        {
            cout << feet << "\'-" << inches << '\"';
        }
};

int main()
{
    Distance dist1, dist2; // две длины
    dist1.setdist(11, 62.5); // установка значений для dist1
    dist2.getdist();// ввод значений для dist2

    cout << "\ndist1 = "; dist1.showdist();
    cout << "\ndist2 = "; dist2.showdist();
    cout << endl;
}