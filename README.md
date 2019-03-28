#vector

A simple implementation of a dynamic vector, which automatically allocates and releases memory.

#Installation

The library can either be downloaded as a prebuild version or compiled from source.

To compile the library execute the following steps:
```
git clone --branch <version> https://gitea.metthub.de/Pfeifenjoy/vector
cmake -DCMAKE_BUILD_TYPE=Release -H. -Bbuild
cmake --build build --target install
```

This will download the source code, compile and install it.
Please replace `<version>` by your desired version of this library.

#Usage with cmake

The library can be easily included into cmake projects by importing the targets.

```cmake
find_package(vector <version> EXACT REQUIRED)
target_link_libraries(<target> PRIVATE vector::vector-shared)
#or
target_link_libraries(<target> PRIVATE vector::vector-static)
```

Hereby `<target>` is your target, which can be linked either to the shared or
the static vector library.

# Interface

The vector can be used as follows:

```c
vector_t vector;
vector_init(&vector, sizeof(int)); //initialize vector of ints

int i = 42;
vector_push(&vector, &i); //copy i to the end of the vector

printf("The vector has %zu elements.\n", vector.length);

int *a = (int *) vector_get(&vector, 0); //get the first element
printf("Using element of vector: %d\n", *a);

vector_delete(&vector, 0); //delete the first element

vector_destroy(&vector);
```
