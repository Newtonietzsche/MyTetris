#pragma once

#include <pthread.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <queue.h>

class ControlManager
{
    private:
        int tailleFenetre;

    public:
        pthread_t threadController;

};