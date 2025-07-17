#pragma once
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <limits> // для std::numeric_limits
#include <thread>
#include <mutex>
#include <condition_variable>
#include <iomanip>
#include "initial_conditions.h"

#define USED false

std::string correctCommandInput();
std::string correctCommandInput(const std::string&);

#if USED
double handlingDoubleInput();
#endif
int handlingIntInput();