#include <iostream>
#include "AppWindow.h"
#include "app.h"

int main() {

    rag::app a;

    try {
        a.run();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;

}