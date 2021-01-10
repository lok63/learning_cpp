# Inclusion Guards

## **Declaring variables, functions or classes multiple times**

C++ programs will not compile if a variable, function or class gets declared more than once. This might seem easy to avoid when the codebase is small. But imagine what happens when you have a large codebase with many different classes, .cpp files, and personnel working on different parts of the code.

Take a look at this code below. There are two different classes in two separate files. One class represents an engine with a variable storing the size of the engine. The other class represents a car, which has a color variable and a variable representing the number of doors.

But there's a catch. The car class also uses the engine class in order to store the car's engine properties. That is why the car.h header file includes the engine header file with the line:

```
#include "engine.h"
```

However, the code will not compile in its current state. Think about why it does not compile correctly when you press the "Test Run" button.

As a hint, look at the include statements on the top of main.cpp. Include statements will essentially copy a file into another file. Remember that a program that defines a class more than once will not compile.

he code would not compile because of these statements:

```
#include "engine.h"#include "car.h"
```

The first include statement will copy the contents of the engine header file into main.cpp. So main.cpp will have the definition of the Engine class.

But then, main.cpp will copy the contents of "car.h" as well. But the "car.h" file also includes engine.h:

```
#include "engine.h"
```

The "engine.h" file ends up being included twice, so the Engine class is declared twice. The Car uses the engine class, and main.cpp also uses the engine class.

The modularity of .cpp and .h files is a big advantage of C++. But how can you avoid the multiple declarations?

# **ifndef**

The solution is to use `# ifndef` statements, which allow you to implement a technique called inclusion guards.

The ifndef statement stands for "if not defined". When you wrap your header files with #ifndef statements, the compiler will only include a header file if the file has not yet been defined. In the current main.cpp example, the "engine.h" file would be included first. Then the compiler includes "car.h". But "car.h" will try to include "engine.h" again; however, the inclusion guard in the "engine.h" file will ensure that "engine.h" does not get included again.

Here is what the "engine.h" file looks like with an ifndef statement:

```cpp
#ifndef ENGINE_H
#define ENGINE_H

#include <string>

class Engine
{
    private:
        std::string enginesize;

    public:

        Engine ();

        Engine (std::string);

        void setSize(std::string);

        std::string getSize();

};

#endif /* ENGINE_H */
```

```cpp
#ifndef FILENAME_H
#define FILENAME_H

header code ...

#endif /* FILENAME_H */
```

Using all caps with the _H is a naming convention. It is also customary to put a comment after the #endif statement with the filename.

You would want to wrap all of your header files with #ifndef statements. That way other programs do not have to keep track of what files have already been included when they want to use your code.

Here are the results of including #ifndef statements in the engine and car header files. If you click on "Test Run", you will see that the code now compiles.

# **Namespaces in Header Files**

As an aside, you'll notice that the header files did not use the standard namespace. It's generally recommended to avoid using namespaces in a header file. This can help avoid naming conflicts later as functions and classes are reused in different parts of a code base.