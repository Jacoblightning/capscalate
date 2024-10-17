//
// Created by jacoblightning3 on 10/16/24.
//

#include "helpers.h"

std::filesystem::path get_self_path() {
    return std::filesystem::canonical("/proc/self/exe");
}