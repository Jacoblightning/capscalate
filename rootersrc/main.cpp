#include <cstdlib>
#include <unistd.h>


int main() {
    setuid(0);
    system("sg root bash");
}
