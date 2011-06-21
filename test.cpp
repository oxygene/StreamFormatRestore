#include <iostream>
#include <iomanip>
#include <cmath>

#include "StreamFormatRestore.h"

void
print(std::ostream& f_stream)
{

    CStreamFormatRestore restore(f_stream);

    f_stream << std::setprecision(20)
             << std::scientific
             << std::setfill('*')
             << std::left
             << std::setw(40);


    f_stream << M_PI << std::endl;
}

int
main(int argc, char* argv[])
{
    std::cout << M_PI << std::endl;
    print(std::cout);
    std::cout << M_PI << std::endl;

    return 0;
}
