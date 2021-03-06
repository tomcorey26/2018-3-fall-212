#include <iostream>
#include <chrono>
#include <random>
#include <cmath>

#define t_p std::chrono::time_point<std::chrono::steady_clock>

int check_time(t_p start_time);

bool num_in_array(const int* arr, int len, int num) {
    return false;
}

bool sum2_in_array(const int* arr, int len, int num) {
    return false;
}

bool sum3_in_array(const int* arr, int len, int num) {
    return false;
}

// Generate an array of random integers. The range is +/- the size of the array
int* gen_rand_list(int size) {
    std::random_device sd;
    std::mt19937 generator(sd());
    std::uniform_int_distribution<int> distribution(-size,size);
    int* nlist = new int[size];
    for (int i = 0; i < size; i++) {
        nlist[i] = distribution(generator);
    }
    return nlist;
}

// Deallocate an array on the heap. A function alias for the delete keyword
void delete_list(int* arr) {
    delete [] arr;
}

// Auxiliary function to keep the program from running too long
int check_time(t_p start_time) {
    auto curr_time = std::chrono::steady_clock::now();
    double t = std::chrono::duration<double> (curr_time - start_time).count();
    return (t > 60) ? 1 : 0;
}

int main() {
    /* Creates an array of pointer to functions
     *
     * To call a function from this array, use the following line:
     *
     *      functions[i](arr, len, num);
     *
     * Where i is the index of the function to be used, and a, b are the parameters
     *    i = 0 : num_in_array
     *    i = 1 : sum2_in_array
     *    i = 2 : sum3_in_array
     *
     * This can be used to benchmark the different implementations without having to
     * repeat code.
     */
    typedef bool (*sum_fn)(const int*, int, int);
    sum_fn functions[] = {num_in_array, sum2_in_array, sum3_in_array};

    /* Example usage */
    // create a list of 20 random numbers (allocate the array dynamically in the heap) 
    int *arr = gen_rand_list(20);
    // apply the three functions to the array with lenght=20 and num=15
    for (int i = 0; i < 3; i++) {
        functions[i](arr, 20, 15);
    }
    delete_list(arr);

    /* Student code starts here */
    // TODO
    
    return 0;
}
