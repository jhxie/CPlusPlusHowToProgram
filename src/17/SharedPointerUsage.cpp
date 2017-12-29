#include <iostream>
#include <memory>

using namespace std;

class Demonstration final
{
public:
    void show()
    {
        cout << "Demonstration::show()" << endl << endl;
    }
};

int main(void)
{
    shared_ptr<Demonstration> pointerToDemonstrationA(new Demonstration);
    pointerToDemonstrationA->show();

    cout << "Return the memory address of 'pointerToDemonstrationA':" << endl;
    cout << pointerToDemonstrationA.get() << endl << endl;

    cout << "Share ownership with 'pointerToDemonstrationB'" << endl;
    shared_ptr<Demonstration> pointerToDemonstrationB(pointerToDemonstrationA);
    pointerToDemonstrationB->show();

    cout << "Compare the memory addresses of both A and B:" << endl;
    cout << pointerToDemonstrationA.get() << endl;
    cout << pointerToDemonstrationB.get() << endl << endl;

    cout << "Compare the reference count of both A and B:" << endl;
    cout << pointerToDemonstrationA.use_count() << endl;
    cout << pointerToDemonstrationB.use_count() << endl;

    pointerToDemonstrationA.reset();
    cout << "After relinquishing ownership of A on the object:" << endl;
    cout << pointerToDemonstrationA.get() << endl << endl;

    cout << "Now the reference count of B becomes:" << endl;
    cout << pointerToDemonstrationB.use_count() << endl;

    cout << "Now the address of B becomes:" << endl;
    cout << pointerToDemonstrationB.get() << endl;

    return 0;
}
