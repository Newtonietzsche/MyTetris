#pragma once

 #include <pthread.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class Fenetre
{
    private:
        int tailleFenetre;
        
    public:
        pthread_t threadFenetre;

};