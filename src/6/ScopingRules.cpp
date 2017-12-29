/**
 * 6.11
 * Scoping example.
 */

#include <iostream>

using namespace std;

void UseGlobal();
void UseLocal();
void UseStaticLocal();

/*
 * Global variable;
 * variable has global namespace scope with static storage duration, and
 * internal linkage.
 */
static int x {1};

int main(void)
{
    cout << "global 'x' in 'main' is " << x << endl;

    int x {5}; // local variable to 'main', shadows 'x' in global namespace

    cout << "local 'x' in 'main''s outer scope is " << x << endl;

    // Block starts a new scope
    {
        int x {7}; // hides both 'x' in outer scope and global 'x'
        cout << "local 'x' in 'main''s inner scope is " << x << endl;
    }

    cout << "local 'x' in 'main''s outer scope is " << x << endl;

    UseLocal();       // 'UseLocal' has local 'x'
    UseStaticLocal(); // 'UseStaticLocal' has static local 'x'
    UseGlobal();      // 'UseGlobal' uses global 'x'

    UseLocal();       // 'UseLocal' re-initializes its local 'x'
    UseStaticLocal(); // 'UseStaticLocal' retains its prior value of static 'x'
    UseGlobal();      // 'UseGlobal' also retains its prior value of 'x'

    cout << "\nlocal 'x' in 'main' is " << x << endl;
    return 0;
}

/**
 * 'UseLocal' re-initializes local variable 'x' during each call.
 */
void UseLocal()
{
    int x {25}; // initialized each time 'UseLocal' is called

    cout << "\nlocal 'x' is " << x << " on entering 'UseLocal'" << endl;
    cout << "local 'x' is " << ++x << " on exiting 'UseLocal'" << endl;
}

/**
 * 'UseStaticLocal' initializes static local variable 'x' only the first time
 * the function is called; value of 'x' is saved between calls to this
 * function.
 */
void UseStaticLocal()
{
    static int x {50}; // initialized first time 'UseStaticLocal' is called

    cout \
        << "\nlocal static 'x' is " << x
        << " on entering 'UseStaticLocal'" << endl;
    cout \
        << "local static 'x' is " << ++x
        << " on exiting 'UseStaticLocal'" << endl;
}

/**
 * 'UseGlobal' modifies global variable 'x' during each call.
 */
void UseGlobal()
{
    cout \
        << "\nglobal 'x' is " << x
        << " on entering 'UseGlobal'" << endl;
    x *= 10;
    cout \
        << "global 'x' is " << x
        << " on exiting 'UseGlobal'" << endl;
}
