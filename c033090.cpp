#include <stdio.h>
#include <math.h>
#include "glibw32.h" // External reference http://www.asahi-net.or.jp/~uc3k-ymd/Glib32/glibw32.html

const int NUMBER = 180;
const double PI = 3.141593;

main()
{
    int i, j, I, J;
    double t, p, x, y, z;
    double r, R;
    double A, B, C;
    double D, E, F, G, H, K, L, M, N, O, P, Q;
    double X, Y, Z;
    r = 1.0;
    R = 2.0;
    A = 45 * (PI / NUMBER); // (double)/(int)->(double), degree->radian, rotate z
    B = 30 * (PI / NUMBER); //                                           rotate x
    C = 60 * (PI / NUMBER);
    ginit(500, 500, WHITE);
    GRAPH g;
    g.window(-PI, -PI, PI, PI);
    
    // External reference Wikipedia
    D = -PI * cos(A) - 0 * sin(A); // line x (-PI, 0) - (PI, 0) -> rotate z
    E = -PI * sin(A) + 0 * cos(A);
    F =  PI * cos(A) - 0 * sin(A);
    G =  PI * sin(A) + 0 * cos(A);
    
    H = 0 * cos(A) - PI * sin(A); // line y (0, PI) - (0, -PI) -> rotate z
    K = 0 * sin(A) + PI * cos(A);
    L = 0 * cos(A) - (-PI) * sin(A);
    M = 0 * sin(A) + (-PI) * cos(A);
    
    g.line(D, E, F, G); // rotate z line x
    g.line(H, K, L, M); //          line y
    g.line(0, 0, 0, 0); // z
    g.setcolor(BLACK);
    for(i = -NUMBER; i < NUMBER; i++)
    {
        I = i + NUMBER;
        t = I * (PI / NUMBER);
        for(j = -NUMBER; j < NUMBER; j++)
        {
            J = j + NUMBER;
            p = J * (PI / NUMBER);
            
            x = R * cos(t) + r * cos(p) * cos(t); // External reference Wikipedia
            y = R * sin(t) + r * cos(p) * sin(t);
            z = r * sin(p);
            
            X = x * cos(A) - y * sin(A); // External reference Wikipedia, rotate z
            Y = x * sin(A) + y * cos(A); //                               rotate z
            
            g.pset(X, Y);
        }
    }
    gend();
}
// cd c:\mingw-jp-20040217\bin
// g++ c033090.cpp libglibw32-3.a -IC:\mingw-jp-20040217\include\ -LC:\mingw-jp-20040217\lib\ -IC:\Glibw32\ -LC:\Glibw32\ -luser
// 32 -lgdi32
// rename a.exe c033090.*
