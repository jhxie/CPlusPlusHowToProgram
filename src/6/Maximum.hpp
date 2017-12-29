/**
 * 6.22
 * Function template 'Maximum' header.
 *
 * From 6.17 (Chapter 6 Section 17) of
 * C++ How to Program, 10th Edition
 * "
 * Overloaded functions are normally used to perform similar operations that
 * involve different program logic on different data types. If the program
 * logic and operations are identical for each data type, overloading may be
 * performed more compactly and conveniently by using function templates.
 * "
 */
#pragma once

template <class T>
T Maximum(T left, T middle, T right)
{
    T maximum_value {left}; // assume 'left' is maximum

    // Determine whether 'middle' is greater than 'maximum_value'.
    if (middle > maximum_value) {
        maximum_value = middle;
    }

    // Determine whether 'right' is greater than 'maximum_value'.
    if (right > maximum_value) {
        maximum_value = right;
    }

    return maximum_value;
}
