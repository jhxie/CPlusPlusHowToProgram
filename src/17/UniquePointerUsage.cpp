#include <iostream>
#include <memory>

using namespace std;

class Demonstration final
{
public:
    void show(void)
    {
        cout << "Demonstration::show()" << endl;
    }
};

int main(void)
{
    unique_ptr<Demonstration> pointerToDemonstrationA(new Demonstration);
    pointerToDemonstrationA->show();

    cout << "Return the memory address of 'pointerToDemonstrationA':" << endl;
    cout << pointerToDemonstrationA.get() << endl << endl;

    cout << "Transfer ownership to 'pointerToDemonstrationB'" << endl;
    unique_ptr<Demonstration> pointerToDemonstrationB = \
        move(pointerToDemonstrationA);
    pointerToDemonstrationB->show();

    cout << "Compare the memory addresses of both A and B:" << endl;
    cout << pointerToDemonstrationA.get() << endl;
    cout << pointerToDemonstrationB.get() << endl << endl;

    cout << "Transfer ownership to 'pointerToDemonstrationC'" << endl;
    unique_ptr<Demonstration> pointerToDemonstrationC = \
        move(pointerToDemonstrationB);
    pointerToDemonstrationC->show();

    cout << "Compare the memory addresses of both A B C:" << endl;
    cout << pointerToDemonstrationA.get() << endl;
    cout << pointerToDemonstrationB.get() << endl;
    cout << pointerToDemonstrationC.get() << endl;
    return 0;
}
