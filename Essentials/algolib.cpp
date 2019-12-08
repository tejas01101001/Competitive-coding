(1)sort(startaddress, endaddress)

startaddress: the address of the first element of the array
endaddress: the address of the last element of the array

int a[10]= {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
sort(a, a+10); 

So by default, sort() sorts an array in ascending order.
sort(a, a+n, greater<int>());
//To sort in descending order
n=sizeof(a)

sort(vec.begin(),vec.end())

(2)binary_search(startaddress, endaddress, valuetofind)

NOTE:array must be sorted.

startaddress: the address of the first element of the array.
endaddress: the address of the last element of the array.
valuetofind: the target value which we have to search for

if (binary_search(a, a + n, 4)) 
        cout << "\nElement found in the array"; 

(3)Algorithm lib
sort(first_iterator, last_iterator) – To sort the given vector
reverse(first_iterator, last_iterator) – To reverse a vector.
*max_element (first_iterator, last_iterator) – To find the maximum element of a vector.
*min_element (first_iterator, last_iterator) – To find the minimum element of a vector.
accumulate(first_iterator, last_iterator, initial value of sum) – Does the summation of vector elements


// Initializing vector with array values 
    int arr[] = {10, 20, 5, 23 ,42 , 15}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    vector<int> vect(arr, arr+n); 
  
sort(vect.begin(), vect.end());//5 10 15 20 23 42 
reverse(vect.begin(), vect.end());//42 23 20 15 10 5 
*max_element(vect.begin(), vect.end());// 42
*min_element(vect.begin(), vect.end());//5
accumulate(vect.begin(), vect.end(), 0);//115

count(first_iterator, last_iterator,x) –
To count the occurrences of x in vector.

find(first_iterator, last_iterator, x) – 
Points to last address of vector ((name_of_vector).end()) if element is not present in vector.

// Initializing vector with array values 
    int arr[] = {10, 20, 5, 23 ,42, 20, 15}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    vector<int> vect(arr, arr+n); 
  
 count(vect.begin(), vect.end(), 20);//2
 find(vect.begin(), vect.end(),5);

vec.erase(position to be deleted) – 
This erases selected element in vector and shifts and resizes the vector elements accordingly.
vec.erase(unique(vec.begin(),vec.end()),vec.end()) – 
This erases the duplicate occurrences in sorted vector in a single line.

// Initializing vector with array values 
    int arr[] = {5, 20, 5, 23, 20, 20}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    vector<int> vect(arr, arr+n); 

vect.erase(vect.begin()+1);//5 5 23 20 20 
//sort enables to use of unique.
sort(vect.begin(), vect.end());
vect.erase(unique(vect.begin(),vect.end()),vect.end()); 
// 5 20 23

distance(first_iterator,desired_position) – 
It returns the distance of desired position from the first iterator.This function is very useful while finding the index.

distance(vect.begin(),max_element(vect.begin(), vect.end()));
                      
next_permutation(first_iterator, last_iterator) – 
This modified the vector to its next permutation.
prev_permutation(first_iterator, last_iterator) – 
This modified the vector to its previous permutation.

next_permutation(vect.begin(), vect.end());
prev_permutation(vect.begin(), vect.end());

Given Vector is:
5 10 15 20 20 23 42 45 
Vector after performing next permutation:
5 10 15 20 20 23 45 42 
Vector after performing prev permutation:
5 10 15 20 20 23 42 45  

lower_bound(first_iterator, last_iterator, x) – 
returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘x’.
upper_bound(first_iterator, last_iterator, x) – 
returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘x’.                       