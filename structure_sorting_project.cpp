#include <iostream>
#include<bits/stdc++.h>    // to use sort function
using namespace std;




struct student
{
    //char name[20];
    string name;
    int number;
    int day, month, year;   //graduation date
};





bool compare_names(const student &n1, const student &n2)
{
    if (n1.name != n2.name)
            return n1.name < n2.name;
}

void sortNames(student arr[], int n)
{
    sort(arr, arr+n, compare_names);
}





bool compare_numbers(const student &n1, const student &n2)
{
    if (n1.number != n2.number)
            return n1.number < n2.number;
}

void sortNumbers(student arr[], int n)
{
    sort(arr, arr+n, compare_numbers);
}





bool compare_dates(const student &d1, const student &d2)
{
    // All cases when true should be returned
    if (d1.year < d2.year)
        return true;
    if (d1.year == d2.year && d1.month < d2.month)
        return true;
    if (d1.year == d2.year && d1.month == d2.month &&
                              d1.day < d2.day)
        return true;

    // If none of the above cases satisfy, return false
    return false;
}

// Function to sort array arr[0..n-1] of dates
void sortDates(student arr[], int n)
{
    // Calling in-built sort function.
    // First parameter array beginning,
    // Second parameter - array ending,
    // Third is the custom compare function
    sort(arr, arr+n, compare_dates);
}



void displayData(struct student arr[], int n)
{
    for (int i=0; i<n; i++)
    {
        cout << arr[i].name << "\t" << arr[i].number << "\t (" << arr[i].day
             << "/"<< arr[i].month << "/"<< arr[i].year << ")\n" ;
    }

}


int main()
{
    student arr[5];
    int n = sizeof(arr)/sizeof(arr[0]);


    cout<<"Please enter (name number day month year): \n";
    for (int i=0; i<n; i++)
    {
        cin >> arr[i].name >> arr[i].number >> arr[i].day
            >> arr[i].month >> arr[i].year;
    }

    cout << "\n\nyour structure: \n";
    displayData(arr, n);


    sortNames(arr, n);
    cout << "\n\nSorted by names:\n";
    displayData(arr, n);


    sortNumbers(arr, n);
    cout << "\n\nSorted by IDs:\n";
    displayData(arr, n);


    sortDates(arr, n);
    cout << "\n\nSorted by graduation dates:\n";
    displayData(arr, n);


    return 0;
}






