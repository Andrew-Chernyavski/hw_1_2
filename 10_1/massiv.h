#pragma once

class Massiv
{
public:
    Massiv();
    int click (int a, int b);
    bool victory(int a, int b);
private:
    int mas[3][3];
    bool lastCross;    
};
